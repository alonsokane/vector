#include "Game.h"
#include "PlayScene.h"
#include "MenuScene.h"
using namespace sf;

int main(int argc, char *argv[]){
	BaseScene *scene = new MenuScene();
	Game &g = Game::create(sf::VideoMode(1120,1400), scene, "el sacrificio de jofri");
	g.run();
	
	return 0;
}

