// from server: 81% by atomic.potato
struct Inner {
    char pad[4];
    void* field4;
};

struct Outer {
    char pad[0x24];
    int field24;
    void method(int, int);
};

extern "C" void* __cdecl sub_40dfb0(void*);
extern "C" void __cdecl sub_5a6c40(void*, void*);

void Outer::method(int a, int b)
{
    int off;
    if (a != 0)
        off = a - 0x1c;
    else
        off = 0;
    int base = field24 + off;
    void* p = sub_40dfb0(*(void**)(b + 4));
    sub_5a6c40((void*)base, *(void**)p);
}
