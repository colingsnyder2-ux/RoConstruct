// from server: 100% by auto
// roc 2008-06 00499170  unit: RBX::Network::VPlayers::?$SignalDesc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00499170
//
// 00499170  6aff                 push -1
// 00499172  68e8727d00           push 0x7d72e8
// 00499177  64a100000000         mov eax, dword ptr fs:[0]
// 0049917d  50                   push eax
// 0049917e  64892500000000       mov dword ptr fs:[0], esp
// 00499185  51                   push ecx
// 00499186  56                   push esi
// 00499187  8bf1                 mov esi, ecx
// 00499189  89742404             mov dword ptr [esp + 4], esi
// 0049918d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00499195  e8d6f0ffff           call 0x498270
// 0049919a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0049919d  50                   push eax
// 0049919e  e8d7742000           call 0x6a067a
// 004991a3  8b0e                 mov ecx, dword ptr [esi]
// 004991a5  51                   push ecx
// 004991a6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004991ad  e8c8742000           call 0x6a067a
// 004991b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004991b6  83c408               add esp, 8
// 004991b9  5e                   pop esi
// 004991ba  64890d00000000       mov dword ptr fs:[0], ecx
// 004991c1  83c410               add esp, 0x10
// 004991c4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
