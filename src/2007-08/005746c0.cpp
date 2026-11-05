// from server: 100% by colin
struct P8ModelInstance {
    char pad[8];
    int field8;
    int fieldC;
    int field10;
    void (__thiscall *field14)(int);

    void GetSetImpl(int arg);
};

void P8ModelInstance::GetSetImpl(int arg) {
    int *p;
    if (arg != 0) {
        p = (int *)(arg - 4);
    } else {
        p = 0;
    }
    int ecx = *(int *)((char *)p + 0xec);
    int esi = field10;
    int v = *(int *)(ecx + esi);
    v += fieldC;
    void (__thiscall *fn)(int) = *(void (__thiscall **)(int))((char *)this + 8);
    fn(v + (int)p + 0xec);
}
