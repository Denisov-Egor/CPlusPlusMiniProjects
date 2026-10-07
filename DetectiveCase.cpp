#include <iostream>
#include <string>

using namespace std;

void showMenu()
{
  cout << R"(
  ========================================
           DETECTIVE CASE
  ========================================

  1. Показать всех подозреваемых
  2. Найти подозреваемого
  3. Показать информацию
  4. Добавить улику
  5. Изменить уровень подозрения
  6. Найти самого подозрительного
  7. Показать статистику

  0. Выйти

  Выберите действие:
  )";
}

void showSuspects(string names[], int ages[], int suspicion[], int evidence[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << i + 1 << ". Имя: " << names[i] 
    << " Возраст: " << ages[i] 
    << " Уровень подозрения: " << suspicion[i] 
    << "  Доказательство: " << evidence[i] 
    << '.' << endl;
  }
}

void searchSuspects(string names[], int ages[], int suspicion[], int evidence[], int size, string searchName)
{
  bool found = false;

  for (int i = 0; i < size; i++)
  {
    if (searchName == names[i])
    {
      found = true;
      cout << "Подозреваемый найден!";
      cout << "Имя: " << names[i] << endl
      << "Возраст: " << ages[i] << endl
      << "Уровень подозрения: " << suspicion[i] << endl 
      << "Улик: " << evidence[i] << endl;
    }
  }  
  
  if (!found)
  {
    cout << "Подозреваемый не найден.";
  }
  
}

void showSuspectInfo(string names[], int ages[], int suspicion[], int evidence[], int numberSuspects)
{
  int indexSuspicion = numberSuspects - 1;

  cout << "Подозреваемый: " << endl
  << "Имя: " << names[indexSuspicion] << endl
  << "Возраст: " << ages[indexSuspicion] << endl
  << "Уровень подозрения: " << suspicion[indexSuspicion] << endl
  << "Улик: " << evidence[indexSuspicion] << endl;
}

void addEvidence(int* evidence, int amount)
{
  *evidence += amount;
}

void changeSuspicion(int* suspicion, int amount)
{
  *suspicion = amount;
}

int findMostSuspicious(int* suspicion, int size)
{
  int maxIndex = 0;

  for (int i = 0; i < size; i++)
  {
    if (*(suspicion + i) > *(suspicion + maxIndex))
    {
      maxIndex = i;
    }
  }
  
  return maxIndex;
}

void showStatistics(int* suspicion, int* evidence, int size)
{
  int totalSuspicion = 0;
  int totalEvidence = 0;

  int maxSuspicion = *(suspicion);
  int minSuspicion = *(suspicion);

  for (int i = 0; i < size; i++)
  {
    totalSuspicion += *(suspicion + i);
    totalEvidence += *(evidence + i);

    if (*(suspicion + i) > maxSuspicion)
    {
      maxSuspicion = *(suspicion + i);
    }

    if (*(suspicion + i) < minSuspicion)
    {
      minSuspicion = *(suspicion + i);
    }
  }

  double averageSuspicion = static_cast<double>(totalSuspicion) / size;

  cout << "========== СТАТИСТИКА ==========" << endl
  << "Всего улик: " << totalEvidence << endl
  << "Среднее подозрение: " << averageSuspicion << endl
  << "Максимальное подозрение: " << maxSuspicion << endl
  << "Минимальное подозрение: " << minSuspicion << endl;
}

int main()
{
  string names[5] = {"Alex", "Boris", "Charlie", "Denis", "Edward"};
  int ages[5] = {25, 31, 28, 35, 22};
  int suspicion[5] = {30, 70, 45, 90, 20};
  int evidence[5] = {1, 3, 2, 5, 0};
  
  string searchName;
  int numberSuspects;
  int amountEvidence;
  int amountSuspicion;
  int indexSuspicion;
  
  int choise = -1;
  
  while (choise != 0)
  {
    showMenu();
    
    cin >> choise;
    
    switch (choise)
    {
    case 1:
      showSuspects(names, ages, suspicion, evidence, 5);
    break;
      
    case 2:
      cout << "Введите имя подозреваемого: ";
      cin >> searchName;

      searchSuspects(names, ages, suspicion, evidence, 5, searchName);
    break;

    case 3:
      cout << "Введите номер подозреваемого: ";
      cin >> numberSuspects;

      while (numberSuspects < 1 || numberSuspects > 5) 
      {
        cout << "Некоректный ввод.";
        cin >> numberSuspects;
      }

      showSuspectInfo(names, ages, suspicion, evidence, numberSuspects);
    break;

    case 4:
      cout << "Введите номер подозреваемого: ";
      cin >> numberSuspects;

      while (numberSuspects < 1 || numberSuspects > 5) 
      {
        cout << "Некоректный ввод.";
        cin >> numberSuspects;
      }

      cout << "Введите количество новых улик: ";
      cin >> amountEvidence;

      addEvidence(&evidence[numberSuspects - 1], amountEvidence);
    break;
    
    case 5:
      cout << "Введите номер подозреваемого: ";
      cin >> numberSuspects;

      while (numberSuspects < 1 || numberSuspects > 5) 
      {
        cout << "Некоректный ввод.";
        cin >> numberSuspects;
      }
      
      cout << "Введите новый уровень подозрения: ";
      cin >> amountSuspicion;
      
      changeSuspicion(&suspicion[numberSuspects - 1], amountSuspicion);
    break;

    case 6:
      indexSuspicion = findMostSuspicious(suspicion, 5);
      
      cout << "Самый подозрительный: " << endl
      << "Имя: " << names[indexSuspicion] << endl
      << "Возраст: " << ages[indexSuspicion] << endl
      << "Уровень подозрения: " << suspicion[indexSuspicion] << endl
      << "Улик: " << evidence[indexSuspicion] << endl;
    break;

    case 7:
      showStatistics(suspicion, evidence, 5);
    break;

    case 0:
      cout << "Выход";
    break;
    
    default:
      cout << "Такого пункта в меню нет.";
    break;
    }
  }
}