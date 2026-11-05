// from server: 27% by atomic.potato
extern "C" void __cdecl sub_772410(void*, void*);

struct S {
    void f(void*);
};

void S::f(void* a) {
    char* p = (char*)this + 0xc;
    sub_772410(p, a);
}
