// from server: 100% by colin
struct P8PartInstance_GetSetImpl {
    char pad0[0x18];
    int field18;
    int field1c;
    int field20;
    void func(int a, float *b);
};

void P8PartInstance_GetSetImpl::func(int a, float *b)
{
    int *p = (int *)a;
    if (p)
        p = (int *)((char *)p - 4);
    else
        p = 0;
    int idx = this->field20;
    int base = p[0xec / 4];
    int v = *(int *)(base + idx);
    float val = *b;
    v += this->field1c;
    void (__thiscall *fn)(int, float) = (void (__thiscall *)(int, float))this->field18;
    fn(v + (int)p + 0xec, val);
}
