// from server: 47% by atomic.potato
struct S
{
};

extern "C" int __cdecl callee(int);

int __cdecl f(int p)
{
    if (p == 0)
        return 0;
    int v = callee(p);
    if (v == 0)
        return 0;
    v = *(int *)(v + 0x68);
    if (v == 0)
        return 0;
    return v;
}
