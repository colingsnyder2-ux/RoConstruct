// from server: 62% by atomic.potato
struct S_func_0067db00 {
    char pad0[0x1c];
    void* m_vtbl1c;
    char pad20[0x74];
    void* m_vtbl94;
    int f(int arg);
};

int S_func_0067db00::f(int arg)
{
    if (arg != 0)
        return 0;
    char* base = (char*)this - 0x94;
    void** vtbl = *(void***)base;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[0x48 / 4];
    fn(base);
    return 0;
}
