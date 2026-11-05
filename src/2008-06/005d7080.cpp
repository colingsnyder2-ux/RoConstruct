// from server: 100% by auto
// roc 2008-06 005d7080  unit: RBX::TimerService  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d7080
//
// 005d7080  6aff                 push -1
// 005d7082  68e8727d00           push 0x7d72e8
// 005d7087  64a100000000         mov eax, dword ptr fs:[0]
// 005d708d  50                   push eax
// 005d708e  64892500000000       mov dword ptr fs:[0], esp
// 005d7095  51                   push ecx
// 005d7096  56                   push esi
// 005d7097  8bf1                 mov esi, ecx
// 005d7099  89742404             mov dword ptr [esp + 4], esi
// 005d709d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005d70a5  e806fdffff           call 0x5d6db0
// 005d70aa  8b4614               mov eax, dword ptr [esi + 0x14]
// 005d70ad  50                   push eax
// 005d70ae  e8c7950c00           call 0x6a067a
// 005d70b3  8b0e                 mov ecx, dword ptr [esi]
// 005d70b5  51                   push ecx
// 005d70b6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005d70bd  e8b8950c00           call 0x6a067a
// 005d70c2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d70c6  83c408               add esp, 8
// 005d70c9  5e                   pop esi
// 005d70ca  64890d00000000       mov dword ptr fs:[0], ecx
// 005d70d1  83c410               add esp, 0x10
// 005d70d4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
