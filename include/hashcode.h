#ifndef LS_H_
#define LS_H_

struct book {
    int id;
    int score;
};

struct lib {
    bool is_signed_up;
    int nb_books;
    int signup_duration;
    int books_per_day;
    struct book books[];
};

int hashcode(int argc, char **argv);

#endif /* !LS_H_ */