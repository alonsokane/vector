#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

class Enemy: public Entity{
public:
	Enemy();
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w) override;
	sf::Sprite &getSprite();
private:
	sf::Texture texEnemy;
	sf::Sprite spEnemy;
	sf::Vector2f velEnemy;
};

#endif

