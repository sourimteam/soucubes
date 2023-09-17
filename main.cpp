/**

    @file      main.cpp
    @brief     Start file of game
    @details   ~
    @author    SourimTeam
    @date      15.09.2023
    @copyright © SourimTeam, 2023. All right reserved.

**/

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Colors.h"
#define CUBE_SIZE            10
#define BLOCK_WIDTH          1
#define BLOCK_HEIGHT         2
#define getCubeSize(a)       CUBE_SIZE * a
#define SCREEN_WIDTH_CUBES   80
#define SCREEN_HEIGHT_CUBES  25
#define SCREEN_WIDTH_BLOCKS  SCREEN_WIDTH_CUBES * BLOCK_WIDTH
#define SCREEN_HEIGHT_BLOCKS SCREEN_HEIGHT_CUBES * BLOCK_HEIGHT
#define SCREEN_WIDTH         getCubeSize(SCREEN_WIDTH_CUBES * BLOCK_WIDTH)
#define SCREEN_HEIGHT        getCubeSize(SCREEN_HEIGHT_CUBES * BLOCK_HEIGHT)

std::vector<std::vector<sf::Color>> map(SCREEN_WIDTH_BLOCKS, std::vector<sf::Color>(SCREEN_HEIGHT_BLOCKS, sf::Color::Transparent));

int main() {
    for (int x = 0; x < SCREEN_WIDTH_CUBES; x++)
        for (int y = SCREEN_HEIGHT_CUBES / 2; y < SCREEN_HEIGHT_CUBES; y++)
            map[x][y] = COLOR_BROWN;
    sf::RectangleShape player{};
    sf::Vector2i player_pos{SCREEN_WIDTH_CUBES / 2, SCREEN_HEIGHT_CUBES / 2 - 1};
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SouCubes 1.1");
    player.setFillColor(sf::Color::Green);
    player.setSize(sf::Vector2f(getCubeSize(BLOCK_WIDTH), getCubeSize(BLOCK_HEIGHT)));
    player.setOrigin(sf::Vector2f(0, 0));
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::D && player_pos.x * BLOCK_WIDTH < SCREEN_WIDTH / CUBE_SIZE - BLOCK_WIDTH)
                    player_pos.x++;
                else if (event.key.scancode == sf::Keyboard::Scan::A && player_pos.x > 0)
                    player_pos.x--;
                else if (event.key.scancode == sf::Keyboard::Scan::W && player_pos.y > 0)
                    player_pos.y--;
                else if (event.key.scancode == sf::Keyboard::Scan::S && player_pos.y * BLOCK_HEIGHT < SCREEN_HEIGHT / CUBE_SIZE - BLOCK_HEIGHT)
                    player_pos.y++;
                else {
                    switch (event.key.scancode) {
                        case sf::Keyboard::Num0:
                            map[player_pos.x][player_pos.y] = sf::Color::Red;
                            break;
                        case sf::Keyboard::Num1:
                            map[player_pos.x][player_pos.y] = sf::Color::Green;
                            break;
                        case sf::Keyboard::Num2:
                            map[player_pos.x][player_pos.y] = sf::Color::Blue;
                            break;
                        case sf::Keyboard::Num3:
                            map[player_pos.x][player_pos.y] = COLOR_BROWN;
                            break;
                        case sf::Keyboard::Num4:
                            map[player_pos.x][player_pos.y] = sf::Color::Black;
                            break;
                        case sf::Keyboard::Num5:
                            map[player_pos.x][player_pos.y] = sf::Color::White;
                            break;
                        case sf::Keyboard::Num6:
                            map[player_pos.x][player_pos.y] = sf::Color::Yellow;
                            break;
                        case sf::Keyboard::Num7:
                            map[player_pos.x][player_pos.y] = COLOR_VIOLET;
                            break;
                        case sf::Keyboard::Num8:
                            map[player_pos.x][player_pos.y] = COLOR_GRAY;
                            break;
                        case sf::Keyboard::Num9:
                            map[player_pos.x][player_pos.y] = sf::Color::Transparent;
                            break;
                    }
                }
            }
        }

        player.setPosition(sf::Vector2f(getCubeSize((float)player_pos.x) * BLOCK_WIDTH, getCubeSize((float)player_pos.y) * BLOCK_HEIGHT));
        window.clear(COLOR_SKY);
        for (int x = 0; x < SCREEN_WIDTH_BLOCKS; x++) {
            for (int y = 0; y < SCREEN_HEIGHT_BLOCKS; y++) {
                sf::RectangleShape block{};
                block.setFillColor(map[x][y]);
                block.setSize(sf::Vector2f(getCubeSize(BLOCK_WIDTH), getCubeSize(BLOCK_HEIGHT)));
                block.setOrigin(sf::Vector2f(0, 0));
                block.setPosition(sf::Vector2f(getCubeSize((float)x) * BLOCK_WIDTH, getCubeSize((float)y) * BLOCK_HEIGHT));
                window.draw(block);
            }
        }
        window.draw(player);
        window.display();
    }

    return 0;
}