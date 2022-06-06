#pragma once
class AssemCode
{
public:
	//сложение
	static int Sum(int a, int b);

	//вычитание
	static int Minus(int a, int b);

	//умножение
	static int Umn(int a, int b);

	//деление
	static int Del(int a, int b);

	//равенство
	static bool Equal(int a, int b);

	//неравенство
	static bool NoEqual(int a, int b);

	//меньше
	static bool Men(int a, int b);

	//больше
	static bool Bol(int a, int b);

	//больше или равно
	static bool BolEqual(int a, int b);

	//меньше или равно
	static bool MenEqual(int a, int b);

	//логическое не
	static int LogNo(int a);

	//логическое и
	static int LogAnd(int a, int b);

	// логическое xor
	static int LogXor(int a, int b);

	//логическое или
	static int LogOr(int a, int b);

	// индексирование массива
	static int Index(int* mass, int index);

	//сдвиг вправо
	static int SdvigR(int a, unsigned char h);

	// сдвиг влево
	static int SdvigL(int a, unsigned char h);

	// циклический сдвиг вправо
	static int SdvigRC(int a, unsigned char h);

	//циклический сдвиг влево
	static int SdvigLC(int a, unsigned char h);

};
