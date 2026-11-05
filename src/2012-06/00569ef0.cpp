// from server: 100% by atomic.potato
extern "C" void __stdcall sub_9779e0(void *, void *, double);

struct S {
    int f(void *, int);
};

double g_00b5f4f8;

int S::f(void *b, int a)
{
    sub_9779e0(b, (void *)a, g_00b5f4f8);
    return (int)b;
}
