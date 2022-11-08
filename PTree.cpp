#include <SFML/Graphics.hpp>
#include "Tree.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

PTree::PTree(sf::Vector2f pointA, sf::Vector2f pointB, size_t depth, bool isLeft)
{
  sf::Vector2f pointC;
  sf::Vector2f pointD;
  sf::Vector2f pointE;

  square = sf::VertexArray(sf::Quads, points);

  left = NULL;
  right = NULL;

  square[0].position = pointA;
  square[1].position = pointB;

  pointC.x =  pointB.x - (pointA.y - pointB.y);
  pointC.y = pointB.y - (pointB.x - pointA.x);

  pointD.x = pointA.x - (pointA.y -  pointB.y);
  pointD.y = pointA.y - (pointB.x - pointA.x);

  pointE.x = pointD.x + (pointB.x - pointA.x - (pointA.y - pointB.y)) / 2.0;
  pointE.y = pointD.y - (pointB.x - pointA.x + pointA.y - pointB.y ) / 2.0;

  // set last two points now that they've been found
  square[2] = pointC;
  square[3] = pointD;

  if (depth) // initialize nodes if not at required depth
  {
    left = new PTree(pointD, pointE, depth - 1);
    right = new PTree(pointE, pointC, depth - 1, false);
  }

  setColor(depth);
}

void PTree::chop()
{
  if (left)
    left->chop();
  if (right)
    right->chop();
  
  delete left;
  delete right;
    
}

void PTree::setColor(size_t depth) 
// Randomly color vertices, trunk should be brown if tree is deep enough
{
  int randInt;
  srand(time(NULL));
  if (depth > 6)
  {
    for (int i = 0; i < points-1; i++)
    {
      randInt = rand()%2;
      square[i].color = brown[randInt];
    }
    square[3].color = sf::Color(83, 49, 24);
  }
  else
  {
    for (int i = 0; i < points-1; i++)
    {
      randInt = rand()%8;
      square[i].color = green[randInt];
    }
    square[3].color = sf::Color(146, 239, 159);
  }
}

void PTree::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
  window.draw(square, renderState);
}
