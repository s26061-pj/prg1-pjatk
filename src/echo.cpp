#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto main(int argc, char *argv[]) -> int

{
  if (argc == 1) {
    return 0;
  }
  auto separator = " ";
  auto reverse = false;
  auto finish_newline = true;

  auto const opt_separator = std::string{"-l"};
  auto const opt_reverse = std::string{"-r"};
  auto const opt_finish = std::string{"-n"};

  auto drukuj = std::vector<std::string>{};
  {
    auto i = 1;
    for (; i < argc; ++i) {
      if (argv[i] == opt_separator) {
        separator = "\n";
      } else if (argv[i] == opt_reverse) {
        reverse = true;
      } else if (argv[i] == opt_finish) {
        finish_newline = false;
      } else {
        break;
      }
    }
    std::copy(argv + i, argv + argc, std::back_inserter(drukuj));
  }
  if (reverse) {
    std::reverse(drukuj.begin(), drukuj.end());
  }

  std::cout << drukuj[0];
  for (auto i = size_t{1}; i < drukuj.size(); ++i) {
    std::cout << separator << drukuj[i];
  }

  if (finish_newline) {
    std::cout << "\n";
  }
  return 0;
}
