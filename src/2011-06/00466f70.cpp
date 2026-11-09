// from server: 100% by auto
// roc 2011-06 00466f70  unit: TimerWindow  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00466f70
//
// 00466f70  6aff                 push -1
// 00466f72  6868a39d00           push 0x9da368
// 00466f77  64a100000000         mov eax, dword ptr fs:[0]
// 00466f7d  50                   push eax
// 00466f7e  64892500000000       mov dword ptr fs:[0], esp
// 00466f85  51                   push ecx
// 00466f86  56                   push esi
// 00466f87  8bf1                 mov esi, ecx
// 00466f89  89742404             mov dword ptr [esp + 4], esi
// 00466f8d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00466f95  e806f7ffff           call 0x4666a0
// 00466f9a  8b06                 mov eax, dword ptr [esi]
// 00466f9c  50                   push eax
// 00466f9d  e8b6303a00           call 0x80a058
// 00466fa2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00466fa6  83c404               add esp, 4
// 00466fa9  5e                   pop esi
// 00466faa  64890d00000000       mov dword ptr fs:[0], ecx
// 00466fb1  83c410               add esp, 0x10
// 00466fb4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
