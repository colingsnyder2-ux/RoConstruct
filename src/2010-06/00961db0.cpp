// from server: 100% by auto
// roc 2010-06 00961db0  unit: RBX::SceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961db0
//
// 00961db0  6aff                 push -1
// 00961db2  6858a29900           push 0x99a258
// 00961db7  64a100000000         mov eax, dword ptr fs:[0]
// 00961dbd  50                   push eax
// 00961dbe  64892500000000       mov dword ptr fs:[0], esp
// 00961dc5  51                   push ecx
// 00961dc6  56                   push esi
// 00961dc7  8bf1                 mov esi, ecx
// 00961dc9  6a04                 push 4
// 00961dcb  89742408             mov dword ptr [esp + 8], esi
// 00961dcf  e8cc5be4ff           call 0x7a79a0
// 00961dd4  83c404               add esp, 4
// 00961dd7  85c0                 test eax, eax
// 00961dd9  7404                 je 0x961ddf
// 00961ddb  8930                 mov dword ptr [eax], esi
// 00961ddd  eb02                 jmp 0x961de1
// 00961ddf  33c0                 xor eax, eax
// 00961de1  8906                 mov dword ptr [esi], eax
// 00961de3  8bce                 mov ecx, esi
// 00961de5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00961ded  e83e08c9ff           call 0x5f2630
// 00961df2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00961df6  894614               mov dword ptr [esi + 0x14], eax
// 00961df9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00961e00  8bc6                 mov eax, esi
// 00961e02  5e                   pop esi
// 00961e03  64890d00000000       mov dword ptr fs:[0], ecx
// 00961e0a  83c410               add esp, 0x10
// 00961e0d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
