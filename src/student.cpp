#include "student.h"
#include <iostream>
#include <string>

auto Student::to_string() const -> std::string {

  return (this->imie + " " + this->nazwisko + " " + this->numer_indeksu + " " +
          std::to_string(this->aktualny_semestr) + " " +
          std::to_string(this->srednia_ocen));
}

Student::Student(std::string const imie, std::string const nazwisko,
                 std::string const numer_indeksu, int aktualny_semestr,
                 float srednia_ocen)
    : imie{imie}, nazwisko{nazwisko}, numer_indeksu{numer_indeksu},
      aktualny_semestr{aktualny_semestr}, srednia_ocen{srednia_ocen} {}

auto main() -> int {

  auto ja = Student{"Justyna", "Anna", "s12345", 1, 4.79};
  std::cout << ja.to_string() << "\n";
  return 0;
}
