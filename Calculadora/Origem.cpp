//Lógica que envolve as operações de somar,
//subtrair, dividir e multiplicar
#include <iostream>

long double Sum(int a, int b);
long double Mult(int a, int b);
long double Div(int a, int b);
long double Subt(int a, int b);


long double Sum(int a, int b)
{
	int FinalResult = 0;
	FinalResult += a + b; //adiciona ao Resultado anterior o valor da nova operação
	return FinalResult;
}

long double Mult(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) * (b); //adiciona ao Resultado anterior o valor da nova operação
	return FinalResult;
}

long double Div(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) / (b);//adiciona ao Resultado anterior o valor da nova operação
	return FinalResult;	
}

long double Subt(int a, int b)
{
	int FinalResult = 0;
	FinalResult += (a) - (b);//adiciona ao Resultado anterior o valor da nova operação
	return FinalResult;
}