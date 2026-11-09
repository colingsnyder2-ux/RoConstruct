// from server: 100% by auto
// roc 2010-06 00559080  unit: G3D::BinaryInput  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559080
//
// 00559080  8b442408             mov eax, dword ptr [esp + 8]
// 00559084  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00559088  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0055908c  2bc1                 sub eax, ecx
// 0055908e  56                   push esi
// 0055908f  8d3410               lea esi, [eax + edx]
// 00559092  740d                 je 0x5590a1
// 00559094  50                   push eax
// 00559095  51                   push ecx
// 00559096  50                   push eax
// 00559097  52                   push edx
// 00559098  ff1580a89e00         call dword ptr [0x9ea880]
// 0055909e  83c410               add esp, 0x10
// 005590a1  8bc6                 mov eax, esi
// 005590a3  5e                   pop esi
// 005590a4  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
