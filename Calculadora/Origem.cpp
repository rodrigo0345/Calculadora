//L�gica que envolve as opera��es de somar,
//subtrair, dividir e multiplicar
#include <iostream>

long double Sum(int a, int b);
long double Mult(int a, int b);
long double Div(int a, int b);
long double Subt(int a, int b);


long double Sum(int a, int b)
{
	int FinalResult = 0;
	FinalResult += a + b; //adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}

long double Mult(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) * (b); //adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}

long double Div(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) / (b);//adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;	
}

long double Subt(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) - (b);//adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}