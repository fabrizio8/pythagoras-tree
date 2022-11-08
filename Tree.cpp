#include <vector>
#include "Tree.hpp"

sf::Vector2f ZERO_VEC = sf::Vector2f(0,0);

sf::Color green[] = 
{
    sf::Color(30, 147, 45),
    sf::Color(77, 168, 59),
    sf::Color(130, 212, 53),
    sf::Color(71, 144, 0),
    sf::Color(18, 119, 25),
    sf::Color(16, 103, 27),
    sf::Color(16, 71, 28),
    sf::Color(24, 83, 14),
};

sf::Color brown[] =
{
    sf::Color(97, 53, 26),
    sf::Color(98, 78, 44),
};

Tree::Tree(double _baseLength, int _recursionDepth, std::vector<sf::Vector2f> init)
            : baseLength{_baseLength}, recursionDepth {_recursionDepth} 
{
    root = new PTree(init[0], init[1], recursionDepth);
}

void Tree::print(sf::RenderWindow &window)
{
    traverse(root, window);
}
void Tree::traverse(PTree* leaf, sf::RenderWindow &window)
{
    if (leaf != NULL)
    {
        leaf->draw(window, leaf->renderState);
        window.display();
    }

    if (leaf->left != NULL)
        traverse(leaf->left, window);
    if (leaf->right != NULL)
        traverse(leaf->right, window);
}
Tree::~Tree()
{
    if (root)
    {
        root->left->chop();
        root->right->chop();
    }
    delete root;
}