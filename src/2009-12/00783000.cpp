// from server: 39% by atomic.potato
struct S {
    char pad[0x50];
    int* value;
    int f();
};

int S::f()
{
    int* p = value;
    if (p)
        return (p[4] - p[3]) >> 3;
    return 0;
}

extern "C" int __stdcall sub_7f4aaa(int, int, int, int, int);
extern "C" void __stdcall sub_7b7e50();
extern "C" void __stdcall sub_98b760();
extern "C" void __stdcall sub_783000(int, int*);

struct T {
    char pad0[0xc];
    int field_c;
    char pad10[0x40];
    void* field_50;
    void g(int*);
};

void T::g(int* a)
{
    int i = 0;
    int n = ((S*)this)->f();
    if (n > 0) {
        do {
            int* p = (int*)field_50;
            int cnt = (p[4] - p[3]) >> 3;
            if (i >= cnt)
                sub_98b760();
            int v = *(int*)(p[3] + i * 8);
            sub_783000(v, a);
            i++;
            n = ((S*)this)->f();
        } while (i < n);
    }
}

void __stdcall sub_783000(int a, int* b)
{
    int x = sub_7f4aaa(0, 0xaffe40, 0xb03a58, 0, a);
    if (x) {
        int v = *(int*)(x + 0x168);
        sub_7b7e50();
    }
    T* t = (T*)a;
    t->g(b);
}
