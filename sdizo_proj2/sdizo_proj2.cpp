// sdizo_proj2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include "mst.h"

using namespace std;

int main()
{
	IncidenceMatrix m(5, false);
	AdjacencyList l(5, false);
	m.createEdge(0, 1, 1);
	m.createEdge(0, 2, 3);
	m.createEdge(1, 2, 3);
	m.createEdge(1, 3, 6);
	m.createEdge(2, 3, 4);
	m.createEdge(2, 4, 2);
	m.createEdge(3, 4, 5);
	l.createEdge(0, 1, 1);
	l.createEdge(0, 2, 3);
	l.createEdge(1, 2, 3);
	l.createEdge(1, 3, 6);
	l.createEdge(2, 3, 4);
	l.createEdge(2, 4, 2);
	l.createEdge(3, 4, 5);
	cout << "Graf Macierzowo: " << endl;
	m.print();
	cout << "Graf Listowo: " << endl;
	l.print();
	cout << "MST Prim Matrix: " << endl;
	prim_matrix(&m, 0, true);
	cout << "MST Kruskal Matrix: " << endl;
	kruskal_matrix(&m, true);
	cout << "MST Prim List: " << endl;
	prim_list(&l, 0, true);
	cout << "MST Kruskal List: " << endl;
	kruskal_list(&l, true);
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
