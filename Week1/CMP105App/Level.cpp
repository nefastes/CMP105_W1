#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(60, 60));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(30, 30));
	rect2.setPosition(115, 115);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(15, 15));
	rect3.setPosition(122.5, 122.5);
	rect3.setFillColor(sf::Color::Blue);

	sf::Vector2u position = window->getSize();
	rect3.setSize(sf::Vector2f(60, 60));
	rect3.setPosition(position.x-60, position.y-60);
	rect3.setFillColor(sf::Color::Blue);

	if (!font.loadFromFile("font/arial.ttf")) std::cout << "Could not load font.\n";
	text.setFont(font);
	text.setString("Hello World !");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(500, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u position = window->getSize();
	rect3.setPosition(position.x - 60, position.y - 60);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);
	window->draw(text);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}