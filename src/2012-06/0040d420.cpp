// from server: 43% by atomic.potato
struct S
{
    int v0;
    int v1;
    int v2;
    int v3;
    void* v4;
    void f();
};

void S::f()
{
    v0 = 0x00b44248;
    v3 = 0x00b44240;
    v3 = 0x00b43e60;

    if (v4 != 0)
    {
        void** table = *(void***)v4;
        typedef void (__thiscall *Fn)(void*);
        ((Fn)table[4])(v4);
    }
}
