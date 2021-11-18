#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  auto bottles = 99;
  if (argc > 1) {
    bottles = std::stoi(argv[1]);
  }
  for (auto n = bottles; n > 0; --n) {
    std::cout << bottles << " bottles of beer on the wall, ";
    std::cout << bottles << " bottles of beer.\n";
    std::cout << "Take one down, pass it around, ";
    std::cout << --bottles << " bottles of beer on the wall...\n";
  }
  std::cout << "No more bottles of beer on the wall,";
  std::cout << "no more bottles of beer.";
  std::cout << "Go to the store and buy some more, ";
  std::cout << bottles << " bottles of beer on the wall...\n";

  return 0;
}
