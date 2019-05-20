#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "rakieta.h"
#include "gracz.h"
#include "menu.h"

#pragma once
#ifndef GAMEAPP_H
#define GAMEAPP_H

class GameApp
{
public:
	//obiekty w grze kontrolowane przez klase aplikacji.
	IGracz* gracz1{nullptr};
	IGracz* gracz2{nullptr};
	Rakieta* rakieta1{nullptr};
	Rakieta* rakieta2{nullptr};
	IMenu* current_menu{nullptr};
	// Pilka* pilka;

	// Ustawienie �rodowiska gry.
	unsigned szybkosc_rakiety{5};
	unsigned screen_width{800};
	unsigned screen_height{600};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/// Typ STAN okre�la obecny stan naszego programu.
	/// W zale�no�ci od tego stanu dostosowywujemy odpowiednie dzia�ania.
	/// @param MENU: odpowiada za stan w kt�rym jest wy�wietlane Menu gry.
	/// @param GRA: odpowiada za stan, kiedy p�tla gry jest wykonywana i gracze mog� ze sob� rywalizowa�.
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	enum STAN
	{
		MENU, GRA
	};
	static STAN stan_gry;

	// zmienia obecny stan gry na nowy.
	static void zmienStan(STAN nowy_stan){
		if(nowy_stan == MENU || nowy_stan == GRA) //validacja stanu
			stan_gry = nowy_stan;
	}

	/// P�tla gry, wykonywana podczas g��wnej rozgrywki.
	/// @param w: okre�la cel na kt�rym zawarte w funkcji instrukcje maj� si� wy�wietla�.
	void gameloop(sf::RenderTarget& w){}
	/*
	{
		auto Y1 = rakieta1->getPozY();
		auto Y2 = rakieta2->getPozY();

		if(Y1 != rakieta1->lim_y)
		{
			if(Y1 < rakieta1->lim_y) rakieta1->setPozY(Y1+szybkosc_rakiety);
			else rakieta1->setPozY(Y1-szybkosc_rakiety);
		}
		else
		{
			if(rakieta1->lim_y > screen_height)
				rakieta1->setPozY(screen_height-rakieta1->getDlugosc/2);
			else
				rakieta1->setPozY((rakieta1->getDlugosc)/2);
		}
		if(Y2 != rakieta2->lim_y)
		{
			if(Y2 < rakieta2->lim_y) rakieta2->setPozY(Y2+szybkosc_rakiety);
			else rakieta2->setPozY(Y1-szybkosc_rakiety);
		}
		else
		{
			if(rakieta2->lim_y > screen_height)
				rakieta2->setPozY(screen_height - rakieta2->getDlugosc/2);
			else
				rakieta2->setPozY(rakieta2->getDlugosc/2);
		}
		w.draw(*rakieta1);
		w.draw(*rakieta2);
	}
	*/

	/// Funkcja menu wstawiona do bloku kodu kt�ry jest odpowiedzialny za wy�wietlanie menu na ekranie.
	/// @param w: okre�la cel na kt�rym zawarte w funkcji instrukcje b�d� si� wy�wietla�.
	void menu_instr(sf::RenderTarget& w){
		if(auto menu = dynamic_cast<MainMenu*>(current_menu))
		{
			w.draw(*menu);
		}
		else if(auto menu = dynamic_cast<PauseMenu*> (current_menu))
		{
			w.draw(*menu);
		}
	}

	/// Funkcja reset jest funkcj� przywracaj�c� stan do ustawien pocz�tkowych,
	/// resetuje ona globalne zasoby ww w programie.
	void reset(){
		if(gracz1 != nullptr){ delete gracz1; gracz1 = nullptr; }
		if(rakieta1 != nullptr){ delete rakieta1; rakieta1 = nullptr; }
		if(gracz2 != nullptr){ delete gracz2; gracz2 = nullptr; }
		if(rakieta2 != nullptr){ delete rakieta2; gracz1 = nullptr; }
		if(current_menu != nullptr){ delete current_menu; current_menu = nullptr; }
	}

	~GameApp() { reset(); }


};


#endif //GAMEAPP_H