#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


struct Ball
{
    float radius;
    sf::Vector2f position;
    sf::Vector2f velocity;
    int charge;
};


int main()
{
    srand(time(0));
    
    const int width = 1000;
    const int height = 800;
    const int n_balls = 100;

    const float delta_t = 0.1;


    sf::RenderWindow window(sf::VideoMode(width, height), "My window");

    window.setFramerateLimit(60);

    sf::CircleShape circle(50.0f);

    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].charge = rand() %550 - 255;
        balls[i].radius = 4 + rand() % 8;
        balls[i].position = {(float)(rand() % width), (float)(rand() % height)};
        balls[i].velocity = {(float)(rand() % 100 - 50), (float)(rand() % 100 - 50)};
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < n_balls; i++)
        {
            balls[i].position += balls[i].velocity * delta_t;

            
            if (balls[i].position.x < 0)
                balls[i].velocity.x *= -1;
            if (balls[i].position.x > width)
                balls[i].velocity.x *= -1;

            if (balls[i].position.y < 0)
                balls[i].velocity.y *= -1;
            if (balls[i].position.y > height)
                balls[i].velocity.y *= -1;

            
            circle.setRadius(balls[i].radius);
            if (balls[i].charge >= 0)
                circle.setFillColor({balls[i].charge, 0, 0});
            else
                circle.setFillColor({0, 0, abs(balls[i].charge)});

            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);
            
            
            window.draw(circle);
        }

        window.display();
    }

    return 0;
}