#include "Header.h"

//сложение
int AssemCode::Sum(int a, int b)
{
	_asm {
		mov eax, a //копируем в eax a
		add eax, b // добавляем из eax b
		
	}

}

//вычитание
int AssemCode::Minus(int a, int b)
{
	_asm {
		mov eax, a //копируем в eax a
		sub eax, b // вычитаем из eax b
	}
}

//умножение
int AssemCode::Umn(int a, int b)
{
	_asm {
		mov eax, a //копируем в eax a
		imul eax, b // знаковое умножение eax на b

	}
}

//деление
int AssemCode::Del(int a, int b)
{
	int result=0;
	_asm {
		mov eax, a //копируем в eax a
		mov edx, 0 // очистить edx
		mov ebx, b //копируем в ebx b
		idiv ebx // idiv eax(числитель) [operand2](знаменатель)
		// Старшие биты результата в edx, а младшие в eax
		mov result, eax // edx нас не интересует
	}
	return result;
}

//равенство
bool AssemCode::Equal(int a, int b)
{
	bool result = false;
	_asm {
		mov eax, a
		cmp eax, b  // меняется бит сравнения (0 | 1)
		jz EQUAL // jz - jump if zero; прыгать, если бит сравнения равен нулю, т.е. сравниваемые числа равны

		mov result, 0 // false
		jmp END

		EQUAL :
		mov result, 1 // true

			END :
	}
	return result;
}

//неравенство
bool AssemCode::NoEqual(int a, int b)
{
	_asm {
		mov eax, a
		cmp eax, b
		jz EQUAL
		mov eax, 1
		jmp END

		EQUAL :
		mov eax, 0

			END :
	}
}

//меньше
bool AssemCode::Men(int a, int b)
{
	_asm {
		mov eax, a
		cmp eax, b
		jl LESS // jl - jump if less <
		mov eax, 0
		jmp END

		LESS :
		mov eax, 1

			END :
	}
}

//больше
bool AssemCode::Bol(int a, int b)
{
	_asm {
		mov eax, a
		cmp eax, b
		jg GREATER // >
		mov eax, 0
		jmp END

		GREATER :
		mov eax, 1

			END :
	}
}

//больше или равно
bool AssemCode::BolEqual(int a, int b)
{
	_asm {
		mov eax, a
		cmp eax, b
		jge GREATEREQUAL // >=
		mov eax, 0
		jmp END

		GREATEREQUAL :
		mov eax, 1

			END :
	}
}

//меньше или равно
bool AssemCode::MenEqual(int a, int b)
{
	_asm {
		mov eax, a
		cmp eax, b
		jle LESSEQUAL // jump if less equal <=
		mov eax, 0
		jmp END

		LESSEQUAL :
		mov eax, 1

			END :
	}
}

//логическое не
int AssemCode::LogNo(int a)
{
	
	_asm {
		mov eax, a
		not eax
	}
	

}

//логическое и
int AssemCode::LogAnd(int a, int b)
{
	_asm {
		mov eax, a
		and eax, b
	}


}

// логическое xor
int AssemCode::LogXor(int a, int b)
{
	_asm {
		mov eax, a
		xor eax, b
	}

}

//логическое или
int AssemCode::LogOr(int a, int b)
{
	_asm {
		mov eax, a
		or eax, b
	}

}

// индексирование массива
int AssemCode::Index(int* mass, int index)
{
	_asm {
		mov eax, index // индекс нужного элемента
		mov ebx, mass // начало массива
		mov eax, [ebx + 4 * eax] // [] - квадратные скобки - получить значение по адресу
	}

}

//сдвиг вправо
int AssemCode::SdvigR(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		shr eax, cl // shr - shift right
	}
}

// сдвиг влево
int AssemCode::SdvigL(int a, unsigned char h)
{
	// ecx - 32 бита
	// cx - первые 16 битов ecx
	// cl - первые 8 битов ecx
	_asm {
		mov eax, a
		// для 'mov' нужно, чтобы операнды имели равный размер
		mov cl, h // cl(8 битов), shift(8 битов)
		shl eax, cl // shl - shift left
	}
}

// циклический сдвиг вправо
int AssemCode::SdvigRC(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		ror eax, cl // rotate right
	}
}

//циклический сдвиг влево
int AssemCode::SdvigLC(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		rol eax, cl // rotate left
	}
}
