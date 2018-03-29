#include "utils.h"

using namespace Utils;

// Отчистка буффера
void Utils::clearBuffer() {
  while ((getchar()) != '\n')
    ;
}