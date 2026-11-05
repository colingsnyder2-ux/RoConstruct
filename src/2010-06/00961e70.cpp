// from server: 100% by auto
// roc 2010-06 00961e70  unit: RBX::SceneUpdater  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961e70
//
// 00961e70  6aff                 push -1
// 00961e72  6858a29900           push 0x99a258
// 00961e77  64a100000000         mov eax, dword ptr fs:[0]
// 00961e7d  50                   push eax
// 00961e7e  64892500000000       mov dword ptr fs:[0], esp
// 00961e85  51                   push ecx
// 00961e86  56                   push esi
// 00961e87  8bf1                 mov esi, ecx
// 00961e89  6a04                 push 4
// 00961e8b  89742408             mov dword ptr [esp + 8], esi
// 00961e8f  e80c5be4ff           call 0x7a79a0
// 00961e94  83c404               add esp, 4
// 00961e97  85c0                 test eax, eax
// 00961e99  7404                 je 0x961e9f
// 00961e9b  8930                 mov dword ptr [eax], esi
// 00961e9d  eb02                 jmp 0x961ea1
// 00961e9f  33c0                 xor eax, eax
// 00961ea1  8906                 mov dword ptr [esi], eax
// 00961ea3  8bce                 mov ecx, esi
// 00961ea5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00961ead  e8def0ffff           call 0x960f90
// 00961eb2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00961eb6  894614               mov dword ptr [esi + 0x14], eax
// 00961eb9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00961ec0  8bc6                 mov eax, esi
// 00961ec2  5e                   pop esi
// 00961ec3  64890d00000000       mov dword ptr fs:[0], ecx
// 00961eca  83c410               add esp, 0x10
// 00961ecd  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
