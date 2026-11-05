// from server: 100% by auto
// roc 2010-06 004276b0  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004276b0
//
// 004276b0  51                   push ecx
// 004276b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004276b5  56                   push esi
// 004276b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004276ba  57                   push edi
// 004276bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004276bf  c644240800           mov byte ptr [esp + 8], 0
// 004276c4  8b442408             mov eax, dword ptr [esp + 8]
// 004276c8  50                   push eax
// 004276c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004276cd  52                   push edx
// 004276ce  83c108               add ecx, 8
// 004276d1  51                   push ecx
// 004276d2  50                   push eax
// 004276d3  56                   push esi
// 004276d4  57                   push edi
// 004276d5  e876fdffff           call 0x427450
// 004276da  83c418               add esp, 0x18
// 004276dd  8d04f7               lea eax, [edi + esi*8]
// 004276e0  5f                   pop edi
// 004276e1  5e                   pop esi
// 004276e2  59                   pop ecx
// 004276e3  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
