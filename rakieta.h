//
// Created by Christofair on 23.04.2019.
//
#include <SFML/Graphics.hpp>

#ifndef PONG_RAKIETA_H
#define PONG_RAKIETA_H


/**
 * Klasa Rakieta reprezentuje obiekt rakiety na ekranie.
 * TODO: Rozszerzy� klas� w celu zaimplementowania w silniku.
 */
class Rakieta
{
public:
	Rakieta(unsigned int x, unsigned int y) : pos_x(x), pos_y(y) {}

	/**
	 * Ustawia pozycje rakiety. Gdzie zostanie wy�wietlona na ekranie.
	 * @param x: pozycja na osi odci�tych.
	 * @param y: pozycja na osi rz�dnych.
	 */
	inline void setPozycja(unsigned int x, unsigned int y);

	/**
	 * Metoda ustawiaj�ca pozycje na osi X.
	 * @param x: wsp�rz�dna x.
	 */
	inline void setPozX(unsigned int x);

	/**
	 * Metoda ustawiaj�ca pozycje na osi Y.
	 * @param y: wsp�rz�dna y.
	 */
	inline void setPozY(unsigned int y);

private:
	unsigned int pos_x;
	unsigned int pos_y;
};


#endif //PONG_RAKIETA_H
