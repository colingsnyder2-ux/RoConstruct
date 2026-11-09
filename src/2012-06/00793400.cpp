// from server: 47% by atomic.potato
struct S_func_00793400 {
    char pad[0x1c];
    void* m_field;
    void f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_006C1280();
extern "C" void* __stdcall sub_0067F2E0(void*, void*);
extern "C" void __stdcall sub_00709480(void*, void*);

void S_func_00793400::f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    void* a = sub_006C1280();
    m_field = a;
    void* b = sub_006C1280();
    void* c = 0;
    void* d = sub_0067F2E0(&c, b);
    sub_00709480(&m_field, d);
    if (c) {
        void* e = *(void**)((char*)c + 4);
        ((void (__stdcall*)(void*))e)(&c);
    }
}
