#pragma once

#include <iostream>

#include "shoe.h"

void show_list(Shoes*, int); //������� ������� ��� ����� �� �����.
void showRecording(Shoes*); //������� ������� ������������ ������ ��������� �� �����.

void push_back(int&, Shoes*&); //������� ��������� ������ � ������ ��������.
void pop_back(int&, Shoes*&); //������� ������� ������ �� ������� ��������.

void pause(); // ������� ����, ���� �� �� ������ enter.
bool isEmpty(int); // ���������, ���� �� ������

bool Test(int); // ������� �� ������������� ��������� ���� � ����� ����������