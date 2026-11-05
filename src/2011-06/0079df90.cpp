// from server: 46% by atomic.potato
struct S
{
    int GetValue();
};

extern "C" int G1_func_0079d8a0(S *, int);

int S::GetValue()
{
    return 0;
}

extern "C" int __stdcall func_0079df90(S *p)
{
    int v = p->GetValue();
    v *= 0x54;
    if (*(int *)((char *)v + 0xabc5d0) != 0xf)
        *((char *)p + 0x2c) = (char)G1_func_0079d8a0(p, 0);
    return 0;
}
