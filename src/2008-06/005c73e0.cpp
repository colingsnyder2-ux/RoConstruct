// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object
{
    unsigned int table0;
    unsigned int table1;
    unsigned char storage[28];

    Object(void*);
};

struct Derived : Object
{
    Derived(void*);
};

inline Derived::Derived(void* argument) : Object(argument)
{
    table0 = 0x83986c;
    table1 = 0x839854;
}

struct S
{
    unsigned char storage[24];
    void* argument;

    Object* f();
};

Object* S::f()
{
    return new Derived(argument);
}
