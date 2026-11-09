// from server: 100% by auto
// roc 2011-06 006eb8f0  unit: VWiniInetRequest_source::?$stream_buffer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006eb8f0
//
// 006eb8f0  51                   push ecx
// 006eb8f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006eb8f5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006eb8f9  c6042400             mov byte ptr [esp], 0
// 006eb8fd  8b0424               mov eax, dword ptr [esp]
// 006eb900  50                   push eax
// 006eb901  8b442414             mov eax, dword ptr [esp + 0x14]
// 006eb905  51                   push ecx
// 006eb906  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006eb90a  52                   push edx
// 006eb90b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006eb90f  50                   push eax
// 006eb910  51                   push ecx
// 006eb911  52                   push edx
// 006eb912  e8a9f8ffff           call 0x6eb1c0
// 006eb917  83c41c               add esp, 0x1c
// 006eb91a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
