// from server: 51% by atomic.potato
extern "C" int __cdecl sub_7583B0(void *, void *);

struct S
{
    int f(void *);
};

S g_s;
unsigned char g_00E31ABE;

int S::f(void *arg)
{
    if (!g_00E31ABE)
    {
        void *p = *(void **)((char *)this + 0x84);
        return sub_7583B0((void *)((char *)p + *(int *)p + (int)this + 0x84), arg);
    }
    return 0;
}
