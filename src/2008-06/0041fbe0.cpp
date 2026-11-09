// from server: 100% by auto
// roc 2008-06 0041fbe0  unit: CListCtrl  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041fbe0
//
// 0041fbe0  56                   push esi
// 0041fbe1  8bf1                 mov esi, ecx
// 0041fbe3  8b06                 mov eax, dword ptr [esi]
// 0041fbe5  57                   push edi
// 0041fbe6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041fbea  85c0                 test eax, eax
// 0041fbec  7404                 je 0x41fbf2
// 0041fbee  3b07                 cmp eax, dword ptr [edi]
// 0041fbf0  7406                 je 0x41fbf8
// 0041fbf2  ff1590288000         call dword ptr [0x802890]
// 0041fbf8  8b4604               mov eax, dword ptr [esi + 4]
// 0041fbfb  2b4704               sub eax, dword ptr [edi + 4]
// 0041fbfe  5f                   pop edi
// 0041fbff  c1f803               sar eax, 3
// 0041fc02  5e                   pop esi
// 0041fc03  c20400               ret 4
// standard library vector<double> (function ??G?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBEHABV01@@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
