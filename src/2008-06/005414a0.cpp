// from server: 100% by king_originala
extern "C" void __cdecl target(void*, void*, void*);

struct S {
    void f(void*, void*);
};

#pragma optimize("", off)
void S::f(void* a, void* b)
{
    target(a, b, reinterpret_cast<char*>(this) + 8);
}
#pragma optimize("", on)
