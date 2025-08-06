#include "sub/configure.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <string>

void configure::findConfigPath() {
  try {
    const char *user = getenv("USER");
    if (user != nullptr) {
      _user = *user;

    } else {
      throw("ERROR WITH FINDING PATH");
    }
  } catch (...) {
  }

  path.append(&_user);
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
      if (buffer[i] != '\n') {

        holder.push_back(buffer[i]);

      } else {
        _config.push_back(holder);
        holder.clear();
      }
    }

  } catch (...) {
  }
  for (int i = 0; i < _config.size(); i++) {
    if (_config[i].find("download")) {
      downloadPos = i;
      downloadPath = _config[i];
    };
  }
}

void configure::writeConfig() {
  std::fstream file;

  try {
    file.open(path, std::ios_base::out);
    if (file.fail())
      throw("FAIL TO OPEM CONFIG ");
    else {
      file.clear();
      std::streamsize size = 5024;
      for (int i = 0; i < _config.size(); i++) {
        file.write(_config[i].c_str(), size);
      }
    }
  } catch (...) {
  }
}
