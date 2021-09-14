#pragma once

#include <string>

using namespace std;

enum Brand
{
    BRAND_ADIDAS = 1,
    BRAND_NIKE = 2,
    BRAND_ECCO = 3,
    BRAND_BARKER = 4,
    BRAND_CROCS = 5,
    BRAND_COLUMBIA = 6,
    BRAND_CONVERSE = 7,
    BRAND_LACOSTE = 8,
    BRAND_VANS = 9,
    BRAND_PORRONET = 10,
};

struct Shoes                                             //объявляем структура, содержащую следующие поля:
{
    string article_number;                               //артикул
    string nameOfShue;                                   //название обуви
    float priseOfShue; // поиск, сортировка              //цена обуви
    int sizeOfShue; // поиск, сортировка                 //размер обуви
    Brand brand_name; // поиск                           //название бренда обуви.
};
