// from server: 82% by atomic.potato
struct S
{
    int v0;
    int pad1[9];
    int v28;
    int pad2[4];
    int v3c;
    S* f(void* p);
};

extern "C" void __stdcall helper(void*);

S* S::f(void* p)
{
    helper(p);
    v3c = 0x00b43c34;
    v0 = 0x00b44290;
    v28 = 0x00b44288;
    v3c = 0x00b44278;
    return this;
}
