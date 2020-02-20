#include "hashcode.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nb_books = 0;
    int nb_libs = 0;
    int nb_days = 0;
    vector <struct book> books;
    struct book b = {0};

    ifstream input_file;
    input_file.open(argv[1]);
    input_file >> nb_books;
    input_file >> nb_libs;
    input_file >> nb_days;
    for (int i = 0; i < nb_books ; i++) {
        input_file >> b.score;
        b.id = i;
        books.push_back(b);
    }
    input_file.close();
    cout << books[0].score << endl;
    return (0);
}