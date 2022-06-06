#pragma once
class AssemCode
{
public:
	//��������
	static int Sum(int a, int b);

	//���������
	static int Minus(int a, int b);

	//���������
	static int Umn(int a, int b);

	//�������
	static int Del(int a, int b);

	//���������
	static bool Equal(int a, int b);

	//�����������
	static bool NoEqual(int a, int b);

	//������
	static bool Men(int a, int b);

	//������
	static bool Bol(int a, int b);

	//������ ��� �����
	static bool BolEqual(int a, int b);

	//������ ��� �����
	static bool MenEqual(int a, int b);

	//���������� ��
	static int LogNo(int a);

	//���������� �
	static int LogAnd(int a, int b);

	// ���������� xor
	static int LogXor(int a, int b);

	//���������� ���
	static int LogOr(int a, int b);

	// �������������� �������
	static int Index(int* mass, int index);

	//����� ������
	static int SdvigR(int a, unsigned char h);

	// ����� �����
	static int SdvigL(int a, unsigned char h);

	// ����������� ����� ������
	static int SdvigRC(int a, unsigned char h);

	//����������� ����� �����
	static int SdvigLC(int a, unsigned char h);

};
