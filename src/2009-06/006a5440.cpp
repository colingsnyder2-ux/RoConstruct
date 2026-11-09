// from server: 100% by auto
// roc 2009-06 006a5440  unit: RBX::VMouse::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006a5440
//
// 006a5440  51                   push ecx
// 006a5441  8b542410             mov edx, dword ptr [esp + 0x10]
// 006a5445  c6042400             mov byte ptr [esp], 0
// 006a5449  8b0424               mov eax, dword ptr [esp]
// 006a544c  50                   push eax
// 006a544d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006a5451  52                   push edx
// 006a5452  8b542410             mov edx, dword ptr [esp + 0x10]
// 006a5456  83c108               add ecx, 8
// 006a5459  51                   push ecx
// 006a545a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006a545e  50                   push eax
// 006a545f  51                   push ecx
// 006a5460  52                   push edx
// 006a5461  e81a070000           call 0x6a5b80
// 006a5466  83c41c               add esp, 0x1c
// 006a5469  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
