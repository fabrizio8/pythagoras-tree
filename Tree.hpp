#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>
#include <vector>

extern sf::Vector2f ZERO_VEC;
extern sf::Color green[];
extern sf::Color brown[];

class PTree: public sf::Drawable
{
  size_t points = 4;
  sf::VertexArray square;
  sf::RenderStates renderState;
	PTree *left;
	PTree *right;

  friend class Tree;

  public:
  PTree(sf::Vector2f pointA = ZERO_VEC, sf::Vector2f pointB = ZERO_VEC,
        size_t depth = 0, bool isLeft = true);
  void chop();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setColor(size_t depth);
};

class Tree
{
  double baseLength;
  int recursionDepth;
  PTree *root;

  public:
  Tree(double _baseLength, int _recursionDepth, std::vector<sf::Vector2f> init); 
  ~Tree();
  void print(sf::RenderWindow &window);
  void traverse(PTree* leaf, sf::RenderWindow &window);
};


#endif
