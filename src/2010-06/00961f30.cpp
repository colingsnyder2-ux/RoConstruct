// from server: 100% by auto
// roc 2010-06 00961f30  unit: RBX::SceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961f30
//
// 00961f30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00961f34  8b5004               mov edx, dword ptr [eax + 4]
// 00961f37  53                   push ebx
// 00961f38  56                   push esi
// 00961f39  57                   push edi
// 00961f3a  8bd9                 mov ebx, ecx
// 00961f3c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00961f40  8d7804               lea edi, [eax + 4]
// 00961f43  51                   push ecx
// 00961f44  52                   push edx
// 00961f45  50                   push eax
// 00961f46  8bcb                 mov ecx, ebx
// 00961f48  e8b3f3ffff           call 0x961300
// 00961f4d  6a01                 push 1
// 00961f4f  8bcb                 mov ecx, ebx
// 00961f51  8bf0                 mov esi, eax
// 00961f53  e858f1ffff           call 0x9610b0
// 00961f58  8937                 mov dword ptr [edi], esi
// 00961f5a  8b4604               mov eax, dword ptr [esi + 4]
// 00961f5d  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00961f63  8930                 mov dword ptr [eax], esi
// 00961f65  8b442414             mov eax, dword ptr [esp + 0x14]
// 00961f69  85c0                 test eax, eax
// 00961f6b  7506                 jne 0x961f73
// 00961f6d  ffd7                 call edi
// 00961f6f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00961f73  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00961f77  8b4904               mov ecx, dword ptr [ecx + 4]
// 00961f7a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00961f7e  85c0                 test eax, eax
// 00961f80  7404                 je 0x961f86
// 00961f82  8b00                 mov eax, dword ptr [eax]
// 00961f84  eb02                 jmp 0x961f88
// 00961f86  33c0                 xor eax, eax
// 00961f88  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00961f8b  7506                 jne 0x961f93
// 00961f8d  ffd7                 call edi
// 00961f8f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00961f93  8b742410             mov esi, dword ptr [esp + 0x10]
// 00961f97  c70600000000         mov dword ptr [esi], 0
// 00961f9d  894e04               mov dword ptr [esi + 4], ecx
// 00961fa0  85db                 test ebx, ebx
// 00961fa2  7502                 jne 0x961fa6
// 00961fa4  ffd7                 call edi
// 00961fa6  8b13                 mov edx, dword ptr [ebx]
// 00961fa8  5f                   pop edi
// 00961fa9  8916                 mov dword ptr [esi], edx
// 00961fab  8bc6                 mov eax, esi
// 00961fad  5e                   pop esi
// 00961fae  5b                   pop ebx
// 00961faf  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
