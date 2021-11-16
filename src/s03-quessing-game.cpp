#include <iostream>
#include <random>
#include <string>

auto quess_number(std::string prompt) -> int {
  auto quess = std::string{};
  std::cout << prompt;
  std::getline(std::cin, quess);
  return std::stoi(quess);
}
auto main() -> int {
  auto rd = std::random_device{};
  auto d = std::uniform_int_distribution<int>{1, 100};
  auto user_number = quess_number("Podaj liczbę od 1 do 100:");
  auto computer_number = d(rd);

  while (user_number != computer_number) {
    if (user_number > computer_number) {
      std::cout << "Za duża! Zgaduj dalej! \n";
    }
    if (user_number <= 0) {
      std::cout << "Podaj liczbę w przedziale 1-100.\n";
    } else if (user_number < computer_number) {
      std::cout << "Za mała! Zgaduj dalej!\n";
    }

    user_number = quess_number("Podaj liczbę: ");
  }

  std::cout << "Brawo! Trafiony, zatopiony!\n";

  return 0;
}
