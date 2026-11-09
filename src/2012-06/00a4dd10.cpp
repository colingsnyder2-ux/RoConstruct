// roc 2012-06 00a4dd10  unit: CXTPTabPaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4dd10
//
// 00a4dd10  8b442404             mov eax, dword ptr [esp + 4]
// 00a4dd14  8b11                 mov edx, dword ptr [ecx]
// 00a4dd16  898104010000         mov dword ptr [ecx + 0x104], eax
// 00a4dd1c  8b4270               mov eax, dword ptr [edx + 0x70]
// 00a4dd1f  ffd0                 call eax
// 00a4dd21  c20400               ret 4
// copied from an identical function in another client (function ?SetValue@CXTPTabPaintManager@ns_ROCX000012@@QAEXH@Z)

namespace ns_ROCX000012 {
struct CXTPTabPaintManager
{
    int m_nValue;
    char m_pad[0x100];
    int m_nField104;
    void SetValue(int);
};

void CXTPTabPaintManager::SetValue(int nValue)
{
    m_nField104 = nValue;
    (*(void (__thiscall **)(CXTPTabPaintManager *))(*(int *)this + 0x70))(this);
}
}
