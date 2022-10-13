#include <iostream>
#include"Bicola.h"
using namespace std;

int main()
{
   Bicola<char> b1;
   b1.pushCola('H');
   b1.pushCola('o');
   b1.pushCola('l');
   b1.pushCola('a');
   muestraBicola(b1);
}
