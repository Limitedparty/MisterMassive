/* MisterMassive - программа, для работы с массивами.
 *
 * Создано неким Mark Vodyanitskiy @mvodya в 2016 году
 *
 * Все файлы в проекте распространяются под лицензией GNU General Public License
 * v3.0 (текст с лицензией в корне проекта).
 * Можно: использовать в коммерции, модифицировать, распространять, использовать
 * в личных целях.
 * Нужно: хотя бы в копипасте оставить ник и ссылку на оригинальный проект.
 *
 * Реверсия - 2017 год (версия 3)
 * Полная реверсия - 2018 год (версия 4)
 */

#include "mistermassive.h"

int main(int argc, char *argv[]) {
  // Вывод приветствия (+ версия)
  printf("Mister Massive v%s\n", VERSION);

  // Запускаем меню (в цикле)
  bool isExit = false;
  while (!isExit) MisterMassive::Menu(isExit);

  return 0;
}