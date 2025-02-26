#include <iostream>
#include <cmath>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;


// Вспомогательные функции, вычисляет расстояние между двумя точками
float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return sqrtf((start.x - finish.x)*(start.x - finish.x) + (start.y - finish.y)*(start.y - finish.y));
}


// Вспомогательные функции, рисует линию на холсте окна window
void drawLine(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f finish, sf::Color color = sf::Color::White)
{
    sf::Vertex line_vertices[2] = {sf::Vertex(start, color), sf::Vertex(finish, color)};
    window.draw(line_vertices, 2, sf::Lines);
}


// Вспомагательный класс, описывет шарик
// position - положение шарика; radius - радиус
// is_chosen - говорит о том, выбран ли шарик или нет
struct Ball
{
    sf::Vector2f position;
    float radius;
    bool isChoosen;
    vector <int> color;

    Ball(sf::Vector2f position, float radius) : position(position), radius(radius)
    {
        color = {255, 255, 255};
        isChoosen = false;
    }

    // Метод, который рисует шарик на холстек окна window
    void draw(sf::RenderWindow& window) const
    {
        // Тут рисуем белый кружочек
        sf::CircleShape circle(radius);
        circle.setFillColor({color[0], color[1], color[2]});
        circle.setOrigin({radius, radius});
        circle.setPosition(position);
        window.draw(circle);

        // Если шарик выбран
        if (isChoosen) {
            // То рисуем "уголки"
            const float fraction = 0.7;
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - radius, position.y + radius*fraction});
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - fraction * radius, position.y + radius});

            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius, position.y + radius*fraction});
            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius*fraction, position.y + radius});

            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius*fraction, position.y - radius});
            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius, position.y - radius*fraction});

            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius*fraction, position.y - radius});
            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius, position.y - radius*fraction});
        }
    }
};


bool isBallInSelectRect(Ball& b, sf::Vector2f start, sf::Vector2f finish)
{
    auto x = b.position.x;
    auto y = b.position.y;
    auto r = b.radius;

    return (x + r <= max(start.x, finish.x)) and (x - r >= min(start.x, finish.x))
           and
           (y + r <= max(start.y, finish.y)) and (y - r >= min(start.y, finish.y));
}


bool isAnyChosen(std::list<Ball> balls) //выделен ли хотя бы один круг
{
    for (Ball& b : balls)
    {
        if (b.isChoosen)
            return true;
    }

    return false;
}


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Select, Move, Delete!", sf::Style::Default, settings);
    window.setFramerateLimit(60);


    // Создаём связный список из шариков
    // Связный список -- потому что нам нужно будет постоянно удалять и добавлять в этот список
    std::list<Ball> balls;
    balls.push_back(Ball({200, 200}, 26));
    balls.push_back(Ball({400, 300}, 20));
    balls.push_back(Ball({500, 100}, 16));
    balls.push_back(Ball({200, 400}, 18));
    balls.push_back(Ball({350, 150}, 22));
    balls.push_back(Ball({750, 400}, 21));


    // Создаём прямоугольник выделения
    // Обратите внимание на четвёртый параметр sf::Color(150, 150, 240, 50)
    // Это alpha - прозрачность      0 = полностью прозрачный     255 = непрозрачный
    sf::RectangleShape selectionRect;
    selectionRect.setFillColor(sf::Color(150, 150, 240, 50));
    selectionRect.setOutlineColor(sf::Color(200, 200, 255));
    selectionRect.setOutlineThickness(1);


    // Специальная переменная, которая будет показывать, что мы находимся в режиме выделения
    bool isSelecting = false;


    sf::Vector2f start =  {0, 0};
    sf::Vector2f finish = {0, 0};
    sf::Vector2f prevMove = {0, 0};
    bool isNowMoving = false; //перемещаются ли сейчас шары шариком?


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                
                // Если мы находимся в режиме выделения, то меняем прямоугольник выделения
                if (isSelecting) {
                    selectionRect.setSize(mousePosition - selectionRect.getPosition());
                }
            }


            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Если не зажат левый Ctrl, то все выделения снимаются
                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                        for (Ball& b : balls) {
                            b.isChoosen = false;
                        }
                    } 

                    bool anyChosen = false; //Выделен ли хотя бы один шарик?
                    // Проверяем попал ли курсор в какой-нибудь шарик, если попал - выделяем
                    for (Ball& b : balls) {
                        if (distance(mousePosition, b.position) < b.radius) {
                            b.isChoosen = true;
                            anyChosen = true;
                            break;
                        }
                    }
                    if (!anyChosen)
                    {
                        // Задаём новое положения прямоугольника выделения
                        isSelecting = true;
                        sf::Vector2f start = mousePosition;
                        selectionRect.setPosition(start);
                        selectionRect.setSize({0, 0});
                    }

                    // ЛКМ + левый Alt - добавляем новый случайный шарик
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                    {
                        isSelecting = false;
                        balls.push_back(Ball(mousePosition, 5 + rand() % 40));
                    }
                    
                }
            }


            // При отпускании кнопки мыши выходим из режима выделения
            if (event.type == sf::Event::MouseButtonReleased)
            {
                isSelecting = false;
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                for (Ball& b : balls)
                {
                    if (b.isChoosen)
                        b.color = {rand() % 255, rand() % 255, rand() % 255};
                }
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
            {
                auto iter = balls.begin();

                for (auto iter = balls.begin(); iter != balls.end(); iter++)
                {
                    if (iter->isChoosen)
                        balls.erase(iter);
                }
            }


             if (isSelecting)
            {
                finish = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                for (Ball& b : balls)
                {
                    if (isBallInSelectRect(b, start, finish))
                        b.isChoosen = true;
                    else
                        b.isChoosen = false;
                }
            }


            if (isAnyChosen(balls) and event.type == sf::Event::MouseButtonPressed and !isNowMoving)
            {
                isNowMoving = true;
                prevMove = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            }

            if (isNowMoving and event.type == sf::Event::MouseMoved and event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f nextMove = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                for (Ball& b : balls)
                {
                    if (b.isChoosen)
                        b.position += nextMove - prevMove;
                }

                prevMove = nextMove;
            }
        }

       

        window.clear(sf::Color::Black);
        // Рисуем все шарики
        for (Ball& b : balls)
        {
            b.draw(window);
        }
        // Рисуем прямоугольник выделения
        if (isSelecting)
        {
            window.draw(selectionRect);
        }
        window.display();
    }

    return 0;
}