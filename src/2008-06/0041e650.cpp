// from server: 100% by king_originala
extern "C" void __cdecl helper(void*);

struct S {
    void* f(void*);
};

void* S::f(void* p)
{
    volatile int state = 0;
    helper(p);
    return p;
}
