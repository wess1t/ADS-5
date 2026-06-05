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
  std::string res;

  for (size_t i = 0; i < inf.length(); i++) {
    char c = inf[i];
    if (c == ' ')
      continue;
    if (isdigit(c)) {
      while (i < inf.length() && isdigit(inf[i])) {
        res += inf[i];
        i++;
      }
      res += ' ';
      i--;
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        res += operators.pop();
        res += ' ';
      }
      if (!operators.empty() && operators.top() == '(')
        operators.pop();
    } else if (isOperator(c)) {
      while (!operators.empty() && operators.top() != '(' &&
        getPriority(operators.top()) >= getPriority(c)) {
        res += operator.pop();
        res += ' ';
        }
      operators.push(c);
    }
  }
  while (!oprators.empty()) {
    res += operators.pop();
    res += ' ';
  }
  if (!res.empty() && res.back() == ' ')
    res.pop_back();
  return res;
}

int eval(const std::string& pref) {
  TStack<int, 100> operands;
  for (size_t i = 0; i < post.length(); i++) {
    char c = post[i];
    if (c == ' ')
      continue;
    if (isdigit(c)) {
      int num = 0;
      while (i < post.length() && isdigit(post[i])) {
        num = num * 10 + (post[i] - '0');
        i++;
      }
      operands.push(num);
      i--;
    } else if (isOperator(c)) {
      if (operands.size() >= 2) {
        int a = operands.pop(), b = operands.pop(), res = 0;
        switch (c) {
          case '+':
            res = a + b;
            break;
          case '-':
            res = a - b;
            break;
          case '*':
            res = a * b;
            break;
          case '/':
            res = a / b;
            break;
        }
        operands.push(res);
      }
    }
  }
  return operands.pop();
}
