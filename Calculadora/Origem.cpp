//L�gica que envolve as opera��es de somar,
//subtrair, dividir e multiplicar
#include <iostream>

long double Sum(float a, float b);
long double Mult(float a, float b);
long double Div(float a, float b);
long double Subt(float a, float b);


long double Sum(float a, float b)
{
	double FinalResult = 0;
	FinalResult += a + b; //adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}

long double Mult(float a, float b)
{
	double FinalResult = 0;
	FinalResult += (a) * (b); //adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}

long double Div(float a, float b)
{
	double FinalResult = 0;
	FinalResult += (a) / (b);//adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;	
}

long double Subt(float a, float b)
{
	double FinalResult = 0;
	FinalResult += (a) - (b);//adiciona ao Resultado anterior o valor da nova opera��o
	return FinalResult;
}