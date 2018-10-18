#include "service.h"

// Конструктор
Service::Service() {
  isExit = false;
}

// Цикл
void Service::Loop() {
  isExit = true;
}