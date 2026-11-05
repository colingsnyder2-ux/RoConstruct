// from server: 100% by atomic.potato
struct S
{
    char pad[0x18];
    void (__thiscall *fn)(void*, int);
    char pad2[0x20 - 0x1c];
    int idx;
    void f(void* a, int* b);
};

void S::f(void* a, int* b)
{
    char* p = (char*)a;
    if (p)
        p -= 0x1c;
    else
        p = 0;
    int v = *b;
    int i = *(int*)((char*)this + 0x20);
    int off = *(int*)(p + 0xb4);
    int c = *(int*)(off + i) + *(int*)((char*)this + 0x1c);
    void (__thiscall *fn)(void*, int) = *(void (__thiscall **)(void*, int))((char*)this + 0x18);
    fn((char*)p + c + 0xb4, v);
}
