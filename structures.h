typdef struct book {
    int id;
    int score;
} book;

typdef struct lib {
    bool is_signed_up;
    int nb_books;
    int signup_duration;
    int books_per_day;
    book books[];
} lib;
