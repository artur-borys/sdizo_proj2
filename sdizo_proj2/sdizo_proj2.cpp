// sdizo_proj2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include "mst.h"
#include "spa.h"
#include "utils.h"
#include "czas.h"

using namespace std;

void checkMatrix();
void checkList();
void clearConsole();
void pause();
void runTests();

void menuCheck() {
	string warning;
	int opcja;
	bool koniec = false;
	while (!koniec) {
		clearConsole();
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "Wybierz reprezentacje: " << endl;
		cout << "1. Macierzowa" << endl;
		cout << "2. Listowa" << endl;
		cout << "0. Powrot" << endl;
		cout << "> ";
		cin >> opcja;
		if (opcja == 1) {
			checkMatrix();
		}
		else if (opcja == 2) {
			checkList();
		}
		else if (opcja == 0) {
			koniec = true;
		}
		else {
			warning = "Nie wybrano opcji z listy!";
		}
	}
}

void checkMatrix() {
	string warning, graphPath;
	IncidenceMatrix Gd, Gn;
	int opcja;
	bool koniec = false;
	while (!koniec) {
		clearConsole();
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "Wybierz reprezentacje: " << endl;
		cout << "1. Generuj losowy graf do pliku" << endl;
		cout << "2. Wczytaj graf z pliku" << endl;
		cout << "3. Wyswietl" << endl;
		cout << "4. Algorytmy MST" << endl;
		cout << "5. Algorytmy najkrotszej sciezki" << endl;
		cout << "0. Powrot" << endl;
		cout << "> ";
		cin >> opcja;
		if (opcja == 1) {
			clearConsole();
			string path;
			size_t v;
			double density;
			cout << "Nazwa pliku: ";
			cin >> path;
			cout << "Ilosc wierzcholkow: ";
			cin >> v;
			cout << "Gestosc (w ulamku dziesietnym): ";
			cin >> density;
			randomGraph(path, v, density);
		}
		else if (opcja == 2) {
			system("CLS");
			cout << "Nazwa pliku: ";
			cin >> graphPath;
			Gd = IncidenceMatrix::readFromFile(graphPath, true);
			Gn = IncidenceMatrix::readFromFile(graphPath, false);
		}
		else if (opcja == 3) {
			clearConsole();
			Gd.print();
			pause();
		}
		else if (opcja == 4) {
			clearConsole();
			size_t s;
			cout << "Wierzcholek startowy: ";
			cin >> s;
			cout << "Graf" << endl;
			Gn.print();
			cout << "Algorytm Prima" << endl;
			prim(&Gn, s, true);
			cout << "Algorytm Kruskala" << endl;
			kruskal(&Gn, true);
			pause();
		}
		else if (opcja == 5) {
			clearConsole();
			size_t s;
			cout << "Wierzcholek startowy: ";
			cin >> s;
			cout << "Graf" << endl;
			Gd.print();
			cout << "Algorytm Dijkstry" << endl;
			dijkstra(&Gd, s, true);
			cout << "Algorytm Bellmana-Forda" << endl;
			bellman_ford(&Gd, s, true);
			pause();
		}
		else if (opcja == 0) {
			break;
		}
		else {
			warning = "Nie wybrano opcji z listy!";
		}
	}
}

void checkList()
{
	string warning, graphPath;
	AdjacencyList Gd, Gn;
	int opcja;
	bool koniec = false;
	while (!koniec) {
		clearConsole();
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "Wybierz reprezentacje: " << endl;
		cout << "1. Generuj losowy graf do pliku" << endl;
		cout << "2. Wczytaj graf z pliku" << endl;
		cout << "3. Wyswietl" << endl;
		cout << "4. Algorytmy MST" << endl;
		cout << "5. Algorytmy najkrotszej sciezki" << endl;
		cout << "0. Powrot" << endl;
		cout << "> ";
		cin >> opcja;
		if (opcja == 1) {
			clearConsole();
			string path;
			size_t v;
			double density;
			cout << "Nazwa pliku: ";
			cin >> path;
			cout << "Ilosc wierzcholkow: ";
			cin >> v;
			cout << "Gestosc (w ulamku dziesietnym): ";
			cin >> density;
			randomGraph(path, v, density);
		}
		else if (opcja == 2) {
			system("CLS");
			cout << "Nazwa pliku: ";
			cin >> graphPath;
			Gd = AdjacencyList::readFromFile(graphPath, true);
			Gn = AdjacencyList::readFromFile(graphPath, false);
		}
		else if (opcja == 3) {
			clearConsole();
			Gd.print();
			pause();
		}
		else if (opcja == 4) {
			clearConsole();
			size_t s;
			cout << "Wierzcholek startowy: ";
			cin >> s;
			cout << "Graf" << endl;
			Gn.print();
			cout << "Algorytm Prima" << endl;
			prim(&Gn, s, true);
			cout << "Algorytm Kruskala" << endl;
			kruskal(&Gn, true);
			pause();
		}
		else if (opcja == 5) {
			clearConsole();
			size_t s;
			cout << "Wierzcholek startowy: ";
			cin >> s;
			cout << "Graf" << endl;
			Gd.print();
			cout << "Algorytm Dijkstry" << endl;
			dijkstra(&Gd, s, true);
			cout << "Algorytm Bellmana-Forda" << endl;
			bellman_ford(&Gd, s, true);
			pause();
		}
		else if (opcja == 0) {
			break;
		}
		else {
			warning = "Nie wybrano opcji z listy!";
		}
	}
}

void clearConsole()
{
	system("CLS");
}

void pause()
{
	system("PAUSE");
}

void runTests()
{
	Czas t;
	size_t sizes[] = { 10, 20, 30, 40, 50 };
	double densities[] = { 0.25, 0.5, 0.75, 0.99 };
	size_t repeats = 100;
	ofstream files_m[] = { ofstream("prim_m.txt"), ofstream("kruskal_m.txt"), ofstream("dijkstra_m.txt"), ofstream("bellman_m.txt") };
	ofstream files_l[] = { ofstream("prim_l.txt"), ofstream("kruskal_l.txt"), ofstream("dijkstra_l.txt"), ofstream("bellman_l.txt") };
	clearConsole();
	for (size_t size : sizes) {
		for (double density : densities) {
			double avg[4] = { 0 };
			cout << "Reprezentacja macierzowa, v=" << size << " gestosc=" << density << endl;
			for (size_t i = 0; i < repeats; i++) {
				IncidenceMatrix G = randomGraphMatrix(size, density, false);
				t.start();
				prim(&G, 0, false);
				t.stop();
				avg[0] = t.result();
				t.start();
				kruskal(&G, false);
				t.stop();
				avg[1] = t.result();
				G = randomGraphMatrix(size, density, true);
				t.start();
				dijkstra(&G, 0, false);
				t.stop();
				avg[2] = t.result();
				t.start();
				bellman_ford(&G, 0, false);
				t.stop();
				avg[3] = t.result();
			}
			for (size_t i = 0; i < 4; i++) {
				avg[i] /= 100;
				files_m[i] << avg[i] << " ";
			}
		}
		for (size_t i = 0; i < 4; i++) {
			files_m[i] << endl;
		}
	}
	for (size_t i = 0; i < 4; i++) {
		files_m[i].close();
	}

	for (size_t size : sizes) {
		for (double density : densities) {
			double avg[4] = { 0 };
			cout << "Reprezentacja listowa, v=" << size << " gestosc=" << density << endl;
			for (size_t i = 0; i < repeats; i++) {
				AdjacencyList G = randomGraphList(size, density, false);
				t.start();
				prim(&G, 0, false);
				t.stop();
				avg[0] = t.result();
				t.start();
				kruskal(&G, false);
				t.stop();
				avg[1] = t.result();
				G = randomGraphList(size, density, true);
				t.start();
				dijkstra(&G, 0, false);
				t.stop();
				avg[2] = t.result();
				t.start();
				bellman_ford(&G, 0, false);
				t.stop();
				avg[3] = t.result();
			}
			for (size_t i = 0; i < 4; i++) {
				avg[i] /= 100;
				files_l[i] << avg[i] << " ";
			}
		}
		for (size_t i = 0; i < 4; i++) {
			files_l[i] << endl;
		}
	}
	for (size_t i = 0; i < 4; i++) {
		files_l[i].close();
	}
	pause();
}

int main()
{
	int opcja;
	string warning;
	while (true) {
		clearConsole();
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "Algorytmy Grafowe, SDiZO, Projekt nr 2" << endl;
		cout << "Artur Borys 241323" << endl;
		cout << "Maj 2019" << endl << endl;
		cout << "1. Sprawdz poprawnosc algorytmow" << endl;
		cout << "2. Wykonaj testy" << endl;
		cout << "0. Wyjscie" << endl;
		cout << "> ";
		cin >> opcja;
		switch (opcja) {
		case 0:
			return 0;
			break;
		case 1:
			menuCheck();
			break;
		case 2:
			runTests();
			break;
		default:
			warning = "Nie wybrano opcji z listy!";
			break;
		}
	}
	return 0;
	randomGraph("test.txt", 5, 0.5);
	IncidenceMatrix m2 = IncidenceMatrix::readFromFile("test.txt", true);
	m2.print();
	AdjacencyList l2 = AdjacencyList::readFromFile("graph_spa.txt", true);
	dijkstra(&m2, 0, true);
	cout << endl;
	dijkstra(&l2, 0, true);
	cout << endl;
	bellman_ford(&m2, 0, true);
	cout << endl;
	bellman_ford(&l2, 0, true);
	IncidenceMatrix m = IncidenceMatrix::readFromFile("graph_mst.txt", false);
	AdjacencyList l = AdjacencyList::readFromFile("graph_mst.txt", false);
	cout << "Graf Macierzowo: " << endl;
	m.print();
	cout << "Graf Listowo: " << endl;
	l.print();
	cout << "MST Prim Matrix: " << endl;
	prim(&m, 0, true);
	cout << "MST Kruskal Matrix: " << endl;
	kruskal(&m, true);
	cout << "MST Prim List: " << endl;
	prim(&l, 0, true);
	cout << "MST Kruskal List: " << endl;
	kruskal(&l, true);
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
