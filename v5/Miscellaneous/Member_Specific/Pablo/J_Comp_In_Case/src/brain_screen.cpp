#include "main.h"
//#include "auton_commands.hpp"
#include "robot.hpp"
#include "brain_screen.hpp"
//#include
//LV_IMG_DECLARE(matabots);

lv_obj_t * rpm_meter;
lv_obj_t * rpm_label;
lv_obj_t * rpm_name;
lv_obj_t * graph;
lv_obj_t * rpm_graph_line;
lv_obj_t * title;
lv_obj_t * gyro_name;
lv_obj_t * gyro_val;
lv_obj_t * gyro_meter;

lv_chart_series_t * rpm_line;
lv_chart_series_t * tar_rpm_line;
static lv_point_t line_points[] = { {0,0}, {5,0}};

std::string output_val;
int flywheel_rpm = 0;
int gyro_deg = 0;
int graph_max = 11;
int currentRPMx = 0;
int currentRPMy = 0;
int priorRPMx = 0;
int priorRPMy = 0;
int graphed_count = 0;
std::uint32_t startTime;
std::uint32_t priorTime;

void flywheel_control_screen()
{

  //=============================Screen
  lv_obj_t * screen = lv_page_create(NULL,NULL);
  lv_scr_load(screen);
  //=============================Title
  title = lv_label_create(screen, NULL);
  lv_label_set_text(title,"Flywheel\nSystem Control");
  lv_obj_set_x(title,20);
  //=============================Graph background
  graph = lv_chart_create(lv_scr_act(), NULL);
  lv_obj_set_size(graph, lv_obj_get_width(screen) / 2, lv_obj_get_width(screen) / 4);
  lv_obj_align(graph, title, LV_ALIGN_OUT_BOTTOM_LEFT, -10, 20);
  lv_chart_set_range(graph, -25, 300);
  //=============================Graph Line
  lv_chart_set_series_width(graph, 1);
  rpm_line = lv_chart_add_series(graph, LV_COLOR_RED);
  tar_rpm_line = lv_chart_add_series(graph, LV_COLOR_LIME);
  // lv_chart_set_point_count(graph, 21);
  //lv_chart_set_div_line_count(graph,
  for (int x = 0; x < 11; x++)
  {
    rpm_line->points[x] = 0;
    delay(20);
  }

  //=============================

  //code Matabots logo here

  //=============================RPM Meter
  static lv_style_t meter_style;
  lv_style_copy(&meter_style, &lv_style_pretty_color);
  meter_style.line.width = 2;
  meter_style.line.color = LV_COLOR_GRAY;
  meter_style.body.padding.hor = 16;
  meter_style.body.main_color = LV_COLOR_LIME;
  meter_style.body.grad_color = LV_COLOR_ORANGE;

  rpm_meter = lv_lmeter_create(lv_scr_act(), NULL);
  lv_lmeter_set_range(rpm_meter, 0, 200);
  lv_lmeter_set_style(rpm_meter, &meter_style);
  lv_obj_set_size(rpm_meter, 100, 100);
  lv_obj_align(rpm_meter, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -20, -10);
  lv_lmeter_set_scale(rpm_meter, 240, 50);

  static lv_style_t num_style;
  lv_style_copy(&num_style, &lv_style_pretty);
  num_style.text.font = &lv_font_dejavu_20;
  num_style.text.color = LV_COLOR_SILVER;

  rpm_label = lv_label_create(rpm_meter, NULL);
  lv_label_set_style(rpm_label, &num_style);
  lv_obj_align(rpm_label, NULL, LV_ALIGN_CENTER, 0, 0);

  rpm_name = lv_label_create(screen, NULL);
  lv_label_set_text(rpm_name,"RPM\n  ");
  lv_obj_align(rpm_name,rpm_meter, LV_ALIGN_OUT_LEFT_TOP, 0,0);

  //=============================Line //not used


  // static lv_style_t line_style;
  // lv_style_copy(&line_style, &lv_style_plain);
  // line_style.line.color = LV_COLOR_RED;
  // line_style.line.width = 4;
  // //
  // rpm_graph_line = lv_line_create(lv_scr_act(), NULL);
  // lv_line_set_points(rpm_graph_line, line_points, 2);
  // lv_line_set_style(rpm_graph_line, &line_style);
  // lv_obj_align(rpm_graph_line, graph, LV_ALIGN_IN_LEFT_MID, 0,0);

  //=============================Gyro Meter

  static lv_style_t gyro_style;
  lv_style_copy(&gyro_style, &lv_style_pretty_color);
  gyro_style.body.main_color = LV_COLOR_BLUE;     /*Line color at the beginning*/
  gyro_style.body.grad_color = LV_COLOR_YELLOW;     /*Line color at the end*/
  gyro_style.body.padding.hor = 10;                      /*Scale line length*/
  gyro_style.body.padding.inner = 8 ;                    /*Scale label padding*/
  gyro_style.body.border.color = LV_COLOR_HEX3(0x333);   /*Needle middle circle color*/
  gyro_style.line.width = 1;
  gyro_style.text.color = LV_COLOR_SILVER;
  gyro_style.line.color = LV_COLOR_RED;
  gyro_style.text.font = &lv_font_dejavu_20;



  static lv_color_t needle_colors[] = {LV_COLOR_AQUA};
  gyro_meter = lv_gauge_create(lv_scr_act(), NULL);
  lv_obj_set_size(gyro_meter, 100, 100);
  lv_gauge_set_style(gyro_meter, &gyro_style);
  lv_gauge_set_needle_count(gyro_meter, 1, needle_colors);
  lv_obj_align(gyro_meter, rpm_meter, LV_ALIGN_OUT_TOP_MID, 0,-10);
  lv_gauge_set_scale(gyro_meter, 360, 180, 1);
  lv_gauge_set_range(gyro_meter, 0, 360);


  gyro_name = lv_label_create(screen, NULL);
  lv_label_set_text(gyro_name,"Gyro\n  ");
  lv_obj_align(gyro_name,gyro_meter, LV_ALIGN_OUT_LEFT_TOP, 0,0);

  gyro_val = lv_label_create(gyro_meter, NULL);
  lv_obj_align(gyro_val,gyro_meter, LV_ALIGN_CENTER, 0, 0);

  //=============================PID Value Button Matrix


}

void rpm_meter_updater()
{
  flywheel_rpm = get_flywheel_avg_rpm();
  output_val = std::to_string(flywheel_rpm) + "%";
  lv_lmeter_set_value(rpm_meter, flywheel_rpm);
  lv_label_set_text(rpm_label, output_val.c_str());
}

void gyro_meter_updater()
{
  gyro_deg = (get_gyro_val()/10);
  output_val = std::to_string(gyro_deg) + "°";
  if (gyro_deg < 0)
  {
    gyro_deg = (360 -(abs(gyro_deg) % 360));
    lv_gauge_set_value(gyro_meter, 0, gyro_deg);
  }
  else
  {
    gyro_deg = (abs(gyro_deg) % 360);
    lv_gauge_set_value(gyro_meter, 0, gyro_deg);
  }
  lv_label_set_text(gyro_val, output_val.c_str());
}

//This line updater was a diversion of the graph_updator.
//unfortunately, it was not yet found a way to clear the line.
//Fortunately, the graph worked out.

// void line_updater()
// {
//   // //21 ms each line prints out a graphed line in 10 seconds
//   // if ((((millis() - (millis()*graphed_count)) - currTime)) >= 21)
//   // {
//   //   if (currentRPMx < graph_max)
//   //   {
//   //     currentRPMx = currentRPMx + 5;
//   //     line_points = {{priorRPMx,priorRPMy},{currentRPMx,currentRPMy}};
//   //     priorRPMx = currentRPMx;
//   //     priorRPMy = currentRPMy;
//   //   }
//   //   else
//   //   {
//   //     graphed_count++;
//   //     currentRPMx = 0;
//   //     lv_obj_align(graph, title, LV_ALIGN_OUT_BOTTOM_LEFT, -10, 20);
//   //   }
//   //   lv_line_set_points(rpm_graph_line, line_points, 2);
//   // }
//   // currentRPMy = get_flywheel_avg_rpm();
// }

void graph_updater()
{
    if ((((millis() - (millis()*graphed_count)) - priorTime)) >= 21)
    {
      if (currentRPMx < graph_max)
      {
        rpm_line->points[currentRPMx] = abs(get_flywheel_avg_rpm());
        tar_rpm_line->points[currentRPMx] = abs(get_flywheel_target_rpm());
        currentRPMx++;
      }
      else
      {
        graphed_count++;
        currentRPMx = 0;
        lv_chart_refresh(graph);
      }
      priorTime = millis();
    }
}

void PID_buttons_update()
{

}
void screen_updater()
{
  // line_points = {}
  startTime = millis();
  priorTime = millis();
  while(true)
  {
    //flywheelUpdater
    rpm_meter_updater();
    //graphUpdater
    //line_updater();
    graph_updater();
    //Gyro updater
    gyro_meter_updater();
    //KPKIKD button
    PID_buttons_update();
    delay(20); //every task with a while loop must have this
  }
}

void draw_test_screen()
{
  //flywheel_set(200);
  // lv_obj_t * label1 =  lv_label_create(lv_scr_act(), NULL);
  // lv_label_set_text(label1, "Hello world!");
  // lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
  flywheel_control_screen();
  screen_updater();
}

//task method for the program of this whole page
void run_brain(void* pntr2)
{
	draw_test_screen();
}
