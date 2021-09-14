#include "workingWithFile.h";

void readFile(Shoes* array_shoes, int N)
{
    string path = "Shoes.dat"; // путь к файлу.
    ifstream fin; // отвечает за ввод данных из файла.

    fin.open(path, ios::binary);

    int MUSOR; // переменная для считывания колиечества записей ( она нам не нужна, так как у нас отдельная функция, которая возвращает количество записей)

    if (!fin.is_open())
        cout << "File opening error!\n";
    else
    {
        fin.read((char*)&(MUSOR), sizeof(MUSOR));

        for (int i = 0; i < N; i++) // ctrl+alt
        {    
            fin.read((char*)&(array_shoes->brand_name), sizeof(array_shoes->brand_name)); //считываем переменные типа int и Brand (enum).
            fin.read((char*)&(array_shoes->priseOfShue), sizeof(array_shoes->priseOfShue));
            fin.read((char*)&(array_shoes->sizeOfShue), sizeof(array_shoes->sizeOfShue));

            int len;                                                 //считываем строку, чтобы ее считать нужно сначала считать длину строки в переменную len,
            fin.read((char*)&len, sizeof(len));                      //а потом саму строку в поле структуры размера len.
            array_shoes->article_number.resize(len);
            fin.read((char*)&(array_shoes->article_number[0]), len);

            fin.read((char*)&len, sizeof(len));
            array_shoes->nameOfShue.resize(len);
            fin.read((char*)&(array_shoes->nameOfShue[0]), len);

            array_shoes++;
        }
    }
    fin.close();
}

int numberOfRecords()
{
    string path = "Shoes.dat";
    ifstream fin; // отвечает за ввод данных из файла.

    fin.open(path, ios::binary);

    int number;

    if (!fin.is_open())
        cout << "File opening error!\n";
    else
        fin.read((char*)&(number), sizeof(number)); // считываем в переменную number количество записей массива структур.

    fin.close();

    return number;
}

void saveShoes(Shoes* array_shoes, int N)
{
    string path1 = "Shoes.dat";
    ofstream fout;  // отвечает за вывод данных в файл.

    fout.open(path1, ios::binary);

    if (!fout.is_open())
        cout << "Error opening file!" << endl;
    else
    {
        fout.write((char*)&(N), sizeof(N)); // записываем количество записей в файл.

        for (int i = 0; i < N; ++i)
        {
            fout.write((char*)&(array_shoes->brand_name), sizeof(array_shoes->brand_name)); // записываем переменные типа int и Brand (enum).
            fout.write((char*)&(array_shoes->priseOfShue), sizeof(array_shoes->priseOfShue));
            fout.write((char*)&(array_shoes->sizeOfShue), sizeof(array_shoes->sizeOfShue));


            int len = array_shoes->article_number.size(); 
            fout.write((char*)&len, sizeof(len));                           // записываем сначала длину строки в файл, а потом саму строку.
            fout.write(array_shoes->article_number.c_str(), len);

            len = array_shoes->nameOfShue.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(array_shoes->nameOfShue.c_str(), len);

            array_shoes++;
        }
        cout << "Save was successful!" << endl << endl;
    }
    fout.close();
}

void keyOfAdminWrite()
{
    string password;
    string path1 = "Password.dat";
    ofstream fout;  // отвечает за вывод данных в файл.

    system("CLS");
    cout << "(0 - Come back)\nChange Password\n\nEnter a new password (without spaces): "; // меню.

    cin >> password;
    if (password[0] == '0') { system("CLS"); return; }
    fout.open(path1, ios::binary);

    if (!fout.is_open())
        cout << "Error opening file!" << endl;
    else
    {
        int len = password.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(password.c_str(), len);
    }

    system("CLS");
    cout << "Password changed successfully. Don't forget it!\nClose the program to save the password." << endl << endl;
    pause();
    system("CLS");
}

string keyOfAdminRead()
{
    string path = "Password.dat";
    ifstream fin; // отвечает за ввод данных из файла
    string password;

    fin.open(path, ios::binary);

    if (!fin.is_open())
        cout << "File opening error!\n";
    else
    {
        int len;                                                 
        fin.read((char*)&len, sizeof(len));                     
        password.resize(len);
        fin.read((char*)&(password[0]), len);
    }
    return password;
}