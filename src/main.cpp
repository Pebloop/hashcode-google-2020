#include "hashcode.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct data d = {0};

struct data get_data(char *filename)
{
    struct data gd = {0};
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

    gd.nb_books = nb_books;
    gd.nb_libs = nb_libs;
    gd.nb_days = nb_days;
    gd.books = books;
    gd.libs = libs;

    return gd;
}

void write_solution(char *outfile)
{
    vector <int> scanned;
    int max_book = 0;
    
    sort(d.libs.begin(), d.libs.end(), [](const struct lib& a, const struct lib& b){

        return (d.nb_days - a.signup_duration) * a.books_per_day > (d.nb_days - b.signup_duration) * b.books_per_day;
    });
    ofstream output_file;
    output_file.open(outfile);
    output_file << d.nb_libs << endl;
    for (int i = 0; i < d.nb_libs; i++) {
        vector <int> choice;
        max_book = 0;
        for (int day = d.libs[i].signup_duration; day < d.nb_days; day++) {
            max_book += d.libs[i].books_per_day;
        }
        max_book = (d.libs[i].nb_books < max_book) ? d.libs[i].nb_books : max_book;
        for (int test = 0; test < d.libs[i].nb_books; test++) {
            bool found = (find(scanned.begin(), scanned.end(), d.libs[i].books[test]) != scanned.end());
            if (!found)
                choice.push_back(d.libs[i].books[test]);
        }
        if (choice.size() < max_book)
            max_book = choice.size();
        output_file << d.libs[i].id << " " << max_book << endl;
        for (int y = 0; y < max_book; y++) {
            output_file << choice[y] << " ";
            scanned.push_back(choice[y]);
        }
        output_file << endl;
    }
    output_file.close();
}

int main(int argc, char *argv[])
{
    d = get_data(argv[1]);
    write_solution(argv[2]);
    return (0);
}