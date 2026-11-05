// from server: 100% by auto
// roc 2009-06 004265e0  unit: boost::any::H::?$holder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004265e0
//
// 004265e0  51                   push ecx
// 004265e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004265e5  56                   push esi
// 004265e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004265ea  57                   push edi
// 004265eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004265ef  c644240800           mov byte ptr [esp + 8], 0
// 004265f4  8b442408             mov eax, dword ptr [esp + 8]
// 004265f8  50                   push eax
// 004265f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004265fd  52                   push edx
// 004265fe  83c108               add ecx, 8
// 00426601  51                   push ecx
// 00426602  50                   push eax
// 00426603  56                   push esi
// 00426604  57                   push edi
// 00426605  e8c6fdffff           call 0x4263d0
// 0042660a  83c418               add esp, 0x18
// 0042660d  8d04f7               lea eax, [edi + esi*8]
// 00426610  5f                   pop edi
// 00426611  5e                   pop esi
// 00426612  59                   pop ecx
// 00426613  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
