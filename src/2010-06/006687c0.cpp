// from server: 100% by auto
// roc 2010-06 006687c0  unit: RBX::VSpawnerService::?$FactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006687c0
//
// 006687c0  6aff                 push -1
// 006687c2  6858a29900           push 0x99a258
// 006687c7  64a100000000         mov eax, dword ptr fs:[0]
// 006687cd  50                   push eax
// 006687ce  64892500000000       mov dword ptr fs:[0], esp
// 006687d5  51                   push ecx
// 006687d6  56                   push esi
// 006687d7  8bf1                 mov esi, ecx
// 006687d9  6a04                 push 4
// 006687db  89742408             mov dword ptr [esp + 8], esi
// 006687df  e8bcf11300           call 0x7a79a0
// 006687e4  83c404               add esp, 4
// 006687e7  85c0                 test eax, eax
// 006687e9  7404                 je 0x6687ef
// 006687eb  8930                 mov dword ptr [eax], esi
// 006687ed  eb02                 jmp 0x6687f1
// 006687ef  33c0                 xor eax, eax
// 006687f1  8906                 mov dword ptr [esi], eax
// 006687f3  8bce                 mov ecx, esi
// 006687f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006687fd  e8ee13f8ff           call 0x5e9bf0
// 00668802  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00668806  894614               mov dword ptr [esi + 0x14], eax
// 00668809  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00668810  8bc6                 mov eax, esi
// 00668812  5e                   pop esi
// 00668813  64890d00000000       mov dword ptr fs:[0], ecx
// 0066881a  83c410               add esp, 0x10
// 0066881d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
