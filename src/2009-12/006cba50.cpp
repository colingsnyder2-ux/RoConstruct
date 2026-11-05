// from server: 74% by atomic.potato
struct S
{
    int field168;
    void f();
};

extern "C" void* __cdecl sub_00699860(S*);
extern "C" void __stdcall sub_0071acf0(void*, int);

void S::f()
{
    void* p = sub_00699860(this);
    if (p)
        sub_0071acf0(p, field168);
}
