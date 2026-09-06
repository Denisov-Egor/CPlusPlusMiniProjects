#include <iostream>

using namespace std;

void inputArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
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

int findSecondMax(int arr[], int size)
{
  int secondMax;
  int max = findMax(arr, size);

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
      secondMax = arr[i] ;
    }
  }
  return secondMax;
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

int countPositive(int arr[], int size)
{
  int positive = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > 0)
    {
      positive++;
    }
  }
  return positive;
}

int countNegative(int arr[], int size)
{
  int negative = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < 0)
    {
      negative++;
    }
  }
  return negative;
}

int countZero(int arr[], int size)
{
  int zero = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 0)
    {
      zero++;
    }
  }
  return zero;
}

int main()
{
  int size;

  cin >> size;

  int arr[size];

  inputArray(arr, size);

  int min = findMin(arr, size);
  int minIndex = findMinIndex(arr, size);

  int max = findMax(arr, size);
  int maxIndex = findMaxIndex(arr, size);
  int secondMax = findSecondMax(arr, size);

  int sum = findSum(arr, size);
  double average = findAverage(arr, size);

  int even = countEven(arr, size);
  int odd = countOdd(arr, size);

  int positive = countPositive(arr, size);
  int negative = countNegative(arr, size);

  int zero = countZero(arr, size);

  cout << "Минимальный: " << min << endl;
  cout << "Минимальный индекс: " << minIndex << endl;

  cout << "Максимальный: " << max << endl;
  cout << "Максимальный индекс: " << maxIndex << endl;
  cout << "Втрой максимум: " << secondMax << endl;

  cout << "Сумма: " << sum << endl;
  cout << "Среднее: " << average << endl;

  cout << "Кол-во четных чисел: " << even << endl;
  cout << "Кол-во не четных чисел: " << odd << endl;

  cout << "Кол-во положительных: " << positive << endl;
  cout << "Кол-во отрицательных: " << negative << endl;
  
  cout << "Кол-во нулей: " << zero << endl;
}