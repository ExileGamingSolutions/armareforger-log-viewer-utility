#include "main.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  _configure.findConfigPath();
  _configure.checkConfig();
  std::cout << _configure._user << std::endl;
  std::cout << _configure.path << std::endl;
  //
  //_scan.readFile(_configure.path);
  // unParsedLogs = _scan.logLines;
  //_parseSort.filter(unParsedLogs);

  return 0;
}
