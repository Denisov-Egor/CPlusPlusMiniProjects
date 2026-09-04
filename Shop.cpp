#include <iostream>

using namespace std;

void printMenu() // Меню
{
  cout << 
  R"(
  ================================
             SHOP
  ================================

  1. Показать товары
  2. Купить товар
  3. Показать сумму покупки
  4. Применить скидку
  5. Очистить покупку
  6. Квитанция
  7. Выход
  Введите действие:
  )";
}

void printProducts() // Спосок товаров
{
 cout << 
  R"(
  ========== PRODUCTS ==========

  1. Keyboard     5000 ₽
  2. Mouse        2500 ₽
  3. Headphones   7000 ₽
  4. Monitor      25000 ₽
  5. USB Cable    1000 ₽
  )";
}

double calculateItemPrice(double price, int quantity) // Стоймость выбраного товара
{
  return price * quantity;
}

double calculateDiscount(double total, double percent) // Размер скидки
{
  return total * percent / 100;
}
double calculateFinalPrice(double total, double discount) //Конеч ст продукта
{
  double finalPrice = total - discount;
  
  return finalPrice;
}

void printReceipt(double total, double discount, double finalPrice) // Квитанция
{
  cout << "========== RECEIPT ==========" << endl;

  cout << "Сумма покупки: " << total << " ₽" << endl;
  cout << "Скидка:" <<  discount << " ₽" << endl;
  cout << "Итоговая сумма:" <<  finalPrice << " ₽" << endl;

  cout <<"=============================" << endl;
}

int main()
{
  double total = 0;
  double discount = 0;
  double finalPrice = 0;
  double price = 0;
  double percent = 0;

  int product;
  int quantity = 0;
  char choice;

  while (true)
  {
    printMenu();

    cin >> choice;

    switch (choice)
    {
    case '1':
      printProducts();
      break;
    
    case '2':
    {
      cout << "Выберети товар: ";
      
      while (true)
      {
        cin >> product;

        if (product < 1 || product > 5)
        {
          cout << "Такого продукта нет. Введите заново";
        }else
        {
          break;
        }       
      }
      switch (product)
      {
      case 1:
        price = 5000;
        break;

      case 2:
          price = 2500;
          break;

     case 3:
        price = 7000;
          break;

      case 4:
        price = 25000;
        break;

      case 5:
        price = 1000;
        break;
        
      default:
        break;
      } 
      cout << "Введите количество: ";
      cin >> quantity;

      while (quantity <= 0)
      {
        cout << "Количество должно быть больше 0: ";
        cin >> quantity;
      }

      double itemPrice = calculateItemPrice(price, quantity);
      total += itemPrice; 
      break;
    }

    case '3':
      if (total == 0)
      {
        cout << "Ваша корзина пустая." << endl;
      }else
      {
        cout << "Сумма покупки: " << total << " ₽" << endl;
      }
      break;

    case '4':
      if (total <= 0)
      {
        cout << "У вас нету покупок.";
      }else
      {
        cout << "Вводите скидку: ";
        cin >> percent;

        while (true)
        {
          if (percent < 0 || percent > 100)
          {
            cout << "Скидка должна быть от 0 до 100%: ";
            cin >> percent;
          }else
          {
            break;
          }
        }
        discount = calculateDiscount(total, percent);
        finalPrice = calculateFinalPrice(total, discount);
        cout << "Скидка: " << discount << " ₽" << endl;
        cout << "Итоговая сумма: " << finalPrice << " ₽" << endl;
      }     
      break;

    case '5':
      total = 0;
      discount = 0;
      finalPrice = 0;

      cout << "Покупка очищена." << endl;
      break;

    case '6':
      printReceipt(total, discount, finalPrice);
      break;

    case '7':
      cout << "Выход";
      break;
    

    }

    if (choice == '7')
    {
      break;
    }
  } 
}
