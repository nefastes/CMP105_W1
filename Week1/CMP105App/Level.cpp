#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	sf::Vector2u position = window->getSize();

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

	rect3.setSize(sf::Vector2f(60, 60));
	rect3.setPosition(position.x-60, position.y-60);
	rect3.setFillColor(sf::Color::Blue);

	circle.setRadius(100);
	circle.setPosition(0, position.y - 200);
	circle.setFillColor(sf::Color::Yellow);


	if (!font.loadFromFile("font/arial.ttf")) std::cout << "Could not load font.\n";
	text.setFont(font);
	text.setString("Hello World !");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(500, 0);

	if(!backgroundTexture.loadFromFile("images/background.png")) std::cout << "Error while loading the background.\n";
	background.setScale(sf::Vector2f(position.x/960.f, position.y/540.f));
	background.setTexture(backgroundTexture);
	background2.setScale(sf::Vector2f(position.x / 960.f, position.y / 540.f));
	background2.setTexture(backgroundTexture);
	background2.setPosition(position.x, 0);
	
	if(!texture.loadFromFile("images/unicorn-sprite1.png")) std::cout << "Error while loading the sprite texture.\n";
	sprite.setTexture(texture);
	sprite.setPosition(400, 400);
	counter = 0;
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
	//Update window size
	sf::Vector2u position = window->getSize();

	//Update desired objects
	rect3.setPosition(position.x - 60, position.y - 60);
	circle.setPosition(0, position.y - 200);
	
	//Background
	sf::Vector2f b1_prevScale = background.getScale();
	sf::Vector2f b2_prevScale = background2.getScale();
	background.setScale(sf::Vector2f(position.x / 960.f, position.y / 540.f));
	background2.setScale(sf::Vector2f(position.x / 960.f, position.y / 540.f));
	if (b1_prevScale != background.getScale() && b2_prevScale != background2.getScale())
	{
		background.setPosition(0, 0);
		background2.setPosition(position.x, 0);
	}
	else if (background.getPosition().x <= -(float)position.x) background.setPosition(position.x, 0);
	else if (background2.getPosition().x <= -(float)position.x) background2.setPosition(position.x, 0);
	else
	{
		background.move(-(position.x / 60.f), 0);
		background2.move(-(position.x / 60.f), 0);
	}

	//Unicorn
	if (counter == 60)
	{
		texture.loadFromFile("images/unicorn-sprite2.png");
		++counter;
	}
	else if (counter == 120)
	{
		texture.loadFromFile("images/unicorn-sprite1.png");
		counter = 0;
	}
	else ++counter;
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(background);
	window->draw(background2);
	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);
	window->draw(circle);
	window->draw(text);
	window->draw(sprite);
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