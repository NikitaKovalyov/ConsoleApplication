#pragma once

#include <iostream>

#include "shoe.h"

void show_list(Shoes*, int); //функция выводит всю обувь на экран.
void showRecording(Shoes*); //функция выводит определенную запись структуры на экран.

void push_back(int&, Shoes*&); //функция добавляет запись в массив структур.
void pop_back(int&, Shoes*&); //функция удаляет запись из массива структур.

void pause(); // функция ждет, пока мы не нажмем enter.
bool isEmpty(int); // проверяет, пуст ли массив

bool Test(int); // проерка на принадлежноть вводимого типа с типом переменной