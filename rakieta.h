//
// Created by Christofair on 23.04.2019.
//
#include <SFML/Graphics.hpp>

#ifndef PONG_RAKIETA_H
#define PONG_RAKIETA_H


/**
 * Klasa Rakieta reprezentująca obiekt rakiety na ekranie.
 */
class Rakieta : public sf::RectangleShape
{
public:
    Rakieta(float x,
			float y,
			float szer,
			float dl)
		: sf::RectangleShape(sf::Vector2f(szer,dl)), lim_y(y), szybkosc(0.3)	{
		setPosition(x, y);
		setFillColor(sf::Color::White);
	}

    /**
     * Metoda ustawiająca pozycje na osi X.
     * @param x: współrzędna x.
     */
    void setPozX(float x);

	/**
	 * Metoda zwracająca pozycje na osi X
	 * @return: pos_x
	 */
	float getPozX();

    /**
     * Metoda ustawiająca pozycje na osi Y.
     * @param y: współrzędna y.
     */
    void setPozY(float y);

	/**
	 * Metoda zwracająca pozycje na osi Y.
	 * @return: pos_y
	 */
	float getPozY();

	/**
	 * Zwracanie szerokości rakiety w pikselach
	 * @return: dlugosc
	 */
	float getSzerokosc();

	/**
	 * Zwracanie długości rakiety w pikselach
	 * @return: szerokosc
	 */
	float getDlugosc();

	/**
     * Ustawianie szerokości rakiety w pikselach,
	 * pomimo tego że ta wielkość raczej jest stała.
	 * @param s: nowa szerokosc dla rakiety
	 */
	void setSzerokosc(float s);

	/**
	 * Ustawianie długości rakiety w pikselach
	 * @param d: nowa długość dla rakiety
	 */
	void setDlugosc(float d);

	/**
	 * Zwracanie szybkosci rakiety w trakcie trwania rozgrywki.
	 * @return : this->szybkosc.
	 */
	float getSzybkosc() const;

	/**
	 * powiadamia o przesunięciu rakiety do pewnego etapu
	 * @param lim: jest granicą do której maksymalnie
	 * przesunie się rakieta na osi OY.
	 */
	void moveTo(float lim);
	/**
	 * przesuwanie rakiety do ustalonego miejsca
	 */
	void move();

public:
	float lim_y;

private:
	float szybkosc;
};

#endif //PONG_RAKIETA_H