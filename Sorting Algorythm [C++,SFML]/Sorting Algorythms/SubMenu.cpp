#include "pch.h"
#include "SubMenu.h"

void SubMenu::showMenu() //tutaj chyba komentarze s¹ zbêdne
{
		system("CLS");
		if (info.getMenu() == 2) {
			std::cout << "ZMIANA KOLORU" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "PROGRAMEM STERUJEMY NACISKAJAC KLAWISZE NA KLAWIATURZE" << std::endl;
			std::cout << "< 1 >Bialy " << std::endl;
			std::cout << "< 2 >NIEBIESKI" << std::endl;
			std::cout << "< Escape >Wroc" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
		}
		else if (info.getMenu() == 3) {
			std::cout << "ZMIANA KIERUNKU" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "PROGRAMEM STERUJEMY NACISKAJAC KLAWISZE NA KLAWIATURZE" << std::endl;
			std::cout << "< 1 >PRAWO " << std::endl;
			std::cout << "< 2 >LEWO" << std::endl;
			std::cout << "< Escape >Wroc" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
		}
		else if (info.getMenu() == 4) {
			std::cout << "INFORMACJE" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "PROGRAMEM STERUJEMY NACISKAJAC KLAWISZE NA KLAWIATURZE" << std::endl;
			std::cout << "Ilosc sortowan: ";			info.showS();  std::cout << std::endl;
			std::cout << "Ilosc zamiany stron: ";		info.showSC(); std::cout << std::endl;
			std::cout << "ilosc zamiany kolorow: ";		info.showC();  std::cout << std::endl;
			std::cout << "ilosc wykonanych operacji: "; info.showA();  std::cout << std::endl;
			std::cout << "Twoje operacje wykonane od samego poczatku: " << std::endl;
			showMoves();
			std::cout << "< Escape >Wroc" << std::endl;
			std::cout << "=============================================================" << std::endl;
			std::cout << "=============================================================" << std::endl;
		}
}
