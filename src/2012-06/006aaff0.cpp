// from server: 100% by auto
// roc 2012-06 006aaff0  unit: RBX::GcJob  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006aaff0
//
// 006aaff0  6aff                 push -1
// 006aaff2  681890ad00           push 0xad9018
// 006aaff7  64a100000000         mov eax, dword ptr fs:[0]
// 006aaffd  50                   push eax
// 006aaffe  64892500000000       mov dword ptr fs:[0], esp
// 006ab005  51                   push ecx
// 006ab006  56                   push esi
// 006ab007  8bf1                 mov esi, ecx
// 006ab009  89742404             mov dword ptr [esp + 4], esi
// 006ab00d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006ab015  e846d9ffff           call 0x6a8960
// 006ab01a  8b06                 mov eax, dword ptr [esi]
// 006ab01c  50                   push eax
// 006ab01d  e8f2702d00           call 0x982114
// 006ab022  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006ab026  83c404               add esp, 4
// 006ab029  5e                   pop esi
// 006ab02a  64890d00000000       mov dword ptr fs:[0], ecx
// 006ab031  83c410               add esp, 0x10
// 006ab034  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
