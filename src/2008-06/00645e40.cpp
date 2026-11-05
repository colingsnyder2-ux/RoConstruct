// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct A
{
    char storage[196];
    A(int a, int b, int c, int d);
};

struct B
{
    char storage[200];
    B(int a, int b, int c, int d);
};

struct C
{
    char storage[200];
    C(int a, int b, int c, int d);
};

void* __cdecl create(int kind, int a, int b, int c, int d)
{
    switch (kind)
    {
    case 6:
        return new A(a, b, c, d);
    case 8:
        return new C(a, b, c, d);
    case 7:
        return new B(a, b, c, d);
    default:
        return 0;
    }
}
