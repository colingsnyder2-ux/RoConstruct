// from server: 100% by auto
// roc 2009-06 00675a10  unit: RBX::TimerService  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00675a10
//
// 00675a10  6aff                 push -1
// 00675a12  6878ef8600           push 0x86ef78
// 00675a17  64a100000000         mov eax, dword ptr fs:[0]
// 00675a1d  50                   push eax
// 00675a1e  64892500000000       mov dword ptr fs:[0], esp
// 00675a25  51                   push ecx
// 00675a26  56                   push esi
// 00675a27  8bf1                 mov esi, ecx
// 00675a29  89742404             mov dword ptr [esp + 4], esi
// 00675a2d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00675a35  e8e6fcffff           call 0x675720
// 00675a3a  8b4614               mov eax, dword ptr [esi + 0x14]
// 00675a3d  50                   push eax
// 00675a3e  e8ef2f0a00           call 0x718a32
// 00675a43  8b0e                 mov ecx, dword ptr [esi]
// 00675a45  51                   push ecx
// 00675a46  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00675a4d  e8e02f0a00           call 0x718a32
// 00675a52  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00675a56  83c408               add esp, 8
// 00675a59  5e                   pop esi
// 00675a5a  64890d00000000       mov dword ptr fs:[0], ecx
// 00675a61  83c410               add esp, 0x10
// 00675a64  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
