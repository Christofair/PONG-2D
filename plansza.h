#pragma once

#include "gracz.h"
// #include "pilka.h"

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
	Plansza(){}

	/// Pozwala innym obiektom otrzyma� potrzebnego im gracza, po numerze id.
	/// id oznacza numer gracza w klasie.
	/// zwraca nullptr je�eli id jest niew�a�ciwe.
	IGracz* getGracz(int id) const;

	/// Metoda tworzy instancje gracza w zale�no�ci od jego id
	/// Rozr�niono 3 rodzaje id.
	/// id == 1 - instancja Gracza1 - zawsze jako klasa Gracz dla cz�owieka.
	/// id == 2 - instancja gracza2 jako klasa Gracz dla cz�owieka
	/// id == 3 - instancja gracza2 jako klasa IGracz dla si
	/// zwraca informacje instancje gracza, w przypadku niepowodzenia nullptr.
	IGracz* createPlayer(Rakieta* r, int id);

	/// Usuwanie instancji graczy. Rozr�nia tylko dwie liczby id: 1 oraz 2
	/// id = 1 usuwa gracza z numerem 1 w klasie,
	/// id = 2 analogicznie z numerem 2.
	void deletePlayer(int id);

	//Pilka* getPilka() const;
	//Pilka* setPilka(Pilka* pilka);

public:

private:
	IGracz* gracz1;
	IGracz* gracz2;
	//Pilka pilka;

};
