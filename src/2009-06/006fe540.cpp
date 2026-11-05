// from server: 100% by auto
// roc 2009-06 006fe540  unit: RBX::AdornRbxGfx  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe540
//
// 006fe540  51                   push ecx
// 006fe541  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fe545  c6042400             mov byte ptr [esp], 0
// 006fe549  8b0424               mov eax, dword ptr [esp]
// 006fe54c  50                   push eax
// 006fe54d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006fe551  52                   push edx
// 006fe552  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fe556  83c108               add ecx, 8
// 006fe559  51                   push ecx
// 006fe55a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006fe55e  50                   push eax
// 006fe55f  51                   push ecx
// 006fe560  52                   push edx
// 006fe561  e8aa79d8ff           call 0x485f10
// 006fe566  83c41c               add esp, 0x1c
// 006fe569  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
