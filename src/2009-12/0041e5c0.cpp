// from server: 100% by auto
// roc 2009-12 0041e5c0  unit: CSelectionTreeCtrl  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041e5c0
//
// 0041e5c0  56                   push esi
// 0041e5c1  8bf1                 mov esi, ecx
// 0041e5c3  8b06                 mov eax, dword ptr [esi]
// 0041e5c5  57                   push edi
// 0041e5c6  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0041e5cc  85c0                 test eax, eax
// 0041e5ce  7508                 jne 0x41e5d8
// 0041e5d0  ffd7                 call edi
// 0041e5d2  8b06                 mov eax, dword ptr [esi]
// 0041e5d4  85c0                 test eax, eax
// 0041e5d6  7404                 je 0x41e5dc
// 0041e5d8  8b00                 mov eax, dword ptr [eax]
// 0041e5da  eb02                 jmp 0x41e5de
// 0041e5dc  33c0                 xor eax, eax
// 0041e5de  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041e5e1  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 0041e5e4  7502                 jne 0x41e5e8
// 0041e5e6  ffd7                 call edi
// 0041e5e8  8b4604               mov eax, dword ptr [esi + 4]
// 0041e5eb  5f                   pop edi
// 0041e5ec  83c00c               add eax, 0xc
// 0041e5ef  5e                   pop esi
// 0041e5f0  c3                   ret 
// standard library map_int<ptr> (function ??Dconst_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QBEABU?$pair@$$CBHPAUT@@@2@XZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
