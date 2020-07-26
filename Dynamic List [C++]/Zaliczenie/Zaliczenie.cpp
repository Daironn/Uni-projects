#include "pch.h"
#include "List.h"
#include <iostream>
#include <string>
#include <cstdio>

int main()
{

	List test;
	//test.push_back(1);
	//test.push_back(1);
	//test.push_back(1);
	//test.push_back(3);
	//test.push_front(53);
	//test.push_back(551);
	//test.pop_value(551);
	//test.push_back(1);
	//test.show();
	//test.write("test.txt");
	test.read("test.txt");
	test.show();
	std::cout << std::endl;

	test.push_back(1);
	test.push_back(754);
	test.push_back(12);
	test.push_back(74335);
	test.push_front(2567);
	test.push_back(1213);
	test.push_back(123);
	test.push_back(71154);
	test.push_back(1267);
	test.push_back(74875);
	test.push_front(212767);
	test.push_back(123443);
	test.push_back(1987);
	test.push_back(75674);
	test.push_back(1882);
	test.push_back(7545);
	test.push_front(2647);
	test.push_back(165423);
	test.push_back(41);
	test.push_back(758554);
	test.push_back(1672);
	test.push_back(7455);
	test.push_front(25667);
	test.push_back(1213);
	test.push_back(0);




	test.sort();
	test.show();

	//std::cout << std::endl;

	//test.pop_front();
	//test.push_back(3);
	//test.push_back(3);

	//test.show();

	system("PAUSE");
}
