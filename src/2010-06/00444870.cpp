// from server: 100% by auto
// roc 2010-06 00444870  unit: RBX::MergeBinder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00444870
//
// 00444870  51                   push ecx
// 00444871  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444875  c6042400             mov byte ptr [esp], 0
// 00444879  8b0424               mov eax, dword ptr [esp]
// 0044487c  50                   push eax
// 0044487d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00444881  52                   push edx
// 00444882  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444886  83c108               add ecx, 8
// 00444889  51                   push ecx
// 0044488a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044488e  50                   push eax
// 0044488f  51                   push ecx
// 00444890  52                   push edx
// 00444891  e8aafeffff           call 0x444740
// 00444896  83c41c               add esp, 0x1c
// 00444899  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
