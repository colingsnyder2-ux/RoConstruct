// from server: 100% by auto
// roc 2009-12 006c1870  unit: RBX::VInstance::?$NonFactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c1870
//
// 006c1870  51                   push ecx
// 006c1871  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c1875  c6042400             mov byte ptr [esp], 0
// 006c1879  8b0424               mov eax, dword ptr [esp]
// 006c187c  50                   push eax
// 006c187d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c1881  52                   push edx
// 006c1882  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c1886  83c108               add ecx, 8
// 006c1889  51                   push ecx
// 006c188a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c188e  50                   push eax
// 006c188f  51                   push ecx
// 006c1890  52                   push edx
// 006c1891  e8dae3ffff           call 0x6bfc70
// 006c1896  83c41c               add esp, 0x1c
// 006c1899  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
