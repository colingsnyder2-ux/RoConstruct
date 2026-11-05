// from server: 100% by auto
// roc 2010-06 009615f0  unit: RBX::SceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009615f0
//
// 009615f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009615f4  8b5004               mov edx, dword ptr [eax + 4]
// 009615f7  53                   push ebx
// 009615f8  56                   push esi
// 009615f9  57                   push edi
// 009615fa  8bd9                 mov ebx, ecx
// 009615fc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00961600  8d7804               lea edi, [eax + 4]
// 00961603  51                   push ecx
// 00961604  52                   push edx
// 00961605  50                   push eax
// 00961606  8bcb                 mov ecx, ebx
// 00961608  e863faffff           call 0x961070
// 0096160d  6a01                 push 1
// 0096160f  8bcb                 mov ecx, ebx
// 00961611  8bf0                 mov esi, eax
// 00961613  e8c82adaff           call 0x7040e0
// 00961618  8937                 mov dword ptr [edi], esi
// 0096161a  8b4604               mov eax, dword ptr [esi + 4]
// 0096161d  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00961623  8930                 mov dword ptr [eax], esi
// 00961625  8b442414             mov eax, dword ptr [esp + 0x14]
// 00961629  85c0                 test eax, eax
// 0096162b  7506                 jne 0x961633
// 0096162d  ffd7                 call edi
// 0096162f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00961633  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00961637  8b4904               mov ecx, dword ptr [ecx + 4]
// 0096163a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0096163e  85c0                 test eax, eax
// 00961640  7404                 je 0x961646
// 00961642  8b00                 mov eax, dword ptr [eax]
// 00961644  eb02                 jmp 0x961648
// 00961646  33c0                 xor eax, eax
// 00961648  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0096164b  7506                 jne 0x961653
// 0096164d  ffd7                 call edi
// 0096164f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00961653  8b742410             mov esi, dword ptr [esp + 0x10]
// 00961657  c70600000000         mov dword ptr [esi], 0
// 0096165d  894e04               mov dword ptr [esi + 4], ecx
// 00961660  85db                 test ebx, ebx
// 00961662  7502                 jne 0x961666
// 00961664  ffd7                 call edi
// 00961666  8b13                 mov edx, dword ptr [ebx]
// 00961668  5f                   pop edi
// 00961669  8916                 mov dword ptr [esi], edx
// 0096166b  8bc6                 mov eax, esi
// 0096166d  5e                   pop esi
// 0096166e  5b                   pop ebx
// 0096166f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
