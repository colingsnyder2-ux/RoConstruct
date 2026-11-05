// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __fastcall func_00723b90(void*);

void S::f()
{
    char** p = (char**)this;
    char* q = *p;
    if (q[0x48] != 0)
    {
        func_00723b90(q);
        q[0x48] = 0;
    }
}
