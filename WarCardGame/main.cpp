#include <iostream>
#include <conio.h>
#include <vector>
std::vector<int> p1;
std::vector<int> p2;
void fWygrana(std::vector<int> &w,std::vector<int> &l,std::vector<int> &gracz, int ilosc) {
	if(ilosc>0) {
		for (int i = 0; i < ilosc; i++) {
			int pomoc = 5;
			if (w.size() % 5 != 0)pomoc = w.size() % 5;
			int x = w.size() - pomoc;
			for (int j = 1; j < pomoc; j++)gracz.push_back(w[x + j]);
			for (int j = 1; j < pomoc; j++)gracz.push_back(l[x + j]);
		}
	}
	gracz.push_back(w[0]);
	gracz.push_back(l[0]);
}
void runda() {
	std::vector<int>w1;
	std::vector<int>w2;
	bool wygrana = false;
	int licz = 1;
	do {
		//std::cout << "1 karta: " << std::endl;
		std::cout << p1[0] << " " << p2[0] << std::endl;
		w1.push_back(p1[0]);
		w2.push_back(p2[0]);
		if (p1[0] == p2[0]) {
			if (p1.size() == 0 || p2.size() == 0)break;
			p1.erase(p1.begin());
			p2.erase(p2.begin());
			do {
				std::cout << "War: " << std::endl;
				int wojna = 3;
				if (p1.size() == 0 || p2.size() == 0)break;
				if (p1.size() < 4 || p2.size() < 4) {
					if(p1.size()<p2.size())wojna = p1.size()-1;
					else wojna = p2.size()-1;
				}
				for (int i = 0; i < wojna; i++) {
					std::cout << p1[i] << " " << p2[i] << std::endl;
					w1.push_back(p1[i]);
					w2.push_back(p2[i]);
				}
				p1.erase(p1.begin(), p1.begin() + wojna);
				p2.erase(p2.begin(), p2.begin() + wojna);
				if (p1.size() == 0 || p2.size() == 0)break;
				w1.push_back(p1[0]);
				w2.push_back(p2[0]);
				//std::cout << "1 wojenna karta: " << std::endl;
				std::cout << p1[0] << " " << p2[0] << std::endl;
				if (p1[0] > p2[0]) {
					fWygrana(w1, w2, p1, licz);
					wygrana = true;
				}
				else if (p2[0] > p1[0]) {
					fWygrana(w2, w1, p2, licz);
					wygrana = true;
				}
				p1.erase(p1.begin());
				p2.erase(p2.begin());
				licz++;
			} while (wygrana==false);
		}
		else {
			if(p1[0]>p2[0])fWygrana(w1,w2,p1,0);
			else fWygrana(w2, w1,p2,0);
			p1.erase(p1.begin());
			p2.erase(p2.begin());
			wygrana = true;
		}
		if (p1.size() == 0 || p2.size() == 0)break;
	} while (wygrana == false);
}
void start(int t) {
	p1.clear();
	p2.clear();
	int x[26] = { 5,1,13,10,11,3,2,10,4,12,5,11,10,5,7,6,6,11,9,6,3,13,6,1,8,1 };
	int y[26] = { 9,12,8,3,11,10,1,4,2,4,7,9,13,8,2,13,7,4,2,8,9,12,3,12,7,5 };
	int x2[26] = { 3,11,6,12,2,13,5,7,10,3,10,4,12,11,1,13,12,2,1,7,10,6,12,5,8,1 };
	int y2[26] = {9,10,7,9,5,2,6,1,11,11,7,9,3,4,8,3,4,8,8,4,6,9,13,2,13,5};
	int x3[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int y3[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	for (int i = 0; i < 26; i++) {
		if (t == 0) {
			p1.push_back(x[i]);
			p2.push_back(y[i]);
		}
		else if (t == 1) {
			p1.push_back(x2[i]);
			p2.push_back(y2[i]);
		}
		else {
			p1.push_back(x3[i]);
			p2.push_back(y3[i]);
		}
	}
}
void main() {
	p1.reserve(52);
	p2.reserve(52);
	for (int i = 0; i < 3; i++) {
		system("cls");
		std::cout << "START" << std::endl;
		start(i);
		do {
			runda();
		} while (p1.size() > 0 && p2.size() > 0);
		if (p1.size() == 0 && p2.size() == 0)std::cout << "Draw";
		else if (p1.size() == 0)std::cout << "Player number two won";
		else std::cout << "Player number one won";
		_getch();
	}
}