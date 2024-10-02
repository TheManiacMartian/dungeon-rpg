#include <SFML/Graphics.hpp>

int main()
{
	// setup window class
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	// make a circle and make it blue
	sf::CircleShape coolCircle(200.0f);
	coolCircle.setFillColor(sf::Color::Blue);

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
			window.draw(coolCircle);

			// render the window
			window.display();
		}
	}

	return 0;
}