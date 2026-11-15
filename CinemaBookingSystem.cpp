#include <iostream>
#include <string>
#include <stdexcept>

int inputMovieId()
{
  int id;
  std::cin >> id;
  return id;
}

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

class Cinema
{
private:
  Movie* movies;
  int movieCount;
  int capacity;
  
  void resize()
  {
    int newCapacity = capacity * 2;
    Movie* newMovies = new Movie[newCapacity];
  
    for (int i = 0; i < movieCount; i++)
    {
      newMovies[i] = movies[i];
    }
    
    delete [] movies;
  
    movies = newMovies;
    capacity = newCapacity;
  }

public:
  Cinema()
        : movies(new Movie[2]), movieCount(0), capacity(2)
  {}

  ~Cinema()
  {
    delete [] movies;
  }

  Movie* findMovie(int id)
  {
    for (int i = 0; i < movieCount; i++)
    {
      if (movies[i].getId() == id)
      {
        return &movies[i];
      }
    }
    
    return nullptr;
  }

  void addMovie(const Movie& movie)
  {
    if (findMovie(movie.getId()) != nullptr)
    {
      throw std::invalid_argument("Фильм с таким ID уже существует");
    }
    
    if (movieCount == capacity)
    {
      resize();
    }
    
    movies[movieCount] = movie;
    movieCount++;
  }

  void displayMovies() const
  {
    if (movieCount == 0)
    {
      std::cout << "Каталог фильмов пуст.\n";
      return;
    }
    
    for (int i = 0; i < movieCount; i++)
    {
      movies[i].display();
    }
  }

  int getMovieCount() const
  {
    return movieCount;
  }

  int getCapacity() const
  {
    return capacity;
  }
};

void showAdministratorMenu(Cinema& cinema)
{
  int choice = -1;

  while (choice != 0)
  {
    std::cout << "\n"
              << "========== МЕНЮ АДМИНИСТРАТОРА ==========\n\n"
              << "1. Добавить фильм\n"
              << "2. Показать все фильмы\n"
              << "3. Удалить фильм\n"
              << "0. Назад\n\n"
              << "Выберите действие: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
      
      break;

    case 2:

      break;

    case 3:

      break;

    case 0:
      std::cout << "Назад.\n";
      break;
    
    default:
      std::cout << "Неверный пункт меню.\n";
      break;
    }
    
  }
}

void showUserMenu(Cinema& cinema)
{
  int choice = -1;

  while (choice != 0)
  {
    std::cout << "\n"
              << "========== МЕНЮ ПОЛЬЗОВАТЕЛЯ ==========\n\n"
              << "1. Показать каталог фильмов\n"
              << "2. Найти фильм по ID\n"
              << "0. Назад\n\n"
              << "Выберите действие: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
      
      break;
    
    case 2:

      break;
    
    case 0:
      std::cout << "Назад.\n";
      break;
    
    default:
      std::cout << "Неверный пункт меню.\n";
      break;
    }    
  }
}

void showMainMenu(Cinema& cinema)
{
  int choice = -1;

  while (choice != 0)
  {
    std::cout << "\n"
              << "========== СИСТЕМА БРОНИРОВАНИЯ КИНО ==========\n\n"
              << "1. Администратор\n"
              << "2. Пользователь\n"
              << "0. Выход\n\n"
              << "Выберите действие: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
      showAdministratorMenu(cinema);
      break;

    case 2:
      showUserMenu(cinema);
      break;

    case 0:
      std::cout << "Выход.\n";
      return;
    
    default:
      std::cout << "Неверный пункт меню.\n";
      break;
    }
  }
}

int main()
{
  Cinema cinema;

  showMainMenu(cinema);
}