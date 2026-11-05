// from server: 79% by atomic.potato
struct S
{
    unsigned char pad0[8];
    unsigned char enabled;
    unsigned char pad9[3];
    void* object;

    int f(void*);
};

int S::f(void* value)
{
    if (enabled)
    {
        void* q = *(void**)object;
        void* p = *(void**)value;
        typedef unsigned char (__thiscall *Fn)(void*, void*);
        if (!((Fn)(*(void**)(*(void**)q)))(q, p))
            return 0;
    }
    return 1;
}
