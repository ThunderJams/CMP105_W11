#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/hyrulefield.ogg", "hyrulefield");

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error\n";
	}

	text.setFont(font);
	text.setString("epic game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped) {
		audio->playMusicbyName("hyrulefield"); 
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}