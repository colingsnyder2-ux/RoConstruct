// roc 2012-06 009f2630  unit: CXTPPropertyGridItem  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f2630
//
// 009f2630  8b442404             mov eax, dword ptr [esp + 4]
// 009f2634  398190000000         cmp dword ptr [ecx + 0x90], eax
// 009f263a  7413                 je 0x9f264f
// 009f263c  898190000000         mov dword ptr [ecx + 0x90], eax
// 009f2642  c744240401000000     mov dword ptr [esp + 4], 1
// 009f264a  e981ffffff           jmp 0x9f25d0
// 009f264f  c20400               ret 4
// copied from an identical function in another client (function ?SetValue@CXTPPropertyGridItem@ns_ROCX00001b@@QAEXH@Z)

namespace ns_ROCX00001b {
struct CXTPPropertyGridItem {
    char pad[0x90];
    int m_nValue;
    void OnValueChanged(int value);

    void SetValue(int value);
};

void CXTPPropertyGridItem::SetValue(int value) {
    if (m_nValue != value) {
        m_nValue = value;
        OnValueChanged(1);
    }
}
}
