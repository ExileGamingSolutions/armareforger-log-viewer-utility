#include "sub/configure.hpp"
#include <bits/types/error_t.h>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

void configure::findConfigPath() {
  try {
    _user = getenv("USER");

  } catch (...) {
  }

  path.append(_user);
  path.append("/.config/armareforger-log-viewer-utility_config.toml");
}

void configure::checkConfig() {
  std::fstream file;
  std::string buffer;
  std::string holder;
  try {
    file.open(path, std::ios_base::in);
    if (file.fail())
      throw("FAIL TO OPEN CONFIG");
    std::getline(file, buffer, '\n');
    for (int i = 0; i < buffer.length(); i++) {
      if (buffer[i] != ' ') {
        std::cout << "out\n";
        holder.push_back(buffer[i]);

      } else {
        _config.push_back(holder);
        holder.clear();
      }
    }

  } catch (...) {
  }
  for (int i = 0; i < _config.size(); i++) {
    if (_config[i].find("downloadPath")) {
      downloadPos = i;
      downloadPath = _config[i];
    } else if (_config[i].find("logPath")) {
      logPos = i;
      logPath = _config[i];
    }
  }
}

void configure::writeConfig() {
  std::ofstream file;
  _config[logPos] = "logPath=" + logPath;
  _config[downloadPos] = "downloadPath=" + downloadPath;

  try {
    file.open(path);
    if (file.is_open() == false)
      throw("FAIL TO OPEN CONFIG ");
    else {
      for (int i = 0; i < _config.size(); i++) {
        file << _config[i] << std::endl;
      }
    }
  } catch (...) {
  }
}
int configure::newConfig() {
  int i = 0;
  while (i != 4) {
    switch (i) {
    case 0:
      std::cout << "What would you like to configure?\n"
                << "1).\t Download path\n"
                << "2).\t Log file path\n"
                   "3).\t Write to disk\n"
                << "4).\t Exit\n";
      std::cin >> i;
      break;
    case 1:
      std::cout << "you selected changing the download path, please enter the "
                   "full path with no quotation marks below\n";
      std::cin >> path;
      i = 0;
      break;
    case 2:
      std::cout << "you selected changing the log path, please enther the full "
                   "path with no quotation marks below\n";
      std::cin >> logPath;
      i = 0;
      break;
    case 3:
      writeConfig();
      i = 0;
      break;
    case 4:
      std::cout << "Exiting.\n";
      break;
    default:
      i = 0;
    }
  }
  return 1;
}
