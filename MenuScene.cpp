#include "MenuScene.h"
#include <iostream>
#include "Game.h"
#include "PlayScene.h"
#include <sstream>
#include "Global.h"
using namespace std;

MenuScene::MenuScene(){
	if(!titleFont.loadFromFile("/Users/alonso/Desktop/thegame1.0/assets/fonts/Cave-Story.ttf")){
		cout<<"ERROR: no se encontro la fuente "<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("the binding ");
	titleText.setCharacterSize(220);
	// centra el texto
	titleText.setPosition(sf::Vector2f((940-titleText.getLocalBounds().width)/2.0, 0));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(sf::Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<Global::highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(150);
	scoreText.setPosition(sf::Vector2f((840-scoreText.getLocalBounds().width)/2.0, 450));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("Presionar ENTER para comenzar");
	pressStartText.setCharacterSize(80);
	pressStartText.setPosition(sf::Vector2f((940-pressStartText.getLocalBounds().width)/2.0, 1050));
}

void MenuScene::update(float elapsed){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Game::getInstance().switchScene(new PlayScene());
	}
}

void MenuScene::draw(sf::RenderWindow &w){
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(pressStartText);
}
