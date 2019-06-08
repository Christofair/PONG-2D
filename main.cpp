#include <cassert>
#include <chrono>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "menu.h"
#include "plansza.h"
#include "sterowanie.h"

#include "globals.h"

using namespace std;

int screen_width = 800;
int screen_height = 600;

STAN stan_gry = STATE::MENU;
Sterowanie stery;
Plansza plansza(screen_width, screen_height);
sf::RenderWindow window(
	sf::VideoMode(screen_width, screen_height), "xPONG 2D"
);


//fast and furious function - only for test
bool detectCollision(Ball& b, Rakieta& r, bool prawa)
{
	if(prawa)
		if(b.GetPosition().x + b.GetSize().x >= r.getPozX()
		   && (b.GetPosition().y >= r.getPozY() && b.GetPosition().y < r.getPozY() + r.getDlugosc())
		   ) return true;
		else return false;
	else
		if(b.GetPosition().x <= r.getPozX()+r.getSzerokosc()
		   && (b.GetPosition().y >= r.getPozY() && b.GetPosition().y < r.getPozY() + r.getDlugosc())
		   ) return true;
		else return false;
}

bool detectCollision(Ball& b, bool gorna)
{
	if(gorna)
		if(b.GetPosition().y <= 0) return true;
		else return false;
	else
		if(b.GetPosition().y + b.GetSize().y >= screen_height) return true;
		else return false;
}

struct Trasa
{
	Trasa(float _a, float _b, float(*f)(float a, float b, float x))
		: a(_a), b(_b), function_trace(f){}
	float a;
	float b;
	float (*function_trace)(float, float, float);
	float operator()(float x)
	{
		return function_trace(a, b, x);
	}
};

float prosta(float a, float b, float x)
{
	return a*x + b;
}

Trasa wylicz(int a)
{
	return Trasa(a, screen_height/2, prosta);
}

int main()
{
	float kierunek = 1;
	float a=2;
	float X = plansza.getWidth()/2;
	// wskazniki do wyswietlania
	Rakieta *r1{nullptr}, *r2{nullptr};
	IGracz *g1{nullptr}, *g2{nullptr};
	Ball *ball{nullptr};
	IMenu* current_menu{nullptr};
	Trasa trace = wylicz(a);

	sf::Event event{};
	//sf::Clock time;

	stan_gry = STAN::MENU;
	// początkowe warunki.
	stery.setMenu(new MainMenu());
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if(event.type == sf::Event::KeyPressed)
			{
				switch(stan_gry)
				{
					case STATE::PAUZA:
					case STATE::MENU:
						stery.menus(event);
						break;
					case STATE::GRA:
						stery.games(event);
						break;
				}
			}
		}


		//drawing
		window.clear(sf::Color::Black);
		current_menu = stery.getMenu();
		g1 = plansza.getGracz(1);
		g2 = plansza.getGracz(2);
		if(g1) r1 = g1->getRakieta();
		if(g2) r2 = g2->getRakieta();
		ball = plansza.getPilka();
		

		switch(stan_gry)
		{
			case STATE::PAUZA:
				window.draw(*dynamic_cast<sf::Drawable*>(current_menu));
				break;
			case STATE::MENU:
				plansza.deletePilka();
				plansza.deletePlayer(1);
				plansza.deletePlayer(2);
				X = screen_width/2;
				window.draw(*dynamic_cast<sf::Drawable*>(current_menu));
				break;
			case STATE::GRA:
			{
				if(r1 == nullptr || r2 == nullptr || ball == nullptr)
					throw("w grze musza byc te 3 obiekty inaczej to nie ma sensu.");
				else
				{
					stery.zwolnijMenu();
					//r1
					r1->move();
					window.draw(*r1);
					//r2
					r2->move();
					window.draw(*r2);
					//ball
					ball->Draw(&window);
					ball->SetPosition(X, trace(X));
					auto size = ball->GetSize().x;
					X += 0.1*kierunek;
					//if(X > screen_width- 2*size || X < size) kierunek *= -1;
					if(detectCollision(*ball, *r1, true)
					   || detectCollision(*ball, *r2, false)
					   || detectCollision(*ball, true)
					   || detectCollision(*ball, false)) kierunek *= -1;
					else
					{
						stan_gry = STAN::MENU;
					}	
					trace = wylicz(a);
				}
				break;
			}
		}

		window.display();
	}
	return 0;
}
