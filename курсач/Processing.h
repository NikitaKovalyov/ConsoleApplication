#pragma once

#include "shoe.h"; // подключаем заголовочный файл shoe.h, потому что там хранится наша структура, которую мы передаем в функции.
#include "editing.h"; // подключаем заголовочный файл shoe.h, потому что там хранятся функции, которые испльзуются в соответствующем cpp файле

void individual_task(Shoes*, int); //функция выводит обувь артикула x и размера y.

void sorting(Shoes*, int); // некое меню сортировки обуви по различным параметрам
int minimum_fromPrice(Shoes*, int, int); // возвращает индекс структуры с минимальной ценой обуви
void selectionSortPrice(Shoes*, int); // сортировка выбором по цене обуви
int minimum_fromSize(Shoes*, int, int); // возвращает индекс структуры с минимальным размером обуви
void selectionSortSize(Shoes*, int); // сортировка выбором по размеру обуви

void search_Shoe(Shoes*, int); // функция выводит меню поиска обуви по 3 критериям (размер, цена, название бренда).
void search_shoeSize(Shoes*, int); // функция выводит обувь размера, введеннго с клавиатуры.
void search_shoePrise(Shoes*, int); // функция выводит всю обувь ценой ниже, чем ввведенная с клавиатуры.
void search_shoeBrand_name(Shoes*, int); // функция выводит обувь бренда, введенного с клавиатуры.