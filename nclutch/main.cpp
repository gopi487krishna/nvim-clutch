#include <CppLinuxSerial/SerialPort.hpp>
#include <iostream>
#include <xdo.h>

int main(int argc, char* argv[]) {

  std::string filename;
  
  if (argc > 1 )
  {
      filename = std::string(argv[1]);
  }
  else
  {
      std::cerr << "Error : Please provide the path to the device\n";
      return EXIT_FAILURE;
  }

  /*Screen context*/
  xdo_t *x = xdo_new(":0.0");


  mn::CppLinuxSerial::SerialPort serialport(
      "/dev/ttyACM0", mn::CppLinuxSerial::BaudRate::B_9600,
      mn::CppLinuxSerial::NumDataBits::EIGHT, mn::CppLinuxSerial::Parity::NONE,
      mn::CppLinuxSerial::NumStopBits::ONE);

  /*Block on read and wait until we get atleast 1 byte*/
  serialport.SetTimeout(-1);

  /*Open the file for communication*/
  serialport.Open();

  std::string readData; // Dummy var for reading a byte

  while (true) {
    serialport.Read(readData);

    /*Send escape key to the focused window*/
    xdo_send_keysequence_window(x, CURRENTWINDOW, "Escape", 0);
  }
  serialport.Close();
  delete x;


  return EXIT_SUCCESS;
}
