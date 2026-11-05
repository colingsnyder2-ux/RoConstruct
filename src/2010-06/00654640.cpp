// from server: 65% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    char pad2[0x20 - 0x1c];
    int offset20;
    int method(int, int*);
};

int S::method(int a, int* b)
{
    S* p;
    if (a != 0)
        p = (S*)((char*)a - 0x1c);
    else
        p = 0;
    int v = *b;
    int idx = this->offset20;
    int base = *(int*)((char*)p + 0x98);
    int arg = *(int*)(base + idx) + *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(int, int) = *(int (__stdcall **)(int, int))((char*)this + 0x18);
    return f(arg + (int)p + 0x98, v);
}
