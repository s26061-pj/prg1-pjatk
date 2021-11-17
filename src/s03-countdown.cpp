#include <iostream>
#include <string>

auto get_number_from_user(std::string prompt) -> int
{
    auto n = std::string{};
    std::cout << prompt;
    std::getline(std::cin, n);
    return std::stoi(n);
}

auto main() -> int
{ 
   auto n = get_number_from_user("Podaj liczbę: ");
   
  while (n > 0) {
  std::cout << n-- << "...\n";
 }
  
  while (n < 0 ) {
  std::cout << n++ << "...\n";
 } 
  
 std::cout << n << "...\n";

  return 0;
}
