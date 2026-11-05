// from server: 100% by auto
// roc 2010-06 008fe750  unit: Ogre::RbxSceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe750
//
// 008fe750  6aff                 push -1
// 008fe752  6858a29900           push 0x99a258
// 008fe757  64a100000000         mov eax, dword ptr fs:[0]
// 008fe75d  50                   push eax
// 008fe75e  64892500000000       mov dword ptr fs:[0], esp
// 008fe765  51                   push ecx
// 008fe766  56                   push esi
// 008fe767  8bf1                 mov esi, ecx
// 008fe769  6a04                 push 4
// 008fe76b  89742408             mov dword ptr [esp + 8], esi
// 008fe76f  e82c92eaff           call 0x7a79a0
// 008fe774  83c404               add esp, 4
// 008fe777  85c0                 test eax, eax
// 008fe779  7404                 je 0x8fe77f
// 008fe77b  8930                 mov dword ptr [eax], esi
// 008fe77d  eb02                 jmp 0x8fe781
// 008fe77f  33c0                 xor eax, eax
// 008fe781  8906                 mov dword ptr [esi], eax
// 008fe783  8bce                 mov ecx, esi
// 008fe785  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008fe78d  e85eb4ceff           call 0x5e9bf0
// 008fe792  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008fe796  894614               mov dword ptr [esi + 0x14], eax
// 008fe799  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008fe7a0  8bc6                 mov eax, esi
// 008fe7a2  5e                   pop esi
// 008fe7a3  64890d00000000       mov dword ptr fs:[0], ecx
// 008fe7aa  83c410               add esp, 0x10
// 008fe7ad  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
