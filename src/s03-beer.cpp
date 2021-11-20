#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  auto bottles = 99;
  if (argc > 1) {
    bottles = std::stoi(argv[1]);
  }
  if (bottles < 0) {
    std::cout
        << "I know you have some bottles left, mate! Don't play with me!\n";
    return 1;
  }
  if (bottles == 0) {
    std::cout << "Don't fool me!\n"
              << "But, ok, let's sing!\n";
  }
  for (auto n = bottles; n > 0; --n) {
    std::cout << n << " bottles of beer on the wall, ";
    std::cout << n << " bottles of beer.\n";
    std::cout << "Take one down, pass it around, ";
    std::cout << n - 1 << " bottles of beer on the wall...\n";
  }
  std::cout << "No more bottles of beer on the wall,";
  std::cout << "no more bottles of beer.";
  std::cout << "Go to the store and buy some more, ";
  std::cout << bottles << " bottles of beer on the wall...\n";

  return 0;
}
