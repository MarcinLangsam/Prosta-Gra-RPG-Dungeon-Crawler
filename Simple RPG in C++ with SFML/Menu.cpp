#include "Menu.h"

void Menu::main_menu(sf::Font font,sf::RenderWindow &window)
{
    new_game_text.setFont(font);
    exit_text.setFont(font);
    instrucion_text.setFont(font);
    new_game_text.setCharacterSize(80);
    exit_text.setCharacterSize(80);
    instrucion_text.setCharacterSize(30);
    new_game_text.setString("Nowa gra");
    exit_text.setString("Wyjscie");
    instrucion_text.setString("Zbierz jak nawiecej zlota zanim zostaniesz pokonany\nPoruszaj sie STRZALKAMI lub WASD\nW walce uzywaj myszki\nWchodz w interakcje z obiketami dotykajc ich\nENTER aby pokazc statsu oraz ESC aby go zamknac\nObiekty:\nSkrzynia: zapewnia złoto bądź misktury\nFontanna: Przywraca zdrowie i mane\nKsiazka: uczy nowych zaklec\nGrobowiec: Zapewnia lepsze przedmioty ale\npilnuje ich przeciwnik");
    new_game.setPosition(100,20);
    exit.setPosition(800,20);
    new_game_text.setPosition(115,22);
    exit_text.setPosition(815,22);
    instrucion_text.setPosition(100,315);
    window.draw(new_game);
    window.draw(exit);
    window.draw(new_game_text);
    window.draw(exit_text);
    window.draw(instrucion_text);
}

int Menu::menu_click(sf::Sprite &a, sf::RenderWindow &window)
{   
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    sf::Event event;
    if(a.getGlobalBounds().contains(translated_pos))
    {
        while (window.pollEvent(event)) 
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    return 1;
                break;
            }
        }
    }
    return 0;
}