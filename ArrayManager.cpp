#include <iostream>

using namespace std;

void inputArray(int arr[], int size)
{
  cout << "Введите эл массива: ";
  
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
}

void printMenu()
{
  cout <<
  R"(
  ===== ARRAY MANAGER =====

  1.  Показать массив
  2.  Максимальное число
  3.  Максимальный индекс
  4.  Минимальное число
  5.  Минимальный индекс
  6.  Сумма
  7.  Среднее
  8.  Количество положительных
  9.  Количество отрицательных
  10. Количество нулей
  11. Количество четных
  12. Количество нечетных
  13. Количество элементов больше среднего
  14. Второй максимум
  15. Перевернуть массив
  16. Количество максимумов
  17. Заменить отрицательные на 0
  18. Найти элемент
  0.  Выход
  )";
}

int findMax(int arr[], int size)
{
  int max = arr[0];

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int findMaxIndex(int arr[], int size)
{
  int maxIndex = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > arr[maxIndex])
    {
      maxIndex = i;
    }
  }
  return maxIndex;
}

int findMin(int arr[], int size)
{
  int min = arr[0];

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

int findMinIndex(int arr[], int size)
{
  int minIndex = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < arr[minIndex])
    {
      minIndex = i;
    }
  }
  return minIndex;
}

int findSum(int arr[], int size)
{
  int sum = 0;

  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

double findAverage(int arr[], int size)
{
  int sum = findSum(arr, size);
  double average = 0;

  average = (double)sum / size;

  return average;
}

int countPositive(int arr[], int size)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > 0)
    {
      count++;
    }
  }
  return count;
}

int countNegative(int arr[], int size)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < 0)
    {
      count++;
    }
  }
  return count;
}

int countZero(int arr[], int size)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 0)
    {
      count++;
    }
  }
  return count;
}

int countEven(int arr[], int size)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] % 2 == 0)
    {
      count++;
    }
  }
  return count;
}

int countOdd(int arr[], int size)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] % 2 != 0)
    {
      count++;
    }
  }
  return count;
}

int countAboveAverage(int arr[], int size)
{
  double average = findAverage(arr, size);
  int count = 0;
  
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > average)
    {
      count++;
    }
  }
  return count;
}

int findSecondMax(int arr[], int size)
{
  int max = findMax(arr, size);
  int secondMax;
  bool hasSecondMax = false;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < max)
    {
      secondMax = arr[i];
      hasSecondMax = true;
      break;
    }
  }

  if (hasSecondMax)
  {
    for (int i = 0; i < size; i++)
    {
      if (arr[i] < max && arr[i] > secondMax)
      {
        secondMax = arr[i];
      }    
    }

    return secondMax;
  }else
  {
    cout << "Второго максимума нет." << endl;
    return 0;
  }
}

int countMax(int arr[], int size)
{
  int max = findMax(arr, size);
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == max)
    {
      count++;
    }
  } 

  return count;
}

void reverseArray(int arr[], int size)
{
  int temp;

  for (int i = 0; i < size / 2; i++)
  {
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void replaceNegatives(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] < 0)
    {
      arr[i] = 0;
    }
  }
}

int findElement(int arr[], int size, int value)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int size;
  int chose;

  while (true)
  {
    cout << "Введите размер массива: ";
    cin >> size;

  while (size <= 0)
  {
    cout << "Ошибка: размер должен быть больше 0." << endl;
    cout << "Введите размер еще раз: ";
    cin >> size;
  }  
  
  int arr[size];

  inputArray(arr, size);

  do
  {
    printMenu();

    cout << "Выберите действие: ";
    cin >> chose;

    switch (chose)
    {
      case 1:
        cout << "Массив: ";
        printArray(arr, size);
        break;

      case 2:
        cout << "Максимальное число: "
             << findMax(arr, size) << endl;
        break;

      case 3:
        cout << "Максимальный индекс: "
             << findMaxIndex(arr, size) << endl;
        break;

      case 4:
        cout << "Минимальное число: "
             << findMin(arr, size) << endl;
        break;

      case 5:
        cout << "Минимальный индекс: "
             << findMinIndex(arr, size) << endl;
        break;

      case 6:
        cout << "Сумма: "
             << findSum(arr, size) << endl;
        break;

      case 7:
        cout << "Среднее: "
             << findAverage(arr, size) << endl;
        break;

      case 8:
        cout << "Положительные: "
             << countPositive(arr, size) << endl;
        break;

      case 9:
        cout << "Отрицательные: "
             << countNegative(arr, size) << endl;
        break;

      case 10:
        cout << "Нули: "
             << countZero(arr, size) << endl;
        break;

      case 11:
        cout << "Четные: "
             << countEven(arr, size) << endl;
        break;

      case 12:
        cout << "Нечетные: "
             << countOdd(arr, size) << endl;
        break;

      case 13:
        cout << "Кол-во элементов больше среднего: "
             << countAboveAverage(arr, size) << endl;
        break;

      case 14:
        cout << "Второй максимум: "
             << findSecondMax(arr, size) << endl;
        break;

      case 15:
        reverseArray(arr, size);

        cout << "Перевернутый массив: ";
        printArray(arr, size);
        break;

      case 16:
        cout << "Количество максимумов: " << countMax(arr, size) << endl;
        break;

      case 17:
      replaceNegatives(arr, size);

      cout << "Отрицательные элементы заменены на 0." << endl;
      cout << "Измененный массив: ";
      printArray(arr, size);
      break;

    case 18:
    {
      int value;

      cout << "Введите элемент для поиска: ";
      cin >> value;

      int index = findElement(arr, size, value);

      if (index == -1)
      {
        cout << "Элемент не найден." << endl;
      }
      else
      {
        cout << "Элемент найден. Индекс: " << index << endl;
      }
    break;
    }

      case 0:
        cout << "Программа завершена.\n";
        break;

      default:
        cout << "Неверный выбор!\n";
    }

  } while (chose != 0);

  return 0;
  }
}