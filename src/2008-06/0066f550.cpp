// from server: 100% by king_originala
struct Argument {
    int field0;
    int field4;
    void f(int);
};

struct Receiver {
    void f(Argument *);
};

struct S {
    int field0;
    int field4;
    Receiver *field8;
    void f(Argument *);
};

void S::f(Argument *argument)
{
    field8->f(argument);
    argument->f(reinterpret_cast<int>(this));
}
