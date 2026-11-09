// from server: 65% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(void*, int);
    int offset1c;
    int offset20;
    int method(int* a, int* b);
};

int S::method(int* a, int* b)
{
    int* p = a;
    if (p != 0)
        p = (int*)((char*)p - 0x1c);
    else
        p = 0;
    int v = *b;
    int idx = *(int*)((char*)this + 0x20);
    int base = *(int*)((char*)p + 0x148);
    int val = *(int*)(base + idx);
    val += *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(void*, int) = *(int (__stdcall **)(void*, int))((char*)this + 0x18);
    return f((char*)p + val + 0x148, v);
}
