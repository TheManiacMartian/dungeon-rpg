#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfx/BitmapText.h"

int main()
{
	// setup window class
	sf::RenderWindow window(sf::VideoMode(480, 320), "Dungeon RPG Game");

	// create view
	sf::View gameView(sf::FloatRect(0.f, 0.f, 480.f, 320.f));
	
	// activate view on window
	window.setView(gameView);

	// testing out text

	// load font
	sfx::BitmapFont pixelFont;
	if (!pixelFont.loadFromFile("assets/fonts/monogram_new.png")) {
		// error, font not found
		printf("Could not find font.");
	}
	else {
		printf("Font was found.");

	}
	// set glyph size of font
	pixelFont.setGlyphSize(6, 12);

	// create text from font
	sfx::BitmapText helloWorldText;
	
	// set text properties
	helloWorldText.setPosition(sf::Vector2f(5.f, 240.f));
	helloWorldText.setFont(pixelFont);
	helloWorldText.setString("Hello World! This is a test.");
	helloWorldText.setCharacterScale(2);
	helloWorldText.setTabSize(2);
	helloWorldText.setFillColor(sf::Color::White);
	

	// make a dog

	// get the texture
	sf::Texture dogTexture;
	if (!dogTexture.loadFromFile("assets/sprites/dog.png")) {
		// we did not find the image
		printf("Could not find image.");
	}
	else
	{
		printf("the dog was found.");

	}

	// get the sprite
	sf::Sprite dogSprite;
	dogSprite.setTexture(dogTexture);
	dogSprite.setScale(sf::Vector2f(1.f, 1.f));

	// loop as long as window is open
	while (window.isOpen())
	{
		// create an event for the window to poll, this will give us messages from the window
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
			{
				// if we recieve a signal to close the window 
				// (alt+f4 or the x window button is pressed), close the window
				window.close();
			}

			// clear window pixels
			window.clear(sf::Color::Blue);

			// draw dog onto window
			window.draw(dogSprite);

			// draw text onto window
			window.draw(helloWorldText);

			// render the window
			window.display();
		}
	}

	return 0;
}