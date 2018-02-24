#include <SFML/Graphics.hpp>
#include "display.h"

int main()
{
    Display display(800, 600, "Hello World!");

    // Load a sprite to display
    if (display.error)
        return display.error;

	// Start the game loop
    while (display.isOpen())
    {
      display.ProcessEvents();
      display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
      display.Update();
    }

    return EXIT_SUCCESS;
}
