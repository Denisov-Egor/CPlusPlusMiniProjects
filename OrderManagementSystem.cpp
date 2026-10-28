#include <iostream>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

void displayMenu()
{
cout <<
  R"(
  ==========================================
        ORDER MANAGEMENT SYSTEM
  ==========================================

  --- Управление заказами ---

  1.  Показать все заказы
  2.  Добавить заказ
  3.  Удалить заказ
  4.  Изменить статус заказа
  5.  Изменить стоимость заказа

  --- Поиск и фильтрация ---

  6.  Найти заказ по ID
  7.  Показать заказы по статусу
  8.  Показать заказы в диапазоне цен

  --- Финансы и статистика ---

  9.  Рассчитать общую стоимость заказов
  10. Рассчитать среднюю стоимость заказа
  11. Найти самый дорогой заказ
  12. Найти самый дешёвый заказ
  13. Показать статистику по статусам
  14. Показать финансовый отчёт

  --- Сортировка ---

  15. Сортировать заказы по ID
  16. Сортировать заказы по стоимости
  17. Сортировать заказы по статусу

  --- Проверка данных ---

  18. Проверить ID заказа
  19. Проверить стоимость заказа
  20. Проверить статус заказа
  21. Проверить уникальность ID

  --- Дополнительные операции ---

  22. Найти свободный слот для заказа
  23. Ввести несколько заказов
  24. Освободить память
  0.  Выход
  )";
}

enum class OrderStatus
{
  New,
  Processing,
  Shipped,
  Delivered
};

struct Order
{
  int id;
  double price;
  OrderStatus status;
};

bool isValidOrderPrice(double price)
{
    return std::isfinite(price) && price > 0;
}

Order* createOrders(int size)
{
  Order* orders = new Order[size];

  return orders;
}

bool isOrderIdUnique(int size, Order* orders, int id)
{
  for (int i = 0; i < size; i++)
  {
    if (orders[i].id == id)
    {
      return false;
    }
  }
  
  return true;
}

void inputOrders(int size, Order* orders)
{
  string statusInput;
  
  for (int i = 0; i < size; i++)
  {
    bool validId = false;
    bool validPrice = false;
    bool validStatus = false;

   while (!validId)
    {
      cout << "Введите ID: ";
      cin >> orders[i].id;

      if (cin.fail())
      {
        cout << "Ошибка: ID должен быть целым числом.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else if (orders[i].id <= 0)
      {
        cout << "Ошибка: ID должен быть больше нуля.\n";
      }else if (!isOrderIdUnique(i, orders, orders[i].id))
      {
        cout << "Ошибка: ID не может повторяться.\n";
      }else
      {
        validId = true;
      }
    }

    while (!validPrice)
    {
      cout << "Введите стоймость: ";
      cin >> orders[i].price;
      
      if (cin.fail())
      {
        cout << "Ошибка: цена должена быть числом.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }else if (!isValidOrderPrice(orders[i].price))
      {
        cout << "Ошибка: цена должена быть больше нуля.\n";
      }else
      {
        validPrice = true;
      }
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите статус: ";
    getline(cin, statusInput);
    
    while (!validStatus) 
    {
      if (statusInput == "новый")
      {
        orders[i].status = OrderStatus::New;
        validStatus = true;
      }else if (statusInput == "в обработке")
      {
        orders[i].status = OrderStatus::Processing;
        validStatus = true;
      }else if (statusInput == "отправлен")
      {
        orders[i].status = OrderStatus::Shipped;
        validStatus = true;
      } else if (statusInput == "доставлен")
      {
        orders[i].status = OrderStatus::Delivered;
        validStatus = true;
      }else
      {
        cout << "Такого статуса нет. Введите статус с снова: \n";
        getline(cin, statusInput);
      }
    }
  }
}

void displayOrders(int size, Order* orders)
{
  if (size == 0)
  {
    cout << "Заказов нет. \n";
    return;
  }
  
  for (int i = 0; i < size; i++)
  {
    cout << "ID заказа: " << orders[i].id << '\n';
    
    cout << "Цена: " << orders[i].price << '\n';

    cout << "Текущий статус: ";

    if (orders[i].status == OrderStatus::New)
    {
      cout << "новый\n";
    }else if (orders[i].status == OrderStatus::Processing)
    {
      cout << "в обработке\n";
    }else if (orders[i].status == OrderStatus::Shipped)
    {
      cout << "отправлен\n";
    }else if (orders[i].status == OrderStatus::Delivered)
    {
      cout << "доставлен\n";
    }

    cout << '\n';
  }
}

void addOrder(int& size, Order*& orders)
{
  Order newOrder;
  string statusInput;
  bool validId = false;
  bool validPrice = false;
  bool validStatus = false;

  cout << "Введите данные нового заказа.\n";

  while (!validId)
  {
    cout << "Введите ID: ";
    cin >> newOrder.id;

    if (cin.fail())
    {
      cout << "Ошибка: ID должен быть целым числом.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else if (newOrder.id <= 0)
    {
      cout << "Ошибка: ID должен быть больше нуля.\n";
    }else if (!isOrderIdUnique(size, orders, newOrder.id))
    {
      cout << "Ошибка: заказ с таким ID уже существует.\n";
    }else
    {
      validId = true;
    }
  }

  while (!validPrice)
  {
    cout << "Введите стоимость: ";
    cin >> newOrder.price;

    if (cin.fail())
    {
      cout << "Ошибка: стоимость должна быть числом.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else if (!isValidOrderPrice(newOrder.price))
    {
      cout << "Ошибка: стоимость должна быть больше нуля.\n";
    }else
    {
      validPrice = true;
    }
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (!validStatus)
  {
    cout << "Введите статус (новый, в обработке, отправлен, доставлен): ";
    getline(cin, statusInput);

    if (statusInput == "новый")
    {
      newOrder.status = OrderStatus::New;
      validStatus = true;
    }else if (statusInput == "в обработке")
    {
      newOrder.status = OrderStatus::Processing;
      validStatus = true;
    }else if (statusInput == "отправлен")
    {
      newOrder.status = OrderStatus::Shipped;
      validStatus = true;
    }else if (statusInput == "доставлен")
    {
      newOrder.status = OrderStatus::Delivered;
      validStatus = true;
    }else
    {
      cout << "Ошибка: неизвестный статус. Попробуйте снова.\n";
    }
  }

  Order* newOrders = new Order[size + 1];

  for (int i = 0; i < size; i++)
  {
    newOrders[i] = orders[i];
  }

  newOrders[size] = newOrder;

  delete[] orders;

  orders = newOrders;
  size++;

  cout << "Заказ успешно добавлен.\n";
}

void inputMultipleOrders(int& size, Order*& orders)
{
  int count;

  cout << "Сколько заказов добавить? ";

  if (!(cin >> count))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ошибка: количество должно быть целым числом.\n";
    return;
  }

  if (count <= 0)
  {
    cout << "Количество должно быть больше нуля.\n";
    return;
  }

  for (int i = 0; i < count; i++)
  {
    cout << "\n--- Новый заказ " << i + 1 << " из " << count << " ---\n";
    addOrder(size, orders);
  }
}

bool removeOrder(int& size, Order*& orders)
{
  int id;

  if (size == 0)
  {
    cout << "Список заказов пуст.\n";
    return false;
  }

  cout << "Введите ID заказа: ";

  if (!(cin >> id))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ошибка: ID должен быть числом.\n";
    return false;
  }

  int index = -1;

  for (int i = 0; i < size; i++)
  {
    if (orders[i].id == id)
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    cout << "Заказ с таким ID не найден.\n";
    return false;
  }
  
  if (size == 1)
  {
    delete [] orders;
    orders = nullptr;
    size = 0;

    cout << "Заказ успешно удален.\n";
    return true;
  }
  
  Order* newOrders = new Order[size - 1];

  int newIndex = 0;
  
  for (int i = 0; i < size; i++)
  {
    if (i != index)
    {
      newOrders[newIndex] = orders[i];
      newIndex++;
    }
  }

  delete[] orders;

  orders = newOrders;
  size--;

  cout << "Заказ успешно удален.\n";
  return true;
}

bool updateOrderStatus(int size, Order* orders, int id, OrderStatus newStatus)
{  
  for (int i = 0; i < size; i++)
  {
    if (orders[i].id == id)
    {
      orders[i].status = newStatus;
      return true;
    }
  }

  return false;
}

bool updateOrderPrice(int size, Order* orders, int id, double newPrice)
{
    for (int i = 0; i < size; i++)
    {
        if (orders[i].id == id && isValidOrderPrice(newPrice))
        {
            orders[i].price = newPrice;
            return true;
        }
    }

    return false;
}

int findOrderById(int size, Order* orders, int id)
{
  for (int i = 0; i < size; i++)
  {
    if (orders[i].id == id)
    {
      return i;
    }
  }
  return -1;
}

void displayOrdersByStatus(int size, Order* orders, OrderStatus status)
{
  bool found = false;

  if (size == 0)
  {
    cout << "Список заказов пуст.\n ";
    return;
  }

  for (int i = 0; i < size; i++)
  {
    if (orders[i].status == status)
    {
      cout << "ID заказа: " << orders[i].id << '\n';
      cout << "Цена: " << orders[i].price << '\n';

      if (orders[i].status == OrderStatus::New)
      {
        cout << "новый\n";
      }else if (orders[i].status == OrderStatus::Processing)
      {
        cout << "в обработке\n";
      }else if (orders[i].status == OrderStatus::Shipped)
      {
        cout << "отправлен\n";
      }else if (orders[i].status == OrderStatus::Delivered)
      {
        cout << "доставлен\n";
      }

      cout << '\n';
      
      found = true;
    }
  }
  
  if (!found)
  {
    cout << "Заказа с таким статусом нет.";
  }
  
}

void displayOrdersInPriceRange(int size, Order* orders, double minPrice, double maxPrice)
{
  bool found = false;

  if (size == 0)
  {
    cout << "Список заказов пуст.\n ";
    return;
  }

  for (int i = 0; i < size; i++)
  {
    if (orders[i].price >= minPrice && orders[i].price <= maxPrice)
    {
      cout << "ID заказа: " << orders[i].id << '\n';
    
      cout << "Цена: " << orders[i].price << '\n';

      cout << "Текущий статус: ";

      if (orders[i].status == OrderStatus::New)
      {
        cout << "новый\n";
      }else if (orders[i].status == OrderStatus::Processing)
      {
        cout << "в обработке\n";
      }else if (orders[i].status == OrderStatus::Shipped)
      {
        cout << "отправлен\n";
      }else if (orders[i].status == OrderStatus::Delivered)
      {
        cout << "доставлен\n";
      }

      cout << '\n';

      found = true;
    }
  }
  
  if (!found)
  {
    cout << "Заказов в даном диапазоне нет.\n";
  }
  
}

double calculateTotalPrice(int size, Order* orders)
{
  double totalSum = 0;

  for (int i = 0; i < size; i++)
  {
    totalSum += orders[i].price;
  }

  return totalSum;
}

double calculateAveragePrice(int size, Order* orders)
{
  double totalPrice = calculateTotalPrice(size, orders);

  return totalPrice / double(size);
}

int findMostExpensiveOrder(int size, Order* orders)
{
  int maxIndex = 0;

  for (int i = 1; i < size; i++)
  {
    if (orders[i].price > orders[maxIndex].price)
    {
      maxIndex = i;
    }
  }
  
  return maxIndex;
}

int findCheapestOrder(int size, Order* orders)
{
  int minIndex = 0;

  for (int i = 1; i < size; i++)
  {
    if (orders[i].price < orders[minIndex].price)
    {
      minIndex = i;
    }
  }
  
  return minIndex;
}

int countOrdersByStatus(int size, Order* orders, OrderStatus status)
{
  int count = 0;

  for (int i = 0; i < size; i++)
  {
    if (orders[i].status == status)
    {
      count ++;
    }
  }
  
  return count;
}

void displayStatusStatistics(int size, Order* orders)
{
  cout << "\n--- Статистика заказов по статусам ---\n";

  cout << "Новые: " << countOrdersByStatus(size, orders, OrderStatus::New) << '\n';

  cout << "В обработке: " << countOrdersByStatus(size, orders, OrderStatus::Processing) << '\n';

  cout << "Отправленные: " << countOrdersByStatus(size, orders, OrderStatus::Shipped) << '\n';

  cout << "Доставленные: " << countOrdersByStatus(size, orders, OrderStatus::Delivered) << '\n';
}

void displayFinancialReport(int size, Order* orders)
{
  int mostExpensiveIndex = findMostExpensiveOrder(size, orders);
  int cheapestIndex = findCheapestOrder(size, orders);

  cout << "\n--- Финансовый отчёт ---\n";

  cout << "Количество заказов: " << size << '\n';

  cout << "Общая стоимость заказов: " << calculateTotalPrice(size, orders) << '\n';

  cout << "Средняя стоимость заказа: " << calculateAveragePrice(size, orders) << '\n';

  cout << "\nСамый дорогой заказ:\n";
  cout << "ID: " << orders[mostExpensiveIndex].id << '\n';
  cout << "Стоимость: " << orders[mostExpensiveIndex].price << '\n';

  cout << "\nСамый дешёвый заказ:\n";
  cout << "ID: " << orders[cheapestIndex].id << '\n';
  cout << "Стоимость: " << orders[cheapestIndex].price << '\n';
}

void sortOrdersById(int size, Order* orders)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (orders[j].id > orders[j + 1].id)
      {
        Order temp = orders[j];
        orders[j] = orders[j + 1];
        orders[j + 1] = temp;
      }
    }
  }
}

void sortOrdersByPrice(int size, Order* orders)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (orders[j].price > orders[j + 1].price)
      {
        Order temp = orders[j];
        orders[j] = orders[j + 1];
        orders[j + 1] = temp;
      }
    }
  }
}

void sortOrdersByStatus(int size, Order* orders)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (static_cast<int>(orders[j].status) >
      static_cast<int>(orders[j + 1].status))
      {
        Order temp = orders[j];
        orders[j] = orders[j + 1];
        orders[j + 1] = temp;
      }
    }
  }
}

bool isValidOrderId(int id)
{
  return id > 0;
}

bool isValidOrderStatus(int status)
{
  return status >= 0 && status <= 3;
}

int findFreeOrderSlot(int size, Order* orders)
{
  for (int i = 0; i < size; i++)
  {
    if (orders[i].id == 0)
    {
      return i;
    }
  }
  return -1;
}

void freeOrders(Order*& orders)
{
  delete[] orders;
  orders = nullptr;
}

void processMenuChoice(int choice, int& size, Order*& orders)
{
  OrderStatus newStatus;

  string statusInput;

  bool validStatus = false;
  bool validPrice = false;
  
  int id;

  double newPrice;
  double minPrice;
  double maxPrice;

  double totalPrice;

  switch (choice)
  {
    case 1:
      displayOrders(size, orders);
      break;

    case 2:
      addOrder(size, orders);
      break;

    case 3:
      removeOrder(size, orders);
      break;

    case 4:
      if (size > 0)
      {
        cout << "Введите ID заказа: ";

        if (!(cin >> id))
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Ошибка: ID должен быть числом.\n";
          break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Введите статус строки: ";
        getline(cin, statusInput);

        while (!validStatus) 
        {
          if (statusInput == "новый")
          {
            newStatus = OrderStatus::New;
            validStatus = true;
          }else if (statusInput == "в обработке")
          {
            newStatus = OrderStatus::Processing;
            validStatus = true;
          }else if (statusInput == "отправлен")
          {
            newStatus = OrderStatus::Shipped;
            validStatus = true;
          } else if (statusInput == "доставлен")
          {
            newStatus = OrderStatus::Delivered;
            validStatus = true;
          }else
          {
            cout << "Такого статуса нет. Введите статус с снова: \n";
            getline(cin, statusInput);
          }
        }

        if (updateOrderStatus(size, orders, id, newStatus))
        {
          cout << "Статус заказа успешно изменён.\n";
        }else
        {
          cout << "Заказ с таким ID не найден.\n";
        }

      }else if (size == 0)
      {
        cout << "Список заказов пуст.\n";
      }
      break;

    case 5:
      if (size > 0)
      {
        cout << "Введите ID заказа: ";

        if (!(cin >> id))
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Ошибка: ID должен быть числом.\n";
          break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Введите новую стоимость: ";

        if (!(cin >> newPrice))
        {
          cout << "Ошибка: стоимость должна быть числом.\n";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
        }

        if (!isValidOrderPrice(newPrice))
        {
          cout << "Ошибка: цена должна быть конечным числом больше нуля.\n";
          break;
        }

        if (updateOrderPrice(size, orders, id, newPrice))
        {
          cout << "Цена успешно изменена\n.";
        }else
        {
          cout << "Заказ с таким ID не найден или цена меньше или равно нулю\n.";
        }
      }else if (size == 0)
      {
        cout << "Список заказов пуст.\n";
      }
      break;

    case 6:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      cout << "Введите ID заказа: ";

      if (!(cin >> id))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Ошибка: ID должен быть числом.\n";
        break;
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      {
        int index = findOrderById(size, orders, id);

        if (index == -1)
        {
          cout << "Заказ с таким ID не найден.\n";
          break;
        }

        cout << "\n--- Найденный заказ ---\n";
        cout << "ID заказа: " << orders[index].id << '\n';
        cout << "Стоимость: " << orders[index].price << '\n';
        cout << "Статус: ";

        if (orders[index].status == OrderStatus::New)
        {
          cout << "новый\n";
        }
        else if (orders[index].status == OrderStatus::Processing)
        {
          cout << "в обработке\n";
        }
        else if (orders[index].status == OrderStatus::Shipped)
        {
          cout << "отправлен\n";
        }
        else if (orders[index].status == OrderStatus::Delivered)
        {
          cout << "доставлен\n";
        }

        cout << '\n';
      }
      break;

    case 7:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "Введите статус заказа (новый, в обработке, отправлен, доставлен): ";
      getline(cin, statusInput);

      validStatus = false;

      while (!validStatus)
      {
        if (statusInput == "новый")
        {
          newStatus = OrderStatus::New;
          validStatus = true;
        }else if (statusInput == "в обработке")
        {
          newStatus = OrderStatus::Processing;
          validStatus = true;
        }else if (statusInput == "отправлен")
        {
          newStatus = OrderStatus::Shipped;
          validStatus = true;
        }else if (statusInput == "доставлен")
        {
          newStatus = OrderStatus::Delivered;
          validStatus = true;
        }else
        {
          cout << "Неизвестный статус. Попробуйте снова: ";
          getline(cin, statusInput);
        }
      }

      displayOrdersByStatus(size, orders, newStatus);
      break;

    case 8:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      cout << "Введите минимальную цену: ";
      cin >> minPrice;

      if (cin.fail())
      {
        cout << "Ошибка: цена должна быть числом.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      }

      cout << "Введите максимальную цену: ";
      cin >> maxPrice;

      if (cin.fail())
      {
        cout << "Ошибка: цена должна быть числом.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      }

      if (!isValidOrderPrice(minPrice) || !isValidOrderPrice(maxPrice))
      {
        cout << "Ошибка: цены должны быть конечными числами больше нуля.\n";
        break;
      }

      if (minPrice > maxPrice)
      {
        cout << "Ошибка: минимальная цена не может быть больше максимальной.\n";
        break;
      }

        displayOrdersInPriceRange(size, orders, minPrice, maxPrice);
        break;

    case 9:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      totalPrice = calculateTotalPrice(size, orders);
          
      cout << "Общая стоимость заказов: " << totalPrice << '\n';
      break;

    case 10:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      cout << "Средняя стоимость заказа: " << calculateAveragePrice(size, orders);
      break;

    case 11:
    {
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      int index = findMostExpensiveOrder(size, orders);

      cout << "\n--- Самый дорогой заказ ---\n";
      cout << "ID заказа: " << orders[index].id << '\n';
      cout << "Стоимость: " << orders[index].price << '\n';
      cout << "Статус: ";

      if (orders[index].status == OrderStatus::New)
      {
        cout << "новый\n";
      }else if (orders[index].status == OrderStatus::Processing)
      {
        cout << "в обработке\n";
      }else if (orders[index].status == OrderStatus::Shipped)
      {
        cout << "отправлен\n";
      }else if (orders[index].status == OrderStatus::Delivered)
      {
        cout << "доставлен\n";
      }

      cout << '\n';

    }
      break;

    case 12:
    {
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      int index = findCheapestOrder(size, orders);

      cout << "\n--- Самый дешёвый заказ ---\n";
      cout << "ID заказа: " << orders[index].id << '\n';
      cout << "Стоимость: " << orders[index].price << '\n';
      cout << "Статус: ";

      if (orders[index].status == OrderStatus::New)
      {
        cout << "новый\n";
      }else if (orders[index].status == OrderStatus::Processing)
      {
        cout << "в обработке\n";
      }else if (orders[index].status == OrderStatus::Shipped)
      {
        cout << "отправлен\n";
      }else if (orders[index].status == OrderStatus::Delivered)
      {
        cout << "доставлен\n";
      }

      cout << '\n';
    }  
      break;

    case 13:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      displayStatusStatistics(size, orders);
      break;

    case 14:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      displayFinancialReport(size, orders);
      break;

    case 15:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      sortOrdersById(size, orders);
      cout << "Заказы отсортированы по ID.\n";
      displayOrders(size, orders);
      break;

    case 16:
      if (size == 0)
      {
        cout << "Список заказов пуст.\n";
        break;
      }

      sortOrdersByPrice(size, orders);

      cout << "Заказы отсортированы по стоимости.\n";
      displayOrders(size, orders);
      break;

    case 17:
        if (size == 0)
        {
          cout << "Список заказов пуст.\n";
          break;
        }

        sortOrdersByStatus(size, orders);

        cout << "Заказы отсортированы по статусу.\n";
        displayOrders(size, orders);
        break;

      case 18:
        cout << "Введите ID для проверки: ";

        if (!(cin >> id))
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Ошибка: ID должен быть целым числом.\n";
          break;
        }

        if (isValidOrderId(id))
        {
          cout << "ID корректен.\n";
        }else
        {
          cout << "Ошибка: ID должен быть больше нуля.\n";
        }
        break;

    case 19:
      cout << "Введите стоимость для проверки: ";

      if (!(cin >> newPrice))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: стоимость должна быть числом.\n";
        break;
      }

      if (isValidOrderPrice(newPrice))
      {
        cout << "Стоимость корректна.\n";
      }else
      {
        cout << "Ошибка: стоимость должна быть конечным числом больше нуля.\n";
      }

      break;

    case 20:
    {
      int status;

        cout << "Введите номер статуса (0 — новый, " << "1 — в обработке, 2 — отправлен, " << "3 — доставлен): ";

        if (!(cin >> status))
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Ошибка: статус должен быть целым числом.\n";
          break;
        }

        if (isValidOrderStatus(status))
        {
          cout << "Статус корректен.\n";
        }
        else
        {
          cout << "Ошибка: такого статуса нет.\n";
        }

        break;
    }

    case 21:
      cout << "Введите ID для проверки уникальности: ";

      if (!(cin >> id))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: ID должен быть целым числом.\n";
        break;
      }

      if (id <= 0)
      {
        cout << "Ошибка: ID должен быть больше нуля.\n";
      }else if (isOrderIdUnique(size, orders, id))
      {
        cout << "Такой ID свободен.\n";
      }else
      {
        cout << "Заказ с таким ID уже существует.\n";
      }
      break;

    case 22:
    {
        int freeSlot = findFreeOrderSlot(size, orders);

        if (freeSlot == -1)
        {
            cout << "Свободных слотов нет. "
                 << "При добавлении заказа массив будет расширен.\n";
        }
        else
        {
            cout << "Найден свободный слот: " << freeSlot << '\n';
        }

        break;
    }

    case 23:
        inputMultipleOrders(size, orders);
        break;

    case 24:
      freeOrders(orders);
      size = 0;
      cout << "Память освобождена. Список заказов пуст.\n";
      break;

    case 0:
      cout << "Программа завершена.\n";
      break;

    default:
      cout << "Неверный пункт меню!\n";
      break;
  }
}

void runOrderManagementSystem(int& size, Order*& orders)
{
  int choice;

   while (true)
   {
    displayMenu();

    cout << "Введите номер пункта меню: ";
    
    if (!(cin >> choice))
    {
      if (cin.eof())
      {
        break;
      }

      cout << "Ошибка: введите целое число.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      continue;
    }

    if (choice < 0 || choice > 24)
    {
      cout << "Неверный пункт меню. Введите число от 0 до 24.\n";
      continue;
    }

    processMenuChoice(choice, size, orders);

    if (choice == 0)
    {
      break;
    }
   }
}

int main()
{
  int size;

  cout << "Введите размер партии: ";
  cin >> size;

  while (cin.fail() || size <= 0)
  {
    cout << "Размер партии должен быть больше нуля и не может быть строкой\n";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите размер партии еще раз: ";
    cin >> size;
  }

  Order* orders = createOrders(size);

  inputOrders(size, orders);

  runOrderManagementSystem(size, orders); 

  freeOrders(orders);
}
