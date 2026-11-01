// from server: 100% by tester
struct S
{
    void f();
};

extern "C" void __fastcall sub_006a1f20(void*);

void S::f()
{
    char* p = *(char**)this;
    if (p[0x58] != 0)
    {
        sub_006a1f20(p);
        p[0x58] = 0;
    }
}
