#pragma once
#include <iostream>
#include <queue>
class Info //klasa ktora bedzie sluzyc jako zmienna statyczna
{			//przechowuje ona informacje o wszystkich zdarzeniach jakie nast¹pi³y
public:		// i zapisuje je do kolejki co by by³y ulozone po kolei i szybciej dostepne od gory

	Info() = default;
	~Info() = default;
private:

	int amountOfActions = 0;
	int amountOfSorts = 0;
	int colourChanges = 0;
	int sideChanges = 0;

	int currentMenu = 1;
	int currentColour = 1;
	int currentSide = 1;

	std::queue<std::string> moves;
public:

	inline void incraseA() { amountOfActions++; };
	inline void incraseS() { amountOfSorts++; };
	inline void incraseC() { colourChanges++; };
	inline void incraseSC() { sideChanges++; };

	inline void saveMoveS() { moves.push("Wykonano sortowanie"); };
	inline void saveMoveC() { moves.push("Zmieniono kolor"); };
	inline void saveMoveSC() { moves.push("Zmieniono strone"); };

	inline void showA() { std::cout << amountOfActions; };
	inline void showS() { std::cout << amountOfSorts; };
	inline void showC() { std::cout << colourChanges; };
	inline void showSC() { std::cout << sideChanges; };

	inline int getMenu() { return currentMenu; };
	inline void setMenu(int a) { currentMenu = a; };

	inline int getColour() { return currentColour; };
	inline void setColour(int a) { currentColour = a; };

	inline int getSide() { return currentSide; };
	inline void setSide(int a) { currentSide = a; };

	void showMoves();
};

