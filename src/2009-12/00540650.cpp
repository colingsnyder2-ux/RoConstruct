// from server: 100% by auto
// roc 2009-12 00540650  unit: RBX::Network::Replicator::NewInstanceItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00540650
//
// 00540650  83ec08               sub esp, 8
// 00540653  53                   push ebx
// 00540654  55                   push ebp
// 00540655  56                   push esi
// 00540656  8bf1                 mov esi, ecx
// 00540658  8b4610               mov eax, dword ptr [esi + 0x10]
// 0054065b  57                   push edi
// 0054065c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0054065f  8bc8                 mov ecx, eax
// 00540661  2bcf                 sub ecx, edi
// 00540663  f7c1fcffffff         test ecx, 0xfffffffc
// 00540669  7504                 jne 0x54066f
// 0054066b  33db                 xor ebx, ebx
// 0054066d  eb27                 jmp 0x540696
// 0054066f  3bf8                 cmp edi, eax
// 00540671  7606                 jbe 0x540679
// 00540673  ff1560b79800         call dword ptr [0x98b760]
// 00540679  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054067d  8b06                 mov eax, dword ptr [esi]
// 0054067f  85c9                 test ecx, ecx
// 00540681  7404                 je 0x540687
// 00540683  3bc8                 cmp ecx, eax
// 00540685  7406                 je 0x54068d
// 00540687  ff1560b79800         call dword ptr [0x98b760]
// 0054068d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00540691  2bdf                 sub ebx, edi
// 00540693  c1fb02               sar ebx, 2
// 00540696  8b542428             mov edx, dword ptr [esp + 0x28]
// 0054069a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054069e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005406a2  52                   push edx
// 005406a3  6a01                 push 1
// 005406a5  50                   push eax
// 005406a6  51                   push ecx
// 005406a7  8bce                 mov ecx, esi
// 005406a9  e8e2f5ffff           call 0x53fc90
// 005406ae  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005406b1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005406b4  7606                 jbe 0x5406bc
// 005406b6  ff1560b79800         call dword ptr [0x98b760]
// 005406bc  8b36                 mov esi, dword ptr [esi]
// 005406be  8bee                 mov ebp, esi
// 005406c0  897c2414             mov dword ptr [esp + 0x14], edi
// 005406c4  85f6                 test esi, esi
// 005406c6  7518                 jne 0x5406e0
// 005406c8  ff1560b79800         call dword ptr [0x98b760]
// 005406ce  33c0                 xor eax, eax
// 005406d0  8d3c9f               lea edi, [edi + ebx*4]
// 005406d3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005406d6  7713                 ja 0x5406eb
// 005406d8  85f6                 test esi, esi
// 005406da  7408                 je 0x5406e4
// 005406dc  8b36                 mov esi, dword ptr [esi]
// 005406de  eb06                 jmp 0x5406e6
// 005406e0  8b06                 mov eax, dword ptr [esi]
// 005406e2  ebec                 jmp 0x5406d0
// 005406e4  33f6                 xor esi, esi
// 005406e6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005406e9  7306                 jae 0x5406f1
// 005406eb  ff1560b79800         call dword ptr [0x98b760]
// 005406f1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005406f5  897804               mov dword ptr [eax + 4], edi
// 005406f8  5f                   pop edi
// 005406f9  5e                   pop esi
// 005406fa  8928                 mov dword ptr [eax], ebp
// 005406fc  5d                   pop ebp
// 005406fd  5b                   pop ebx
// 005406fe  83c408               add esp, 8
// 00540701  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
