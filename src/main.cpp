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
    vector <struct lib> libs;
    struct book b = {0};
    struct lib l = {0};
    int bookId = 0;

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
    for (int i = 0; i < nb_libs; i++) {
        input_file >> l.nb_books;
        input_file >> l.signup_duration;
        input_file >> l.books_per_day;
        for (int y = 0; y < l.nb_books; y++) {
            input_file >> bookId;
            l.books.push_back(bookId);
        }
        l.id = i;
    }
    input_file.close();
    cout << books[0].score << endl;
    return (0);
}