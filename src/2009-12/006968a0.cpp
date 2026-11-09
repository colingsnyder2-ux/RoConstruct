// from server: 71% by atomic.potato
struct S {
    unsigned char f();
};

unsigned char S::f()
{
    int* p = *(int**)((char*)this + 0x1b4);
    if (p)
        return ((unsigned char (__thiscall *)(int*))(*(int**)p + 0x48))(p);
    return 0;
}
