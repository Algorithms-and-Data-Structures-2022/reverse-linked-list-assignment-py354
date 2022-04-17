#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (front_ == nullptr || front_ == back_) {
      return;
    }

    Node* current = front_;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    Node* tmp = front_;
    front_ = back_;
    back_ = tmp;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (front_ == nullptr || front_ == back_) {
      return;
    }

    reverse_recursive_helper(front_->next, front_);

    front_->next = nullptr;
    Node* tmp = front_;
    front_ = back_;
    back_ = tmp;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr || prev == nullptr) {
      return;
    }

    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
