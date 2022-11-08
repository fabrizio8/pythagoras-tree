#include <iostream>
#include <cctype>
#include "Tree.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{	
	double baseLength;
	int recursionDepth;
	bool close = false;
	float x, y;

	if (argc != 3)
	{
		std::cerr << "Must enter base size and recursion depth as command line arguments" << std::endl;
		exit(1);
	}

	baseLength = atof(argv[1]);
	recursionDepth = atoi(argv[2]);

	if (baseLength <= 0 || recursionDepth < 1)
	{
		std::cerr << "Base length and recusion depth must be positive and greater than 0" << std::endl;
		exit(1);
	}

	x = baseLength * 6;
	y = baseLength * 4;

	sf::RenderWindow window(sf::VideoMode(x, y), "Tree");

	x = x/2 - baseLength/2; // set x value for square to middle of screen

	std::vector<sf::Vector2f> init =
	{
		sf::Vector2f(x, y),
		sf::Vector2f(x + baseLength, y),
	};

	Tree tree = Tree(baseLength, recursionDepth, init); // create tree
	tree.print(window); // draw and print to screen
	std::cout << "PRESS ANY KEY TO EXIT (in the tree window)" << std::endl;

	while (window.isOpen() && !close)
	{
		sf::Event event;
		while (window.pollEvent(event) && !close)
		{
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				// window.clear();
				// close = true;
			}
		}
	}

	return 0;
}

