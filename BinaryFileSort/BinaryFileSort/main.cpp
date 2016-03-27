// BinaryFileSort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "debugService.h"
#include "LargeBinaryFileSortClass.h"
/*

���� ���� ���� ������� ��� ��������:

���, ��������, ����� �������:

���������� �������� ��������� (���������� ����������), ������� ����� ����������� �� 
����������� ������� �������� ���� ����������� 32-� ��������� ����� �����. ��� ����:
� ������ �������� ����� ����������� ������ ������ ��������� ����������� ������, �������
���� ����� 128 ��. ������ ����� ����� ���� ����� 4 ��������. ������ ����� ������ 4 ������.
� ���� ���������� ��������� ������������ ��� �������� ���������� ���������� � ���������
����� � ��� �������� ������������� �����������. (��� �������, � 2 ���� ������ �������
�������� �����)
� ��������� ����� ��������������� C++14 ����������� ������������ � release-������������
� ������������ �� ��������.
� ����� ����� ���������� �� SSD �����. �� ���������� ����� ����������� 8-� �������
���������.
� ������� ���� ����� ���������� � ��� �� ���������� ��� � ����������� ���� � �����
���������� input. ��������������� ���� ������ ���������� � ���� �� ���������� � �����
��� output.
� ���������� �������� ������������� ���������� � ����������� ���������� STL.
� ���������� �������� ������������� ��������������� ��� ��������� ������ ���������.
� ���������� ������� ������ ��� �������� ��� �������� ������ ��������� � ��������������
������.
*/
int main()
{
	DebugService debugService;
	debugService.CreateInputFile();

	LargeBinaryFileSortClass binarySorter;
	binarySorter.Sort();

    return 0;
}

