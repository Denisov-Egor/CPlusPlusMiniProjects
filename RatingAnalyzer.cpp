#include <iostream>

using namespace std;

void inputArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
}

double findAverage(int arr[], int size)
{
  double sum = 0;
  double average = 0;

  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  average = sum / size; 
  return average;
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

int countGrade(int arr[], int size, int grade)
{
  int count = 0;
  
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == grade)
    {
      count++;
    }
  }
  return count;  
}

int countFailed(int arr[], int size)
{
  int countFail = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] < 3)
    {
      countFail++;    
    }
  }
  return countFail;
}

int countSuccessful(int arr[], int size)
{
  int countSucc = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] >= 3)
    {
      countSucc++;    
    }
  }
  return countSucc;
}

double successPercent(int arr[], int size)
{
  int countSucc = countSuccessful(arr, size);

  double percent;

  percent = (double)countSucc / size * 100;

  return percent;
}

double failedPercent(int arr[], int size)
{
  int countFal = countFailed(arr, size);

  double percent;

  percent = (double)countFal / size * 100;

  return percent;
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

int main()
{
  int size;

  cin >> size;

  int arr[size];

  inputArray(arr, size);

  double average = findAverage(arr, size);
  int max = findMax(arr, size);
  int min = findMin(arr, size);

  int five = countGrade(arr, size, 5);
  int four = countGrade(arr, size, 4);
  int three = countGrade(arr, size, 3);
  int two = countGrade(arr, size, 2);

  int countFail = countFailed(arr, size);
  int countSucc = countSuccessful(arr, size);

  double succPercent = successPercent(arr, size);
  double failPercent = failedPercent(arr, size);

  int maxIndex = findMaxIndex(arr, size);

  cout << "Среднее: " << average << endl;
  cout << "Максимальное: " << max << endl;
  cout << "Минимальное: " << min << endl;

  cout << "5: " << five << endl;
  cout << "4: " << four << endl;
  cout << "3: " << three << endl;
  cout << "2: " << two << endl;

  cout << "Кол-во успешных оценок: " << countSucc << endl;
  cout << "Успешных: " << succPercent << "%" << endl;

  cout << "Кол-во неуспешных оценок: " << countFail << endl;
  cout << "Неуспешных: " << failPercent << "%" << endl;

  cout << "Лучший результат находится под индексом: " << maxIndex << endl;
}
