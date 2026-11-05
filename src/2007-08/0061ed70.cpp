// from server: 100% by auto
// roc 2007-08 0061ed70  unit: RBX::ScoreHud  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061ed70
//
// 0061ed70  51                   push ecx
// 0061ed71  8b542410             mov edx, dword ptr [esp + 0x10]
// 0061ed75  c6042400             mov byte ptr [esp], 0
// 0061ed79  8b0424               mov eax, dword ptr [esp]
// 0061ed7c  50                   push eax
// 0061ed7d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061ed81  52                   push edx
// 0061ed82  8b542410             mov edx, dword ptr [esp + 0x10]
// 0061ed86  51                   push ecx
// 0061ed87  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0061ed8b  50                   push eax
// 0061ed8c  51                   push ecx
// 0061ed8d  52                   push edx
// 0061ed8e  e8bdf5ffff           call 0x61e350
// 0061ed93  83c41c               add esp, 0x1c
// 0061ed96  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
