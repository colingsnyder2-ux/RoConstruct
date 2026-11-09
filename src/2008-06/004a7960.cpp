// from server: 100% by auto
// roc 2008-06 004a7960  unit: RBX::VHint::?$FactoryProduct::Creator  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7960
//
// 004a7960  51                   push ecx
// 004a7961  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a7965  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a7969  c6042400             mov byte ptr [esp], 0
// 004a796d  8b0424               mov eax, dword ptr [esp]
// 004a7970  50                   push eax
// 004a7971  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a7975  51                   push ecx
// 004a7976  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a797a  52                   push edx
// 004a797b  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a797f  50                   push eax
// 004a7980  51                   push ecx
// 004a7981  52                   push edx
// 004a7982  e8b9f9ffff           call 0x4a7340
// 004a7987  83c41c               add esp, 0x1c
// 004a798a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
