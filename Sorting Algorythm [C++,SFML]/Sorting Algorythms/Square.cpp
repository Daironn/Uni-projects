#include "pch.h"
#include "Square.h"


int poss = 0;
int possa = 0; // zmienne regulugace odstepy pomiedzy slupkami

WHITE::Square::Square(int s):Shape(s)
{

	shape.setSize(sf::Vector2f(5,size));
	shape.setFillColor(colour);
	shape.setPosition(sf::Vector2f(posit->get_x()+(poss*10), posit->get_y()));
	shape.setRotation(180.f);
	poss++;


}

WHITE::Square::Square(const Shape & s):Shape(s)
{

	shape.setSize(sf::Vector2f(5, size));
	shape.setFillColor(colour);
	shape.setPosition(sf::Vector2f(posit->get_x() + (poss * 10), posit->get_y()));

	poss++;


}
										//konstruktor kopjujacy
WHITE::Square::Square(const Square & s) // jawnie nie jest uzywany co prawda, ale przy napelnianiu tablicy jest wywolywany
{

	Shape::size = s.Shape::size;
	this->shape = s.shape;

}


void WHITE::Square::draw(sf::RenderWindow & window)
{
	window.draw(shape);
}

void WHITE::Square::set_posioton(sf::Vector2f poss)
{
	shape.setPosition(poss);
}

void WHITE::Square::set_size(int s)
{
	this->size = s;
}




//BLUE
BLUE::Square::Square(int s) :Shape(s)
{

	shape.setSize(sf::Vector2f(5, size));
	shape.setFillColor(colour);
	shape.setPosition(sf::Vector2f(posit->get_x() + (possa * 10), posit->get_y()));
	shape.setRotation(180.f);
	possa++;


}

BLUE::Square::Square(const Shape& s) :Shape(s)
{

	shape.setSize(sf::Vector2f(5, size));
	shape.setFillColor(colour);
	shape.setPosition(sf::Vector2f(posit->get_x() + (possa * 10), posit->get_y()));

	possa++;

}

BLUE::Square::Square(const Square& s)
{

	Shape::size = s.Shape::size;
	this->shape = s.shape;

}

void BLUE::Square::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void BLUE::Square::set_posioton(sf::Vector2f poss)
{
	shape.setPosition(poss);
}

void BLUE::Square::set_size(int s)
{
	this->size = s;
}