// from server: 72% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (!*((unsigned char *)this + 4))
    {
        void *p = *(void **)this;
        if (p)
        {
            int v = ((int (__thiscall *)(void *))0x98b4c4)(p);
            if (v != -1)
            {
                *((unsigned char *)this + 5) = (unsigned char)v;
                *((unsigned char *)this + 4) = 1;
            }
            else
            {
                *(void **)this = 0;
                *((unsigned char *)this + 4) = 1;
            }
        }
        else
        {
            *(void **)this = 0;
            *((unsigned char *)this + 4) = 1;
        }
    }
    return *((unsigned char *)this + 5);
}
