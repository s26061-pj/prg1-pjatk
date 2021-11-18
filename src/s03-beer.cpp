#include <iostream>
#include <string>

auto number_of_bottles(std::string prompt) -> int {
  auto bottle = std::string{};
  std::cout << prompt;
  std::getline(std::cin, bottle);
  return std::stoi(bottle);
}

auto main() -> int {
  auto n = number_of_bottles("Ile masz flaszek:");
  while (n > 0) {
    std::cout << n << " bottles of beer on the wall, ";
    std::cout << n << " bottles of beer.\n";
    std::cout << "Take one down, pass it around, ";
    std::cout << --n << " bottles of beer on the wall...\n";
  }
  std::cout << "No more bottles of beer on the wall,";
  std::cout << "no more bottles of beer.";
  std::cout << "Go to the store and buy some more, ";
  std::cout << n << " bottles of beer on the wall...\n";

  return 0;
}
