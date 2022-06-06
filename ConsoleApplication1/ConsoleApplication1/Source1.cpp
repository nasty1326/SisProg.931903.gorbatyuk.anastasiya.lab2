#include <iostream>
#include "Header1.h"

void BubSort(int* mass, int n)
{
	_asm {
		// type short -> 2 
		// type int -> 4 
		// type long -> 8

		mov edx, n
		dec edx									// Нужно n-1 внутренних итераций.
		oloop :
		mov ecx, edx						// Большие числа уже отсортированы, их не надо проверять.
		mov esi, mass
		iloop :
		mov eax, [esi]					// mov eax, mass[i]
		mov ebx, [esi + type mass]		// mov ebx, mass[i + 4]
		cmp eax, ebx
		jle noswap
		swap :
		mov[esi + type mass], eax	// mov mass[i + 4], eax
		mov[esi], ebx				// mov mass[i], ebx
		noswap :
		add esi, type mass			// двигаемся к следующему элементу arr
		loop iloop				    // loop - уменьшить счётчик(ecx) на единицу и прыгнуть если он не равен нулю
		dec edx // decrease(уменьшить) edx
		jnz oloop // Если edx != 0, то повторить цикл
	}

}

