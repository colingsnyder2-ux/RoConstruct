// from server: 100% by auto
// roc 2009-12 0048cac0  unit: G3D::Shader  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048cac0
//
// 0048cac0  51                   push ecx
// 0048cac1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048cac5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048cac9  c6042400             mov byte ptr [esp], 0
// 0048cacd  8b0424               mov eax, dword ptr [esp]
// 0048cad0  50                   push eax
// 0048cad1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048cad5  51                   push ecx
// 0048cad6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048cada  52                   push edx
// 0048cadb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048cadf  50                   push eax
// 0048cae0  51                   push ecx
// 0048cae1  52                   push edx
// 0048cae2  e8f9f9ffff           call 0x48c4e0
// 0048cae7  83c41c               add esp, 0x1c
// 0048caea  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
