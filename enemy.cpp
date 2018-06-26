#include "Enemy.h"


Enemy::Enemy(){
	texEnemy.loadFromFile("/Users/alonso/Desktop/thegame1.0/assets/images/Delirium.png");
	spEnemy.setTexture(texEnemy);
    spEnemy.setScale(0.4, 0.4);
	
	srand(time(0));
	spEnemy.setPosition(rand()%1000, rand()%1200);//1120,1400
	velEnemy.x = 2+rand()%3;
	velEnemy.y = 2+rand()%3;
}

void Enemy::update(float elapsed){
	// mover la pelota
	spEnemy.move(velEnemy);
	
	// limitar el movimiento del enemigo en la ventana
	sf::Vector2f EnemyPos = spEnemy.getPosition();

	if(EnemyPos.x < 10){
		EnemyPos.x = 10;
		velEnemy.x *= -1;
	}
	if(EnemyPos.x > 1040){
		EnemyPos.x = 1040;
		velEnemy.x *= -1;
	}
	if(EnemyPos.y < 10){
		EnemyPos.y = 10;
		velEnemy.y *= -1;
	}
	if(EnemyPos.y > 1300){
		EnemyPos.y = 1300;
		velEnemy.y *= -1;
	}
	spEnemy.setPosition(EnemyPos);
}

void Enemy::draw(sf::RenderWindow &w){
	w.draw(spEnemy);
}

sf::Sprite &Enemy::getSprite(){
	return spEnemy;
}
