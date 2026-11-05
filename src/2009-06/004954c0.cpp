// from server: 100% by auto
// roc 2009-06 004954c0  unit: Ogre::RbxMaterialAdapter  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004954c0
//
// 004954c0  6aff                 push -1
// 004954c2  6878ef8600           push 0x86ef78
// 004954c7  64a100000000         mov eax, dword ptr fs:[0]
// 004954cd  50                   push eax
// 004954ce  64892500000000       mov dword ptr fs:[0], esp
// 004954d5  51                   push ecx
// 004954d6  56                   push esi
// 004954d7  8bf1                 mov esi, ecx
// 004954d9  6a04                 push 4
// 004954db  89742408             mov dword ptr [esp + 8], esi
// 004954df  e854352800           call 0x718a38
// 004954e4  83c404               add esp, 4
// 004954e7  85c0                 test eax, eax
// 004954e9  7404                 je 0x4954ef
// 004954eb  8930                 mov dword ptr [eax], esi
// 004954ed  eb02                 jmp 0x4954f1
// 004954ef  33c0                 xor eax, eax
// 004954f1  8906                 mov dword ptr [esi], eax
// 004954f3  8bce                 mov ecx, esi
// 004954f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004954fd  e8de6e1a00           call 0x63c3e0
// 00495502  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00495506  894614               mov dword ptr [esi + 0x14], eax
// 00495509  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00495510  8bc6                 mov eax, esi
// 00495512  5e                   pop esi
// 00495513  64890d00000000       mov dword ptr fs:[0], ecx
// 0049551a  83c410               add esp, 0x10
// 0049551d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
