// from server: 43% by atomic.potato
extern void __stdcall G1_func_006353b0(int);

struct Tool
{
    int value_1f8;
    void f();
};

void Tool::f()
{
    int value = value_1f8;
    int delta = (value + 1) & 0x80000001;
    if (delta < 0)
        delta = (delta - 1) | ~1;
    G1_func_006353b0(delta + value + 1);
}
