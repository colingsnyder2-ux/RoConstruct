// from server: 100% by king_originala
struct Argument {
    int get();
};

struct S_func_0062dda0 {
    char pad0[304];
    int value;
    void f(int a1, Argument* a2);
};

void S_func_0062dda0::f(int a1, Argument* a2)
{
    if (a2)
        value = a2->get();
}
