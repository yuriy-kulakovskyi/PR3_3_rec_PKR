#include "functions.h"
#include <iostream>

// Функція для створення нового вузла
Node* createNode(int value) {
  Node* newNode = new Node();
  newNode->data = value;
  newNode->prev = nullptr;
  newNode->next = nullptr;
  return newNode;
}

// Рекурсивна функція для додавання елемента в кінець списку
void append(Node*& head, int value) {
  if (head == nullptr) {
    head = createNode(value);
  }
  else if (head->next == nullptr) {
    Node* newNode = createNode(value);
    head->next = newNode;
    newNode->prev = head;
  }
  else {
    append(head->next, value); // Рекурсивний виклик
  }
}

// Рекурсивна функція для виведення списку на екран
void printList(Node* head) {
  if (head == nullptr) {
    std::cout << std::endl;
    return;
  }
  std::cout << head->data << " ";
  printList(head->next); // Рекурсивний виклик
}

// Рекурсивна функція для перевірки, чи є в списку пара сусідніх елементів з однаковими значеннями
bool hasAdjacentEqual(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return false;  // Базовий випадок: Якщо списку немає або лише один елемент
  }
  if (head->data == head->next->data) {
    return true;  // Знайшли пару однакових елементів
  }
  return hasAdjacentEqual(head->next);  // Рекурсивний виклик
}