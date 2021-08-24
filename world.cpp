#include "world.h"

World::World(const int sz, const sf::Vector2u worldSize)
  : segmentSize_{ sz }
  , worldSize_{ worldSize }
{
  initializeApple();
  initializeWalls();
}

void World::draw(sf::RenderWindow& r)
{
  for ( int i = 0; i < 4; ++i ) {
    r.draw(walls_[i]);
  }
}

/** Update the state of world.
 */
void World::update()
{
  // TODO: implemented as follow
  //   - check if the snake can eat the apple
  //   - check if the snake collides with the walls
}

void World::initializeApple()
{
  apple_.shape.setFillColor(sf::Color::Green);
  apple_.shape.setRadius(segmentSize_ / 2.0);

  createApple();
}

/** Create an apple at a random position in the world. The position must not be on the walls.
 */
void World::createApple()
{
  // DAY 2: Create an apple at a random position in the world. The position must not be on the
  // walls.
}

void World::initializeWalls()
{
  for ( int i = 0; i < 4; ++i ) {
    walls_[i].setFillColor(sf::Color::Red);
    if ( (i + 1) % 2 == 0 ) {
      walls_[i].setSize(sf::Vector2f(worldSize_.x * segmentSize_, segmentSize_));
    } else {
      walls_[i].setSize(sf::Vector2f(segmentSize_, worldSize_.y * segmentSize_));
    }

    if ( i < 2 ) {
      walls_[i].setPosition(0, 0);
    } else {
      walls_[i].setOrigin(walls_[i].getSize());
      walls_[i].setPosition(sf::Vector2f(worldSize_.x * segmentSize_, worldSize_.y * segmentSize_));
    }
  }
}
