// from server: 100% by auto
// roc 2009-12 005b1810  unit: RBX::BrickBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1810
//
// 005b1810  51                   push ecx
// 005b1811  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b1815  c6042400             mov byte ptr [esp], 0
// 005b1819  8b0424               mov eax, dword ptr [esp]
// 005b181c  50                   push eax
// 005b181d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b1821  52                   push edx
// 005b1822  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b1826  83c108               add ecx, 8
// 005b1829  51                   push ecx
// 005b182a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005b182e  50                   push eax
// 005b182f  51                   push ecx
// 005b1830  52                   push edx
// 005b1831  e85afcffff           call 0x5b1490
// 005b1836  83c41c               add esp, 0x1c
// 005b1839  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
