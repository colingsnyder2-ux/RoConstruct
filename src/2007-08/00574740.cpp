// from server: 100% by colin
struct P8PartInstance_GetSetImpl
{
    char pad0[0x18];
    int m18;
    int m1c;
    int m20;
    void (__thiscall *m_func)(void*, unsigned char);
    char pad28[0xc4];
    int m_ec;

    void GetSetImpl(int a, unsigned char* b);
};

void P8PartInstance_GetSetImpl::GetSetImpl(int a, unsigned char* b)
{
    P8PartInstance_GetSetImpl* p = (P8PartInstance_GetSetImpl*)a;
    if (p)
        p = (P8PartInstance_GetSetImpl*)((char*)p - 4);
    else
        p = 0;

    unsigned char idx = *b;
    int off = *(int*)((char*)p + 0xec);
    int val = *(int*)(off + this->m20);
    val += this->m1c;
    void (__thiscall *fn)(void*, unsigned char) = *(void (__thiscall**)(void*, unsigned char))((char*)this + 0x18);
    fn((void*)((char*)p + 0xec + val), idx);
}
