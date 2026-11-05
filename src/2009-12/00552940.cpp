// from server: 53% by atomic.potato
struct Exposer
{
    int f(void *);
};

extern "C" int __stdcall sub_00552540(void *);

int Exposer::f(void *p)
{
    if (sub_00552540(p) == 0)
    {
        struct VTable
        {
            int a[21];
        };
        return ((VTable *)*(int *)this)->a[20];
    }
    return 0;
}
