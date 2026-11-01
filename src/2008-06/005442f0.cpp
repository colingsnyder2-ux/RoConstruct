// from server: 100% by king_originala
extern "C" void __cdecl target(void*, void*, void*);

struct S {
    char padding[8];
    int value;
    void f(void*, void*);
};

#pragma optimize("", off)
void S::f(void* a, void* b)
{
    target(a, b, &value);
}
#pragma optimize("", on)
