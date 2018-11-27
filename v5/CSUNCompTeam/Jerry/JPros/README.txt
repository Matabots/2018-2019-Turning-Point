


This project, JPROS, is the v5 code for the small robot named Jerry.
  -CSUN Vex Robotics

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


For Danial, Gisela, Omar, and the rest of the CSUN Programming Competition Team:

These are the main files and their contents:

#bin
  - (DON'T EDIT) low level machine language data stuff, don't worry about it.
#firmware
  - (DON'T EDIT) project firmware low level language stuff, don't worry about it either.
#include
  - (DON'T EDIT) This folder contains all the api libraries available for us to use.
  Unfortunately, we cannot use the okapi and pros namespaces at the same time,
  so for now, we will be working in the pros namespace. API is available online.
  -This folder also contains the main header files for our project.

  #display
    - (DON'T EDIT) This is the library for the screen UI.
  #okapi
    - (DON'T EDIT) This is the library for the okapi namespace, which we are
    not using at the moment.
  #pros
    - (DON'T EDIT) This is the library for the pros namespace.
  *api.h
    - (DON"T EDIT) This file holds the general library for the pros namespace.
  *auton_commands.hpp
    - This file contains the signatures of the main autonomous commands, and
    selects the
    autonomous to use.
  *auton_scripts.hpp
    - This file contains the signatures of the methods/functions to use for an
    autonomous code.
  *drive.hpp
    - This file contains the signature(s) of the drive method(s).
  *main.h
    - This is the main file of the **whole** project. It contains the includes
    of all the header files that are being used, and this file should be called
    in every file that we create. It also declares the pros namespace.
  *serial.hpp
    - This file contains the signatures of the serial communication to run between the vex v5
    brain and another microcontroller/SBC.
#src
  -This folder contains the main c++ source code for our project. Each c++ file
  must have a corresponding header file with the proper syntax for these to
  work. Each file must have a "#include "main.h"" and
  "#include "headerfilename.hpp"" (where headerfilename is the name of the
  corresponding header file) as well as includes for all the other header files
  needed.

  *auton_commands.cpp
    - This file contains the main autonomous commands, and
    selects the autonomous to use.
  *auton_scripts.cpp
    - This file contains the methods/functions to use for an
    autonomous code.
  *autonomous.cpp
    - (DON'T EDIT UNLESS NEEDED) This file runs the autonomous code that is chosen through
    "auton_scripts.cpp"
  *drive.cpp
    - This file contains the drive method(s).
  *initialize.cpp
    - (DON'T EDIT UNLESS NEEDED) This file initializes the brain and some of the namespace.
  *opcontrol.cpp
    - This file runs the driver code written in "drive.cpp".
  *serial.cpp
    - This file contains the serial communication to run between the vex v5
    brain and another microcontroller/SBC.

#common.mk
  - (DON'T EDIT) This contains 'make' information.

#Makefile
  - (DON'T EDIT) This contains the 'make' instructions for building the program.
#project.pros
  - (DON'T EDIT) This is a .pros file, a low level code for the firmware to run.
#README.txt
  - (DON'T EDIT) This file.
