// from server: 100% by atomic.potato
struct S
{
    char padding[20];
    int value;
};

extern "C" void G1_func_0090cfe0(S *, int);
extern "C" void G1_func_00982114(S *);

void func_0090d110(S *p)
{
    if (p)
    {
        G1_func_0090cfe0(p, p->value);
        G1_func_00982114(p);
    }
}
