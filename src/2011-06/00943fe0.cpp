// from server: 44% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_0080b1d8(void *, DWORD, void *, DWORD, const char *);
extern "C" void __cdecl sub_0080a304(void *);

struct S_func_00943fe0
{
    virtual ~S_func_00943fe0();
};

S_func_00943fe0::~S_func_00943fe0()
{
    void *p = *(void **)this;
    if (p)
    {
        void *q = (char *)p - 4;
        sub_0080b1d8(p, 8, *(void **)q, 0x7736f0, "SUVW");
        sub_0080a304(q);
    }
}
