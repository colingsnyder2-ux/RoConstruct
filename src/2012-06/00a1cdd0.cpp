// roc 2012-06 00a1cdd0  unit: CXTPMenuBar  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1cdd0
//
// 00a1cdd0  56                   push esi
// 00a1cdd1  57                   push edi
// 00a1cdd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00a1cdd6  8bf1                 mov esi, ecx
// 00a1cdd8  81ffbf2f0000         cmp edi, 0x2fbf
// 00a1cdde  7505                 jne 0xa1cde5
// 00a1cde0  e8fbfdffff           call 0xa1cbe0
// 00a1cde5  57                   push edi
// 00a1cde6  8bce                 mov ecx, esi
// 00a1cde8  e8536df7ff           call 0x993b40
// 00a1cded  5f                   pop edi
// 00a1cdee  5e                   pop esi
// 00a1cdef  c20400               ret 4
// copied from an identical function in another client (function ?func@CXTPMenuBar@ns_ROCX000012@@QAEXI@Z)

namespace ns_ROCX000012 {
struct CXTPMenuBar {
    void sub_6A6BD0();
    void sub_644750(unsigned int);
    void func(unsigned int);
};

void CXTPMenuBar::func(unsigned int arg) {
    if (arg == 0x2fbf) {
        sub_6A6BD0();
    }
    sub_644750(arg);
}
}
