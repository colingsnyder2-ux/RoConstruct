// from server: 46% by atomic.potato
extern "C" void* __stdcall sub_007090e0();
extern "C" void* __stdcall sub_006c1520();
extern "C" void* __stdcall sub_006c1280();
extern "C" void* __stdcall sub_0067f2e0(void*, void*, void*);
extern "C" void* __stdcall sub_00709480();

struct S {
    char pad[0x1c];
    void* field_1c;
    void method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void S::method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    void* a;
    void* b;
    field_1c = sub_007090e0();
    void* p1 = sub_006c1520();
    sub_0067f2e0(&a, p1, &a);
    sub_00709480();
    void* p2 = sub_006c1280();
    sub_0067f2e0(&b, p2, &b);
    sub_00709480();
    if (a) {
        void (*f)(void*) = *(void (**)(void*))((char*)a + 4);
        f(&a);
    }
    if (b) {
        void (*f)(void*) = *(void (**)(void*))((char*)b + 4);
        f(&b);
    }
}
