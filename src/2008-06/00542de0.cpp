// from server: 100% by king_originala
extern "C" void __cdecl helper(void *, int);

struct S {
    void f(void *);
};

#pragma optimize("", off)
void S::f(void *p)
{
    helper(p, 0);
}
