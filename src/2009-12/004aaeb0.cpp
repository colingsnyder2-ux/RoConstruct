// from server: 100% by auto
// roc 2009-12 004aaeb0  unit: Ogre::RbxSceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aaeb0
//
// 004aaeb0  6aff                 push -1
// 004aaeb2  68d8c59300           push 0x93c5d8
// 004aaeb7  64a100000000         mov eax, dword ptr fs:[0]
// 004aaebd  50                   push eax
// 004aaebe  64892500000000       mov dword ptr fs:[0], esp
// 004aaec5  51                   push ecx
// 004aaec6  56                   push esi
// 004aaec7  8bf1                 mov esi, ecx
// 004aaec9  6a04                 push 4
// 004aaecb  89742408             mov dword ptr [esp + 8], esi
// 004aaecf  e88c893400           call 0x7f3860
// 004aaed4  83c404               add esp, 4
// 004aaed7  85c0                 test eax, eax
// 004aaed9  7404                 je 0x4aaedf
// 004aaedb  8930                 mov dword ptr [eax], esi
// 004aaedd  eb02                 jmp 0x4aaee1
// 004aaedf  33c0                 xor eax, eax
// 004aaee1  8906                 mov dword ptr [esi], eax
// 004aaee3  8bce                 mov ecx, esi
// 004aaee5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aaeed  e81e732700           call 0x722210
// 004aaef2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004aaef6  894614               mov dword ptr [esi + 0x14], eax
// 004aaef9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004aaf00  8bc6                 mov eax, esi
// 004aaf02  5e                   pop esi
// 004aaf03  64890d00000000       mov dword ptr fs:[0], ecx
// 004aaf0a  83c410               add esp, 0x10
// 004aaf0d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
