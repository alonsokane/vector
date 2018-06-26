#include "PlayScene.h"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <sstream>
#include "Global.h"
#include "MenuScene.h"
#include "Game.h"
using namespace std;

PlayScene::PlayScene(){
	player = new Player(sf::Vector2f(304, 306));
	add(player);
	
	minVel = 150;
	createNewEnemy(minVel);
	timeToNewEnemy.restart();
	if(!fontScoreText.loadFromFile("/Users/alonso/Desktop/thegame1.0/assets/fonts/Cave-Story.ttf")){
		cout<<"ERROR: no se encontro la fuente "<<endl;
	}
	
	texBackground.loadFromFile("/Users/alonso/Desktop/thegame1.0/assets/images/im1.png");
	spBackground.setTexture(texBackground);
    spBackground.setScale(2, 2.5);
    
	
	score = 0;
	scoreText.setFont(fontScoreText);
	scoreText.setColor(sf::Color::White);
}


void PlayScene::update(float elapsed){
	// actualiza al personaje
	BaseScene::update(elapsed);
	
	// crear nueva pelota
	if(timeToNewEnemy.getElapsedTime().asSeconds()>10){
		minVel += 50;
		createNewEnemy(minVel);
		timeToNewEnemy.restart();
	}
	
	// revisa colisiones entre el personaje y las pelotas
	for(const auto &Enemy: enemies){
		if(player->collidesWithEnemy(Enemy)){
			if(score > Global::highScore){
				Global::highScore = score;
			}
			Game::getInstance().switchScene(new MenuScene());
		}
	}
	
	// actualiza el puntaje
	score += elapsed;
	stringstream tmp;
	tmp<<"SCORE: "<<int(score);
	scoreText.setString(tmp.str());
}

void PlayScene::draw(sf::RenderWindow &w){
	w.draw(spBackground);
	BaseScene::draw(w);
	w.draw(scoreText);
}

void PlayScene::createNewEnemy(float minVel){
	Enemy *b = new Enemy();
	enemies.push_back(b);
	add(b);
}

