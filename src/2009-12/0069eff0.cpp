// from server: 100% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, int, int);

struct S
{
    char padding[0x98];
    int field;
    void f();
};

void S::f()
{
    int value = field;
    if (value)
        UniversalTool((void *)value, 2, 0);
}
