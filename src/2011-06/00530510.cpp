// from server: 97% by atomic.potato
extern "C" void __cdecl Function80B1D8(void *, unsigned int, unsigned int, const void *);
extern "C" void __cdecl Function80A304(void *);

struct ProfiledRakPeer {
    unsigned char padding0[16];
    void *value;
    unsigned char padding1[8];
    unsigned int count;
    void f();
};

void ProfiledRakPeer::f()
{
    if (count > 0) {
        void *valueCopy = value;
        if (valueCopy != 0) {
            void *p = (char *)valueCopy - 4;
            Function80B1D8(valueCopy, 16, *(unsigned int *)p, (const void *)0x86b640);
            Function80A304(p);
        }
    }
}
