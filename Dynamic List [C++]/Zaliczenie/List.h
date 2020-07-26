#pragma once
#include<iostream>
#include <fstream>
#include <string>

struct Object {

	int data;
	int counter;
	Object * next;
};

class List
{
private:

	unsigned list_size;
private:

	Object * first;
	Object * last;
public:

	List() :list_size(0) {};
	~List() = default;
public:

	void push_back(int i);
	void pop_back();

	void push_front(int i);
	void pop_front();

	void pop_value(int value);

	void read(const std::string & filename);
	void write(const std::string & filename);

	void show() const;

	void sort();
	void swap(Object * ob1, Object * ob2);

	bool is_empty() const;

};