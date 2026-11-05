// from server: 70% by atomic.potato
struct S
{
    void __fastcall f(S*, S*);
    unsigned char pad0[0x28];
};

void __fastcall S::f(S* a, S* b)
{
    S* c = *(S**)((char*)a + 0x10);
    *(unsigned char*)((char*)b + 5) &= 0xfb;
    *(S**)((char*)b + 0x1c) = *(S**)((char*)c + 0x28);
    *(S**)((char*)c + 0x28) = b;
}
