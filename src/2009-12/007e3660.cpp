// from server: 100% by auto
// roc 2009-12 007e3660  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e3660
//
// 007e3660  51                   push ecx
// 007e3661  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e3665  c6042400             mov byte ptr [esp], 0
// 007e3669  8b0424               mov eax, dword ptr [esp]
// 007e366c  50                   push eax
// 007e366d  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e3671  52                   push edx
// 007e3672  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e3676  83c108               add ecx, 8
// 007e3679  51                   push ecx
// 007e367a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007e367e  50                   push eax
// 007e367f  51                   push ecx
// 007e3680  52                   push edx
// 007e3681  e8eaf4ffff           call 0x7e2b70
// 007e3686  83c41c               add esp, 0x1c
// 007e3689  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
