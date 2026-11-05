// from server: 79% by atomic.potato
struct A {
    void* f();
};

struct B {
    void g(A*);
};

extern "C" void* __cdecl sub_67e1d0();
extern "C" void* __cdecl sub_67ebf0(void*);
extern "C" void __cdecl sub_597910(void*, void*);

void __stdcall sub_67f490(void* p)
{
    void* v = sub_67e1d0();
    if (v) {
        void* w = sub_67ebf0(v);
        if (w) {
            void** vt = *(void***)w;
            ((void (__thiscall*)(void*))vt[1])(w);
        }
        sub_597910(p, v);
    }
}
