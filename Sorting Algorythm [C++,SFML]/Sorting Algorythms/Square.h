#pragma once
#include "Shape.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//zamiast uzywac 2 osobnych klas square, postanowilem zamknac je w przestrzeniach nazw, teraz klasa jest jedna
//ale podzielona za pomoca przestrzeni, uwa¿am to za wygodniejsze rozwiazanie
namespace WHITE {
	class Square :
		public Shape
	{
		template<class T>
		friend class Sorting_array;

	public:

		Square() :Shape(0) {};
		Square(int s);
		Square(const Shape& s);
		Square(const Square& s);
		virtual ~Square() = default;
	public:

		virtual void draw(sf::RenderWindow& window);
		int get_size() const { return size; };
		sf::Vector2f get_Position()const { return shape.getPosition(); };
	private:


		sf::RectangleShape shape;
		sf::Color colour = sf::Color::White;
	private:

		void set_posioton(sf::Vector2f);
		void set_size(int);
	public:

		bool operator < (Square const& boj) { return this->size < boj.get_size(); };
		bool operator > (Square const& boj) { return this->size > boj.get_size(); };
	};
}


namespace BLUE {
	class Square :
		public Shape
	{
		template<class T>
		friend class Sorting_array;

	public:

		Square() :Shape(0) {};
		Square(int s);
		Square(const Shape& s);
		Square(const Square& s);
		virtual ~Square() = default;
	public:

		virtual void draw(sf::RenderWindow& window);
		int get_size() const { return size; };
		sf::Vector2f get_Position()const { return shape.getPosition(); };
	private:

		sf::RectangleShape shape;
		sf::Color colour = sf::Color::Blue;
	private:

		void set_posioton(sf::Vector2f);
		void set_size(int);
	public:
		bool operator < (Square const& boj) { return this->size < boj.get_size(); };
		bool operator > (Square const& boj) { return this->size > boj.get_size(); };

	};
}