// from server: 100% by king_originala
struct S;

struct T
{
    void f(S*);
};

struct S
{
    char padding[0x104];
    T* target;
    void f(S*);
};

void S::f(S*)
{
    target->f(this);
}
