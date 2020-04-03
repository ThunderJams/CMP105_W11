#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error\n";
	}

	text.setFont(font);
	text.setString("cool title screen, press enter to play");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

Menu::~Menu()
{

}

// handle user input
void Menu::handleInput(float dt)
{

}

// Update game objects
void Menu::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter)) {
		audio->stopAllMusic();
		gameState->setCurrentState(State::LEVEL);
	}
	
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}

	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped) {
		audio->playMusicbyName("cantina");
	}
}

// Render Menu
void Menu::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}