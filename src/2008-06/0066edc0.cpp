// from server: 100% by king_originala
struct Result {
    int get();
};

struct S {
    char padding[0xC4];
    int value;

    int lookup();
    void update();
    void f();
};

void S::f()
{
    Result* result = reinterpret_cast<Result*>(lookup());
    if (value != result->get())
        update();
}
