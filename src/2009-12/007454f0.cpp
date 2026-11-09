// from server: 100% by auto
// roc 2009-12 007454f0  unit: RBX::VFlagStandService::?$FactoryProduct  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007454f0
//
// 007454f0  83ec0c               sub esp, 0xc
// 007454f3  8b442410             mov eax, dword ptr [esp + 0x10]
// 007454f7  53                   push ebx
// 007454f8  55                   push ebp
// 007454f9  8bd9                 mov ebx, ecx
// 007454fb  8b08                 mov ecx, dword ptr [eax]
// 007454fd  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 00745500  56                   push esi
// 00745501  8b33                 mov esi, dword ptr [ebx]
// 00745503  57                   push edi
// 00745504  8b7d00               mov edi, dword ptr [ebp]
// 00745507  894c2410             mov dword ptr [esp + 0x10], ecx
// 0074550b  89742420             mov dword ptr [esp + 0x20], esi
// 0074550f  90                   nop 
// 00745510  85f6                 test esi, esi
// 00745512  7406                 je 0x74551a
// 00745514  3b742420             cmp esi, dword ptr [esp + 0x20]
// 00745518  7406                 je 0x745520
// 0074551a  ff1560b79800         call dword ptr [0x98b760]
// 00745520  3bfd                 cmp edi, ebp
// 00745522  7458                 je 0x74557c
// 00745524  85f6                 test esi, esi
// 00745526  7531                 jne 0x745559
// 00745528  ff1560b79800         call dword ptr [0x98b760]
// 0074552e  33c0                 xor eax, eax
// 00745530  3b7814               cmp edi, dword ptr [eax + 0x14]
// 00745533  7506                 jne 0x74553b
// 00745535  ff1560b79800         call dword ptr [0x98b760]
// 0074553b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074553f  395708               cmp dword ptr [edi + 8], edx
// 00745542  7519                 jne 0x74555d
// 00745544  57                   push edi
// 00745545  56                   push esi
// 00745546  8d44241c             lea eax, [esp + 0x1c]
// 0074554a  50                   push eax
// 0074554b  8bcb                 mov ecx, ebx
// 0074554d  e84e5ad6ff           call 0x4aafa0
// 00745552  8b30                 mov esi, dword ptr [eax]
// 00745554  8b7804               mov edi, dword ptr [eax + 4]
// 00745557  ebb7                 jmp 0x745510
// 00745559  8b06                 mov eax, dword ptr [esi]
// 0074555b  ebd3                 jmp 0x745530
// 0074555d  85f6                 test esi, esi
// 0074555f  7517                 jne 0x745578
// 00745561  ff1560b79800         call dword ptr [0x98b760]
// 00745567  33c0                 xor eax, eax
// 00745569  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0074556c  7506                 jne 0x745574
// 0074556e  ff1560b79800         call dword ptr [0x98b760]
// 00745574  8b3f                 mov edi, dword ptr [edi]
// 00745576  eb98                 jmp 0x745510
// 00745578  8b06                 mov eax, dword ptr [esi]
// 0074557a  ebed                 jmp 0x745569
// 0074557c  5f                   pop edi
// 0074557d  5e                   pop esi
// 0074557e  5d                   pop ebp
// 0074557f  5b                   pop ebx
// 00745580  83c40c               add esp, 0xc
// 00745583  c20400               ret 4
// standard library list<ptr> (function ?remove@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
