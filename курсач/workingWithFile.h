#pragma once

#include <fstream>

#include "shoe.h"; // подключаем заголовочный файл shoe.h, потому что там хранится наша структура.
#include "editing.h"; // подключаем заголовочный файл editing.h, потому что там хранятся функции, которые мы используем в соответствующем cpp файле

int numberOfRecords(); // функция, возвращающая из файла количество записей в массиве структур.
void readFile(Shoes*, int); // считываем записи из файла Shoes.dat в нашу структуру.
void saveShoes(Shoes*, int); // сохраняем записи в файл Shoes.dat.

void keyOfAdminWrite(); // функция изменения пароля.
string keyOfAdminRead(); // функция, которая возвращает пароль.