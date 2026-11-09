// from server: 65% by atomic.potato
struct S {
    char pad[8];
    int (__stdcall *fn)(void*, int);
    int offset;
    int index;
    int method(void*, int);
};

int S::method(void* a, int b)
{
    char* p = (char*)a;
    if (p != 0)
        p -= 0x1c;
    else
        p = 0;

    int* q = (int*)b;
    int v = *q;

    int idx = *(int*)((char*)this + 0x10);
    int base = *(int*)(p + 0x84);
    int val = *(int*)(base + idx);
    val += *(int*)((char*)this + 0xc);

    int (__stdcall *f)(void*, int) = *(int (__stdcall **)(void*, int))((char*)this + 8);
    return f((void*)(val + (int)p + 0x84), v);
}
