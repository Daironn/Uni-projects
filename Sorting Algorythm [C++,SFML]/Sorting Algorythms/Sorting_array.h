#pragma once
#include <vector>
#include "Shape.h"
#include "Sorting_array.cpp"
#include <SFML/Graphics.hpp>
template<class T>
class Sorting_array //klasa szablonowa, oparta na wektorze, ktora bedzie sortowac
{
public:

	Sorting_array() = default;
	~Sorting_array() = default;
	Sorting_array(std::vector<T> array);

public:

	std::vector<T> array; // szablonowy wektor
public:

	void sort(sf::RenderWindow & window,int type_of_algorythm = 0);  
	void push_back(T & obj);
	void pop_back();

	inline bool get_dond() { return dond; };
	inline void changeSide(int a) { side = a; };
public:
	void show();

	void draw(sf::RenderWindow & window); // rysuje cala tablice 
private:

	void swap(T & obj, T & obj2); //zamienia s³upki miejscami

	void sort_one(sf::RenderWindow& window, sf::Text& text);// algorytm ulepszonego sortowania bombelkowego
	bool dond = false;// sprawdza czy sortowanie jest skonczone
	int side = 1; // strona w ktora sortujemy

public:

	T& operator[](size_t n) { return array[n]; };
	void operator()(sf::RenderWindow& window,int type_of_algorythm = 0); //operatory

};

template<class T>
Sorting_array<T>::Sorting_array(std::vector<T> array) // konstruktor kopiujacy
{

	this->array = array;

}

template<class T>
inline void Sorting_array<T>::swap(T & obj, T & obj2) // zamiana miejscami
{
	sf::Vector2f newPos = obj.shape.getPosition();
	int newSize = obj.size;

	obj.set_size(obj2.size);
	obj2.set_size(newSize);

}

template<class T>
inline void Sorting_array<T>::sort_one(sf::RenderWindow & window, sf::Text & text)
{

for (int i = 0; i < this->array.size(); i++) {

		for (int j = 0; j < this->array.size() - 1 - i; j++) {

			this->array[j].shape.setFillColor(sf::Color::Red);

			window.clear();
			this->draw(window);
			window.draw(text);
			window.display();

			if (side == 1) {
				if (this->array[j] > this->array[j + 1]) {

					this->swap(this->array[j], this->array[j + 1]);

				}
			}
			else if (side == 2) {
				if (this->array[j] < this->array[j + 1]) {

					this->swap(this->array[j], this->array[j + 1]);

				}
			}

			this->array[j].shape.setFillColor(array[i].colour);

		}

		for (int j = 0; j < this->array.size(); j++) {
			this->array[j].shape.setSize(sf::Vector2f(5, array[j].size));

		}

	}
	dond = true;

}

template<class T>
inline void Sorting_array<T>::operator()(sf::RenderWindow& window, int type_of_algorythm)
{
	sort(window);
}

template<class T>
inline void Sorting_array<T>::sort(sf::RenderWindow & window,int type_of_algorythm)
{
	dond = false;
	if (type_of_algorythm == 0) { // program mial obslugowac wiecej algorytmow, z czasem bede go rozwijal

		sf::Text text;
		sf::Font font;
		font.loadFromFile("C:/Users/blizz/source/repos/Daironn/Un-Sorting-Algorythm/Sorting Algorythms/arial-mt-black/ARIBL0.ttf");
		text.setFont(font);
		text.setString("Bubble sorting");
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold); //ustawienie wlasciwosci napisu

		if (dond != true) {
			this->sort_one(window, text);
		}
		
	}
}

template<class T>
void Sorting_array<T>::push_back(T & obj)
{
	this->array.push_back(obj);
}

template<class T>
void Sorting_array<T>::pop_back()
{
	this->array.pop_back();
}

template<class T>
inline void Sorting_array<T>::show()
{
	for (auto x : this->array) {
		std::cout << x.get_size()<<std::endl;
	}
}

template<class T>
void Sorting_array<T>::draw(sf::RenderWindow & window)
{
	//for (auto x : this->array) {
	//	x.draw(window);
	//}
	//rysowanie na ekranie, metoda wolniejsza na gorze i szybsza na dole, a pomoca iteratorow
	typename std::vector<T>::iterator ite;
	for (ite = this->array.begin(); ite < this->array.end(); ++ite) {
		ite->draw(window);
	}
}