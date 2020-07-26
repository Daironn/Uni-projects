#include "pch.h"
#include "Menu.h"
#include "SubMenu.h"
#include "Square.h"
#include "Sorting_array.h"
#include <map>
#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>

template<class T>
void full_array(Sorting_array<T>* obj); //funkcja napełniająca tablice

bool isnotsorting = true; //bool czy odebrać kontrolę czy nie

Info Menu::info; //inicjowanie zmiennej statycznej


int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Bubble Sorting!"); //utworzenie okna o rozmiarach 1200x900 i napisie na pasku

	std::multimap<std::string, Menu*> menus; //tablica różnych typów dziedziczących po sobie

	Menu First;
	SubMenu second;

	menus.insert(std::pair<std::string, Menu*>("1", &First)); //multimap przechowujacy zmienne roznych typów
	menus.insert(std::pair<std::string, SubMenu*>("22", &second)); // dzieki temu mogę zmieniać zmienna statyczną
																   //uzywajac obu indeksow i wywolywac rozne funcke
																	//zaleznie od wybranego klucza
	Sorting_array<BLUE::Square> blue;
	Sorting_array<WHITE::Square> white;

	full_array(&blue);
	full_array(&white);

	//linijki powyżej to przygotowanie wszystkiego co będzie potrzebne do działania programu

	menus.find("22")->second->setMenu(1);

		while (window.isOpen())
		{
			//Wyświetlanie nadmenu/menu głownego, jak kto woli
			if (menus.find("1")->second->isEnded() == false) { //if powstrzymujący przed ciąglym wyśiwetlaniem menu

				system("CLS");
				menus.find("1")->second->showMenu(); //używanie metodu showMenu z klasy MENU
			}			
			menus.find("1")->second->changeend(true);


			sf::Event event;
			while (window.pollEvent(event))
			{

				switch (event.type) {
					//To jest w sumie mało potrzebne ale wygodne, zamyka okno iksikiem
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:


					//Tutaj sprawdza czy menu czy submenu
					//*używanie dwóch innych zmiennych z rzutowaniem w góre

					if (menus.find("1")->second->getMenu() == 1) {

						//wybiera kolor
						if (isnotsorting == true) {
						if (event.key.code == sf::Keyboard::Num1) {

								//*aby sprawdzić stan obiektu statycznego
								if (menus.find("22")->second->getColour() == 1) {

									system("CLS");
										std::cout << "SYMULACJA TRWA, NA TEN CZAS KONTROLA JEST WYLACZONA" << std::endl;
										isnotsorting = false;
										white(window); //wywolanie operatorem funkcji

										system("CLS");
										std::cout << "SYMULACJA ZAKONCZONA, NACISNIJ ENTER ZEBY WROCIC DO MENU" << std::endl;


								}

								if (menus.find("22")->second->getColour() == 2) {

									system("CLS");
									std::cout << "SYMULACJA TRWA, NA TEN CZAS KONTROLA JEST WYLACZONA" << std::endl;
									isnotsorting = false;
									blue(window);

									system("CLS");
									std::cout << "SYMULACJA ZAKONCZONA, NACISNIJ ENTER ZEBY WROCIC DO MENU" << std::endl;

								}
							}
						
						//Przechodzenie do submenu
						if (event.key.code == sf::Keyboard::Num2) {

							menus.find("22")->second->setMenu(2);

						}
						if (event.key.code == sf::Keyboard::Num3) {

							menus.find("22")->second->setMenu(3);

						}
						if (event.key.code == sf::Keyboard::Num4) {

							menus.find("22")->second->setMenu(4);
						}
					}
						if (event.key.code == sf::Keyboard::Escape) {

							window.close();
						}
						if (event.key.code == sf::Keyboard::Enter) {

							menus.find("22")->second->setMenu(1);
							menus.find("1")->second->changeend(false);

							isnotsorting = true;
							menus.find("22")->second->incraseS();
						}
						break;
					}

					//Submenu o zmianie koloru
					 if(menus.find("1")->second->getMenu() == 2){

						 menus.find("22")->second->showMenu(); //używanie metodu showMenu z klasy SubMenu, polimorfizm


						if (event.key.code == sf::Keyboard::Num1) {

							menus.find("22")->second->setColour(1);
							std::cout << "Kolor zostal zmieniony na bialy";
						}

						if (event.key.code == sf::Keyboard::Num2) {

							menus.find("22")->second->setColour(2);

							std::cout << "Kolor zostal zmieniony na niebieski";
						}

						if (event.key.code == sf::Keyboard::Escape) {

							menus.find("22")->second->setMenu(1);
							menus.find("22")->second->incraseC();
							menus.find("1")->second->changeend(false);
						}
						break;
					}

					 //submenu o zmianie kierunku
					 if (menus.find("1")->second->getMenu() == 3) {

						 menus.find("22")->second->showMenu();
						 if (event.key.code == sf::Keyboard::Num1) {

							 menus.find("22")->second->setSide(2);
							 blue.changeSide(2);
							 white.changeSide(2);

							 std::cout << "Od teraz sortowanie jest w prawo";

						 }

						 if (event.key.code == sf::Keyboard::Num2) {


							 blue.changeSide(1);
							 white.changeSide(1);
							 menus.find("22")->second->setSide(1);
							 std::cout << "Od teraz sortowanie jest w lewo";

						 }
						 if (event.key.code == sf::Keyboard::Escape) {

							 menus.find("22")->second->setMenu(1);
							 menus.find("22")->second->incraseSC();
							 menus.find("1")->second->changeend(false);
						 }
						 break;
					 }

					 //submenu dające informacje
					 if (menus.find("1")->second->getMenu() == 4) {

						 menus.find("22")->second->showMenu();

						 if (event.key.code == sf::Keyboard::Escape) {

							 menus.find("22")->second->setMenu(1);
							 menus.find("1")->second->changeend(false);
						 }
						 break;
					 }
					
				}
			}
			window.display();
		}
	return 0;
}

//funckja napelniajaca nasza tablice
template<class T>
void full_array(Sorting_array<T>* obj)
{
	for (int i = 0; i < 118; i++) {

		int random = rand() % 500;
		T obja(random);
		obj->push_back(obja);

	}
}
