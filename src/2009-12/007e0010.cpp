// from server: 100% by auto
// roc 2009-12 007e0010  unit: RBX::CircleRadialNormal  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e0010
//
// 007e0010  51                   push ecx
// 007e0011  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e0015  c6042400             mov byte ptr [esp], 0
// 007e0019  8b0424               mov eax, dword ptr [esp]
// 007e001c  50                   push eax
// 007e001d  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e0021  52                   push edx
// 007e0022  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e0026  83c108               add ecx, 8
// 007e0029  51                   push ecx
// 007e002a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007e002e  50                   push eax
// 007e002f  51                   push ecx
// 007e0030  52                   push edx
// 007e0031  e86afbffff           call 0x7dfba0
// 007e0036  83c41c               add esp, 0x1c
// 007e0039  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
