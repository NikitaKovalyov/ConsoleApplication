#include "workingWithFile.h";

void readFile(Shoes* array_shoes, int N)
{
    string path = "Shoes.dat"; // ���� � �����.
    ifstream fin; // �������� �� ���� ������ �� �����.

    fin.open(path, ios::binary);

    int MUSOR; // ���������� ��� ���������� ����������� ������� ( ��� ��� �� �����, ��� ��� � ��� ��������� �������, ������� ���������� ���������� �������)

    if (!fin.is_open())
        cout << "File opening error!\n";
    else
    {
        fin.read((char*)&(MUSOR), sizeof(MUSOR));

        for (int i = 0; i < N; i++) // ctrl+alt
        {    
            fin.read((char*)&(array_shoes->brand_name), sizeof(array_shoes->brand_name)); //��������� ���������� ���� int � Brand (enum).
            fin.read((char*)&(array_shoes->priseOfShue), sizeof(array_shoes->priseOfShue));
            fin.read((char*)&(array_shoes->sizeOfShue), sizeof(array_shoes->sizeOfShue));

            int len;                                                 //��������� ������, ����� �� ������� ����� ������� ������� ����� ������ � ���������� len,
            fin.read((char*)&len, sizeof(len));                      //� ����� ���� ������ � ���� ��������� ������� len.
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
    ifstream fin; // �������� �� ���� ������ �� �����.

    fin.open(path, ios::binary);

    int number;

    if (!fin.is_open())
        cout << "File opening error!\n";
    else
        fin.read((char*)&(number), sizeof(number)); // ��������� � ���������� number ���������� ������� ������� ��������.

    fin.close();

    return number;
}

void saveShoes(Shoes* array_shoes, int N)
{
    string path1 = "Shoes.dat";
    ofstream fout;  // �������� �� ����� ������ � ����.

    fout.open(path1, ios::binary);

    if (!fout.is_open())
        cout << "Error opening file!" << endl;
    else
    {
        fout.write((char*)&(N), sizeof(N)); // ���������� ���������� ������� � ����.

        for (int i = 0; i < N; ++i)
        {
            fout.write((char*)&(array_shoes->brand_name), sizeof(array_shoes->brand_name)); // ���������� ���������� ���� int � Brand (enum).
            fout.write((char*)&(array_shoes->priseOfShue), sizeof(array_shoes->priseOfShue));
            fout.write((char*)&(array_shoes->sizeOfShue), sizeof(array_shoes->sizeOfShue));


            int len = array_shoes->article_number.size(); 
            fout.write((char*)&len, sizeof(len));                           // ���������� ������� ����� ������ � ����, � ����� ���� ������.
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
    ofstream fout;  // �������� �� ����� ������ � ����.

    system("CLS");
    cout << "(0 - Come back)\nChange Password\n\nEnter a new password (without spaces): "; // ����.

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
    ifstream fin; // �������� �� ���� ������ �� �����
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