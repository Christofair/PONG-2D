//
// Created by Christofair on 23.04.2019.
//
#include "rakieta.h"
#include <SFML/Window/Keyboard.hpp>


#ifndef PONG_IGRACZ_H
#define PONG_IGRACZ_H


class IGracz
{
public:
	IGracz() = default;
	IGracz(Rakieta* r) : rakieta(r) {}
    virtual ~IGracz() = default;

    /**
     * Pobranie rakiety od gracza i operowanie na niej.
     * Np wykonywanie operacji jak rysowanie na ekranie.
     * @return: Referencje obiektu rakiety.
     */
	virtual Rakieta* getRakieta() const { return rakieta; }

    /**
     * Przypiuje obiekt rakiety dla gracza.
     * @param r: obiekt rakiety do przypisania dla pola.
     */
	virtual void setRakieta(Rakieta* r) { rakieta = r; }
    /**
     * Zwraca wartosc flagi SI, w celu możliwości sprawdzenia czy dla klasy utworzyć nowy wątek czy nie.
     * domyślną wartością tej flagi jest true, co oznacza że obiekty są tworzone domyślnie dla sterowania przez PC
     * @return boolean from SI flag.
     */
	virtual bool checkSI() { return SI; }

protected:
	Rakieta* rakieta{nullptr};
	bool SI{true};
};


#endif //PONG_IGRACZ_H
