#include "utils.h"

using namespace Utils;

// Отчистка буффера (для scanf)
void Utils::clearBuffer() {
  while ((getchar()) != '\n')
    ;
}