#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace std;


sf::RectangleShape rect(sf::Vector2f(100, 100));

sf::Text text;
sf::Font font;


class Slider
{
private:
    int mCurrValue;
    int mMinValue;
    int mMaxValue;
    bool isPressed;

    sf::Vector2f mPos;
    sf::Vector2f mSliderPos;

    sf::RectangleShape bar = sf::RectangleShape(sf::Vector2f(120, 4));
    sf::RectangleShape slideBar = sf::RectangleShape(sf::Vector2f(4, 12));

public:
    Slider(int MinValue, int MaxValue)
    {
        mMinValue = MinValue;
        mMaxValue = MaxValue;
        mCurrValue = MinValue;
        isPressed = false;
        mSliderPos = {-1, -1};
    }

    void setPosition(const sf::Vector2f& position)
    {
        mPos = position;
        if (mSliderPos == sf::Vector2f {-1, -1})
            mSliderPos = position;
    }

    int get_mCurrValue() const
    {
        return mCurrValue;
    }


    void drag(sf::RenderWindow& window, sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
    		sf::Vector2f mousePos_Button = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    		if (event.mouseButton.button == sf::Mouse::Left)
            {
    			if (slideBar.getGlobalBounds().contains(mousePos_Button))
    				isPressed = true;

    			else if (bar.getGlobalBounds().contains(mousePos_Button))
                {
                    mSliderPos = {mousePos_Button.x, slideBar.getPosition().y};
    				if (mousePos_Button.x - mPos.x > 120)
    					mCurrValue = mMaxValue;
    				else
    					mCurrValue = mMinValue + (mousePos_Button.x - mPos.x) / 120. * (mMaxValue - mMinValue);
    			}
    			else
    				isPressed = false;
    		}
    	}

    	if (event.type == sf::Event::MouseButtonReleased)
    		isPressed = false;

        if (event.type == sf::Event::MouseMoved)
        {
    		sf::Vector2f mousePos_Move = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    		if (isPressed)
            {
    			if (mousePos_Move.x <= mPos.x + 120 && mousePos_Move.x >= mPos.x)
                {
    				mSliderPos = {mousePos_Move.x, mSliderPos.y};
    				mCurrValue = mMinValue + (mousePos_Move.x - mPos.x) / 120. * (mMaxValue - mMinValue);
    			}
    			else
                {
    				if (mousePos_Move.x > mPos.x + 120)
                    {
    					mSliderPos = {mPos.x + 120, mSliderPos.y};
    					mCurrValue = mMaxValue;
    				}
    				else if (mousePos_Move.x < mPos.x)
                    {
    					mPos = {mPos.x, mSliderPos.y};
    					mCurrValue = mMinValue;
    				}
    			}
    		}
        }
    }


    void draw(sf::RenderWindow& window)
    {
        bar.setFillColor({100, 100, 100});
        bar.setOutlineColor({0, 0, 0});
        bar.setOutlineThickness(1);
        bar.setPosition(mPos);
        window.draw(bar);

        slideBar.setFillColor({100, 100, 100});
        slideBar.setOutlineColor({0, 0, 0});
        slideBar.setOutlineThickness(1);
        slideBar.setOrigin(-2, 5);
        slideBar.setPosition(mSliderPos);    
        window.draw(slideBar);

        text.setString(to_string(mCurrValue));
        text.setFont(font);
        text.setCharacterSize(14); 
        text.setFillColor(sf::Color::Black);
        text.setPosition({mPos.x + 130, mPos.y - 8});
        window.draw(text);
    }
};


void BeautifulBackground(sf::RenderWindow& window)
{
    rect.setFillColor({255, 255, 255});
    rect.setOutlineColor({0, 0, 0});
    rect.setOutlineThickness(2);
    rect.setSize({1000, 25});
    rect.setPosition(3, 3);
    window.draw(rect);

    rect.setSize({600, 700});
    rect.setPosition(70, 50);
    window.draw(rect);

    rect.setFillColor({255, 0, 0});
    rect.setSize({25, 25});
    rect.setPosition(975, 3);
    window.draw(rect);

    text.setString("Peint :)");
    text.setFont(font);
    text.setCharacterSize(20); 
    text.setFillColor(sf::Color::Black);
    text.setPosition(5,0);
    window.draw(text);    
}


int main()
{
    const int width = 1000;
    const int height = 800;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(width, height), "My window", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    font.loadFromFile("Lobster-Regular.ttf");

    sf::CircleShape circle(50.0f);
    circle.setFillColor({200, 216, 200});

    Slider s(25, 200);
    Slider rs(0, 255);
    Slider gs(0, 255);
    Slider bs(0, 255);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear({200, 200, 200});

        BeautifulBackground(window);

        s.setPosition({750, 300});
        rs.setPosition({750, 400});
        gs.setPosition({750, 500});
        bs.setPosition({750, 600});

        s.drag(window, event);
        rs.drag(window, event);
        gs.drag(window, event);
        bs.drag(window, event);

        s.draw(window);
        rs.draw(window);
        gs.draw(window);
        bs.draw(window);

        circle.setRadius(s.get_mCurrValue());
        circle.setOrigin({circle.getRadius(), circle.getRadius()});
        circle.setPosition({350, 400});
        circle.setFillColor({rs.get_mCurrValue(), gs.get_mCurrValue(), bs.get_mCurrValue()});
        window.draw(circle);
        
        window.display();
    }


    return 0;
}