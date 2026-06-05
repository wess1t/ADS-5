// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {

private:
  T data[size];
  int top_i;

public:
  TStack() : top_i(-1) {}
  void push(const T& item) {
    if (top_i < size - 1)
      data[++top_i] = item;
  }
  T pop() {
    if (top_i >= 0)
      return data[top_i--];
    return T();
  }
  T top() const {
    if (top_i >= 0)
      return data[top_i];
    return T();
  }
  bool empty() const {
    return top_i == -1;
  }
  int size() const {
    return top_i + 1;
  }
  void clear() {
    top_i = -1;
  }
};

#endif  // INCLUDE_TSTACK_H_
