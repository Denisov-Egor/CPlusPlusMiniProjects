#include <iostream>
#include <string>
#include <stdexcept>

void showMainMenu();
void showAdministratorMenu();
void showUserMenu();

class Movie
{
private:
  int id;
  std::string title;
  int duration;
  int ageRating;
public:
  Movie() : id(0), title("Неизвестно"), duration(0), ageRating(0) {}

  Movie(int id, const std::string& title, int duration, int ageRating)
      : id(id), title(title),  duration(duration), ageRating(ageRating)
  {
    if (id <= 0)
    {
      throw std::invalid_argument("ID фильма должен быть больше нуля");
    }

    if (title.empty())
    {
      throw std::invalid_argument("Название фильма не должно быть пустым");
    }
    
    if (duration <= 0)
    {
      throw std::invalid_argument("Продолжительность должна быть больше нуля");
    }
    
    if (ageRating < 0 || ageRating > 18)
    {
      throw std::invalid_argument("Возрастной рейтинг должен быть от 0 до 18");
    }  
  }

  int getId() const
  {
    return id;
  }

  const std::string& getTitle() const
  {
    return title;
  }

  int getDuration() const
  {
    return duration;
  }

  int getAgeRating() const
  {
    return ageRating;
  }

  void display() const
  {
    std::cout << "ID фильма: " << id << '\n'
              << "Название: " << title << '\n'
              << "Продолжительность: " << duration << " мин.\n"
              << "Возрастной рейтинг: " << ageRating << "+\n";
  }
};

int main()
{

}