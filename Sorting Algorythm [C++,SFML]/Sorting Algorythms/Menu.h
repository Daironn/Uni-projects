#pragma once
#include"Info.h"

#include <iostream>

class Menu //klasa menu, tutaj chyba wszystko jest jasne
{
public:

	Menu();
	~Menu() = default;
protected:

	static Info info;
private:

	bool ended = false;

public:

	virtual void showMenu();

	inline bool isEnded() { return ended; };
	inline void changeend(bool a) { ended = a; };

	inline void setMenu(int a) { info.setMenu(a); };
	inline int getMenu() { return info.getMenu(); };

	inline void setColour(int a) { info.setColour(a); };
	inline int getColour() { return info.getColour(); };

	inline void setSide(int a) { info.setSide(a); };
	inline int getSide() { return info.getSide(); };

	inline void incraseS() { info.incraseA(); info.incraseS(); info.saveMoveS(); info.saveMoveS(); };
	inline void incraseC() { info.incraseA();  info.incraseC(); info.saveMoveC(); info.saveMoveC();};
	inline void incraseSC() { info.incraseA();  info.incraseSC(); info.saveMoveSC(); info.saveMoveSC();};

	inline void showMoves() { info.showMoves(); };



};

