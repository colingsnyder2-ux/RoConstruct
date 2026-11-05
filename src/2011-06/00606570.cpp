// from server: 86% by atomic.potato
struct S
{
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int (*callback)(int *, int *, int);
    int pad5;
    int value;
    int pad7;
    int f();
};

int S::f()
{
    int *p = reinterpret_cast<int *>(callback);
    if (p != 0)
    {
        int *q = &value;
        if (*p != 0)
            reinterpret_cast<int (__thiscall *)(int *, int *, int)>(*p)(q, q, 2);
    }
    callback = 0;
    return 0;
}
