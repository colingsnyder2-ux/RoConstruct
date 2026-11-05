// from server: 65% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl func_00719b76(void *, DWORD, DWORD, const char *);

struct seg_00860000
{
    char pad[0xd4];
    void f();
};

void seg_00860000::f()
{
    func_00719b76((void *)((char *)this + 0xd4), 0x1c, 2, "SUVW");
}
