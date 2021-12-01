
#include <iostream>
#include <string>

struct Student {

  std::string const imie;
  std::string const nazwisko;
  std::string const numer_indeksu;
  int aktualny_semestr;
  float srednia_ocen;

  auto to_string() const -> std::string;

  Student() = default;
  Student(std::string const imie, std::string const nazwisko,
          std::string const numer_indeksu, int aktualny_semestr,
          float srednia_ocen);
};
