#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "colors.h"

using namespace std;

/*
Points inside a circle with a given radius.
The program checks how many of the given elements fit into a circle with the given radius
It defines a structure Punkt(Point) with three double variables: x, y, and odl.
It also declares several functions to calculate the distance between a point
and the center of the circle, to fill an array with random values for x and y, to count
how many points are inside the circle, and to write the points inside the circle to a file.
In the main function, it first initializes a seed for the random number generator and opens
a file named result.txt to write the output. It then prompts the user to enter the
number of points to generate and the radius of the circle. It allocates an array of points
with the specified size, fills it with random values, counts how many points are inside
the circle, and writes those points to the file. Finally, it deallocates the array
and terminates the program.
*/

struct Punkt
{
    double x, y, odl;
};

double odleglosc_od_srodka( double x, double y)
{
    return sqrt( x*x + y*y );
}

void uzupelnij( Punkt *tab, int N )
{
    for (int i = 0; i < N; i++)
    {
        tab[i].x = double(rand()%101) / 10;
        tab[i].y = double(rand()%101) / 10;
        tab[i].odl = odleglosc_od_srodka( tab[i].x, tab[i].y );
        //cout << tab[i].x << " " << tab[i].y << "   distance: " << tab[i].odl << endl;
    }
}

int wewnatrz_okregu( Punkt *tab, int N, int R )
{
    int ilosc = 0;
    for (int i = 0; i < N; i++)
    {
        if( odleglosc_od_srodka( tab[i].x, tab[i].y ) < R )
            ilosc++;
    }

    return ilosc;
}

void zapis_do_pliku( ofstream &plik, Punkt *tab, int N, int R )
{
    for (int i = 0; i < N; i++)
    {
        if( odleglosc_od_srodka( tab[i].x, tab[i].y ) < R )
        {
            plik << fixed << setprecision(2) << tab[i].x << " " << tab[i].y << "   distance: " << tab[i].odl << endl;
        }
    }
}

void displayHeader() {
    Colors::setColor(Colors::CYAN);
    Colors::drawLine('*');
    cout << "           Points inside a circle calculator" << endl;
    cout << "                by Adrian Lesniak" << endl;
    Colors::drawLine('*');
    Colors::setColor(Colors::WHITE);
}

void displayMenu() {
    Colors::setColor(Colors::GREEN);
    cout << "\nAvailable options:\n";
    Colors::drawLine('-', 30);
    cout << "1. Generate and analyze points\n";
    cout << "2. Load points from file\n";
    cout << "3. Display program info\n";
    cout << "4. Exit\n";
    Colors::drawLine('-', 30);
    Colors::setColor(Colors::WHITE);
}

void displayProgramInfo() {
    system("cls");
    Colors::setColor(Colors::YELLOW);
    cout << "\nProgram Description:\n";
    Colors::drawLine();
    cout << "This program generates random points and checks how many\n";
    cout << "of them fall within a circle of specified radius.\n";
    cout << "Features include:\n";
    cout << "- Random point generation\n";
    cout << "- Distance calculation\n";
    cout << "- File I/O operations\n";
    cout << "- Visual representation\n\n";
    Colors::setColor(Colors::WHITE);
    cout << "Press any key to return to menu...";
    cin.ignore();
    cin.get();
}

void drawAsciiCircle() {
    Colors::setColor(Colors::CYAN);
    cout << "\n";
    cout << "        ***#######***        \n";
    cout << "     **###############**     \n";
    cout << "   **###################**   \n";
    cout << "  *#######################*  \n";
    cout << " *#########################* \n";
    cout << " *#########################* \n";
    cout << " *#########################* \n";
    cout << "  *#######################*  \n";
    cout << "   **###################**   \n";
    cout << "     **###############**     \n";
    cout << "        ***#######***        \n";
    Colors::setColor(Colors::WHITE);
}

void generateAndAnalyzePoints() {
    system("cls");
    Colors::setColor(Colors::MAGENTA);
    cout << "\nPoint Generation and Analysis\n";
    Colors::drawLine();

    drawAsciiCircle(); // Dodano wyświetlanie ASCII art koła

    try {
        int N;
        double R;
        
        cout << "Enter the amount of points: ";
        if (!(cin >> N) || N <= 0) {
            throw runtime_error("Invalid number of points");
        }

        cout << "Please enter the radius R of the circle: ";
        if (!(cin >> R) || R <= 0) {
            throw runtime_error("Invalid radius value");
        }

        Punkt* tab = new Punkt[N];
        uzupelnij(tab, N);

        ofstream plik("result.txt");
        if (!plik) {
            throw runtime_error("Cannot open result file");
        }

        int count = wewnatrz_okregu(tab, N, R);
        Colors::setColor(Colors::CYAN);
        cout << "\nResults:\n";
        cout << "- Total points: " << N << endl;
        cout << "- Points inside circle: " << count << endl;
        cout << "- Percentage: " << fixed << setprecision(2) 
             << (count * 100.0 / N) << "%\n";

        zapis_do_pliku(plik, tab, N, R);
        delete[] tab;

    } catch (const exception& e) {
        Colors::setColor(Colors::YELLOW);
        cout << "\nError: " << e.what() << endl;
    }

    Colors::setColor(Colors::WHITE);
    cout << "\nPress any key to return to menu...";
    cin.ignore();
    cin.get();
}

void loadPointsFromFile() {
    system("cls");
    Colors::setColor(Colors::MAGENTA);
    cout << "\nLoading points from file (result.txt)\n";
    Colors::drawLine();

    ifstream plik("result.txt");
    if (!plik) {
        Colors::setColor(Colors::YELLOW);
        cout << "File 'result.txt' not found. No points to load.\n";
        Colors::setColor(Colors::WHITE);
        cout << "\nPress any key to return to menu...";
        cin.ignore();
        cin.get();
        return;
    }

    string line;
    int count = 0;
    while (getline(plik, line)) {
        cout << line << endl;
        count++;
    }
    if (count == 0) {
        Colors::setColor(Colors::YELLOW);
        cout << "File is empty.\n";
    }
    Colors::setColor(Colors::WHITE);
    cout << "\nPress any key to return to menu...";
    cin.ignore();
    cin.get();
}

int main() {
    srand(time(NULL));
    int choice;

    while (true) {
        system("cls");
        displayHeader();
        displayMenu();

        Colors::setColor(Colors::CYAN);
        cout << "\nEnter your choice (1-4): ";
        Colors::setColor(Colors::WHITE);

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: generateAndAnalyzePoints(); break;
            case 2: loadPointsFromFile(); break; // Dodano obsługę opcji 2
            case 3: displayProgramInfo(); break;
            case 4: return 0;
            default: continue;
        }
    }
}
