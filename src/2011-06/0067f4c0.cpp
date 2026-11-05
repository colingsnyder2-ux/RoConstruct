// from server: 42% by atomic.potato
struct A {
    void* f();
};

struct B {
    void g();
};

extern "C" A* __cdecl sub_67e1d0();
extern "C" B* __cdecl sub_67ec30(A*);
extern "C" void __stdcall sub_597910(B*, A*);

void __stdcall sub_67f4c0(A* a)
{
    A* p = sub_67e1d0();
    if (p) {
        B* b = sub_67ec30(p);
        if (b) {
            void** vt = *(void***)b;
            ((void (__thiscall*)(B*))vt[1])(b);
        }
        sub_597910(b, p);
    }
}
