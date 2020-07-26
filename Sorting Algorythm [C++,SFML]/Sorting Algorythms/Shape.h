#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Shape
{
	template<class T>
	friend class Sorting_array;
	friend class Square;

private:
	class Vector2f
	{
	public:
		Vector2f() = default;
		Vector2f(float, float);
		~Vector2f() = default;

	private:
		float x;
		float y;
	public:
		float get_x();
		float get_y();
	};


public:

	Shape() :size(0) { posit = std::make_unique<Vector2f>(10, 610); };
	Shape(int s) :size(s) { posit = std::make_unique<Vector2f>(10, 610); };
	Shape(const Shape & obj) : size(obj.size) { posit = std::make_unique<Vector2f>(10, 610); };
	~Shape() = default;

	inline void show_size() { std::cout << size; }
	virtual void draw(sf::RenderWindow& window) = 0;


protected:

	int size;
	std::unique_ptr<Vector2f> posit;
public:

	friend std::ostream & operator <<(std::ostream & os, Shape & obj);

};

