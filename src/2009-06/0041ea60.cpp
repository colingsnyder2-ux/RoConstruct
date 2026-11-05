// from server: 100% by auto
// roc 2009-06 0041ea60  unit: CSelectionTreeCtrl  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ea60
//
// 0041ea60  83ec08               sub esp, 8
// 0041ea63  53                   push ebx
// 0041ea64  55                   push ebp
// 0041ea65  56                   push esi
// 0041ea66  8bf1                 mov esi, ecx
// 0041ea68  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0041ea6b  57                   push edi
// 0041ea6c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0041ea6f  7606                 jbe 0x41ea77
// 0041ea71  ff15ace98900         call dword ptr [0x89e9ac]
// 0041ea77  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0041ea7a  8b2e                 mov ebp, dword ptr [esi]
// 0041ea7c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0041ea7f  7606                 jbe 0x41ea87
// 0041ea81  ff15ace98900         call dword ptr [0x89e9ac]
// 0041ea87  8b06                 mov eax, dword ptr [esi]
// 0041ea89  53                   push ebx
// 0041ea8a  55                   push ebp
// 0041ea8b  57                   push edi
// 0041ea8c  50                   push eax
// 0041ea8d  8d442420             lea eax, [esp + 0x20]
// 0041ea91  50                   push eax
// 0041ea92  8bce                 mov ecx, esi
// 0041ea94  e8a7fa2700           call 0x69e540
// 0041ea99  5f                   pop edi
// 0041ea9a  5e                   pop esi
// 0041ea9b  5d                   pop ebp
// 0041ea9c  5b                   pop ebx
// 0041ea9d  83c408               add esp, 8
// 0041eaa0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
