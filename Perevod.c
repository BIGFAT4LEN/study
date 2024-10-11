//перевод из шестнадцатиричной в десятичную, включая знаки после запятой
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double power (double base, int degree) //функция для подсчета степеней
{
double res = 1;
if (degree >= 0) //для чисел перед запятой
{
	for ( int i = 0; i < degree; ++i)
	{
		res *= base;
	}
}
else //для чисел после запятой
{
	for ( int  i = 0; i > degree; --i)
	{
		res *= 1 / base;
	}
}
return res;
}

int dot (char *base15) //нахождение знака после запятой
{
	for (int i = 0; i < strlen(base15); i++)
    {
            if (base15[i] == '.')
        {
            return i;
        }
    }
    return strlen(base15);
}

int NumEquals (char *base15, int i) //эквивалент букв шестнадцатиричной в десятичной
{
	switch (base15[i])
	{
		case 'A':
		return 10;
		break;
		case 'B':
		return 11;
		break;
		case 'C':
		return 12;
		break;
		case 'D':
		return 13;
		break;
		case 'E':
		return 14;
		break;
		default:
		return (base15[i] - '0');
	}
}

void convert( int degree, char *base15 ) //функция преобразования шестнадцатиричного числа в десятичное
{
	double result = 0;
	for ( int i = 0; i < strlen(base15); i++)
	{
		if (base15[i]!= '.')
		{
		result += NumEquals (base15,i) * power (15,degree);
		degree--;
		}
	}
	printf("%f\n",result );
}

int main()
{
	char *base15 = "E.AB";
	convert (dot(base15) - 1,base15);
	return 0;
}
