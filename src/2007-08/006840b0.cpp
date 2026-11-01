// from server: 100% by colin
struct CArrayBase {
    void Construct(int n);
};

struct CArrayDerived {
    char pad0[0x20];
    CArrayBase arr;
    char pad1[0x18];
    int m_3c;
    int m_40;
    int m_44;

    CArrayDerived();
};

extern "C" void __stdcall sub_73833a();

CArrayDerived::CArrayDerived()
{
    sub_73833a();
    *(void**)this = (void*)0x7cf0d4;
    arr.Construct(10);
    m_3c = 0;
    m_40 = 0;
    m_44 = 1;
}
