// from server: 100% by auto
// roc 2008-06 00410830  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00410830
//
// 00410830  6aff                 push -1
// 00410832  68e8727d00           push 0x7d72e8
// 00410837  64a100000000         mov eax, dword ptr fs:[0]
// 0041083d  50                   push eax
// 0041083e  64892500000000       mov dword ptr fs:[0], esp
// 00410845  51                   push ecx
// 00410846  56                   push esi
// 00410847  8bf1                 mov esi, ecx
// 00410849  6a04                 push 4
// 0041084b  89742408             mov dword ptr [esp + 8], esi
// 0041084f  e8cc002900           call 0x6a0920
// 00410854  83c404               add esp, 4
// 00410857  85c0                 test eax, eax
// 00410859  7404                 je 0x41085f
// 0041085b  8930                 mov dword ptr [eax], esi
// 0041085d  eb02                 jmp 0x410861
// 0041085f  33c0                 xor eax, eax
// 00410861  8906                 mov dword ptr [esi], eax
// 00410863  8bce                 mov ecx, esi
// 00410865  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041086d  e84ee9ffff           call 0x40f1c0
// 00410872  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00410876  894614               mov dword ptr [esi + 0x14], eax
// 00410879  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00410880  8bc6                 mov eax, esi
// 00410882  5e                   pop esi
// 00410883  64890d00000000       mov dword ptr fs:[0], ecx
// 0041088a  83c410               add esp, 0x10
// 0041088d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
