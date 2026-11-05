// roc 2012-06 00992e00  unit: CXTPCommandBar  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992e00
//
// 00992e00  56                   push esi
// 00992e01  8bf1                 mov esi, ecx
// 00992e03  8b8e68010000         mov ecx, dword ptr [esi + 0x168]
// 00992e09  85c9                 test ecx, ecx
// 00992e0b  7413                 je 0x992e20
// 00992e0d  e878f8feff           call 0x98268a
// 00992e12  8b442408             mov eax, dword ptr [esp + 8]
// 00992e16  898668010000         mov dword ptr [esi + 0x168], eax
// 00992e1c  5e                   pop esi
// 00992e1d  c20400               ret 4
// 00992e20  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00992e24  898e68010000         mov dword ptr [esi + 0x168], ecx
// 00992e2a  5e                   pop esi
// 00992e2b  c20400               ret 4
// copied from an identical function in another client (function ?SetField@CXTPCommandBar@ns_ROCX000000@@QAEXPAX@Z)

namespace ns_ROCX000000 {
struct CXTPCommandBar {
    char pad[0x168];
    void* field_168;
    void SetField(void* p);
};

extern "C" void __fastcall sub_6301E4(void* p);

void CXTPCommandBar::SetField(void* p) {
    if (field_168 != 0) {
        sub_6301E4(field_168);
    }
    field_168 = p;
}
}
