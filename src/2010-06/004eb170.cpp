// from server: 34% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    void __cdecl f(int, int, int);
};

extern "C" void __cdecl sub_4e1b30(short*, int, short*);
extern "C" void __cdecl sub_4ea220(short*);

void S::f(int a, int b, int c)
{
    short v = 0;
    sub_4e1b30(&v, a, &v);
    if (*(int*)((char*)this + 4) != 0)
        sub_4ea220(&v);
}
