// from server: 100% by king_originala
struct Interface {
    virtual void invoke(int) = 0;
};

struct S {
    char padding[0x1f0];
    void base(void*);
    void f(void*);
};

void S::f(void* argument)
{
    base(argument);
    reinterpret_cast<Interface*>(reinterpret_cast<char*>(this) + 0x1f0)->invoke(1);
}
