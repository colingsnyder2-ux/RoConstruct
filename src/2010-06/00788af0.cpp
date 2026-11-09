// from server: 100% by auto
// roc 2010-06 00788af0  unit: RBX::HUMAN::GettingUp  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788af0
//
// 00788af0  51                   push ecx
// 00788af1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788af5  56                   push esi
// 00788af6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00788afa  57                   push edi
// 00788afb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00788aff  c644240800           mov byte ptr [esp + 8], 0
// 00788b04  8b442408             mov eax, dword ptr [esp + 8]
// 00788b08  50                   push eax
// 00788b09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00788b0d  52                   push edx
// 00788b0e  83c108               add ecx, 8
// 00788b11  51                   push ecx
// 00788b12  50                   push eax
// 00788b13  56                   push esi
// 00788b14  57                   push edi
// 00788b15  e816fcffff           call 0x788730
// 00788b1a  8d0476               lea eax, [esi + esi*2]
// 00788b1d  83c418               add esp, 0x18
// 00788b20  c1e004               shl eax, 4
// 00788b23  03c7                 add eax, edi
// 00788b25  5f                   pop edi
// 00788b26  5e                   pop esi
// 00788b27  59                   pop ecx
// 00788b28  c20c00               ret 0xc
// standard library vector<pod48> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
