#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <string>

class Display
{
    public:
        Display(int width, int height, const std::string& title);
        bool isOpen();
        void ProcessEvents();
        void Clear(float r, float g, float b, float a);
        void Update();

        int error;

        virtual ~Display();
    protected:
    private:
        Display(const Display& other);
        Display& operator=(const Display& other);

        sf::Texture texture;
        sf::Sprite sprite;
        sf::RenderWindow* m_window;
};

#endif // DISPLAY_H
