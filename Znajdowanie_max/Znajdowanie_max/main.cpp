#include <iostream>

using namespace std;

float tab[5], srednia, m[1];

int main()
{
    cout << "Podaj 5 liczb oddzielonych spacja: " << endl;
    cin >> tab[0] >> tab[1] >> tab[2] >> tab[3] >> tab[4];

    srednia = (tab[0] + tab[1] + tab[2] + tab[3] + tab[4]) / 5;
    cout << "Srednia: " << srednia << endl;

    cout << "Najblizsza sredniej arytmetycznej jest: ";

    m[0] = tab[0];

    for (int i = 0; i < 5; i++)
    {
        if (abs(srednia - tab[i]) < abs(srednia - m[0]))
            m[0] = tab[i];

        if (abs(srednia - tab[i]) == abs(srednia - m[0]))
            m[1] = tab[i];
    }

    if (m[1] != NULL && m[0] != m[1])
    {
        cout << m[0] << " i " << m[1];
    }
    else cout << m[0];

    return 0;
}