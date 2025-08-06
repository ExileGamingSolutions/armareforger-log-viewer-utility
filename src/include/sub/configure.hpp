#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class configure {
public:
  char _user;
  std::string path = "/home/";
  std::string downloadPath;
  std::vector<std::string> _config;
  void findConfigPath();
  void checkConfig();
  void writeConfig();
};
