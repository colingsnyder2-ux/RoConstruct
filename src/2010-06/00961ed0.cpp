// from server: 100% by auto
// roc 2010-06 00961ed0  unit: RBX::SceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961ed0
//
// 00961ed0  6aff                 push -1
// 00961ed2  6858a29900           push 0x99a258
// 00961ed7  64a100000000         mov eax, dword ptr fs:[0]
// 00961edd  50                   push eax
// 00961ede  64892500000000       mov dword ptr fs:[0], esp
// 00961ee5  51                   push ecx
// 00961ee6  56                   push esi
// 00961ee7  8bf1                 mov esi, ecx
// 00961ee9  6a04                 push 4
// 00961eeb  89742408             mov dword ptr [esp + 8], esi
// 00961eef  e8ac5ae4ff           call 0x7a79a0
// 00961ef4  83c404               add esp, 4
// 00961ef7  85c0                 test eax, eax
// 00961ef9  7404                 je 0x961eff
// 00961efb  8930                 mov dword ptr [eax], esi
// 00961efd  eb02                 jmp 0x961f01
// 00961eff  33c0                 xor eax, eax
// 00961f01  8906                 mov dword ptr [esi], eax
// 00961f03  8bce                 mov ecx, esi
// 00961f05  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00961f0d  e83ef1ffff           call 0x961050
// 00961f12  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00961f16  894614               mov dword ptr [esi + 0x14], eax
// 00961f19  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00961f20  8bc6                 mov eax, esi
// 00961f22  5e                   pop esi
// 00961f23  64890d00000000       mov dword ptr fs:[0], ecx
// 00961f2a  83c410               add esp, 0x10
// 00961f2d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
