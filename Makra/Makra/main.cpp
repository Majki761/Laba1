#include <iostream>

using namespace std;

// Etapy kompilacji w C++
// 1. Preprocesor - analiza dyrektyw preprocesora (#)
// 2. Kompilacja - kompilujemy kazdy plik .cpp osobno (jednostki kompilacji), tworzymy pliki posrednie .obj, .o
// a) Komplacja do Assemblera
// b) Kompilacja do kodu maszynowego - rozny dla roznych platform
// 3. Linker - linkuje pliki posrednie do jednego wykonywalnego(.exe, .elf)


#define MAKRO cout << "Moje makro" << endl;   // makro
#define POWER(a) a * a                        // makro z parametrem
#define PI 3.14
#define IS_DEBUG
#define PS5

constexpr float PI2 = 3.14f;

inline void func() //funkcja rozwija w miejscu wywolania - spoko dla malych i czesto uzywanych funkcji
{
	cout << "funkcja inline" << endl;
}

int main()
{
	MAKRO
	func();

#ifdef IS_DEBUG
	cout << "to jest debugowa komenda" << endl;
#endif


	cout << POWER(7) << endl;
	
	int r = 10;
    cout << PI2 * POWER(r) << endl;

	return 0;
}
