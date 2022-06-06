#include "Header.h"

//��������
int AssemCode::Sum(int a, int b)
{
	_asm {
		mov eax, a //�������� � eax a
		add eax, b // ��������� �� eax b
		
	}

}

//���������
int AssemCode::Minus(int a, int b)
{
	_asm {
		mov eax, a //�������� � eax a
		sub eax, b // �������� �� eax b
	}
}

//���������
int AssemCode::Umn(int a, int b)
{
	_asm {
		mov eax, a //�������� � eax a
		imul eax, b // �������� ��������� eax �� b

	}
}

//�������
int AssemCode::Del(int a, int b)
{
	int result=0;
	_asm {
		mov eax, a //�������� � eax a
		mov edx, 0 // �������� edx
		mov ebx, b //�������� � ebx b
		idiv ebx // idiv eax(���������) [operand2](�����������)
		// ������� ���� ���������� � edx, � ������� � eax
		mov result, eax // edx ��� �� ����������
	}
	return result;
}

//���������
bool AssemCode::Equal(int a, int b)
{
	bool result = false;
	_asm {
		mov eax, a
		cmp eax, b  // �������� ��� ��������� (0 | 1)
		jz EQUAL // jz - jump if zero; �������, ���� ��� ��������� ����� ����, �.�. ������������ ����� �����

		mov result, 0 // false
		jmp END

		EQUAL :
		mov result, 1 // true

			END :
	}
	return result;
}

//�����������
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

//������
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

//������
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

//������ ��� �����
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

//������ ��� �����
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

//���������� ��
int AssemCode::LogNo(int a)
{
	
	_asm {
		mov eax, a
		not eax
	}
	

}

//���������� �
int AssemCode::LogAnd(int a, int b)
{
	_asm {
		mov eax, a
		and eax, b
	}


}

// ���������� xor
int AssemCode::LogXor(int a, int b)
{
	_asm {
		mov eax, a
		xor eax, b
	}

}

//���������� ���
int AssemCode::LogOr(int a, int b)
{
	_asm {
		mov eax, a
		or eax, b
	}

}

// �������������� �������
int AssemCode::Index(int* mass, int index)
{
	_asm {
		mov eax, index // ������ ������� ��������
		mov ebx, mass // ������ �������
		mov eax, [ebx + 4 * eax] // [] - ���������� ������ - �������� �������� �� ������
	}

}

//����� ������
int AssemCode::SdvigR(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		shr eax, cl // shr - shift right
	}
}

// ����� �����
int AssemCode::SdvigL(int a, unsigned char h)
{
	// ecx - 32 ����
	// cx - ������ 16 ����� ecx
	// cl - ������ 8 ����� ecx
	_asm {
		mov eax, a
		// ��� 'mov' �����, ����� �������� ����� ������ ������
		mov cl, h // cl(8 �����), shift(8 �����)
		shl eax, cl // shl - shift left
	}
}

// ����������� ����� ������
int AssemCode::SdvigRC(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		ror eax, cl // rotate right
	}
}

//����������� ����� �����
int AssemCode::SdvigLC(int a, unsigned char h)
{
	_asm {
		mov eax, a
		mov cl, h
		rol eax, cl // rotate left
	}
}
