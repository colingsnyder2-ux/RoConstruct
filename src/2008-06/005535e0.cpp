// from server: 100% by king_originala
#pragma optimize("", off)

extern "C" void __cdecl helper(void*, void*);

struct S {
    void f(void*, void*);
};

void S::f(void* a, void* b) {
    helper(a, b);
}
