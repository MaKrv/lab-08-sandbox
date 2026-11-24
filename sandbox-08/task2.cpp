#include <iostream>

int read_number(const char *s, int &i) {
  int value = 0;
  while (s[i] >= '0' && s[i] <= '9') {
    value = value * 10 + (s[i] - '0');
    i = i + 1;
  }
  return value;
}

void calculate(const char *expr) {
  int i = 0;
  int left = read_number(expr, i);
  char op = expr[i];
  i = i + 1;
  int right = read_number(expr, i);

  if (expr[i] != '\0') {
    std::cout << "error at " << i << '\n';
    return;
  }
  int result = (op == '+')   ? left + right
               : (op == '-') ? left - right
                             : left * right;
  std::cout << result << '\n';
}

int main() {
  calculate("12+34");
  calculate("7*6x");
}