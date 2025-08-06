#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class configure {
public:
  std::string _user;
  std::string path = "/home/";
  std::string logPath;
  std::string downloadPath;
  int downloadPos = 0;
  int logPos = 1;
  std::vector<std::string> _config;
  void findConfigPath();
  void checkConfig();
  void writeConfig();
  int newConfig();
};
