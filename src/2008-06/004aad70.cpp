// from server: 100% by king_originala
extern char notification;

struct S {
    char padding[0x134];
    int value;
    void notify(const void*);
    void set(const int*);
};

void S::set(const int* input)
{
    if (*input != value) {
        value = *input;
        notify(&notification);
    }
}
