// from server: 88% by colin
struct VCApp_CComContainedObject {
    void* m_pUnknown;
    void* m_pUnk04;
    void* m_pUnk08;
    void* m_pUnk0C;
    void* m_pUnk10;
    void* m_pUnk14;
    void* m_pUnk18;
    void* m_pUnk1C;
    void* m_pUnk20;
    void* m_pUnk24;
    void* m_pUnk28;
};

struct VCApp_Inner {
    void* m_pVtbl;
};

struct VCApp_Outer {
    void* m_pVtbl;
};

void VCApp_CComContainedObject_Forward(VCApp_CComContainedObject* self, void* arg);

void VCApp_CComContainedObject_Forward(VCApp_CComContainedObject* self, void* arg)
{
    VCApp_Inner* inner = (VCApp_Inner*)self->m_pUnk28;
    void** vtbl = (void**)inner->m_pVtbl;
    void (*fn)(VCApp_Inner*, void*) = (void (*)(VCApp_Inner*, void*))vtbl[1];
    fn(inner, arg);
}
