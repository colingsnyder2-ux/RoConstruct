// from server: 100% by auto
// roc 2009-12 006c16e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c16e0
//
// 006c16e0  51                   push ecx
// 006c16e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c16e5  56                   push esi
// 006c16e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 006c16ea  57                   push edi
// 006c16eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006c16ef  c644240800           mov byte ptr [esp + 8], 0
// 006c16f4  8b442408             mov eax, dword ptr [esp + 8]
// 006c16f8  50                   push eax
// 006c16f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006c16fd  52                   push edx
// 006c16fe  83c108               add ecx, 8
// 006c1701  51                   push ecx
// 006c1702  50                   push eax
// 006c1703  56                   push esi
// 006c1704  57                   push edi
// 006c1705  e896ecffff           call 0x6c03a0
// 006c170a  8bc6                 mov eax, esi
// 006c170c  83c418               add esp, 0x18
// 006c170f  c1e005               shl eax, 5
// 006c1712  03c7                 add eax, edi
// 006c1714  5f                   pop edi
// 006c1715  5e                   pop esi
// 006c1716  59                   pop ecx
// 006c1717  c20c00               ret 0xc
// standard library vector<pod32> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
