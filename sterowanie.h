//
// Created by Christofair on 23.04.2019.
//

#include <SFML/Window/Event.hpp>
#include "gracz.h"
#include "IMenu.h"

#ifndef PONG_STEROWANIE_H
#define PONG_STEROWANIE_H

/**
 * Klasa sterowanie czyli klasa odpowiadaj�ca za interakcje
 * z u�ytkownikiem. Opakowuje ona dane zdarzenie i przekazuje
 * je odpowiednio dla danej sytuacji w programie. Klasa ta jest
 * potrzebna ze wzgl�du na sterowanie za pomoc� zdarze�. W ka�dej
 * chwili mo�na t� klas� napisa� od nowa, aby wspiera�a inny rodzaj
 * biblioteki. Wywo�uje ona odpowiednie funkcje zwrotne do zdarze�.
 */
class Sterowanie
{
public:
	enum STAN
	{
		MENU, GRA
	};

	/**
	 *
	 * @param init_state
	 */
	Sterowanie(STAN init_state) : stan(init_state) {}

	/**
	 * Operator wywo�ania pe�ni role funktora
	 * klasa wykonuje odpowiednie instrukcje ze wzgl�du
	 * na przekazany obiekt zdarzenia.
	 * @param e: ww obiekt zdarzenia.
	 */
	void operator()(sf::Event e);

	/**
	 * Zmienia warto�� pola stanu, kt�ry okre�la aktualny stan
	 * rozgrywki.
	 * @param s: jest innym stanem, kt�ry chcemy ustawi�.
	 */
	void zmienStan(STAN s);

	/**
	 * Ustawia referencje graczy do kt�rych sterowanie si� b�dzie odnosi�o.
	 * @param g: jest obiektem gracza, na kt�rego rachunek b�dziemy wywo�ywa� metody.
	 * @param who: jest numerem gracza w celu rozr�nienia dla klasy sterowanie.
	 */
	void setGracz(Gracz *g, int who);

	/**
	 * Przypisuje menu do kt�rego obiekt b�dzie wysy�a� komunikaty.
	 * @param m: jest wska�nikiem na to menu.
	 */
	void setMenu(IMenu* m);

private:
	STAN stan{ STAN::MENU };
	Gracz* gracz1{ nullptr };
	Gracz* gracz2{ nullptr };
	IMenu* imenu{ nullptr };
};


#endif //PONG_STEROWANIE_H
