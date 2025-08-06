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
  std::string downloadPath;
  int downloadPos;
  std::vector<std::string> _config;
  void findConfigPath();
  void checkConfig();
  void writeConfig();
  void newConfig();
};
