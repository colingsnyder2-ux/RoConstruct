// from server: 95% by atomic.potato
struct S
{
    int value;
    void f(int);
};

extern "C" void __cdecl Notify(const char *);

void S::f(int value)
{
    if (value != *(int *)((char *)this + 0xac))
    {
        *(int *)((char *)this + 0xac) = value;
        Notify((const char *)0xc04580);
    }
}
