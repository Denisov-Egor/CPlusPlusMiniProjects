#include <iostream>

using namespace std;

void printMenu()
{
  cout << 
  R"(
  ================================
             ATM
  ================================

  1. Проверить баланс
  2. Пополнить счёт
  3. Снять деньги
  4. Перевести деньги
  5. Рассчитать комиссию
  6. Выход

  Введите действие:
  )";
}

double inputAmount()
{
  double amount = 0;

  cout << "Введите сумму: ";
  cin >> amount;

  while (true)
  {
    if (amount <= 0)
    {
      cout << "Сумма должна быть больше 0." << endl;
      cin >> amount;
    }else
    {
      return amount;
    }
  }
}

double calculateCommission(double amount)
{
  return amount * 0.05;
}

bool canWithdraw(double balance, double amount)
{
  double commission = calculateCommission(amount);

  if (amount + commission <= balance)
  {
    return true;
  }else
  {
    return false;
  } 
}

double deposit(double balance, double amount)
{
  balance += amount;
  return balance;
}

double withdraw(double balance, double amount)
{
  double total = 0;
  double newBalance = 0;

  double commission = calculateCommission(amount);

  total = amount + commission;
  newBalance = balance - total;

  return newBalance;
}

double transfer(double balance, double amount)
{
  double newBalance = balance - amount;
  
  return newBalance;
}

int main()
{
  double balance = 10000;
  double amount = 0;
  char chose;

  while (true)
  {
    printMenu();
  
    cin >> chose;
  
    switch (chose)
    {
    case '1':
      cout << "Ваш баланс: " << balance;
      break;
  
    case '2':
      amount = inputAmount();

      balance = deposit(balance, amount);

      cout << "Счёт пополнен." << endl;
      cout << "Зачислено: " << amount << " ₽" << endl;
      cout << "Баланс: " << balance << " ₽" << endl;
      break;
  
    case '3':
      amount = inputAmount();

      if (canWithdraw(balance, amount))
      {
        balance = withdraw(balance, amount);

        double commission = calculateCommission(amount);

        cout << "Снятие выполнено." << endl;
        cout << "Снято: " << amount << " ₽" << endl;
        cout << "Комиссия: " << commission << " ₽" << endl;
        cout << "Баланс: " << balance << " ₽" << endl;
      }else
      {
        cout << "Недостаточно средств." << endl;
      }           
      break;
  
    case '4':
      amount = inputAmount();

      if (amount <= balance)
      {
        balance = transfer(balance, amount);

        cout << "Перевод выполнен." << endl;
        cout << "Переведено: " << amount << " ₽" << endl;
        cout << "Баланс: " << balance << " ₽" << endl;
      }else
      {
        cout << "Недостаточно средств.";
      }
      break;
  
    case '5':
    {
      amount = inputAmount();

      double commission = calculateCommission(amount);

      cout << commission;
      break;
    }
  
    case '6':
      cout << "Выход";
      break;
    
    default:
    cout << "Такого выбора нет";
      break;
    }
    
    if (chose == '6')
    {
      break;
    }
  }
}