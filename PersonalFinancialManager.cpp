#include <iostream>

using namespace std;

void printMenu()
{
  cout << 
  R"(
  ================================
       PERSONAL FINANCE
  ================================

  1. Добавить доход
  2. Добавить расход
  3. Показать баланс
  4. Показать общие доходы
  5. Показать общие расходы
  6. Рассчитать процент расходов
  7. Сбросить данные
  8. Показать полную статистику
  9. Выход

  Введите действие:
  )";
}

double inputAmount()
{
  double amount;

  while (true)
  {
    cout << "Введите сумму: ";
    cin >> amount;

    if (amount <= 0)
    {
      cout << "Сумма должна быть больше 0.";
    }else
    {
      return amount;
    }
  }  
}

double addIncome(double income, double amount)
{
  return income + amount;
}
double addExpense(double expenses, double amount)
{
  return expenses + amount;
}
double calculateBalance(double income, double expenses)
{
  return income - expenses;
}
double calculateExpensePercent(double income, double expenses)
{
  return expenses / income * 100;
}

void printBalance(double income, double expenses)
{
  cout << "Ваш баланс: ";
  cout << calculateBalance(income, expenses) << endl;
}

void printStatistics(double income, double expenses)
{
  cout << "========== STATISTICS ==========" << endl;

  cout << "Доходы:" << income << endl;
  cout << "Расходы:" << expenses << endl; 
  cout << "Баланс:" << calculateBalance(income, expenses) << endl;
  if (income == 0)
    {
      cout << "Невозможно рассчитать процент: доход равен 0." << endl;
    }else
    {
      cout << "Процент расходов: "
      << calculateExpensePercent(income, expenses)
      << "%" << endl;
    }
}

int main()
{
  double income = 0;
  double expenses = 0;
  double amount = 0; 

  char chose; 

  while (true)
  {
    printMenu();

    cin >> chose;

      switch (chose)
      {
      case '1':
        amount = inputAmount();
      
        income = addIncome(income, amount);
    
        cout << "Ваш доход увеличился на: " << amount;
        break;
    
      case '2':
        amount = inputAmount();
    
        expenses = addExpense(expenses, amount);
    
        cout << "Ваш расход увеличился на: " << amount;
        break;
    
      case '3':   
        printBalance(income, expenses);
        break;
    
      case '4':
        cout << "Общий доход: " << income;
        break;

      case '5':
        cout << "Общий расход: " << expenses;
        break;
    
      case '6':
        if (income == 0)
        {
          cout << "Невозможно рассчитать процент: доход равен 0.";
          break;
        }
        
        cout << "Процент расходов: " << calculateExpensePercent(income, expenses) << "%";
        break;
    
      case '7':
        income = 0;
        expenses = 0;

        cout << "Данные сброшены.";
        break;

      case '8':
        printStatistics(income, expenses);
        break;
    
      case '9':
        cout << "Выход";
        break;
      
      default:
        break;
      }
      
      if (chose == '9')
      { 
        break;
      }
  }
}