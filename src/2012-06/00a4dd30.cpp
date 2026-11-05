// roc 2012-06 00a4dd30  unit: CXTPTabPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4dd30
//
// 00a4dd30  8b442404             mov eax, dword ptr [esp + 4]
// 00a4dd34  8b11                 mov edx, dword ptr [ecx]
// 00a4dd36  898108010000         mov dword ptr [ecx + 0x108], eax
// 00a4dd3c  8b4270               mov eax, dword ptr [edx + 0x70]
// 00a4dd3f  ffd0                 call eax
// 00a4dd41  c20400               ret 4
// copied from an identical function in another client (function ?SetValue@CXTPTabPaintManager@ns_ROCX000013@@QAEXH@Z)

namespace ns_ROCX000013 {
struct CXTPTabPaintManager
{
    int m_pad[0x42];
    int m_nValue;

    void SetValue(int value);
};

void CXTPTabPaintManager::SetValue(int value)
{
    m_nValue = value;
    ((void (__thiscall *)(CXTPTabPaintManager *))((*(void ***)this)[0x1C]))(this);
}
}
