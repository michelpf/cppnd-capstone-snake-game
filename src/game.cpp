#include "game.h"
#include "SDL.h"
#include <iostream>
#include <chrono>
#include <future>
#include <thread>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, snake);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this    frame is too small (i.e. frame_duration is
 // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      
      return;
    }
  }
}

void TimerThread(bool *_superFood) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    *_superFood = false;
}

int Game::GetSuperFoodChange(){
  if (snake.difficulty == "Easy"){
     return 5;
  }
  else if (snake.difficulty == "Normal"){
    return 2;
  }
  else 
  {
  	return 1;
  }
}

void Game::Update() {

  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  
  std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> dis(1, 10);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    
    if (_superFood) {
    	score = score + 100;
        std::cout << "You got a super meal! Plus 100 points!" << std::endl;
    }
    else
    {
    	score++;
    }
    
    PlaceFood();
    
    // Grow snake and increase speed.
    snake.GrowBody();  
    snake.speed += 0.02;
    
    if(dis(gen) <= GetSuperFoodChange()){
      _superFood = true;
      std::thread superFoodTimer(TimerThread, &_superFood);
      superFoodTimer.detach();
    }
  }
}

void Game::UpdateStartSpeed()
{
	snake.SetStartingSpeed();
}

std::string Game::GetDifficulty()
{
	
  return snake.difficulty;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }