#include <iostream>
#include <string>

using namespace std;

void showMenu()
{
  cout << 
  R"(
  ========================================
          PLAYER MANAGER
          BATTLE ARENA
  ========================================
  1. Информация об игроке
  2. Список врагов
  3. Найти врага
  4. Начать бой
  5. Восстановить здоровье
  6. Получить награду
  7. Магазин
  8. Использовать предмет
  9. Статистика
  0. Выход

  Введите число: 

  )";
}

void showPlayer(string name, int health, int maxHealth, int level, int experience, int money)
{
  cout << 
  R"(
  ================================
          PLAYER INFO
  ================================
  )";

  cout << "Имя: " << name << '\n';
  cout << "Здоровье: " << health << '/' << maxHealth << '\n';
  cout << "Левел: " << level << '\n';
  cout << "Опыт: " << experience << '\n';
  cout << "Деньги: " << money << '\n';
}

void showEnemy(string enemyName, int enemyHealth, int enemyMaxHealth, int enemyDamage, int enemyReward, int enemyExperience)
{
  cout << 
  R"(
  ================================
          ENEMY INFO
  ================================
  )";

  cout << "Имя: " << enemyName << '\n';
  cout << "Здоровье: " << enemyHealth << '/' << enemyMaxHealth << '\n';
  cout << "Урон: " << enemyDamage << '\n';
  cout << "Награда: " << enemyReward << '\n';
  cout << "Опыт: " << enemyExperience << '\n';
}

void takeDamage(int& health, int damage)
{
  health -= damage;

  if (health < 0)
  {
    health = 0;
  }
}

void attackEnemy(int& enemyHealth, int damage)
{
  enemyHealth -= damage;

  if (enemyHealth < 0)
  {
    enemyHealth = 0;
  }
}

void addMoney(int& money, int amount)
{
  money += amount;
}

void addExperience(int& experience, int amount)
{
  experience += amount;
}

void getReward(int& money, int& pendingReward, int& totalRewards)
{
  addMoney(money, pendingReward);
  totalRewards += pendingReward;
  pendingReward = 0;
}

void levelUp(int& level, int& maxHealth, int& health, int& playerDamage, int experience)
{
  while (experience >= level * 100)
  {
    level++;
    maxHealth += 20;
    health = maxHealth;
    playerDamage += 5;
  }
}

void battleRound(string name, string enemyName, int& health, int& enemyHealth, int playerDamage, int enemyDamage, int& maxDamageDealt)
{
  cout << '\n';
  cout << '\t' << name << " атакует " << enemyName << '\n';
  
  attackEnemy(enemyHealth, playerDamage);
  if (enemyHealth > 0)
  {
    takeDamage(health, enemyDamage);
  }

  if(playerDamage > maxDamageDealt)
  {
  maxDamageDealt = playerDamage;
  }
}

void battle(
  string name, int& health, int& maxHealth, int& level, int& experience, int& pendingReward, int& playerDamage, 
  string enemyName, int& enemyHealth, int enemyDamage, int enemyReward, int enemyExperience,
  int& defeatedEnemies, int& totalExperience, int& usedItems, int& maxDamageDealt, string& strongestEnemy
)
{
  while (health > 0 && enemyHealth > 0)
  {
    battleRound(name, enemyName, health, enemyHealth, playerDamage, enemyDamage, maxDamageDealt);
  }
  if (enemyHealth <= 0)
  {
    cout  << '\n';
    cout << '\t' << name << " победил " << enemyName << '\n';

    pendingReward += enemyReward;
    totalExperience += enemyExperience;

    if (enemyReward > 0)
    {
      strongestEnemy = enemyName;
    }

    addExperience(experience, enemyExperience);
    levelUp(level, maxHealth, health, playerDamage, experience);

    defeatedEnemies++;
  }else if (health <= 0)
  {
    cout << '\t' << enemyName << " победил " << name << '\n';
  }  

}

void searchEnemy(string enemyNames[], int enemyHealth[], int enemyMaxHealth[], int enemyDamage[], int enemyReward[], int enemyExperience[])
{
  bool found = false;
  string searchEnemyName;
  cout << "Введите имя врага: ";
  cin >> searchEnemyName;
  for (int i = 0; i < 4; i++)
  {
    if (enemyNames[i].find(searchEnemyName) != string::npos)
    {
      showEnemy( enemyNames[i], enemyHealth[i], enemyMaxHealth[i], enemyDamage[i], enemyReward[i], enemyExperience[i]);
      found = true;
    } 
  }
  if (!found)
  {
    cout << "Враг не найден.\n";
  }
}

bool heal(int& health, int maxHealth, int amount)
{
  if (health <= 0)
  {
    cout << "Игрок мёртв. Восстановление невозможно.\n";
    return false;
  }else if (health >= maxHealth)
  {
    cout << "Здоровье уже на максимуме.\n";
    return false;
  }
  if (amount <= 0)
  {
    cout << "Количество лечения должно быть больше нуля.\n";
    return false;
  }
  
  health += amount;
  if (health > maxHealth)
  {
    health = maxHealth;
  }
  return true;
}

void showShop(string itemNames[], int itemPrices[], int itemHealing[])
{
  cout << 
  R"(
  ================================
             SHOP
  ================================
  )";

  for (int i = 0; i < 5; i++)
  {
    cout << i << ' ' << itemNames[i] << ' ' << itemPrices[i] << ' ' << itemHealing[i] << '\n';
  }  
}

void showInventory(string itemNames[], int inventory[])
{
  cout << 
  R"(
  ================================
           INVENTORY
  ================================
  )";

  for (int i = 0; i < 5; i++)
  {
    cout << i << ' ' << itemNames[i] << ' ' << inventory[i] << '\n';
  }
}

void useItem(int& health, int& maxHealth, string itemNames[], int itemHealing[], int inventory[], int& usedItems)
{
  showInventory(itemNames, inventory);

  bool healed;
  
  int itemIndex;
  cout << "Введите позицию (0 - 4): ";
  cin  >> itemIndex;

  while (itemIndex < 0 || itemIndex > 4)
  {
    cout << "Номер товара введен не правильно введите еще раз: ";
    cin >> itemIndex;
  }

  if (inventory[itemIndex] == 0)
  {
    cout << "Предмета " << itemNames[itemIndex] << " нет.";
  }else 
  {
    healed = heal(health, maxHealth, itemHealing[itemIndex]);

    if (healed == true)
    {
      inventory[itemIndex]--;
      usedItems++;
      
      cout << "Предмет использован.\n";
    }
  }
  
}

void showStatistics( int defeatedEnemies, int totalExperience, int totalRewards, int usedItems, int maxDamageDealt, string strongestEnemy)
{
  cout << "Статистика игрока\n";

  cout << "Побеждено врагов: " << defeatedEnemies << '\n';
  cout << "Получено опыта: " << totalExperience << '\n';
  cout << "Получено денег: " << totalRewards << '\n';
  cout << "Использовано предметов: " << usedItems << '\n';
  cout << "Максимальный урон игрока: " << maxDamageDealt << '\n';
  cout << "Самый сильный враг: " << strongestEnemy << '\n';
}

int main()
{
  int chose = -1;
  string name;

  cout  << "Введите имя игрока: ";
  cin >> name;

  int health = 100;
  int maxHealth = 100;
  int level = 1;
  int experience = 0;
  int money = 500;
  int pendingReward = 0;
  int playerDamage = 20;

  showPlayer(name, health, maxHealth, level, experience, money);
  
  string enemyNames[4] = {"Goblin", "Orc", "Skeleton", "Dragon"};
  int enemyHealth[4] = {50, 100, 75, 300};
  int enemyMaxHealth[4] = {50, 100, 75, 300};
  int enemyDamage[4] = {10, 20, 15, 40};
  int enemyReward[4] = {100, 250, 175, 1000};
  int enemyExperience[4] = {50, 100, 75, 500};
  int enemyIndex;

  int defeatedEnemies = 0;
  int totalExperience = 0;
  int totalRewards = 0;
  int usedItems = 0;
  int maxDamageDealt = 0;
  string strongestEnemy;

  string itemNames[5] = 
  {
    "Small Potion",
    "Medium Potion",
    "Large Potion",
    "Mega Potion",
    "Full Heal"
  };

  int itemPrices[5] = 
  {
    50,
    100,
    200,
    350,
    500
  };

  int itemHealing[5] = 
  {
    25,
    50,
    100,
    150,
    999
  };

  int inventory[5] = {0, 0, 0, 0, 0};
  
  while (chose != 0)
  {
    showMenu();
    cin >> chose;
    switch (chose)
    {
      case 1:
        showPlayer(name, health, maxHealth, level, experience, money);
        break;
      
      case 2:
        for (int i = 0; i < 4; i++)
        {
          showEnemy(
            enemyNames[i],
            enemyHealth[i],
            enemyMaxHealth[i],
            enemyDamage[i],
            enemyReward[i],
            enemyExperience[i]
          );
        }
      break;
        
        case 3:
          searchEnemy(enemyNames, enemyHealth, enemyMaxHealth, enemyDamage, enemyReward, enemyExperience);
          break;
        
        case 4:
          if (health <= 0)
          {
            cout << "Игрок мёртв. Начать бой невозможно.\n";
          }
          else
          {
            cout << "Введите номер врага (0-3): ";
            cin >> enemyIndex;
            if (enemyIndex >= 0 && enemyIndex <= 3)
            {
              if (enemyHealth[enemyIndex] <= 0)
              {
                cout << "Этот враг уже побеждён.\n";
              }
              else
              {
                battle( 
                  name, health, maxHealth, level, experience, pendingReward, playerDamage, 
                  enemyNames[enemyIndex], enemyHealth[enemyIndex], enemyDamage[enemyIndex], enemyReward[enemyIndex], enemyExperience[enemyIndex],
                  defeatedEnemies, totalExperience, usedItems, maxDamageDealt, strongestEnemy
                );
              }
            }
            else
            {
              cout << '\t' << "Неверный номер врага!\n";
            }
          }
          break;
  
        case 5:
          int amount;
          cout << "Введите количество здоровья для восстановления: ";
          cin >> amount;    
  
          heal(health, maxHealth, amount);     
      break;

      case 6:
        if (pendingReward > 0)
        {
          getReward(money, pendingReward, totalRewards);
          cout << "Награды успешно получены.";
        }else if (pendingReward == 0)
        {
          cout << "Награды для получения нет.";
        }
        
      break;

      case 7:
        int itemIndex;

        showShop(itemNames, itemPrices, itemHealing);

        cout << "Введите номер товара (0 - 4): ";
        cin >> itemIndex;

        while (itemIndex < 0 || itemIndex > 4)
        {
          cout << "Номер товара введен не правильно введите еще раз: ";
          cin >> itemIndex;
        }

        if (money >= itemPrices[itemIndex])
        {
          inventory[itemIndex]++;

          addMoney(money, -itemPrices[itemIndex]);
          cout << itemNames[itemIndex] << ' ' << "Успешно куплен";
        }else
        {
          cout << "Не хватает денег.";
        }

        showInventory(itemNames, inventory);
               
      break;

      case 8:
      useItem(health, maxHealth, itemNames, itemHealing, inventory, usedItems);

      break;

      case 9:
        showStatistics(defeatedEnemies, totalExperience, totalRewards, usedItems, maxDamageDealt, strongestEnemy);

        break;

      case 0:
      cout << "Выход";
    break;

    default:
    cout << "Неверный пункт меню введите снова: ";
      break;
    }
  }
  
}