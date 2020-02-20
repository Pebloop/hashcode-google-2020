#ifndef LS_H_
#define LS_H_

#include <vector>

struct book {
    int id;
    int score;
};

struct lib {
    int id;
    bool is_signed_up;
    int nb_books;
    int signup_duration;
    int books_per_day;
    std::vector <struct book> books;
};

struct data {
    int nb_books;
    int nb_libs;
    int nb_days;
    std::vector <struct book> books;
    std::vector <struct lib> libs;
};

int hashcode(int argc, char **argv);

#endif /* !LS_H_ */