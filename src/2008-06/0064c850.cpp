// from server: 100% by king_originala
struct S {
    char padding[0xe0];
    char first[0x20];
    char second[0x40];
    char third[0x20];
    char fourth[0x20];

    void helper(void *, int, int);
    void f();
};

void S::f()
{
    helper(second, 0, 2);
    helper(first, 0, 1);
    helper(third, 0, 4);
    helper(fourth, 0, 5);
}
