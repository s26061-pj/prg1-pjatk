#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

auto pop_top(std::stack<double> &stack) -> double {
  if (stack.empty()) {
    throw std::logic_error{"empty stack"};
  }
  auto element = std::move(stack.top());
  stack.pop();
  return element;
}

auto evaluate_addition(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for +"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(a + b);
}

auto evaluate_subtraction(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for -"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(a - b);
}

auto evaluate_division(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for /"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(a / b);
}

auto evaluate_multiplication(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for *"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(a * b);
}

auto evaluate_modulo(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for %"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  int A = a;
  int B = b;
  stack.push(A % B);
}

auto evaluate_power(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for **"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(pow(a, b));
}

auto evaluate_squareroot(std::stack<double> &stack) -> void {
  if (stack.size() < 1) {
    throw std::logic_error{"not enough operands for sqrt"};
  }
  auto const a = pop_top(stack);
  stack.push(sqrt(a));
}

auto evaluate_intdivision(std::stack<double> &stack) -> void {
  if (stack.size() < 2) {
    throw std::logic_error{"not enough operands for //"};
  }
  auto const b = pop_top(stack);
  auto const a = pop_top(stack);
  stack.push(floor(a / b));
}

auto evaluate_szescian(std::stack<double> &stack) -> void {
  if (stack.size() < 1) {
    throw std::logic_error{"not enough operands for ^3"};
  }
  auto const a = pop_top(stack);
  stack.push(a * a * a);
}

auto make_args(int argc, char *argv[]) -> std::vector<std::string> {
  auto args = std::vector<std::string>{};
  std::copy_n(argv, argc, std::back_inserter(args));
  return args;
}

auto main(int argc, char *argv[]) -> int {
  auto const args = make_args(argc - 1, argv + 1);

  auto stack = std::stack<double>{};
  for (auto const each : args) {
    try {
      if (each == "p") {
        std::cout << pop_top(stack) << "\n";
      } else if (each == "+") {
        evaluate_addition(stack);
      } else if (each == "-") {
        evaluate_subtraction(stack);
      } else if (each == "**") {
        evaluate_power(stack);
      } else if (each == "*") {
        evaluate_multiplication(stack);
      } else if (each == "/") {
        evaluate_division(stack);
      } else if (each == "%") {
        evaluate_modulo(stack);
      } else if (each == "sqrt") {
        evaluate_squareroot(stack);
      } else if (each == "//") {
        evaluate_intdivision(stack);
      } else if (each == "^3") {
        evaluate_szescian(stack);
      } else {
        stack.push(std::stod(each));
      }
    } catch (std::logic_error const &e) {
      std::cerr << "error: " << each << ": " << e.what() << "\n";
    }
  }

  return 0;
}
