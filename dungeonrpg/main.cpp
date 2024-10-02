#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// setup window class
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	// make a dog

	// get the texture
	sf::Texture dogTexture;
	if (!dogTexture.loadFromFile("assets/sprites/dog.png")) {
		// we did not find the image
		printf("Could not find image");
	}

	// get the sprite
	sf::Sprite dogSprite;
	dogSprite.setTexture(dogTexture);
	dogSprite.setScale(sf::Vector2f(3.0f, 3.0f));

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
			window.clear();

			// draw circle onto window
			window.draw(dogSprite);

			// render the window
			window.display();
		}
	}

	return 0;
}