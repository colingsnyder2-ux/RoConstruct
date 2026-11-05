// from server: 33% by colin
struct CComAggObject {
    void* operator new(unsigned int);
    void operator delete(void*);
    CComAggObject();
    ~CComAggObject();
    long m_dwRef;
    void* m_pUnkOuter;
    void* m_pUnkInner;
    void* m_pVtbl1;
    void* m_pVtbl2;
    void* m_pVtbl3;
    void* m_pVtbl4;
    unsigned short m_wFlags;
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);

void* CComAggObject::operator new(unsigned int size)
{
    return sub_62FEF6(size);
}

CComAggObject::CComAggObject()
{
    m_dwRef = 0;
    m_pUnkOuter = 0;
    m_pUnkInner = 0;
    m_pVtbl1 = (void*)0x78595c;
    m_wFlags = 0;
    m_pVtbl2 = (void*)0x785bc0;
    m_pVtbl3 = (void*)0x785ba8;
    m_pVtbl4 = (void*)0x785b84;
    *(void**)((char*)this + 0x14) = (void*)0x785b5c;
    m_dwRef = m_dwRef + 1;
    m_dwRef = m_dwRef - 1;
}

void* __cdecl sub_40BCD0()
{
    CComAggObject* p = new CComAggObject();
    return p;
}
