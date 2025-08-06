#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class configure {
  std::string defPath = "";
  void findConfigPath();
  void checkConfig();
  void writeConfig();
};
