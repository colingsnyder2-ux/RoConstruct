// from server: 100% by king_originala
struct Value {
    int index;
    float value;
};

struct Argument {
    char padding[44];
    Value* target;
};

struct Receiver {
    void resize(Argument* argument);
};

extern "C" float __cdecl infinity();

struct S {
    char padding[16];
    Receiver* receiver;
    void f(Argument* argument);
};

void S::f(Argument* argument)
{
    receiver->resize(argument);
    double value = infinity();
    if (argument->target)
        argument->target->value = value;
}
