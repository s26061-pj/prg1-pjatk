#include <iostream>
#include <string>

auto get_password(std::string prompt) -> std::string {
  auto haslo = std::string{};
  std::cout << prompt;
  std::getline(std::cin, haslo);
  return haslo;
}

auto main(int, char *argv[]) -> int {
  auto a = get_password("Podaj hasło: ");
  while (a != argv[1]) {
    a = get_password("Złe hasło! Podaj hasło: ");
  }
 std::cout << "Brawo! Brawo!\n";
  
  return 0;
}
