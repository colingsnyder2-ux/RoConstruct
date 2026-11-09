// from server: 70% by atomic.potato
struct S
{
    int field110;
    int field21c;
    int f(int value);
};

typedef int (__thiscall *Callback)(int *, int);
extern "C" int __stdcall call_918c10(int, int);

int S::f(int value)
{
    int *p = *(int **)(field110 + 4);
    Callback fn = (Callback)(*(int **)(p) + 8);
    fn((int *)(field110 + 4), value);
    return call_918c10(field21c, value);
}
