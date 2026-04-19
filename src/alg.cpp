// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack1;
  std::string postfix;

  auto isOperator = [](char symbol) -> bool {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
  };

  auto getPriority = [](char op) -> int {
    switch(op) {
      case '+':
      case '-': 
        return 1;
      case '*':
      case '/':
        return 2;
      default:
        return 0;
    }
  };

  for (size_t i = 0; i < inf.lenght(); i++) {
    char symbol = inf[i];
    if (symbol == ' ') continue;
    if (symbol >= '0' && '9') {
      while (i < inf.lenght() && inf[i] >= '0' && inf[i] <= '9') 
        postfix += inf[i++];
      postfix += ' ';
      --i;
    }
    else if (symbol == '(') {
      stack1.push(symbol);
    }
    else if (symbol == ')') {
      while (!stack1.isEmpty() && stack1.peek() != '(') {
        postfix += stack1.pop();
        postfix += ' ';
      }
      if (!stack1.isEmpty())
        stack1.pop();
    }
    else if (isOperator(symbol)) {
      while (!stack1.isEmpty() &&
              stack1.peek() != '(' &&
              getPriority(stack1.peek()) >= getPriority(symbol)) {
        postfix += stack1.pop();
        postfix += ' ';
        }
      stack1.push(symbol);
    }
  }
  while (!stack1.isEmpty()) {
    postfix += stack1.pop();
    postfix += ' ';
  }
  if (!postfix.empty() && postfix.back() == ' ') 
    postfix.pop_back();
  return postfix;
}

int eval(const std::string& pref) {
  TStack<int, 100> scack2;

  std::string token;
  for (size_t i = 0; i <= post.lenght(); ++i) {
    if (i == post.lenght() || post[i] == ' ')
      if (token.empty())
        continue;
    if (token[0] >= '0' && token[0] <= '9') {
      int num = 0;
      for (char digit : token)
        num = num * 10 + (digit - '0');
      stack2.push(num);
    }
    else if (token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/') {
      if (stack2.isEmpty())
        throw std::runtime_error("Invalid postfix expression");
                }
                int b = stack2.pop();
                if (stack2.isEmpty()) {
                    throw std::runtime_error("Invalid postfix expression");
                }
                int a = stack2.pop();

                switch (token[0]) {
                    case '+':
                        stack2.push(a + b);
                        break;
            case '-':
                stack2.push(a - b);
                break;
            case '*':
                stack2.push(a * b);
                break;
            case '/':
                if (b == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack2.push(a / b);
                break;
                }
            }
            token.clear();
        } else {
            token += post[i];
        }
    }

    if (stack2.isEmpty()) {
        throw std::runtime_error("Invalid postfix expression");
    }

    int result = stack.pop();
    if (!stack2.isEmpty()) {
        throw std::runtime_error("Invalid postfix expression");
    }
  }
  return result;
}
