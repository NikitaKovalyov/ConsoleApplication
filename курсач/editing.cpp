#include "editing.h";

void show_list(Shoes* array_shoes, int N)
{
    if (!isEmpty(N))
    {
        cout << "№\tShoe brand\tShoe price\tShoe size\tShoe article number\tShoe name" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < N; i++)
        {
            cout << i + 1 << "\t";
            showRecording(array_shoes);
            array_shoes++;
        }
        cout << endl;
    }
    else
        cout << "No shoes in stock!" << endl;
}

void showRecording(Shoes* array_shoes)
{
    switch (array_shoes->brand_name)
    {
    case 1: cout << "Adidas\t\t"; break;
    case 2: cout << "Nike\t\t"; break;
    case 3: cout << "Ecco\t\t"; break;
    case 4: cout << "Barker\t\t"; break;
    case 5: cout << "Crocs\t\t"; break;
    case 6: cout << "Columbia\t"; break;
    case 7: cout << "Converse\t"; break;
    case 8: cout << "Lacoste\t\t"; break;
    case 9: cout << "Vans\t\t"; break;
    case 10: cout << "Porronet\t"; break;
    }

    cout << array_shoes->priseOfShue << "\t\t";
    cout << array_shoes->sizeOfShue << "\t\t";
    cout << array_shoes->article_number << "\t\t";
    cout << array_shoes->nameOfShue << endl;
}

void push_back(int& N, Shoes*& array_shoes)
{
    system("CLS");
    Shoes* newArray = new Shoes[N + 1]; // создаём массив размером на 1 больше исходного.
    for (int i = 0; i < N; i++)
    {
        (newArray + i)->article_number = (array_shoes + i)->article_number; // заполняем новый массив данными исходного массива.
        (newArray + i)->nameOfShue = (array_shoes + i)->nameOfShue;
        (newArray + i)->priseOfShue = (array_shoes + i)->priseOfShue;
        (newArray + i)->sizeOfShue = (array_shoes + i)->sizeOfShue;
        (newArray + i)->brand_name = (array_shoes + i)->brand_name;
    }
    // вводим значения добавленной записи массива структур.
    cout << "(0 - Come back)\nEnter the name of the shoe brand: 1. Adidas, 2. Nike, 3. Ecco, 4. Barker, 5. Crocs, 6. Columbia, 7. Converse, 8. Lacoste, 9. Vans, 10. Porronet: ";
    int answer;
    while (true)
    {
        cin >> answer;
        if (answer == 0) { system("CLS"); return; }
        switch (answer)
        {
        case 1: (newArray + N)->brand_name = BRAND_ADIDAS; break;
        case 2: (newArray + N)->brand_name = BRAND_NIKE; break;
        case 3: (newArray + N)->brand_name = BRAND_ECCO; break;
        case 4: (newArray + N)->brand_name = BRAND_BARKER; break;
        case 5: (newArray + N)->brand_name = BRAND_CROCS; break;
        case 6: (newArray + N)->brand_name = BRAND_COLUMBIA; break;
        case 7: (newArray + N)->brand_name = BRAND_CONVERSE; break;
        case 8: (newArray + N)->brand_name = BRAND_LACOSTE; break;
        case 9: (newArray + N)->brand_name = BRAND_VANS; break;
        case 10: (newArray + N)->brand_name = BRAND_PORRONET; break;
        }
        cout << "=============================" << endl;
        if ((newArray + N)->brand_name > 0 and (newArray + N)->brand_name < 11) break;
        else cout << "You entered incorrect data! Try again: " << endl;
    }
    
    cout << "Enter the price of shoes: ";
    cin >> (newArray + N)->priseOfShue;
    cout << "=============================" << endl;
    cout << "Enter shoe size: ";
    cin >> (newArray + N)->sizeOfShue;
    cout << "=============================" << endl;
    cout << "Enter the article of the shoe. The article must begin with the letters M (for men), W (for women) and C (for children): ";
    cin >> (newArray + N)->article_number;
    cout << "=============================" << endl;
    cout << "Enter the name of the shoe: ";
    cin >> (newArray + N)->nameOfShue;
    cout << "=============================" << endl;
    N++;

    system("CLS");
    cout << "Shoes added." << endl << endl;
    pause(); system("CLS");

    delete[] array_shoes; // освобождаем память, в которой хранятся данные исходного массива.
    array_shoes = newArray; // теперь наш указатель указывает на новый массив.
}

void pop_back(int& N, Shoes*& array_shoes)
{
    if (!isEmpty(N))
    {
        system("CLS");
        int answer;
        show_list(array_shoes, N);

        cout << "(0 - Come back)\nEnter the number of the shoes you want to remove from the list: ";
        while (true)
        {
            cin >> answer;
            if (answer == 0) { system("CLS"); return; }
            if (Test(answer) and answer > 0 and answer <= N)
                break;
            else
                cout << "You entered incorrect data! Try again: ";
        }

        swap(*(array_shoes + answer - 1), *(array_shoes + N - 1)); // меняем местами запись, которую мы выбрали для удаления с последней.
        Shoes* newArr = new Shoes[--N]; // создали массив на единицу меньше исходного.
        for (int i = 0; i < N; i++)
        {
            (newArr + i)->article_number = (array_shoes + i)->article_number; // заполняем новый массив данными исходного массива.
            (newArr + i)->nameOfShue = (array_shoes + i)->nameOfShue;
            (newArr + i)->priseOfShue = (array_shoes + i)->priseOfShue;
            (newArr + i)->sizeOfShue = (array_shoes + i)->sizeOfShue;
            (newArr + i)->brand_name = (array_shoes + i)->brand_name;
        }
        delete[] array_shoes; // освобождаем память, в которой хранятся данные исходного массива.

        array_shoes = newArr; // теперь наш указатель указывает на новый массив.
        system("CLS");
        cout << "Shoes deleted!" << endl << endl;
        pause(); system("CLS");
    }
    else
    {
        system("CLS");
        cout << "You cannot delete anything, as there is no stock." << endl << endl;
        pause(); system("CLS");
    }
}

void pause()
{
    cout << "To continue, press Enter . . .";
    cin.get(); cin.get();
}

bool isEmpty(int N)
{
    bool flag = (N > 0) ? false : true;
    return flag;
}

bool Test(int ind)
{
    if (cin.good()) return true; // // проерка на принадлежноть вводимого типа с типом переменной
    else
    {
        cin.clear(); // Очищает флаг ошибки на cin (чтобы будущие операции ввода-вывода работали правильно)
        cin.ignore(32767, '\n'); // Переход к следующей строке
        return false;
    }
}