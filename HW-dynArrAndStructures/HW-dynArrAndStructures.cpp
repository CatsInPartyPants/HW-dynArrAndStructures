#include <iostream>
#include <string>

//task1
int** addColumn(int** arr, int rows, int columns, int* arr2, int position);

//task2
int** deleteColumn(int** arr, int rows, int columns, int position);

//task 3

void moveRow(int** arr, int M, int N, int count);

void moveColomn(int** arr, int M, int N, int count);

//task4
int** transponseMatrix(int** arr, int rows, int columns);

//task5

struct phone_name {
    std::string name;
    long long number;
};

phone_name* find_by_phone(phone_name* arr, long long number);
phone_name* find_by_name(phone_name* arr, std::string name);

//structs

//task1

struct complexNumber {
    double a;
    double b;
};

void show_complex(complexNumber number)
{
    if(number.b > 0)
        std::cout << number.a << " + " << number.b << "i" << std::endl;
    else
        std::cout << number.a << " - " << fabs(number.b) << "i" << std::endl;
}

complexNumber sum(complexNumber first, complexNumber second)
{
    complexNumber result;
    result.a = first.a + second.a;
    result.b = first.b + second.b;
    return result;
}

complexNumber diff(complexNumber first, complexNumber second)
{
    complexNumber result;
    result.a = first.a - second.a;
    result.b = first.b - second.b;
    return result;
}

complexNumber mul(complexNumber first, complexNumber second)
{
    complexNumber result;
    result.a = (first.a * second.a) - (first.b * second.b);
    result.b = (first.b * second.a) + (first.a * second.b);
    return result;
}

complexNumber div(complexNumber first, complexNumber second)
{
    complexNumber result;
    result.a = ((first.a * second.a) + (first.b * second.b)) / ((second.a*second.a) + (second.b*second.b));
    result.b = ((first.b* second.a) - (first.a * second.b)) / ((second.a * second.a) + (second.b * second.b));
    return result;
}

//task2struct

struct Car {
    double length;
    double clearence;
    double engine_size;
    double engine_power;
    int wheel_diameter;
    std::string color;
    std::string gearbox_type;
};

void set_car(Car* car)
{
    std::cout << "Enter length of the car->";
    std::cin >> car->length;
    std::cout << "Enter clearence of the car->";
    std::cin >> car->clearence;
    std::cout << "Enter engine size of the car->";
    std::cin >> car->engine_size;
    std::cout << "Enter engine power of the car->";
    std::cin >> car->engine_power;
    std::cout << "Enter wheel diameter of the car->";
    std::cin >> car->wheel_diameter;
    std::cout << "Enter color of the car->";
    std::cin >> car->color;
    std::cout << "Enter gearbox type of the car->";
    std::cin >> car->gearbox_type;
}

void show_car(Car* car)
{
    std::cout << "The lenght of the car is " << car->length << std::endl;
    std::cout << "The clearence of the car is " << car->clearence << std::endl;
    std::cout << "The engine size of the car is " << car->engine_size << std::endl;
    std::cout << "The engine power of the car is " << car->engine_power << std::endl;
    std::cout << "The wheel diameter of the car is " << car->wheel_diameter << std::endl;
    std::cout << "The color of the car is " << car->color << std::endl;
    std::cout << "The gearbox type of the car is " << car->gearbox_type << std::endl;
}

//task3 struct (Library)

struct Book {
    std::string name;
    std::string author;
    std::string publisher;
    std::string genre;
};

void show_all_books(Book* books, int size);

int edit_book(Book* books, int size);

void find_by_author(Book* books, std::string author, int size);

void find_by_name(Book* books, std::string name, int size);

void sort_by_author(Book* books, int size);

void sort_by_publisher(Book* books, int size);

void sort_by_name(Book* books, int size);

//task4 struct

struct Car_4 {
    std::string color;
    std::string model;
    union{
        int intnumber;
        char charnumber[8];
    } number;
};

void set_car_4(Car_4 car)
{
    int answer;
    std::cout << "Set color:";
    std::cin >> car.color;
    std::cout << "Set model:";
    std::cin >> car.model;
    std::cout << "Is the number of the car consists of letters(1) or of numbers(2)?";
    std::cin >> answer;
    if (answer == 1)
    {
        std::cout << "Enter number of the car:";
        std::cin >> car.number.charnumber;
    }
    else if (answer == 2)
    {
        std::cout << "Enter number of the car:";
        std::cin >> car.number.intnumber;
    }
}

void show_car(Car_4 car)
{
    std::cout << "Car color:" << car.color << std::endl;
    std::cout << "Car model:" << car.model << std::endl;
    std::cout << "Car number:" << car.number.charnumber << car.number.intnumber << std::endl;
}

void show_car_array(Car_4* cars)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Car color:" << cars[i].color << std::endl;
        std::cout << "Car model:" << cars[i].model << std::endl;
        std::cout << "Car number:" << cars[i].number.intnumber << std::endl;
    }
}

void change_car_in_array(Car_4* car, int position)
{
    int answer;
    std::cout << "Set color:";
    std::cin >> car[position].color;
    std::cout << "Set model:";
    std::cin >> car[position].model;
    std::cout << "Is the number of the car consists of letters(1) or of numbers(2)?";
    std::cin >> answer;
    if (answer == 1)
    {
        std::cout << "Enter number of the car:";
        std::cin >> car[position].number.charnumber;
    }
    else if (answer == 2)
    {
        std::cout << "Enter number of the car:";
        std::cin >> car[position].number.intnumber;
    }
}

Car_4* find_car_by_number(Car_4* cars, int number)
{
    Car_4* for_find;
    for (int i = 0; i < 5; i++)
    {
        if (cars[i].number.intnumber == number)
        {
            for_find = cars+i;
            return for_find;
        }
    }
}

int main()
{
    
    //task 1
    //making array
    std::cout << "Task1\n";
    int** task1array = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        task1array[i] = new int[5];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            task1array[i][j] = j;
            std::cout << task1array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int array_for_input[5] = { 11,11,11,11,11 };

    task1array = addColumn(task1array, 5, 5, array_for_input, 2);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << task1array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //delete array
    for (int i = 0; i < 5; i++)
    {
        delete[] task1array[i];
    }
    delete[] task1array;
    
    
    //task2
    std::cout << "\n\n\nTask2\n";
    //making array
    int** task2array = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        task2array[i] = new int[5];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            task2array[i][j] = j;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << task2array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    task2array = deleteColumn(task2array, 5, 5, 2);
    //showing array after delete 1 column
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << task2array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //delete array
    for (int i = 0; i < 5; i++)
    {
        delete[] task2array[i];
    }
    delete[] task2array;

    //task 3

    int** arr3 = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        arr3[i] = new int[5];
    }
    srand(time(NULL));

    // before 
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr3[i][j] = 1 + rand() % (50 + 1);
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //after
    moveRow(arr3, 5, 5, 2);
    moveColomn(arr3, 5, 5, 2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //delete dynamic array

    for (int i = 0; i < 5; i++)
    {
        delete[] arr3[i];
    }
    delete[] arr3;


    //task 4
    std::cout << "\n\n\nTask4\n";
    //making matrix 5x5
    int** task4array = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        task4array[i] = new int[5];
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            task4array[i][j] = rand() %10 + 1;
        }
    }
    //show matrix before transponse
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << task4array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    task4array = transponseMatrix(task4array, 5, 5);

    //show matrix after transponse
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << task4array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //task 5
    std::cout << "\n\n\nTask5\n";
    phone_name* array_phone_name = new phone_name [4];
    array_phone_name[0].name = "Artem";
    array_phone_name[0].number = 89115567453;
    array_phone_name[1].name = "Aleksandr";
    array_phone_name[1].number = 89115567454;
    array_phone_name[2].name = "Evgeniy";
    array_phone_name[2].number = 89115567455;
    array_phone_name[3].name = "Maria";
    array_phone_name[3].number = 89115567456;

    phone_name* for_find_by_number = find_by_phone(array_phone_name, 89115567456);
    std::cout << for_find_by_number->name << std::endl;

    phone_name* for_find_by_name = find_by_name(array_phone_name, "Evgeniy");
    std::cout << for_find_by_name->number<< std::endl;

    delete[] array_phone_name;

    //task1 struct
    std::cout << "\n\n\nTask1struct\n";

    complexNumber first, second;
    first.a = 2;
    first.b = 3;
    second.a = 5;
    second.b = -7;
    complexNumber result = sum(first, second);
    show_complex(result);
    result = diff(first, second);
    show_complex(result);
    result = mul(first, second);
    show_complex(result);
    result = div(first, second);
    show_complex(result);


    Car_4 array_of_cars[5];
    array_of_cars[0].color = "red";
    array_of_cars[0].model = "TS";
    array_of_cars[0].number.intnumber = 4891;

    array_of_cars[1].color = "blue";
    array_of_cars[1].model = "TSL";
    array_of_cars[1].number.intnumber = 4892;

    array_of_cars[2].color = "green";
    array_of_cars[2].model = "TSR";
    array_of_cars[2].number.intnumber = 4898;

    array_of_cars[3].color = "yellow";
    array_of_cars[3].model = "TSR";
    array_of_cars[3].number.intnumber = 4899;

    array_of_cars[4].color = "black";
    array_of_cars[4].model = "TLS";
    array_of_cars[4].number.intnumber = 9999;

    show_car_array(array_of_cars);

    Car_4* my_car;
    my_car = find_car_by_number(array_of_cars, 4899);
    std::cout << my_car->model;

    //task 3 struct (Library)

    setlocale(LC_ALL, "ru");
    Book* book_info = new Book[10];

    book_info[0].name = "Колобок";
    book_info[0].author = "Писахов";
    book_info[0].publisher = "Дрофа";
    book_info[0].genre = "Фольклор";

    book_info[1].name = "Сказки бабушки Галины";
    book_info[1].author = "Галина";
    book_info[1].publisher = "Дрофа";
    book_info[1].genre = "Фольклор";

    book_info[2].name = "Война и мир";
    book_info[2].author = "Толстой";
    book_info[2].publisher = "Просвещение";
    book_info[2].genre = "Роман";

    book_info[3].name = "Мастер и Маргарита";
    book_info[3].author = "Булгаков";
    book_info[3].publisher = "Проба";
    book_info[3].genre = "Фэнтези";

    book_info[4].name = "Двенадцать стульев";
    book_info[4].author = "Петров";
    book_info[4].publisher = "Проба";
    book_info[4].genre = "Комедия";

    book_info[5].name = "Преступление и наказание";
    book_info[5].author = "Достоевский";
    book_info[5].publisher = "Проба";
    book_info[5].genre = "Детектив";

    book_info[6].name = "Палата № 6";
    book_info[6].author = "Чехов";
    book_info[6].publisher = "Дрофа";
    book_info[6].genre = "Комедия";

    book_info[7].name = "Евгений Онегин";
    book_info[7].author = "Пушкин";
    book_info[7].publisher = "Проба";
    book_info[7].genre = "Драма";

    book_info[8].name = "Ревизор";
    book_info[8].author = "Гоголь";
    book_info[8].publisher = "Просвещение";
    book_info[8].genre = "Комедия";

    book_info[9].name = "Шерлок холмс";
    book_info[9].author = "Доиль";
    book_info[9].publisher = "Просвещение";
    book_info[9].genre = "Детектив";

    show_all_books(book_info, 10);
    //edit_book(book_info, 10);

    sort_by_name(book_info, 10);
    show_all_books(book_info, 10);
    sort_by_author(book_info, 10);
    show_all_books(book_info, 10);

    delete[] book_info;
}

//task 1
int** addColumn(int** arr, int rows, int columns, int* arr2, int position)
{
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[columns + 1];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns + 1; j++)
        {
            if (j == position)
            {
                new_arr[i][j] = arr2[i];
            }
            else 
            {
                if(j < position)
                    new_arr[i][j] = arr[i][j];
                if(j > position)
                    new_arr[i][j] = arr[i][j-1];
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return new_arr;
}

//task 2
int** deleteColumn(int** arr, int rows, int columns, int position)
{
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[columns - 1];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            if (j < position)
            {
                new_arr[i][j] = arr[i][j];
            }
            if (j == position)
            {
                new_arr[i][j] = arr[i][j + 1];
            }
            if (j > position)
            {
                new_arr[i][j] = arr[i][j + 1];
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return new_arr;
}

//task 3

// moving rows
void moveRow(int** arr, int M, int N, int count)
{

    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < count; k++)
        {
            int temp;
            temp = arr[i][0];
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][N - 1] = temp;
        }
    }
}

//moving colomns
void moveColomn(int** arr, int M, int N, int count)
{
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < count; k++)
        {
            int temp = 0;
            temp = arr[0][j];
            for (int i = 0; i < M - 1; i++)
            {
                arr[i][j] = arr[i + 1][j];
            }
            arr[M - 1][j] = temp;
        }

    }
}

//task 4

int** transponseMatrix(int** arr, int rows, int columns)
{
    int** new_arr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            new_arr[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return new_arr;
}

//task 5
phone_name* find_by_phone(phone_name* arr, long long number)
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i].number == number)
            return arr+i;
    }
}

phone_name* find_by_name(phone_name* arr, std::string name)
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i].name == name)
            return arr + i;
    }
}

//task 3 struct (Library)


void show_all_books(Book* books, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Books in library: \n";
        std::cout << i + 1 << "." << books[i].name << ",\n";
        std::cout << books[i].author << ",\n";
        std::cout << books[i].publisher << ",\n";
        std::cout << books[i].genre << ",\n";
    }
    std::cout << std::endl;
}

int edit_book(Book* books, int size)
{
    int position;
    std::cout << "What book do you want to edit?";
    std::cin >> position;
    if (position >= size)
    {
        return 1;
    }
    std::cin.get();
    std::cout << "Enter the name of the book:";
    std::getline(std::cin, books[position].name);

    std::cout << "Enter the author of the book:";
    std::getline(std::cin, books[position].author);

    std::cout << "Enter the publisher of the book:";
    std::getline(std::cin, books[position].publisher);

    std::cout << "Enter the genre of the book:";
    std::getline(std::cin, books[position].genre);
    return 0;
}

void find_by_author(Book* books, std::string author, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (author == books[i].author)
        {
            std::cout << books[i].author << std::endl;
            std::cout << books[i].name << std::endl;
            std::cout << books[i].publisher << std::endl;
            std::cout << books[i].genre << std::endl;
        }
    }
}

void find_by_name(Book* books, std::string name, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (name == books[i].name)
        {
            std::cout << books[i].author << std::endl;
            std::cout << books[i].name << std::endl;
            std::cout << books[i].publisher << std::endl;
            std::cout << books[i].genre << std::endl;
        }
    }
}

void sort_by_author(Book* books, int size)
{
    Book temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (strcmp(books[i].author.c_str(), books[j].author.c_str()) == 1)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sort_by_name(Book* books, int size)
{
    Book temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (strcmp(books[i].name.c_str(), books[j].name.c_str()) == 1)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void sort_by_publisher(Book* books, int size)
{
    Book temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (strcmp(books[i].publisher.c_str(), books[j].publisher.c_str()) == 1)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
