// from server: 100% by auto
// roc 2008-06 004248a0  unit: CSelectionTreeCtrl  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004248a0
//
// 004248a0  83ec08               sub esp, 8
// 004248a3  53                   push ebx
// 004248a4  55                   push ebp
// 004248a5  56                   push esi
// 004248a6  8bf1                 mov esi, ecx
// 004248a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004248ab  57                   push edi
// 004248ac  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004248af  7606                 jbe 0x4248b7
// 004248b1  ff1590288000         call dword ptr [0x802890]
// 004248b7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004248ba  8b2e                 mov ebp, dword ptr [esi]
// 004248bc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004248bf  7606                 jbe 0x4248c7
// 004248c1  ff1590288000         call dword ptr [0x802890]
// 004248c7  8b06                 mov eax, dword ptr [esi]
// 004248c9  53                   push ebx
// 004248ca  55                   push ebp
// 004248cb  57                   push edi
// 004248cc  50                   push eax
// 004248cd  8d442420             lea eax, [esp + 0x20]
// 004248d1  50                   push eax
// 004248d2  8bce                 mov ecx, esi
// 004248d4  e8a7d8feff           call 0x412180
// 004248d9  5f                   pop edi
// 004248da  5e                   pop esi
// 004248db  5d                   pop ebp
// 004248dc  5b                   pop ebx
// 004248dd  83c408               add esp, 8
// 004248e0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
