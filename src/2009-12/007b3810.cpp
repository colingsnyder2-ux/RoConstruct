// from server: 100% by auto
// roc 2009-12 007b3810  unit: RBX::Assembly  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3810
//
// 007b3810  51                   push ecx
// 007b3811  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3815  c6042400             mov byte ptr [esp], 0
// 007b3819  8b0424               mov eax, dword ptr [esp]
// 007b381c  50                   push eax
// 007b381d  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b3821  52                   push edx
// 007b3822  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3826  83c108               add ecx, 8
// 007b3829  51                   push ecx
// 007b382a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007b382e  50                   push eax
// 007b382f  51                   push ecx
// 007b3830  52                   push edx
// 007b3831  e81afaffff           call 0x7b3250
// 007b3836  83c41c               add esp, 0x1c
// 007b3839  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
