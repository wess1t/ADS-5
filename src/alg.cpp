// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include "tstack.h"

int getPriority(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> operators;
  std::string result;

  for (size_t i = 0; i < inf.length(); i++) {
    char c = inf[i];

    if (c == ' ') {
      continue;
    }

    if (isdigit(c)) {
      while (i < inf.length() && isdigit(inf[i])) {
        result += inf[i];
        i++;
      }
      result += ' ';
      i--;
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        result += operators.pop();
        result += ' ';
      }
      if (!operators.empty() && operators.top() == '(') {
        operators.pop();
      }
    } else if (isOperator(c)) {
      while (!operators.empty() && operators.top() != '(' &&
             getPriority(operators.top()) >= getPriority(c)) {
        result += operators.pop();
        result += ' ';
      }
      operators.push(c);
    }
  }

  while (!operators.empty()) {
    result += operators.pop();
    result += ' ';
  }

  if (!result.empty() && result.back() == ' ') {
    result.pop_back();
  }

  return result;
}

int eval(const std::string& post) {
  TStack<int, 100> operands;

  for (size_t i = 0; i < post.length(); i++) {
    char c = post[i];

    if (c == ' ') {
      continue;
    }

    if (isdigit(c)) {
      int number = 0;
      while (i < post.length() && isdigit(post[i])) {
        number = number * 10 + (post[i] - '0');
        i++;
      }
      operands.push(number);
      i--;
    } else if (isOperator(c)) {
      if (operands.getSize() >= 2) {
        int b = operands.pop();
        int a = operands.pop();
        int result = 0;

        switch (c) {
          case '+':
            result = a + b;
            break;
          case '-':
            result = a - b;
            break;
          case '*':
            result = a * b;
            break;
          case '/':
            result = a / b;
            break;
        }
        operands.push(result);
      }
    }
  }

  return operands.pop();
}
