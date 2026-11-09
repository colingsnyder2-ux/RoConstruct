// from server: 22% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl call_target(int, int *);

void S::f()
{
    int value;
    value = 1;
    if (value)
        value = *(int *)((char *)&value + 12);
    else
        value = **(int **)((char *)&value + 12);
    call_target(value, (int *)((char *)&value + 16));
}
