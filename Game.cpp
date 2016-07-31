#include "Game.h"

void Game::Start(void)
{
    VideoMode VMode(windowWidth, windowHeight, 32);
    RenderWindow Window(VMode, "Blank");
    Window.setFramerateLimit(60);
    Window.setPosition(Vector2i(300,40));

    gameObject background("Images/black.png", 0, 0);

    Event event;
    while (Window.isOpen())
    {
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    Window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape)
                        Window.close();
                    break;
                default:
                    break;
            }
        }

        background.showGameObject(Window);

        Window.display();
    }
}
