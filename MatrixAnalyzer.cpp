#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

void showMenu()
{
  cout <<
  R"(
  ========================================
             MATRIX ANALYZER
  ========================================

  1. Создать матрицу
  2. Заполнить вручную
  3. Заполнить случайными числами
  4. Показать матрицу

  ----------- АНАЛИЗ ---------------------

  5. Сумма всех элементов
  6. Минимальный элемент
  7. Максимальный элемент
  8. Среднее значение
  9. Суммы строк
  10. Суммы столбцов

  ----------- ДИАГОНАЛИ ------------------

  11. Главная диагональ
  12. Побочная диагональ
  13. Сумма главной диагонали
  14. Сумма побочной диагонали
  15. Максимум главной диагонали
  16. Минимум побочной диагонали

  ----------- ПОИСК ----------------------

  17. Найти элемент
  18. Найти все вхождения элемента
  19. Количество положительных
  20. Количество отрицательных
  21. Количество нулей
  22. Количество чётных
  23. Количество нечётных

  ----------- СТРОКИ ----------------------

  24. Сумма выбранной строки
  25. Строка с максимальной суммой
  26. Строка с минимальной суммой
  27. Строка с максимальным количеством положительных
  28. Строка с минимальным количеством отрицательных

  ----------- СТОЛБЦЫ ---------------------

  29. Сумма выбранного столбца
  30. Столбец с максимальной суммой
  31. Столбец с минимальной суммой
  32. Столбец с максимальным количеством положительных
  33. Столбец с минимальным количеством отрицательных

  ----------- ИЗМЕНЕНИЕ -------------------

  34. Поменять первую и последнюю строки
  35. Поменять первый и последний столбцы
  36. Транспонировать матрицу

  ----------- ОБЛАСТИ ---------------------

  37. Сумма выше главной диагонали
  38. Сумма ниже главной диагонали
  39. Сумма выше побочной диагонали
  40. Сумма ниже побочной диагонали

  0. Выход

  ========================================
  )";
}

void inputMatrix(int arr[][MAX_SIZE], int size1, int size2)
{
  cout << "Введите матрицу:" << endl;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      cin >> arr[i][j];
    }
  }
}

void randomFill(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      arr[i][j] = rand() % 100;
    }
  }
}

void printMatrix(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      cout << arr[i][j] << ' ';
    }

    cout << endl;
  }
}

int getSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      sum += arr[i][j];
    }
  }

  return sum;
}

int getMin(int arr[][MAX_SIZE], int size1, int size2)
{
  int min = arr[0][0];

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] < min)
      {
        min = arr[i][j];
      }
    }
  }

  return min;
}

int getMax(int arr[][MAX_SIZE], int size1, int size2)
{
  int max = arr[0][0];

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] > max)
      {
        max = arr[i][j];
      }
    }
  }

  return max;
}

double getAverage(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = getSum(arr, size1, size2);

  return double(sum) / (size1 * size2);
}

void printRowSums(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int i = 0; i < size1; i++)
  {
    int sum = 0;

    for (int j = 0; j < size2; j++)
    {
      sum += arr[i][j];
    }

    cout << "Сумма строки " << i + 1 << ": " << sum << endl;
  }
}

void printColumnSums(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int j = 0; j < size2; j++)
  {
    int sum = 0;

    for (int i = 0; i < size1; i++)
    {
      sum += arr[i][j];
    }

    cout << "Сумма столбца " << j + 1 << ": " << sum << endl;
  }
}

int findMaxRow(int arr[][MAX_SIZE], int size1, int size2)
{
  int maxSum = 0;
  int maxRow = 0;

  for (int j = 0; j < size2; j++)
  {
    maxSum += arr[0][j];
  }

  for (int i = 1; i < size1; i++)
  {
    int sum = 0;

    for (int j = 0; j < size2; j++)
    {
      sum += arr[i][j];
    }

    if (sum > maxSum)
    {
      maxSum = sum;
      maxRow = i;
    }
  }

  return maxRow;
}

int findMinRow(int arr[][MAX_SIZE], int size1, int size2)
{
  int minSum = 0;
  int minRow = 0;

  for (int j = 0; j < size2; j++)
  {
    minSum += arr[0][j];
  }

  for (int i = 1; i < size1; i++)
  {
    int sum = 0;

    for (int j = 0; j < size2; j++)
    {
      sum += arr[i][j];
    }

    if (sum < minSum)
    {
      minSum = sum;
      minRow = i;
    }
  }

  return minRow;
}

int findMaxColumn(int arr[][MAX_SIZE], int size1, int size2)
{
  int maxSum = 0;
  int maxCol = 0;

  for (int i = 0; i < size1; i++)
  {
    maxSum += arr[i][0];
  }

  for (int j = 1; j < size2; j++)
  {
    int sum = 0;

    for (int i = 0; i < size1; i++)
    {
      sum += arr[i][j];
    }

    if (sum > maxSum)
    {
      maxSum = sum;
      maxCol = j;
    }
  }

  return maxCol;
}

int findMinColumn(int arr[][MAX_SIZE], int size1, int size2)
{
  int minSum = 0;
  int minCol = 0;

  for (int i = 0; i < size1; i++)
  {
    minSum += arr[i][0];
  }

  for (int j = 1; j < size2; j++)
  {
    int sum = 0;

    for (int i = 0; i < size1; i++)
    {
      sum += arr[i][j];
    }

    if (sum < minSum)
    {
      minSum = sum;
      minCol = j;
    }
  }

  return minCol;
}

void printMainDiagonal(int arr[][MAX_SIZE], int size1, int size2)
{
  int size = (size1 < size2) ? size1 : size2;

  for (int i = 0; i < size; i++)
  {
    cout << arr[i][i] << ' ';
  }

  cout << endl;
}

void printSecondaryDiagonal(int arr[][MAX_SIZE], int size1, int size2)
{
  int size = (size1 < size2) ? size1 : size2;

  for (int i = 0; i < size; i++)
  {
    cout << arr[i][size2 - 1 - i] << ' ';
  }

  cout << endl;
}

int getMainDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;
  int size = (size1 < size2) ? size1 : size2;

  for (int i = 0; i < size; i++)
  {
    sum += arr[i][i];
  }

  return sum;
}

int getSecondaryDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;
  int size = (size1 < size2) ? size1 : size2;

  for (int i = 0; i < size; i++)
  {
    sum += arr[i][size2 - 1 - i];
  }

  return sum;
}

int getMainDiagonalMax(int arr[][MAX_SIZE], int size1, int size2)
{
  int size = (size1 < size2) ? size1 : size2;
  int max = arr[0][0];

  for (int i = 0; i < size; i++)
  {
    if (arr[i][i] > max)
    {
      max = arr[i][i];
    }
  }

  return max;
}

int getSecondaryDiagonalMin(int arr[][MAX_SIZE], int size1, int size2)
{
  int size = (size1 < size2) ? size1 : size2;
  int min = arr[0][size2 - 1];

  for (int i = 0; i < size; i++)
  {
    if (arr[i][size2 - 1 - i] < min)
    {
      min = arr[i][size2 - 1 - i];
    }
  }

  return min;
}

bool searchElement(int arr[][MAX_SIZE], int size1, int size2)
{
  int number;

  cout << "Введите элемент для поиска: ";
  cin >> number;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] == number)
      {
        cout << "Элемент найден: строка "
             << i + 1
             << ", столбец "
             << j + 1
             << endl;

        return true;
      }
    }
  }

  return false;
}

int findAllOccurrences(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;
  int search;

  cout << "Введите элемент для поиска: ";
  cin >> search;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] == search)
      {
        count++;
      }
    }
  }

  return count;
}

int countPositive(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] > 0)
      {
        count++;
      }
    }
  }

  return count;
}

int countNegative(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] < 0)
      {
        count++;
      }
    }
  }

  return count;
}

int countZero(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] == 0)
      {
        count++;
      }
    }
  }

  return count;
}

int countEven(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] % 2 == 0)
      {
        count++;
      }
    }
  }

  return count;
}

int countOdd(int arr[][MAX_SIZE], int size1, int size2)
{
  int count = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] % 2 != 0)
      {
        count++;
      }
    }
  }

  return count;
}

int getRowSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;
  int row;

  cout << "Введите номер строки: ";
  cin >> row;

  if (row < 1 || row > size1)
  {
    cout << "Такой строки нет." << endl;
    return 0;
  }

  for (int j = 0; j < size2; j++)
  {
    sum += arr[row - 1][j];
  }

  return sum;
}

int findRowWithMaxPositive(int arr[][MAX_SIZE], int size1, int size2)
{
  int maxPositive = 0;
  int maxRow = 0;

  for (int i = 0; i < size1; i++)
  {
    int count = 0;

    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] > 0)
      {
        count++;
      }
    }

    if (count > maxPositive)
    {
      maxPositive = count;
      maxRow = i;
    }
  }

  return maxRow;
}

int findRowWithMinNegative(int arr[][MAX_SIZE], int size1, int size2)
{
  int minNegative = 0;
  int minRow = 0;

  for (int j = 0; j < size2; j++)
  {
    if (arr[0][j] < 0)
    {
      minNegative++;
    }
  }

  for (int i = 1; i < size1; i++)
  {
    int count = 0;

    for (int j = 0; j < size2; j++)
    {
      if (arr[i][j] < 0)
      {
        count++;
      }
    }

    if (count < minNegative)
    {
      minNegative = count;
      minRow = i;
    }
  }

  return minRow;
}

int getColumnSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;
  int col;

  cout << "Введите номер столбца: ";
  cin >> col;

  if (col < 1 || col > size2)
  {
    cout << "Такого столбца нет." << endl;
    return 0;
  }

  for (int i = 0; i < size1; i++)
  {
    sum += arr[i][col - 1];
  }

  return sum;
}

int findColumnWithMaxPositive(int arr[][MAX_SIZE], int size1, int size2)
{
  int maxPositive = 0;
  int maxCol = 0;

  for (int j = 0; j < size2; j++)
  {
    int count = 0;

    for (int i = 0; i < size1; i++)
    {
      if (arr[i][j] > 0)
      {
        count++;
      }
    }

    if (count > maxPositive)
    {
      maxPositive = count;
      maxCol = j;
    }
  }

  return maxCol;
}

int findColumnWithMinNegative(int arr[][MAX_SIZE], int size1, int size2)
{
  int minNegative = 0;
  int minCol = 0;

  for (int i = 0; i < size1; i++)
  {
    if (arr[i][0] < 0)
    {
      minNegative++;
    }
  }

  for (int j = 1; j < size2; j++)
  {
    int count = 0;

    for (int i = 0; i < size1; i++)
    {
      if (arr[i][j] < 0)
      {
        count++;
      }
    }

    if (count < minNegative)
    {
      minNegative = count;
      minCol = j;
    }
  }

  return minCol;
}

void swapRows(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int j = 0; j < size2; j++)
  {
    int temp = arr[0][j];
    arr[0][j] = arr[size1 - 1][j];
    arr[size1 - 1][j] = temp;
  }
}

void swapColumns(int arr[][MAX_SIZE], int size1, int size2)
{
  for (int i = 0; i < size1; i++)
  {
    int temp = arr[i][0];
    arr[i][0] = arr[i][size2 - 1];
    arr[i][size2 - 1] = temp;
  }
}

void transposeMatrix(int arr[][MAX_SIZE], int& size1, int& size2)
{
  int temp[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      temp[j][i] = arr[i][j];
    }
  }

  for (int i = 0; i < size2; i++)
  {
    for (int j = 0; j < size1; j++)
    {
      arr[i][j] = temp[i][j];
    }
  }

  int tempSize = size1;
  size1 = size2;
  size2 = tempSize;
}

int getAboveMainDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (j > i)
      {
        sum += arr[i][j];
      }
    }
  }

  return sum;
}

int getBelowMainDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (i > j)
      {
        sum += arr[i][j];
      }
    }
  }

  return sum;
}

int getAboveSecondaryDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (j < size2 - 1 - i)
      {
        sum += arr[i][j];
      }
    }
  }

  return sum;
}

int getBelowSecondaryDiagonalSum(int arr[][MAX_SIZE], int size1, int size2)
{
  int sum = 0;

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (j > size2 - 1 - i)
      {
        sum += arr[i][j];
      }
    }
  }

  return sum;
}

int main()
{
  int size1, size2;
  int choice = -1;

  srand(time(0));

  cout << "Введите размер матрицы максимум 100: ";
  cin >> size1 >> size2;

  if (size1 < 1 || size1 > MAX_SIZE ||
      size2 < 1 || size2 > MAX_SIZE)
  {
    cout << "Некорректный размер матрицы." << endl;
    return 1;
  }

  int arr[MAX_SIZE][MAX_SIZE];

  while (choice != 0)
  {
    showMenu();

    cout << "Выберите действие: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Введите новый размер матрицы: ";
      cin >> size1 >> size2;

      if (size1 < 1 || size1 > MAX_SIZE ||
          size2 < 1 || size2 > MAX_SIZE)
      {
        cout << "Некорректный размер матрицы." << endl;
      }
      else
      {
        cout << "Размер матрицы изменён." << endl;
      }
      break;

    case 2:
      inputMatrix(arr, size1, size2);
      break;

    case 3:
      randomFill(arr, size1, size2);
      cout << "Матрица заполнена случайными числами." << endl;
      break;

    case 4:
      printMatrix(arr, size1, size2);
      break;

    case 5:
      cout << "Сумма всех элементов: "
           << getSum(arr, size1, size2) << endl;
      break;

    case 6:
      cout << "Минимальный элемент: "
           << getMin(arr, size1, size2) << endl;
      break;

    case 7:
      cout << "Максимальный элемент: "
           << getMax(arr, size1, size2) << endl;
      break;

    case 8:
      cout << "Среднее значение: "
           << getAverage(arr, size1, size2) << endl;
      break;

    case 9:
      printRowSums(arr, size1, size2);
      break;

    case 10:
      printColumnSums(arr, size1, size2);
      break;

    case 11:
      cout << "Главная диагональ: ";
      printMainDiagonal(arr, size1, size2);
      break;

    case 12:
      cout << "Побочная диагональ: ";
      printSecondaryDiagonal(arr, size1, size2);
      break;

    case 13:
      cout << "Сумма главной диагонали: "
           << getMainDiagonalSum(arr, size1, size2) << endl;
      break;

    case 14:
      cout << "Сумма побочной диагонали: "
           << getSecondaryDiagonalSum(arr, size1, size2) << endl;
      break;

    case 15:
      cout << "Максимум главной диагонали: "
           << getMainDiagonalMax(arr, size1, size2) << endl;
      break;

    case 16:
      cout << "Минимум побочной диагонали: "
           << getSecondaryDiagonalMin(arr, size1, size2) << endl;
      break;

    case 17:
      if (!searchElement(arr, size1, size2))
      {
        cout << "Элемент не найден." << endl;
      }
      break;

    case 18:
      cout << "Количество вхождений: "
           << findAllOccurrences(arr, size1, size2) << endl;
      break;

    case 19:
      cout << "Количество положительных: "
           << countPositive(arr, size1, size2) << endl;
      break;

    case 20:
      cout << "Количество отрицательных: "
           << countNegative(arr, size1, size2) << endl;
      break;

    case 21:
      cout << "Количество нулей: "
           << countZero(arr, size1, size2) << endl;
      break;

    case 22:
      cout << "Количество чётных: "
           << countEven(arr, size1, size2) << endl;
      break;

    case 23:
      cout << "Количество нечётных: "
           << countOdd(arr, size1, size2) << endl;
      break;

    case 24:
      cout << "Сумма выбранной строки: "
           << getRowSum(arr, size1, size2) << endl;
      break;

    case 25:
      cout << "Строка с максимальной суммой: "
           << findMaxRow(arr, size1, size2) + 1 << endl;
      break;

    case 26:
      cout << "Строка с минимальной суммой: "
           << findMinRow(arr, size1, size2) + 1 << endl;
      break;

    case 27:
      cout << "Строка с максимальным количеством положительных: "
           << findRowWithMaxPositive(arr, size1, size2) + 1 << endl;
      break;

    case 28:
      cout << "Строка с минимальным количеством отрицательных: "
           << findRowWithMinNegative(arr, size1, size2) + 1 << endl;
      break;

    case 29:
      cout << "Сумма выбранного столбца: "
           << getColumnSum(arr, size1, size2) << endl;
      break;

    case 30:
      cout << "Столбец с максимальной суммой: "
           << findMaxColumn(arr, size1, size2) + 1 << endl;
      break;

    case 31:
      cout << "Столбец с минимальной суммой: "
           << findMinColumn(arr, size1, size2) + 1 << endl;
      break;

    case 32:
      cout << "Столбец с максимальным количеством положительных: "
           << findColumnWithMaxPositive(arr, size1, size2) + 1 << endl;
      break;

    case 33:
      cout << "Столбец с минимальным количеством отрицательных: "
           << findColumnWithMinNegative(arr, size1, size2) + 1 << endl;
      break;

    case 34:
      swapRows(arr, size1, size2);
      cout << "Первая и последняя строки поменяны местами." << endl;
      break;

    case 35:
      swapColumns(arr, size1, size2);
      cout << "Первый и последний столбцы поменяны местами." << endl;
      break;

    case 36:
      transposeMatrix(arr, size1, size2);
      cout << "Матрица транспонирована." << endl;
      break;

    case 37:
      cout << "Сумма выше главной диагонали: "
           << getAboveMainDiagonalSum(arr, size1, size2) << endl;
      break;

    case 38:
      cout << "Сумма ниже главной диагонали: "
           << getBelowMainDiagonalSum(arr, size1, size2) << endl;
      break;

    case 39:
      cout << "Сумма выше побочной диагонали: "
           << getAboveSecondaryDiagonalSum(arr, size1, size2) << endl;
      break;

    case 40:
      cout << "Сумма ниже побочной диагонали: "
           << getBelowSecondaryDiagonalSum(arr, size1, size2) << endl;
      break;

    case 0:
      cout << "Программа завершена." << endl;
      break;

    default:
      cout << "Такого варианта нет." << endl;
      break;
    }
  }

  return 0;
}
