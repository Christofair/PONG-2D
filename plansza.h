#pragma once

#include "gracz.h"
#include "Ball.h"

struct KeysGlobalSet
{
	Klawisz up = Klawisz::Unknown;
	Klawisz down = Klawisz::Unknown;
	Klawisz left = Klawisz::Unknown;
	Klawisz right = Klawisz::Unknown;
};

/// Klasa Plansza jest manad�erem graczy oraz pi�ki.
/// Obiekt tej klasy jest wyexternowany w globals.h
/// Utrzymuje ona obiekty graczy w odpowiednim stanie.
class Plansza
{
public:
	/// Konstruktor przyjmuj�cy wymiary planszy.
	/// @param width - szerokosc planszy
	/// @param height - wysokosc planszy.
	Plansza(float _width, float _height) : width(_width), height(_height){}

	/// Pozwala innym obiektom otrzyma� potrzebnego im gracza, po numerze id.
	/// id oznacza numer gracza w klasie.
	/// zwraca nullptr je�eli id jest niew�a�ciwe.
	IGracz* getGracz(int id) const
	{
		switch(id)
		{
			case 1: return gracz1;
			case 2: return gracz2;
			default: return nullptr;
		}
	}


	/// Metoda tworzy instancje gracza w zale�no�ci od jego id
	/** Rozr�niono 3 rodzaje id.
	/// id == 1 - instancja Gracza1 - zawsze jako klasa Gracz dla cz�owieka.
	/// id == 2 - instancja gracza2 jako klasa Gracz dla cz�owieka
	/// id == 3 - instancja gracza2 jako klasa IGracz dla si
	/// zwraca instancje gracza, w przypadku niepowodzenia nullptr.
	 */
	IGracz* createPlayer(Rakieta* r, int id);

	/// Usuwanie instancji graczy. Rozr�nia tylko dwie liczby id: 1 oraz 2
	/** id = 1 usuwa gracza z numerem 1 w klasie,
	/// id = 2 analogicznie z numerem 2. */
	void deletePlayer(int id);

	/// Zwraca obiekt pilki dla klas.
	Ball* getPilka() const
	{
		return pilka;
	}

	/// Tworzy now� instancje dla pi�ki.
	/**
	/// @return: referencje do utworzonego obiektu.
	/// @return: w przypadku niepowodzenia nullptr.
	 */
	Ball* createPilka();

	/// Usuwa wewn�trzn� instancje pi�ki.
	void deletePilka();

public:
	float getWidth() const { return width; }
	float getHeight() const { return height; }

private:
	IGracz* gracz1;
	IGracz* gracz2;
	Ball* pilka;
private:
	float width;
	float height;
};
