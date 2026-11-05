// from server: 67% by atomic.potato
struct S {
    int f(void* a, void* b);
};

int S::f(void* a, void* b)
{
    void* p;
    void* q;

    p = a ? (char*)a + 0x1c : 0;
    q = *(void**)((char*)*(void**)((char*)this + 0x140) + 0x1c);
    return ((int (__thiscall *)(void*, void*, void*))(*(unsigned int*)((char*)q)[0] + 0x10))(q, p, b);
}
