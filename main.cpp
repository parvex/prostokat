#include "point.h"
#include "rectangle.h"
using namespace std;


void showrect(const Rect& rect);


void setcoords(Rect& rect);


int main()
{
    bool end = 0;
    while(!end)
    {
        cout << "Witaj stworz prostokat podajac 2 punkty w postaci : x1 y1 x2 y2\n\n";

        Rect rect1;
        Rect rect2;
        Rect rect3;

        setcoords(rect1);

        cout << "brawo stworzyles prostokat o wspolrzednych:\n";
        showrect(rect1);

        cout << "\npodaj drugi prostokat" << endl;

        setcoords(rect2);
        cout << "\nbrawo stworzyles drugi prostokat o wspolrzednych" << endl;
        showrect(rect2);

        cout << "\nco chcesz z nimi zrobic?\n"
                "dodac +\n"
                "odjac - \n"
                "porownac =\n"
                "sprawdzic czy sie przecinaja - p\n"
                "sprawdzic czy sie zawieraja w sobie - z\n"
                "podac nowe prostokaty - n\n"
                "wyjsc z programu - q\n";

        char choice;

        bool change;
        change = 0;
        while(!change)
        {
            choice = 0;
            cin >> choice;
            cin.sync();
            switch(choice)
            {
            case'+':
                {
                rect3 = rect1 + rect2;
                cout << "dodaje, wynik to ";
                showrect(rect3);
                break;
                }
            case'-':
                {

                rect3 = rect1 - rect2;
                cout << "odejmuje, wynik to ";
                showrect(rect3);
                break;
                }
            case'=':
                {

                if(rect1 == rect2)
                    cout << "prostokaty sa takie same\n" << endl;
                else
                    cout << "prostokaty sa rozne\n";
                break;
                }
            case'p':
                {
                    if(rect1.crosses(rect2))
                        cout<< "przecinaja sie\n";
                    else
                        cout << "nie przecinaja sie\n";

                    break;
                }
            case'z':
                {
                    if(rect1.encloses(rect2))
                        cout << "pierwszy zawiera drugi\n";
                    else if(rect2.encloses(rect1))
                        cout << "drugi zawiera pierwszy\n";
                    else
                        cout << "nie zawieraja sie\n";

                    break;
                }
            case'n':
                {
                change = 1;
                break;
                }
            case'q':
                {
                change = 1;
                end = 1;
                break;
                }
            }
        }
    }


	return 0;
}




void showrect(const Rect& rect)
{
    cout << "lup(" << rect.gettopleft().x << "," << rect.gettopleft().y << ") rdwn(" << rect.getbottomright().x << "," << rect.getbottomright().y << ")" << endl;
}

void setcoords(Rect& rect)
{
    int tab[4];
    for(int i = 0; i < 4; i++)
    {

        while(!(cin>>tab[i])) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
        {
            cin.clear(); //kasowanie flagi b³êdu strumienia
            cin.sync(); //kasowanie zbêdnych znaków z bufora
        }
    }
    cin.sync();
    rect = { {tab[0], tab[1]}, {tab[2], tab[3]}};
}

