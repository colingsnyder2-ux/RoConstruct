// from server: 100% by auto
// roc 2008-06 00428f10  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428f10
//
// 00428f10  51                   push ecx
// 00428f11  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428f15  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00428f19  c6042400             mov byte ptr [esp], 0
// 00428f1d  8b0424               mov eax, dword ptr [esp]
// 00428f20  50                   push eax
// 00428f21  8b442414             mov eax, dword ptr [esp + 0x14]
// 00428f25  51                   push ecx
// 00428f26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00428f2a  52                   push edx
// 00428f2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00428f2f  50                   push eax
// 00428f30  51                   push ecx
// 00428f31  52                   push edx
// 00428f32  e889faffff           call 0x4289c0
// 00428f37  83c41c               add esp, 0x1c
// 00428f3a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
