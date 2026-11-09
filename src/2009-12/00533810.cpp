// from server: 81% by atomic.potato
extern "C" void sub_52B060(void*, void*);

struct S
{
    S* __cdecl f(void*);
};

S* S::f(void* p)
{
    sub_52B060(this, p);
    sub_52B060(this, (char*)p + 2);
    return this;
}
