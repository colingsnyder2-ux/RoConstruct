// from server: 100% by auto
// roc 2009-12 007009f0  unit: RBX::VTimerService::?$FactoryProduct  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007009f0
//
// 007009f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007009f4  8b5004               mov edx, dword ptr [eax + 4]
// 007009f7  53                   push ebx
// 007009f8  56                   push esi
// 007009f9  57                   push edi
// 007009fa  8bd9                 mov ebx, ecx
// 007009fc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00700a00  8d7804               lea edi, [eax + 4]
// 00700a03  51                   push ecx
// 00700a04  52                   push edx
// 00700a05  50                   push eax
// 00700a06  8bcb                 mov ecx, ebx
// 00700a08  e853ffffff           call 0x700960
// 00700a0d  6a01                 push 1
// 00700a0f  8bcb                 mov ecx, ebx
// 00700a11  8bf0                 mov esi, eax
// 00700a13  e8f8d0fbff           call 0x6bdb10
// 00700a18  8937                 mov dword ptr [edi], esi
// 00700a1a  8b4604               mov eax, dword ptr [esi + 4]
// 00700a1d  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00700a23  8930                 mov dword ptr [eax], esi
// 00700a25  8b442414             mov eax, dword ptr [esp + 0x14]
// 00700a29  85c0                 test eax, eax
// 00700a2b  7506                 jne 0x700a33
// 00700a2d  ffd7                 call edi
// 00700a2f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00700a33  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00700a37  8b4904               mov ecx, dword ptr [ecx + 4]
// 00700a3a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00700a3e  85c0                 test eax, eax
// 00700a40  7404                 je 0x700a46
// 00700a42  8b00                 mov eax, dword ptr [eax]
// 00700a44  eb02                 jmp 0x700a48
// 00700a46  33c0                 xor eax, eax
// 00700a48  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00700a4b  7506                 jne 0x700a53
// 00700a4d  ffd7                 call edi
// 00700a4f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00700a53  8b742410             mov esi, dword ptr [esp + 0x10]
// 00700a57  c70600000000         mov dword ptr [esi], 0
// 00700a5d  894e04               mov dword ptr [esi + 4], ecx
// 00700a60  85db                 test ebx, ebx
// 00700a62  7502                 jne 0x700a66
// 00700a64  ffd7                 call edi
// 00700a66  8b13                 mov edx, dword ptr [ebx]
// 00700a68  5f                   pop edi
// 00700a69  8916                 mov dword ptr [esi], edx
// 00700a6b  8bc6                 mov eax, esi
// 00700a6d  5e                   pop esi
// 00700a6e  5b                   pop ebx
// 00700a6f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
