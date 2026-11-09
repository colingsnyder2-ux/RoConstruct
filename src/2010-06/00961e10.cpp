// from server: 100% by auto
// roc 2010-06 00961e10  unit: RBX::SceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961e10
//
// 00961e10  6aff                 push -1
// 00961e12  6858a29900           push 0x99a258
// 00961e17  64a100000000         mov eax, dword ptr fs:[0]
// 00961e1d  50                   push eax
// 00961e1e  64892500000000       mov dword ptr fs:[0], esp
// 00961e25  51                   push ecx
// 00961e26  56                   push esi
// 00961e27  8bf1                 mov esi, ecx
// 00961e29  6a04                 push 4
// 00961e2b  89742408             mov dword ptr [esp + 8], esi
// 00961e2f  e86c5be4ff           call 0x7a79a0
// 00961e34  83c404               add esp, 4
// 00961e37  85c0                 test eax, eax
// 00961e39  7404                 je 0x961e3f
// 00961e3b  8930                 mov dword ptr [eax], esi
// 00961e3d  eb02                 jmp 0x961e41
// 00961e3f  33c0                 xor eax, eax
// 00961e41  8906                 mov dword ptr [esi], eax
// 00961e43  8bce                 mov ecx, esi
// 00961e45  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00961e4d  e81ef1ffff           call 0x960f70
// 00961e52  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00961e56  894614               mov dword ptr [esi + 0x14], eax
// 00961e59  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00961e60  8bc6                 mov eax, esi
// 00961e62  5e                   pop esi
// 00961e63  64890d00000000       mov dword ptr fs:[0], ecx
// 00961e6a  83c410               add esp, 0x10
// 00961e6d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
