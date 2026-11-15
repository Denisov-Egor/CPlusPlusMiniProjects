#include <iostream>
#include <string>
#include <stdexcept>

void showMainMenu();
void showAdministratorMenu();
void showUserMenu();

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

int main()
{

}