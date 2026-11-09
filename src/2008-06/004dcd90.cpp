// from server: 100% by auto
// roc 2008-06 004dcd90  unit: RBX::ViewNew::ViewG3D  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dcd90
//
// 004dcd90  51                   push ecx
// 004dcd91  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dcd95  56                   push esi
// 004dcd96  8b742410             mov esi, dword ptr [esp + 0x10]
// 004dcd9a  57                   push edi
// 004dcd9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004dcd9f  c644240800           mov byte ptr [esp + 8], 0
// 004dcda4  8b442408             mov eax, dword ptr [esp + 8]
// 004dcda8  50                   push eax
// 004dcda9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004dcdad  52                   push edx
// 004dcdae  83c108               add ecx, 8
// 004dcdb1  51                   push ecx
// 004dcdb2  50                   push eax
// 004dcdb3  56                   push esi
// 004dcdb4  57                   push edi
// 004dcdb5  e8b6fcffff           call 0x4dca70
// 004dcdba  8d0c76               lea ecx, [esi + esi*2]
// 004dcdbd  83c418               add esp, 0x18
// 004dcdc0  8d048f               lea eax, [edi + ecx*4]
// 004dcdc3  5f                   pop edi
// 004dcdc4  5e                   pop esi
// 004dcdc5  59                   pop ecx
// 004dcdc6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
