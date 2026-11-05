// from server: 100% by why2
// roc 2009-06 0072d3c0  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072d3c0

struct CXTPCommandBar {
    char pad[0x5c];
    int m_nSomething;
};

extern "C" CXTPCommandBar* __cdecl sub_72d390();

int __cdecl sub_72d3c0()
{
    CXTPCommandBar* p = sub_72d390();
    if (p)
        return p->m_nSomething;
    return 0;
}
