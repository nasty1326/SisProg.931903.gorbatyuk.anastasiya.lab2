#include <iostream>
#include "Header1.h"

void BubSort(int* mass, int n)
{
	_asm {
		// type short -> 2 
		// type int -> 4 
		// type long -> 8

		mov edx, n
		dec edx									// ����� n-1 ���������� ��������.
		oloop :
		mov ecx, edx						// ������� ����� ��� �������������, �� �� ���� ���������.
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
		add esi, type mass			// ��������� � ���������� �������� arr
		loop iloop				    // loop - ��������� �������(ecx) �� ������� � �������� ���� �� �� ����� ����
		dec edx // decrease(���������) edx
		jnz oloop // ���� edx != 0, �� ��������� ����
	}

}

