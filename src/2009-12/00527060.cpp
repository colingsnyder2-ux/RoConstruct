// from server: 40% by atomic.potato
extern "C" void __cdecl sub_4164B0(void*, void*);
extern "C" void* __cdecl sub_4161E0(void*);

struct S
{
    char pad[0xc];
    void* field_c;
    void* field_10;
    void f(int);
};

extern "C" void __cdecl sub_526130(void*, int);

void S::f(int)
{
    void* local;
    void* p;
    void* q;
    int zero = 0;
    void (*fn)();

    sub_4164B0(&local, &p);
    int n = ((char*)field_10 - (char*)field_c) >> 2;
    if (n <= 1)
        fn();
    q = sub_4161E0((char*)field_c + 4);
    p = *(void**)q;
    n = ((char*)field_10 - (char*)field_c) >> 2;
    if (n <= 0)
        fn();
    void* src = field_c;
    sub_4164B0(&local, src);
    sub_526130(this, -1);
}
