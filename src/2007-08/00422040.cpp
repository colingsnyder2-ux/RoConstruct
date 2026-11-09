// from server: 100% by auto
// roc 2007-08 00422040  unit: CRobloxTreeCtrl  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422040
//
// 00422040  83ec08               sub esp, 8
// 00422043  53                   push ebx
// 00422044  55                   push ebp
// 00422045  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 0042204b  56                   push esi
// 0042204c  8bf1                 mov esi, ecx
// 0042204e  57                   push edi
// 0042204f  8b7e08               mov edi, dword ptr [esi + 8]
// 00422052  397e04               cmp dword ptr [esi + 4], edi
// 00422055  7602                 jbe 0x422059
// 00422057  ffd5                 call ebp
// 00422059  8b5e04               mov ebx, dword ptr [esi + 4]
// 0042205c  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0042205f  7602                 jbe 0x422063
// 00422061  ffd5                 call ebp
// 00422063  57                   push edi
// 00422064  56                   push esi
// 00422065  53                   push ebx
// 00422066  56                   push esi
// 00422067  8d442420             lea eax, [esp + 0x20]
// 0042206b  50                   push eax
// 0042206c  8bce                 mov ecx, esi
// 0042206e  e88dbbfeff           call 0x40dc00
// 00422073  5f                   pop edi
// 00422074  5e                   pop esi
// 00422075  5d                   pop ebp
// 00422076  5b                   pop ebx
// 00422077  83c408               add esp, 8
// 0042207a  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
