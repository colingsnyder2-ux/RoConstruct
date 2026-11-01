// from server: 100% by auto
// roc 2007-08 0040b320  unit: CBrowserView  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b320
//
// 0040b320  6aff                 push -1
// 0040b322  68a9b77600           push 0x76b7a9
// 0040b327  64a100000000         mov eax, dword ptr fs:[0]
// 0040b32d  50                   push eax
// 0040b32e  83ec44               sub esp, 0x44
// 0040b331  56                   push esi
// 0040b332  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040b337  33c4                 xor eax, esp
// 0040b339  50                   push eax
// 0040b33a  8d44244c             lea eax, [esp + 0x4c]
// 0040b33e  64a300000000         mov dword ptr fs:[0], eax
// 0040b344  8b4108               mov eax, dword ptr [ecx + 8]
// 0040b347  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0040b34b  be49922409           mov esi, 0x9249249
// 0040b350  2bf0                 sub esi, eax
// 0040b352  3bf2                 cmp esi, edx
// 0040b354  733c                 jae 0x40b392
// 0040b356  688c597800           push 0x78598c
// 0040b35b  8d4c240c             lea ecx, [esp + 0xc]
// 0040b35f  ff1598e67700         call dword ptr [0x77e698]
// 0040b365  8d442408             lea eax, [esp + 8]
// 0040b369  50                   push eax
// 0040b36a  8d4c2428             lea ecx, [esp + 0x28]
// 0040b36e  c744245800000000     mov dword ptr [esp + 0x58], 0
// 0040b376  e84571ffff           call 0x4024c0
// 0040b37b  6878f78300           push 0x83f778
// 0040b380  8d4c2428             lea ecx, [esp + 0x28]
// 0040b384  51                   push ecx
// 0040b385  c744242c6c4e7800     mov dword ptr [esp + 0x2c], 0x784e6c
// 0040b38d  e80c582200           call 0x630b9e
// 0040b392  03c2                 add eax, edx
// 0040b394  894108               mov dword ptr [ecx + 8], eax
// 0040b397  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0040b39b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b3a2  59                   pop ecx
// 0040b3a3  5e                   pop esi
// 0040b3a4  83c450               add esp, 0x50
// 0040b3a7  c20400               ret 4
// standard library list<string> (function ?_Incsize@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
