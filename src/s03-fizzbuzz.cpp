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
   if (n % 3 == 0 && n % 5 != 0) {
   std::cout << "Fizz\n"; 
  }
   if (n % 5 == 0 && n % 3 != 0) {
   std::cout << "Buzz\n";
  }
   if (n % 3 == 0 && n % 5 == 0) {
  std::cout << "FizzBuzz\n";
 }
 
return 0;

}


    
