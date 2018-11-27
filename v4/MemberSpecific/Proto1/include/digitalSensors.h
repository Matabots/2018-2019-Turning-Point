#ifndef DIGITALSENSORS_H
#define DIGITALSENSORS_H

#include "ports.h"
#include "API.h"
//unsure how to modularize this class due to encoders being
//too specific
class digitalSensors{
  private:
    Encoder leftEncoder;
    Encoder rightEncoder;
    Encoder rightLiftEncoder;
    Encoder leftLiftEncoder;
    Encoder coneLiftEncoder;
    int leftLimitSwitchPort;
    int leftLimitSwitch;
    int rightLimitSwitchPort;
    int rightLimitSwitch;

  public:
    digitalSensors();

    void set_leftLimitSwitch(int port);
    int get_leftLimitSwitch();
    void set_rightLimitSwitch(int port);
    int get_rightLimitSwitch();


    void set_coneLiftEncoder(int port1, int port2, bool direction);
    Encoder get_coneLiftEncoder();
    int coneLiftEncoderVal();

    void set_leftLiftEncoder(int port1, int port2, bool direction);
    Encoder get_leftLiftEncoder();
    int leftLiftEncoderVal();

    void set_rightLiftEncoder(int port1, int port2, bool direction);
    Encoder get_rightLiftEncoder();
    int rightLiftEncoderVal();
    int rightLiftEncoderValModern();

    void set_LeftEncoder(int port1, int port2, bool direction);
    Encoder get_LeftEncoder();
    Encoder* get_pLeftEncoder();
    int leftEncoderVal();
    void set_RightEncoder(int port1, int port2, bool direction);
    Encoder get_RightEncoder();
    int rightEncoderVal();
    void resetDriveEncoders();
    void resetLiftEncoders();

    void printEncoderValues();
};
#endif
