#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "BaseScene.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class PlayScene: public BaseScene{
private:
	Player *player;						/// el jugador
	vector<Enemy *> enemies;				/// arreglo con los enemy
	float minVel;						/// velocidad mínima de la proxima pelota que se creara
	sf::Clock timeToNewEnemy;			/// reloj para medir cuando crear una nueva pelota
	float score;						/// puntaje
	sf::Text scoreText;					/// texto para mostrar el puntaje
	sf::Font fontScoreText;				/// fuente del texto
	void createNewEnemy(float minVel);	/// agregar un nuevo enemy
	sf::Texture texBackground;			/// textura del fondo
	sf::Sprite spBackground;			/// sprite del fondo
	
public:
	PlayScene();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};

#endif

