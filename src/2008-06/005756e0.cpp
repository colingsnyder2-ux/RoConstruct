// from server: 100% by king_originala
struct S;

struct T {
    unsigned int data[2];
    void __thiscall initialize(void* argument, S* owner, void* value);
};

struct S {
    char padding[0x204];
    void* value;
    void __thiscall f(void* argument);
};

void S::f(void* argument)
{
    T temporary;
    temporary.initialize(argument, this, value);
}
