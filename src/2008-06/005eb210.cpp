// from server: 100% by auto
// roc 2008-06 005eb210  unit: RBX::VSky::?$FactoryProduct  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005eb210
//
// 005eb210  6aff                 push -1
// 005eb212  68e16c7d00           push 0x7d6ce1
// 005eb217  64a100000000         mov eax, dword ptr fs:[0]
// 005eb21d  50                   push eax
// 005eb21e  64892500000000       mov dword ptr fs:[0], esp
// 005eb225  83ec20               sub esp, 0x20
// 005eb228  56                   push esi
// 005eb229  8bf1                 mov esi, ecx
// 005eb22b  6a04                 push 4
// 005eb22d  89742408             mov dword ptr [esp + 8], esi
// 005eb231  e8ea560b00           call 0x6a0920
// 005eb236  83c404               add esp, 4
// 005eb239  85c0                 test eax, eax
// 005eb23b  7404                 je 0x5eb241
// 005eb23d  8930                 mov dword ptr [eax], esi
// 005eb23f  eb02                 jmp 0x5eb243
// 005eb241  33c0                 xor eax, eax
// 005eb243  8906                 mov dword ptr [esi], eax
// 005eb245  8d4c2408             lea ecx, [esp + 8]
// 005eb249  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005eb251  ff1560248000         call dword ptr [0x802460]
// 005eb257  50                   push eax
// 005eb258  8b442438             mov eax, dword ptr [esp + 0x38]
// 005eb25c  50                   push eax
// 005eb25d  8bce                 mov ecx, esi
// 005eb25f  c644243401           mov byte ptr [esp + 0x34], 1
// 005eb264  e817ffffff           call 0x5eb180
// 005eb269  8d4c2408             lea ecx, [esp + 8]
// 005eb26d  c644242c00           mov byte ptr [esp + 0x2c], 0
// 005eb272  ff1568248000         call dword ptr [0x802468]
// 005eb278  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005eb27c  8bc6                 mov eax, esi
// 005eb27e  5e                   pop esi
// 005eb27f  64890d00000000       mov dword ptr fs:[0], ecx
// 005eb286  83c42c               add esp, 0x2c
// 005eb289  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
