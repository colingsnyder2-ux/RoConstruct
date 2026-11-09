// from server: 100% by king_originala
extern "C" void __cdecl target(void*);

struct S {
    void f(void*);
};

#pragma optimize("", off)
void S::f(void* p)
{
    target(p);
}
#pragma optimize("", on)
