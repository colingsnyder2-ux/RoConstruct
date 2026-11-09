// from server: 100% by auto
// roc 2008-06 005d6c80  unit: RBX::VTimerService::?$FactoryProduct  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d6c80
//
// 005d6c80  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005d6c84  8b5004               mov edx, dword ptr [eax + 4]
// 005d6c87  53                   push ebx
// 005d6c88  56                   push esi
// 005d6c89  57                   push edi
// 005d6c8a  8bd9                 mov ebx, ecx
// 005d6c8c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005d6c90  8d7804               lea edi, [eax + 4]
// 005d6c93  51                   push ecx
// 005d6c94  52                   push edx
// 005d6c95  50                   push eax
// 005d6c96  8bcb                 mov ecx, ebx
// 005d6c98  e853ffffff           call 0x5d6bf0
// 005d6c9d  6a01                 push 1
// 005d6c9f  8bcb                 mov ecx, ebx
// 005d6ca1  8bf0                 mov esi, eax
// 005d6ca3  e818feffff           call 0x5d6ac0
// 005d6ca8  8937                 mov dword ptr [edi], esi
// 005d6caa  8b4604               mov eax, dword ptr [esi + 4]
// 005d6cad  8b3d90288000         mov edi, dword ptr [0x802890]
// 005d6cb3  8930                 mov dword ptr [eax], esi
// 005d6cb5  8b442414             mov eax, dword ptr [esp + 0x14]
// 005d6cb9  85c0                 test eax, eax
// 005d6cbb  7506                 jne 0x5d6cc3
// 005d6cbd  ffd7                 call edi
// 005d6cbf  8b442414             mov eax, dword ptr [esp + 0x14]
// 005d6cc3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d6cc7  8b4904               mov ecx, dword ptr [ecx + 4]
// 005d6cca  894c2418             mov dword ptr [esp + 0x18], ecx
// 005d6cce  85c0                 test eax, eax
// 005d6cd0  7404                 je 0x5d6cd6
// 005d6cd2  8b00                 mov eax, dword ptr [eax]
// 005d6cd4  eb02                 jmp 0x5d6cd8
// 005d6cd6  33c0                 xor eax, eax
// 005d6cd8  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005d6cdb  7506                 jne 0x5d6ce3
// 005d6cdd  ffd7                 call edi
// 005d6cdf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d6ce3  8b742410             mov esi, dword ptr [esp + 0x10]
// 005d6ce7  c70600000000         mov dword ptr [esi], 0
// 005d6ced  894e04               mov dword ptr [esi + 4], ecx
// 005d6cf0  85db                 test ebx, ebx
// 005d6cf2  7502                 jne 0x5d6cf6
// 005d6cf4  ffd7                 call edi
// 005d6cf6  8b13                 mov edx, dword ptr [ebx]
// 005d6cf8  5f                   pop edi
// 005d6cf9  8916                 mov dword ptr [esi], edx
// 005d6cfb  8bc6                 mov eax, esi
// 005d6cfd  5e                   pop esi
// 005d6cfe  5b                   pop ebx
// 005d6cff  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
