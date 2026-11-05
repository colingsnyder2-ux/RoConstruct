// from server: 100% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    void func_00664d70(DWORD, const char *, const char *, DWORD);
};

extern "C" void __cdecl func_007f4929(const char *);

void func_00972680()
{
    ((S *)0xb90274)->func_00664d70(0xd0, "ServiceAdded", "service", 1);
    func_007f4929((const char *)0x984830);
}
