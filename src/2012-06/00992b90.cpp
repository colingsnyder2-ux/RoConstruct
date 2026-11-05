// roc 2012-06 00992b90  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992b90
//
// 00992b90  8b8178010000         mov eax, dword ptr [ecx + 0x178]
// 00992b96  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00992b9a  894818               mov dword ptr [eax + 0x18], ecx
// 00992b9d  c20400               ret 4
// copied from an identical function in another client (function ?SetInnerValue@CXTPCommandBar@ns_ROCX000005@@QAEXH@Z)

namespace ns_ROCX000005 {
struct Inner
{
    char pad_0[0x18];
    int value;
};

struct CXTPCommandBar
{
    char pad_0[0x178];
    Inner* pInner;
    void SetInnerValue(int value);
};

void CXTPCommandBar::SetInnerValue(int value)
{
    pInner->value = value;
}
}
