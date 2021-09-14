#pragma once

#include "shoe.h"; // ���������� ������������ ���� shoe.h, ������ ��� ��� �������� ���� ���������, ������� �� �������� � �������.
#include "editing.h"; // ���������� ������������ ���� shoe.h, ������ ��� ��� �������� �������, ������� ����������� � ��������������� cpp �����

void individual_task(Shoes*, int); //������� ������� ����� �������� x � ������� y.

void sorting(Shoes*, int); // ����� ���� ���������� ����� �� ��������� ����������
int minimum_fromPrice(Shoes*, int, int); // ���������� ������ ��������� � ����������� ����� �����
void selectionSortPrice(Shoes*, int); // ���������� ������� �� ���� �����
int minimum_fromSize(Shoes*, int, int); // ���������� ������ ��������� � ����������� �������� �����
void selectionSortSize(Shoes*, int); // ���������� ������� �� ������� �����

void search_Shoe(Shoes*, int); // ������� ������� ���� ������ ����� �� 3 ��������� (������, ����, �������� ������).
void search_shoeSize(Shoes*, int); // ������� ������� ����� �������, ��������� � ����������.
void search_shoePrise(Shoes*, int); // ������� ������� ��� ����� ����� ����, ��� ���������� � ����������.
void search_shoeBrand_name(Shoes*, int); // ������� ������� ����� ������, ���������� � ����������.