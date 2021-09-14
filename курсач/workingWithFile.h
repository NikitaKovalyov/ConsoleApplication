#pragma once

#include <fstream>

#include "shoe.h"; // ���������� ������������ ���� shoe.h, ������ ��� ��� �������� ���� ���������.
#include "editing.h"; // ���������� ������������ ���� editing.h, ������ ��� ��� �������� �������, ������� �� ���������� � ��������������� cpp �����

int numberOfRecords(); // �������, ������������ �� ����� ���������� ������� � ������� ��������.
void readFile(Shoes*, int); // ��������� ������ �� ����� Shoes.dat � ���� ���������.
void saveShoes(Shoes*, int); // ��������� ������ � ���� Shoes.dat.

void keyOfAdminWrite(); // ������� ��������� ������.
string keyOfAdminRead(); // �������, ������� ���������� ������.