// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int kN>
class TStack {
 private:
  T data[kN];
  int top_index;

 public:
  TStack() : top_index(-1) {}

  void push(const T& item) {
    if (top_index < kN - 1) {
      data[++top_index] = item;
    }
  }

  T pop() {
    if (top_index >= 0) {
      return data[top_index--];
    }
    return T();
  }

  T top() const {
    if (top_index >= 0) {
      return data[top_index];
    }
    return T();
  }

  bool empty() const {
    return top_index == -1;
  }

  int getSize() const {
    return top_index + 1;
  }

  void clear() {
    top_index = -1;
  }
};

#endif  // INCLUDE_TSTACK_H_
