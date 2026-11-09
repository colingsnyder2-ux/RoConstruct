// from server: 100% by auto
// roc 2010-06 006ef7f0  unit: RBX::HandlesBase  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ef7f0
//
// 006ef7f0  56                   push esi
// 006ef7f1  8bf1                 mov esi, ecx
// 006ef7f3  8b06                 mov eax, dword ptr [esi]
// 006ef7f5  57                   push edi
// 006ef7f6  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 006ef7fc  85c0                 test eax, eax
// 006ef7fe  7508                 jne 0x6ef808
// 006ef800  ffd7                 call edi
// 006ef802  8b06                 mov eax, dword ptr [esi]
// 006ef804  85c0                 test eax, eax
// 006ef806  7404                 je 0x6ef80c
// 006ef808  8b00                 mov eax, dword ptr [eax]
// 006ef80a  eb02                 jmp 0x6ef80e
// 006ef80c  33c0                 xor eax, eax
// 006ef80e  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ef811  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 006ef814  7502                 jne 0x6ef818
// 006ef816  ffd7                 call edi
// 006ef818  8b4604               mov eax, dword ptr [esi + 4]
// 006ef81b  5f                   pop edi
// 006ef81c  83c00c               add eax, 0xc
// 006ef81f  5e                   pop esi
// 006ef820  c3                   ret 
// standard library map_int<ptr> (function ??Dconst_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QBEABU?$pair@$$CBHPAUT@@@2@XZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
