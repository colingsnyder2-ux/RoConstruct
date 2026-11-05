// from server: 100% by auto
// roc 2010-06 009758f0  unit: RBX::RightAngleRampBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009758f0
//
// 009758f0  51                   push ecx
// 009758f1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009758f5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009758f9  c6042400             mov byte ptr [esp], 0
// 009758fd  8b0424               mov eax, dword ptr [esp]
// 00975900  50                   push eax
// 00975901  8b442414             mov eax, dword ptr [esp + 0x14]
// 00975905  51                   push ecx
// 00975906  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0097590a  52                   push edx
// 0097590b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0097590f  50                   push eax
// 00975910  51                   push ecx
// 00975911  52                   push edx
// 00975912  e8d99cf6ff           call 0x8df5f0
// 00975917  83c41c               add esp, 0x1c
// 0097591a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
