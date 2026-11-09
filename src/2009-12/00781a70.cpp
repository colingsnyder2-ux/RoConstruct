// from server: 96% by atomic.potato
extern "C" void __cdecl Function782da0(void *, void *, void *, void *);

struct S {
    int f(int, int);
};

int S::f(int a, int b)
{
    Function782da0((char *)this + 8, (void *)b, (void *)a, *(void **)((char *)this + 0x2c));
    return a;
}
