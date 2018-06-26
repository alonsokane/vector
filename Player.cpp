#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(const sf::Vector2f &pos){
	texChar.loadFromFile("/Users/alonso/Desktop/thegame1.0/assets/images/The_Sad_Onion_Isaac.png");
	spChar.setTexture(texChar);
    spChar.setScale(0.5, 0.5);
	spChar.setPosition(pos);
}

void Player::update(float elapsed){
	// mover al personaje
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		spChar.move(-CHAR_VEL, 0);
	}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		spChar.move(CHAR_VEL, 0);
	}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        spChar.move(0,-CHAR_VEL);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        spChar.move(0,CHAR_VEL);
    }
	// limitar el movimiento del personaje a la ventana en el eje X y eje Y
	sf::Vector2f charPos = spChar.getPosition();
	if(charPos.x < 10) charPos.x = 10;
	if(charPos.x > 1040) charPos.x = 1040;//1120,1400
    if(charPos.y < 10) charPos.y = 10;
    if(charPos.y > 1300) charPos.y = 1300;
    
	spChar.setPosition(charPos);
}

void Player::draw(sf::RenderWindow &w){
	w.draw(spChar);
}

sf::Sprite &Player::getSprite(){
	return spChar;
}

bool Player::collidesWithEnemy(Enemy *b){
	sf::FloatRect charRect = getSprite().getGlobalBounds();
	sf::FloatRect enemyRect = b->getSprite().getGlobalBounds();
	return charRect.intersects(enemyRect);
}
