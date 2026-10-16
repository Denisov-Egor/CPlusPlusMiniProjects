#include <iostream>

using namespace std;

void showMenu()
{
  cout << "\n========== WAREHOUSE INVENTORY MANAGER ==========\n";
  cout << "1. Показать склад\n";
  cout << "2. Показать статистику\n";
  cout << "3. Найти партию\n";
  cout << "4. Изменить количество товара\n";
  cout << "5. Поступление товара\n";
  cout << "6. Списание товара\n";
  cout << "7. Добавить партию\n";
  cout << "8. Удалить партию\n";
  cout << "0. Выход\n";
  cout << "=================================================\n";
  cout << "Выберите действие: ";
}

int getBatchCount()
{
  int batchCount;
  
  cout << "Введите кол-во партий: ";
  cin >> batchCount;

  return batchCount;
}

int** createInventory(int batchCount)
{
  int** inventory = new int*[batchCount];

  for (int i = 0; i < batchCount; i++)
  {
    inventory[i] = new int;
  }

  return inventory;
}

void inputInventory(int** inventory, int batchCount)
{
  int productQuantity;

  for (int i = 0; i < batchCount; i++)
  {
    cout << "Введите кол-во товара в партии " << i + 1 << ": ";

    cin >> productQuantity;
    *inventory[i] = productQuantity;
  }
}

void displayInventory(int** inventory, int batchCount)
{
  for (int i = 0; i < batchCount; i++)
  {
    cout << "Партия ";
    cout << i + 1 << ": ";
    cout << *inventory[i] << '\n';
  }
}

int calculateTotalQuantity(int** inventory, int batchCount)
{
  int generalSum = 0;

  for (int i = 0; i < batchCount; i++)
  {
    generalSum += *inventory[i];
  }

  return generalSum;
}

int findMinQuantity(int** inventory, int batchCount)
{
  int minQuantity = *inventory[0];

  for (int i = 1; i < batchCount; i++)
  {
    if (*inventory[i] < minQuantity)
    {
      minQuantity = *inventory[i];
    }
  }
  
  return minQuantity;
}

int findMaxQuantity(int** inventory, int batchCount)
{
  int maxQuantity = *inventory[0];

  for (int i = 1; i < batchCount; i++)
  {
    if (*inventory[i] > maxQuantity)
    {
      maxQuantity = *inventory[i];
    }
  }
  
  return maxQuantity;
}

double calculateAverageQuantity(int** inventory, int batchCount)
{
  int generalSum = calculateTotalQuantity(inventory, batchCount);

  return double(generalSum) / batchCount;

}

int countEmptyBatches(int** inventory, int batchCount)
{
  int emptyBatches = 0;

  for (int i = 0; i < batchCount; i++)
  {
    if (*inventory[i] == 0)
    {
      emptyBatches++;
    }
  }
  
  return emptyBatches;
}

int countLowStockBatches(int** inventory, int batchCount, int threshold)
{
  int countThreshold = 0;

  for (int i = 0; i < batchCount; i++)
  {
    if (*inventory[i] < threshold)
    {
      countThreshold++;
    }
  }
  
  return countThreshold;
}

void findBatchByNumber(int** inventory, int batchCount, int batchNumber)
{
  for (int i = 0; i < batchCount; i++)
  {
    if (i == batchNumber - 1)
    {
      cout << "Партия ";
      cout << i + 1 << ": ";
      cout << *inventory[i] << '\n';
    }
  }
}

void updateBatchQuantity(int** inventory, int batchCount, int batchNumber)
{
  for (int i = 0; i < batchCount; i++)
  {
    if (i == batchNumber - 1)
    {
      cout << "Введите новое количество товара для партии " << i + 1 << ": ";
      cin >> *inventory[i];
    }
  }
}

void addStock(int** inventory, int batchCount, int batchNumber)
{
  int quantity;

  for (int i = 0; i < batchCount; i++)
  {
    if (i == batchNumber - 1)
    {
      cout << "Введите количество товара которое поступило на склад " << i + 1 << ": ";
      cin >> quantity;

      while (quantity < 0)
      {
        cout << "Количество товара должно быть больше 0. Введите снова: ";
        cin >> quantity;
      }

      *inventory[i] += quantity;
      cout << *inventory[i];
    }
  }
}

void removeStock(int** inventory, int batchCount, int batchNumber)
{
  int quantity;

  for (int i = 0; i < batchCount; i++)
  {
    if (i == batchNumber - 1)
    {
      cout << "Партия ";
      cout << i + 1 << ": ";
      cout << *inventory[i] << '\n';

      cout << "Введите количество товара которое нужно списать со склада " << i + 1 << ": ";
      cin >> quantity;

      while (quantity < 0 || quantity > *inventory[i])
      {
        cout << "Количество товара должно быть больше 0 и не превышать количество товара на складе. Введите снова: ";
        cin >> quantity;
      }

      *inventory[i] -= quantity;
      cout << *inventory[i];
    }
  }
}

int** addBatch(int** inventory, int batchCount)
{
  int** newInventory = new int*[batchCount + 1];
  int newQuantity;

  for (int i = 0; i < batchCount; i++)
  {
    newInventory[i] = inventory[i];
  }
  
  newInventory[batchCount] = new int;

  cout << "Введите новое количество товара: ";
  cin >> newQuantity;

  *newInventory[batchCount] = newQuantity;
  
  delete [] inventory;

  return newInventory;
}

int** removeBatch(int** inventory, int batchCount, int batchNumber)
{
  int** newInventory = new int*[batchCount - 1];
  int j = 0;

  for (int i = 0; i < batchCount; i++)
  {
    if (i == batchNumber - 1)
    {
      continue;
    }

    newInventory[j] = inventory[i];
    j++;
  }

  delete inventory[batchNumber - 1];
  delete[] inventory;

  return newInventory;
}

void freeInventory(int** inventory, int batchCount)
{
  for (int i = 0; i < batchCount; i++)
  {
    delete inventory[i];
  }
  
  delete [] inventory;
  inventory = nullptr;
}

int main()
{
  int batchCount;
  int** inventory;
  int threshold;
  int batchNumber;
  int choice;

  batchCount = getBatchCount();

  inventory = createInventory(batchCount);
  inputInventory(inventory, batchCount);

  while (true)
  {
    showMenu();
    cin >> choice;

    switch (choice)
    {
      case 1:
        displayInventory(inventory, batchCount);
        break;

      case 2:
        cout << "Общее количество товара: "
             << calculateTotalQuantity(inventory, batchCount) << '\n';

        cout << "Минимальное количество товара: "
             << findMinQuantity(inventory, batchCount) << '\n';

        cout << "Максимальное количество товара: "
             << findMaxQuantity(inventory, batchCount) << '\n';

        cout << "Среднее количество товара: "
             << calculateAverageQuantity(inventory, batchCount) << '\n';

        cout << "Количество пустых партий: "
             << countEmptyBatches(inventory, batchCount) << '\n';

        cout << "Введите минимальный порог: ";
        cin >> threshold;

        cout << "Количество партий ниже порога: "
             << countLowStockBatches(inventory, batchCount, threshold) << '\n';
        break;

      case 3:
        cout << "Введите номер партии: ";
        cin >> batchNumber;

        while (batchNumber < 1 || batchNumber > batchCount)
        {
          cout << "Неверный номер. Попробуйте снова: ";
          cin >> batchNumber;
        }

        findBatchByNumber(inventory, batchCount, batchNumber);
        break;

      case 4:
        cout << "Введите номер партии: ";
        cin >> batchNumber;

        while (batchNumber < 1 || batchNumber > batchCount)
        {
          cout << "Неверный номер. Попробуйте снова: ";
          cin >> batchNumber;
        }

        updateBatchQuantity(inventory, batchCount, batchNumber);
        break;

      case 5:
        cout << "Введите номер партии: ";
        cin >> batchNumber;

        while (batchNumber < 1 || batchNumber > batchCount)
        {
          cout << "Неверный номер. Попробуйте снова: ";
          cin >> batchNumber;
        }

        addStock(inventory, batchCount, batchNumber);
        break;

      case 6:
        cout << "Введите номер партии: ";
        cin >> batchNumber;

        while (batchNumber < 1 || batchNumber > batchCount)
        {
          cout << "Неверный номер. Попробуйте снова: ";
          cin >> batchNumber;
        }

        removeStock(inventory, batchCount, batchNumber);
        break;

      case 7:
        inventory = addBatch(inventory, batchCount);
        batchCount++;
        break;

      case 8:
        if (batchCount > 1)
        {
          cout << "Введите номер партии для удаления: ";
          cin >> batchNumber;

          while (batchNumber < 1 || batchNumber > batchCount)
          {
            cout << "Неверный номер. Попробуйте снова: ";
            cin >> batchNumber;
          }

          inventory = removeBatch(inventory, batchCount, batchNumber);
          batchCount--;
        }
        else
        {
          cout << "Нельзя удалить последнюю партию.\n";
        }
        break;

      case 0:
        freeInventory(inventory, batchCount);
        inventory = nullptr;

        cout << "Память освобождена. Программа завершена.\n";
        return 0;

      default:
        cout << "Неизвестная команда. Попробуйте снова.\n";
    }
  }
}