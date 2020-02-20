#include "hashcode.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct data get_data(char *filename)
{
    struct data d = {0};
    int nb_books = 0;
    int nb_libs = 0;
    int nb_days = 0;
    vector <struct book> books;
    vector <struct lib> libs;
    struct book b = {0};
    struct lib l = {0};
    int bookId = 0;

    ifstream input_file;
    input_file.open(filename);
    input_file >> nb_books;
    input_file >> nb_libs;
    input_file >> nb_days;
    for (int i = 0; i < nb_books ; i++) {
        b = {0};
        input_file >> b.score;
        b.id = i;
        books.push_back(b);
    }
    for (int i = 0; i < nb_libs; i++) {
        l = {0};
        input_file >> l.nb_books;
        input_file >> l.signup_duration;
        input_file >> l.books_per_day;
        for (int y = 0; y < l.nb_books; y++) {
            input_file >> bookId;
            l.books.push_back(bookId);
        }
        l.id = i;
        libs.push_back(l);
    }
    input_file.close();

    d.nb_books = nb_books;
    d.nb_libs = nb_libs;
    d.nb_days = nb_days;
    d.books = books;
    d.libs = libs;

    return d;
}

void write_solution(struct data d, char *outfile)
{
    vector <int> scanned;
    int max_book = 0;
    
    sort(d.libs.begin(), d.libs.end(), [](const struct lib& a, const struct lib& b){
        return a.signup_duration < b.signup_duration || (a.signup_duration <= b.signup_duration && a.books_per_day > b.books_per_day);
    });
    ofstream output_file;
    output_file.open(outfile);
    output_file << d.nb_libs << endl;
    for (int i = 0; i < d.nb_libs; i++) {
        //max_book = d.libs[i].nb_books - d.libs
        output_file << d.libs[i].id << " " << d.libs[i].nb_books << endl;
        for (int y = 0; y < d.libs[i].nb_books; y++) {
            output_file << d.libs[i].books[y] << " ";
        }
        output_file << endl;
    }
    output_file.close();
}

int main(int argc, char *argv[])
{
    struct data d = get_data(argv[1]);
    write_solution(d, argv[2]);
    return (0);
}