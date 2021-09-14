#include "Processing.h";

void individual_task(Shoes* array_shoes, int N)
{
    system("CLS");
    string articl;
    int size, kol = 0;
    if (!isEmpty(N)) 
    {
        cout << "(0 - Come back)\nEnter the article of the shoe.The article must begin with the letters M(for men), W(for women) and C(for children). Example: M1234567, D0000000\n->";
        while (true)
        {
            cin >> articl;
            if (articl[0] == '0') { system("CLS"); return; }
            if (articl[0] == 'M' or articl[0] == 'W' or articl[0] == 'C')  // если артикул начинается с M, W, C идем дальше, иначе нужно ввести артикул заново.
                break;
            else system("CLS"); cout << "(0 - Come back)\nThe article must start with M, W or C! Try entering the article number again.\n->";
        }

        while (true) // проверка на принадлежноть вводимого типа с типом переменной
        {
            cout << "Enter your shoe size: ";
            cin >> size;
            if (size == 0) { system("CLS"); return; }
            if (Test(size)) break;
            else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
        }

        system("CLS");
        for (int i = 0; i < N; i++)
        {
            if (array_shoes->article_number[0] == articl[0] and array_shoes->sizeOfShue == size)
            {
                kol++;
                if (kol == 1)
                {
                    cout << "list of shoes of size  " << size << " and article -  " << articl[0] << "......." << ":" << endl << endl;
                    cout << "№\tShoe brand\tShoe price\tShoe size\tShoe article number\tShoe name" << endl;
                    cout << "------------------------------------------------------------------------------------------" << endl;
                }
                cout << kol << "\t"; showRecording(array_shoes);
            }
            array_shoes++;
        }
        if (kol == 0)
            cout << "Shoes article " << articl << " and size " << size << " - no." << endl;
        cout << endl;
    }
    else 
        cout << "In the array no records." << endl << endl; pause(); system("CLS");
}

int minimum_fromPrice(Shoes* array_shoes, int position, int N)
{
    int min_index = position;

    for (int count = position + 1; count < N; count++)
    {
        if ((array_shoes + count)->priseOfShue < (array_shoes + min_index)->priseOfShue) min_index = count;
    }
    return min_index;
}

void selectionSortPrice(Shoes* array_shoes, int N)
{
    for (int count = 0; count < N - 1; count++)
    {
        swap(*(array_shoes + count), *(array_shoes + minimum_fromPrice(array_shoes, count, N)));
    }
}

int minimum_fromSize(Shoes* array_shoes, int position, int N)
{
    int min_index = position;

    for (int count = position + 1; count < N; count++)
    {
        if ((array_shoes + count)->sizeOfShue < (array_shoes + min_index)->sizeOfShue) min_index = count;
    }
    return min_index;
}

void selectionSortSize(Shoes* array_shoes, int N)
{
    for (int count = 0; count < N - 1; count++)
    {
        swap(*(array_shoes + count), *(array_shoes + minimum_fromSize(array_shoes, count, N)));
    }
}

void sorting(Shoes* array_shoes, int N)
{
    system("CLS");
    if (!isEmpty(N))
    {
        int answer;
        while (true)
        {
            while (true) // проверка на принадлежноть вводимого типа с типом переменной
            {
                cout << "(0 - Come Back)\n1 - Sorting shoes by price\n2 - Sorting shoes by size\n->";
                cin >> answer;
                if (answer == 0) { system("CLS"); return; }
                if (Test(answer)) break;
                else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
            }

            if (answer == 1) {
                selectionSortPrice(array_shoes, N);
                system("CLS");
                cout << "Sort shoes in ascending order of price." << endl << endl;
                show_list(array_shoes, N);
                pause(); system("CLS");
                break;
            }
            else if (answer == 2)
            {
                selectionSortSize(array_shoes, N);
                system("CLS");
                cout << "Sort shoes in ascending order of size." << endl << endl;
                show_list(array_shoes, N);
                pause(); system("CLS");
                break;
            }
            else system("CLS"); cout << "You entered incorrect data! Try again:" << endl << endl;
        }
    }
    else
        cout << "In the array no records." << endl << endl;
}

void search_Shoe(Shoes* array_shoes, int N)
{
    system("CLS");
    if (!isEmpty(N))
    {
        bool flag = true;
        int answer;
       
        while (flag)
        {
            while (true) // проверка на принадлежноть вводимого типа с типом переменной
            {
                cout << "(0 - Come back)\n1 - Search for shoes by size\n2 - Search for shoes by price\n3 - Search for shoes by brand name\n->";
                cin >> answer;
                if (answer == 0) { system("CLS"); return; }
                if (Test(answer)) break;
                else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
            }

            switch (answer)
            {
            case 1: search_shoeSize(array_shoes, N); flag = false;
                break;
            case 2: search_shoePrise(array_shoes, N); flag = false;
                break;
            case 3: search_shoeBrand_name(array_shoes, N); flag = false;
                break;
            default:  system("CLS"); cout << "You entered incorrect data! Try again:" << endl << endl;
                break;
            }
        }
    }
    else 
        cout << "In the array no records." << endl << endl; pause(); system("CLS");
}

void search_shoeSize(Shoes* array_shoes, int N)
{
    int size, kol = 0;

    system("CLS");
    cout << "Enter the shoe size you need: ";

    while (true) // проверка на принадлежноть вводимого типа с типом переменной
    {
        cin >> size;
        if (Test(size)) break;
        else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
    }
    
    system("CLS");

    for (int i = 0; i < N; i++)
    {
        if (array_shoes->sizeOfShue == size)
        {
            kol++;
            if (kol == 1)
            {
                cout << "Size " << size << " Shoe List:" << endl << endl;
                cout << "№\tShoe brand\tShoe price\tShoe size\tShoe article number\tShoe name" << endl;
                cout << "------------------------------------------------------------------------------------------" << endl;
            }
            cout << kol << "\t";
            showRecording(array_shoes);
        }
        array_shoes++;
    }
    if (kol == 0)
        cout << "There are no shoes of this size!" << endl << endl;
    cout << endl;
}

void search_shoePrise(Shoes* array_shoes, int N)
{
    int geld, kol = 0;

    system("CLS");
    cout << "How much money do you want to spend on shoes? " << endl;

    while (true) // проверка на принадлежноть вводимого типа с типом переменной
    {
        cin >> geld;
        if (Test(geld)) break;
        else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
    }

    system("CLS");
    for (int i = 0; i < N; i++)
    {
        if (array_shoes->priseOfShue <= geld)
        {
            kol++;
            if (kol == 1)
            {
                cout << "For this kind of money, we can offer you the following options:" << endl << endl;
                cout << "№\tShoe brand\tShoe price\tShoe size\tShoe article number\tShoe name" << endl;
                cout << "------------------------------------------------------------------------------------------" << endl;
            }
            cout << kol << "\t";
            showRecording(array_shoes);
        }
        array_shoes++;
    }
    if (kol == 0)
        cout << "Unfortunately, we don't have shoes for that kind of money." << endl << endl;
    cout << endl;
}

void search_shoeBrand_name(Shoes* array_shoes, int N)
{
    int brandd, kol = 0;
    system("CLS");
    while (true)
    {
        while (true) // проверка на принадлежноть вводимого типа с типом переменной
        {
            cout << "Enter the name of the shoe brand: 1. Adidas, 2. Nike, 3. Ecco, 4. Barker, 5. Crocs, 6. Columbia, 7. Converse, 8. Lacoste, 9. Vans, 10. Porronet: ";
            cin >> brandd;
            if (Test(brandd)) break;
            else { system("CLS"); cout << "You entered incorrect data! Try again: " << endl << endl; }
        }

        if (brandd > 0 and brandd <= 10)
            break;
        else 
            system("CLS"); cout << "You can only enter a number from 1 to 10. Try again!" << endl << endl;
    }

    system("CLS");
    for (int i = 0; i < N; i++)
    {
        if (array_shoes->brand_name == brandd)
        {
            kol++;
            if (kol == 1)
            {
                cout << "Shoes of this brand:" << endl << endl;
                cout << "№\tShoe brand\tShoe price\tShoe size\tShoe article number\tShoe name" << endl;
                cout << "------------------------------------------------------------------------------------------" << endl;
            }
            cout << kol << "\t";
            showRecording(array_shoes);
        }
        array_shoes++;
    }
    if (kol == 0)
        cout << "There are no shoes of this brand!" << endl << endl;
    cout << endl;
}