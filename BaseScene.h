#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"
#include <vector>
using namespace std;



  // Representa una escena del juego.
  // Para crear una nueva clase de escena, heredar de esta clase
  // y redefinir el comportamiento de los metodos

class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// funcion que sera invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// funcion que sera invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);

	/// funcion que sera invocada para notificar a la escena de un evento
	virtual void process_event(const sf::Event &e);

	/// agrega un nuevo enemy a la escena
	void add(Entity *e);
	
	/// eliminar un enemy de la escena
	void remove(Entity *e);
	
private:
	vector<Entity *> entities;
	vector<Entity *> to_delete;
};

#endif

