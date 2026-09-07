#include <iostream>

using namespace std;

void inputArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
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

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < max)
    {
      secondMax = arr[i];
      break;
    }
  }

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < max && arr[i] > secondMax)
    {
      secondMax = arr[i];
    }
  }

  return secondMax;
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

int main()
{
  int size;

  cin >> size;

  int arr[size];

  inputArray(arr, size);

  int max = findMax(arr, size);
  int maxIndex = findMaxIndex(arr, size);

  int min = findMin(arr, size);
  int minIndex = findMinIndex(arr, size);

  int sum = findSum(arr, size);
  double average = findAverage(arr, size);

  int positive = countPositive(arr, size);
  int negative = countNegative(arr, size);
  int zero = countZero(arr, size);

  int even = countEven(arr, size);
  int odd = countOdd(arr, size);
  
  int aboveAverage = countAboveAverage(arr, size);
  int secondMax = findSecondMax(arr, size);

  cout << "Максимальное число: " << max << endl;
  cout << "Максимальный индекс: " << maxIndex << endl;

  cout << "Минимальное число: " << min << endl;
  cout << "Минимальный индекс: " << minIndex << endl;

  cout << "Сумма: " << sum << endl;
  cout << "Среднее: " << average << endl;

  cout << "Положительные: " << positive << endl;
  cout << "Отрицательные: " << negative << endl;
  cout << "Нули: " << zero << endl;

  cout << "Четные: " << even << endl;
  cout << "Нечетныe: " << odd << endl;

  cout << "Кол-во эл больше среднего: " << aboveAverage << endl;
  cout << "Второй максимум: " << secondMax << endl;

  cout << "Перевернутый массив: ";   
  reverseArray(arr, size);

  for (int i = 0; i < size; i++)
  {
  cout << arr[i] << " ";
  }
}
