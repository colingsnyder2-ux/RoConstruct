// from server: 100% by atomic.potato
struct S
{
    void f(char*, char*);
};

extern "C" void __fastcall sub_6a1c00(void*);

void S::f(char* p, char* end)
{
    while (p != end)
    {
        sub_6a1c00(p);
        p += 24;
    }
}
