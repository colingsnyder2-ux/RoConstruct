// from server: 100% by auto
// roc 2011-06 00544070  unit: G3D::BinaryInput  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00544070
//
// 00544070  8b442408             mov eax, dword ptr [esp + 8]
// 00544074  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00544078  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054407c  2bc1                 sub eax, ecx
// 0054407e  56                   push esi
// 0054407f  8d3410               lea esi, [eax + edx]
// 00544082  740d                 je 0x544091
// 00544084  50                   push eax
// 00544085  51                   push ecx
// 00544086  50                   push eax
// 00544087  52                   push edx
// 00544088  ff15fc09a400         call dword ptr [0xa409fc]
// 0054408e  83c410               add esp, 0x10
// 00544091  8bc6                 mov eax, esi
// 00544093  5e                   pop esi
// 00544094  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
