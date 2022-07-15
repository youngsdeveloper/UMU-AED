#include "Utils.h"

#include <iostream>
#include <string>

using namespace std;

/*
 * Módulo en el que se encuentran algunas funciones auxiliares del programa.
*/

string Utils::minusculas(string entrada){
	
    int letras[7][2]= {{0xA1, 0x81}, {0xA9, 0x89}, {0xAD, 0x8D},
     {0xB3, 0x93}, {0xBA, 0x9A}, {0xBC, 0x9C}, {0xB1, 0x91}};

   for(unsigned int i= 0; i<entrada.length(); i++){
      if (entrada[i]!=-61){
         entrada[i]= tolower(entrada[i]);  
      }else if (i+1<entrada.length()) {
		  i++;
         for (int j= 0; j<7; j++)
            if (entrada[i]==(char)letras[j][1]) {
                  entrada[i]= (char)letras[j][0];
                  break;
            }
      }
   }
   return entrada;
}


unsigned long long int Utils::mod(long long int a, long long int b) {
    long long int ret = a % b;
    while(ret < 0){
        ret += b;
    }
    return ret;
}