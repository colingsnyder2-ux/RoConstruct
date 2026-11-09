// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const char cursorTable[];
extern const char cursorSecondaryTable[];

struct Base {
    int data[7];
    int f(int);
};

struct Cursor : Base {
    int state;
    float x, y, z, dx, dy, dz;
    Cursor(int);
};

struct S {
    int reserved[6];
    int value;
    Cursor* f();
};

__forceinline Cursor::Cursor(int a)
{
    Base::f(a);
    *(volatile int*)&data[0] = (int)cursorTable;
    *(volatile int*)&data[1] = (int)cursorSecondaryTable;
    *(volatile int*)&state = 0;
    *(volatile float*)&x = 0.0f;
    *(volatile float*)&y = 0.0f;
    *(volatile float*)&z = 0.0f;
    *(volatile float*)&dx = 0.0f;
    *(volatile float*)&dy = 0.0f;
    *(volatile float*)&dz = 0.0f;
}

Cursor* S::f()
{
    return new Cursor(value);
}
