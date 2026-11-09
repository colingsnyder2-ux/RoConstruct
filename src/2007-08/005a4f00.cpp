// from server: 100% by colin
struct GetSetImpl {
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    void invoke(int, int);
};

void GetSetImpl::invoke(int a, int b)
{
    int obj = a;
    if (obj != 0)
        obj -= 4;
    else
        obj = 0;

    unsigned char idx = *(unsigned char*)b;
    int off = *(int*)(obj + 0x108);
    int v = *(int*)(off + field_0x20);
    v += field_0x1c;
    v += obj + 0x108;

    void (__thiscall *fn)(int, int) = (void (__thiscall *)(int, int))field_0x18;
    fn(v, idx);
}
