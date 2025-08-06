#include "sub/scan.hpp"
void scan::readFile(std::string file) {
  try {
    read.open(file);

    if (read.fail())
      throw("CHECK PATH");

    if (file == "def")
      throw("PATH NOT CONFIGURED");
    std::cout << "OPENED SUCCESSFULLY! \n";

  } catch (...) {
    std::cout << "CANNOT OPEN FILE\n";
  };
  // null endline
  std::getline(read, a, '\000');

  for (int i = 0; i < a.length(); i++) {
    if (a[i] != '\n') {

      x.push_back(a[i]);

    } else {
      logLines.push_back(x);
      x.erase();
    }
  }
  read.close();
}
std::vector<std::string> scan::getLog() { return logLines; }
