#include "editing.h"; // редактирование.
#include "Processing.h"; // обработка.
#include "workingWithFile.h"; // работа с файлами.
#include "shoe.h"; // структура обуви


void user_functionality(Shoes*& , int&); // функци€ выводит функционал пользовател€.
void administrator_functionality(Shoes*& , int&); // функци€ выводит функционал администратора.
bool checkPassword(string); // провер€ет пароль на правильность


int main()
{
    setlocale(LC_ALL, "Rus");

    int N = numberOfRecords(); 

    Shoes* array_shoes = new Shoes[N];  // объ€вл€ем массив структур размера N.

    readFile(array_shoes, N);

    //keyOfAdminWrite();

    string PASSWORDFile = keyOfAdminRead();  // пароль администратора.
    int answer;
    bool flag = true;

    while (flag)
    {   
        while (true) // проверка на принадлежноть вводимого типа с типом переменной
        {
            cout << "1 - Log in as a user\n2 - Log in as an administrator\n3 - Save and exit\n->";
            cin >> answer;
            if (Test(answer)) break; 
            else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
        }

        switch (answer)
        {
        case 1: user_functionality(array_shoes, N); break;
        case 2: system("CLS"); cout << "Enter the password: ";
            if (checkPassword(PASSWORDFile)) { administrator_functionality(array_shoes, N); break; }
            else { cout << "Invalid password!" << endl << endl; pause(); system("CLS"); break; }
        case 3: flag = false; break;
        default: system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; break;
        }
    }
    system("CLS");

    saveShoes(array_shoes, N);

    delete[] array_shoes; // очистка пам€ти
    array_shoes = NULL; // теперь указатель указывает на NULL
    return 0;
}

void user_functionality(Shoes*& array_shoes, int &N)
{
    system("CLS");
    cout << "Welcome to our shoe store!" << endl << endl;
    int answer;
    bool flag = true;
    while (flag)
    {
        while (true) // проверка на принадлежноть вводимого типа с типом переменной
        {
            cout << "1 - View all shoes\n2 - Sorting  for shoes by criteria\n3 - Search for shoes by criteria\n4 - Displaying a list of shoes of article x and size y\n5 - Come back\n->";
            cin >> answer;
            if (Test(answer)) break;
            else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
        }

        switch (answer)
        {
        case 1: system("CLS"); show_list(array_shoes, N); pause(); system("CLS"); break;
        case 2: sorting(array_shoes, N); break;
        case 3: search_Shoe(array_shoes, N); break;
        case 4: individual_task(array_shoes, N); break;
        case 5:  flag = false; system("CLS"); break;
        default: system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; break;
        }
    }
}

void administrator_functionality(Shoes*& array_shoes, int &N)
{
    system("CLS");
    cout << "You are logged in as an administrator!" << endl << endl;
    int answer;
    bool flag = true;
    while (flag)
    {
        while (true) // проверка на принадлежноть вводимого типа с типом переменной
        {
            cout << "1 - View all shoes\n2 - Add shoes\n3 - Delete shoes\n4 - Change password\n5 - Come back\n->";
            cin >> answer;
            if (Test(answer)) break;
            else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
        }

        switch (answer)
        {
        case 1: system("CLS"); show_list(array_shoes, N); pause(); system("CLS"); break;
        case 2: push_back(N, array_shoes); break;
        case 3: pop_back(N, array_shoes); break;
        case 4: keyOfAdminWrite(); break;
        case 5:  flag = false; system("CLS"); break;
        default:system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; break;
        }
    }
}

bool checkPassword(string PASSWORDFile)
{
    string password;
    cin >> password;
    if (password == PASSWORDFile) return true;
    else return false;
}