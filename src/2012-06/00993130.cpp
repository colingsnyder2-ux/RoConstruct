// roc 2012-06 00993130  unit: CXTPCommandBar  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00993130
//
// 00993130  53                   push ebx
// 00993131  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00993135  55                   push ebp
// 00993136  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0099313a  56                   push esi
// 0099313b  57                   push edi
// 0099313c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00993140  57                   push edi
// 00993141  53                   push ebx
// 00993142  55                   push ebp
// 00993143  8bf1                 mov esi, ecx
// 00993145  e8b6ffffff           call 0x993100
// 0099314a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0099314e  50                   push eax
// 0099314f  57                   push edi
// 00993150  53                   push ebx
// 00993151  55                   push ebp
// 00993152  8bce                 mov ecx, esi
// 00993154  e83bf1feff           call 0x982294
// 00993159  5f                   pop edi
// 0099315a  5e                   pop esi
// 0099315b  5d                   pop ebp
// 0099315c  5b                   pop ebx
// 0099315d  c21000               ret 0x10
// copied from an identical function in another client (function ?func@CXTPCommandBar@ns_ROCX000005@@QAEXHHHH@Z)

namespace ns_ROCX000005 {
struct CXTPCommandBar {
    void sub_643D90(int, int, int);
    void sub_62FDDC(int, int, int, int);
    void func(int, int, int, int);
};

void CXTPCommandBar::func(int a, int b, int c, int d) {
    sub_643D90(a, b, c);
    sub_62FDDC(a, b, c, d);
}
}
