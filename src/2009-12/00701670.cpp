// from server: 92% by atomic.potato
struct S
{
    void* a;
};

extern "C" unsigned char f(S* p)
{
    unsigned char r = 0;
    if (p && p->a)
    {
        void* q = *(void**)((char*)p->a + 0x18);
        if (q && (char*)q - 8)
            r = 1;
    }
    return r;
}
