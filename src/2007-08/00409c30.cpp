// from server: 100% by colin
struct CComObjectLike {
    unsigned char pad[0x28];
    unsigned long m_dwRef;
    unsigned long __stdcall AddRef();
};

unsigned long __stdcall CComObjectLike::AddRef()
{
    return ++m_dwRef;
}
