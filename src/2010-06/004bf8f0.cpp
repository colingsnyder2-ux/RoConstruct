// from server: 100% by atomic.potato
struct S
{
    bool f(void* p);
};

bool S::f(void* p)
{
    while (p != 0)
    {
        p = *(void**)((char*)p + 0x4c);
        if (p == this)
            return true;
    }
    return false;
}
