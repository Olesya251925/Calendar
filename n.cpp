#include <iostream>
#include <iomanip>
using namespace std;

int shiftOne;
int shiftTwo;
void months(string monthOneColumn, string monthTwoColumn, int dayOne, int dayTwo) {
  cout << "     " << monthOneColumn << "            " << monthTwoColumn << "\n Пн Вт Ср Чт Пт    Пн Вт Ср Чт Пт \n";
  int weekFirstColumn = 1;
  int dayFirstColumn = 1; // день начинается с 1 числа
  int weekSecondColumn = 1;
  int daySecondColumn= 1;
  
  shiftTwo = (shiftOne + dayOne) % 5;
  int shiftTwoColumn = shiftTwo;
  while ((dayFirstColumn <= dayOne) || (daySecondColumn <= dayTwo)) {
    while (shiftOne != 0) {
      cout << "   "; //сдвиг 1-ой строки
      shiftOne -= 1;
      weekFirstColumn += 1;
    }
    while (((weekFirstColumn) <= 5) && (dayFirstColumn <= dayOne)) {
      cout << setw(3) << dayFirstColumn; //расстояние между столбцами 1-го столбца
      dayFirstColumn += 1; //вывод дней 1-го столбца
      weekFirstColumn += 1; //вывод дней в виде столбца(1)
    }
    if (dayFirstColumn >= dayOne) {
      while (weekFirstColumn <= 5) {
        cout << "   ";
        weekFirstColumn += 1; //один день недели = 1 день; 1 столбец
      }
    }
    weekFirstColumn = 1;
    cout << "  ";
    while (shiftTwo != 0) {
      cout << "   ";
      shiftTwo -= 1;
      weekSecondColumn += 1;
    }
    while ((weekSecondColumn <= 5) && (daySecondColumn <= dayTwo)) {
      cout << setw(3) << daySecondColumn; //расстояние между столбцами 2-го столбца
      daySecondColumn += 1; //вывод дней 2-го столбца
      weekSecondColumn += 1; //вывод дней в виде столбца(2)
    }
    weekSecondColumn = 1; //один день недели = 1 день; 2 столбец
    cout << "\n";
  }
  shiftOne = (dayTwo + shiftTwoColumn) % 5; // чтобы каждое число было под своим днем недели
  cout << "\n\n";
}

int main() {
  int year;
  cout << "Введите год: ";
  cin >> year;
  cout << "\n";
  
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
    months("Январь", "Февраль", 31, 29);
  } else {
    months("Январь", "Февраль", 31, 28);
  }
  months("Март", "Апрель", 31, 30);
  months("Май", "Июнь", 31, 30);
  months("Июль", "Август", 31, 31);
  months("Сентябрь", "Октябрь", 30, 31);
  months("Ноябрь", "Декабрь", 30, 31);
  return 0;
}
