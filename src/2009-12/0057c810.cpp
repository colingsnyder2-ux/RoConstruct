// from server: 100% by auto
// roc 2009-12 0057c810  unit: RBX::SceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c810
//
// 0057c810  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057c814  8b5004               mov edx, dword ptr [eax + 4]
// 0057c817  53                   push ebx
// 0057c818  56                   push esi
// 0057c819  57                   push edi
// 0057c81a  8bd9                 mov ebx, ecx
// 0057c81c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057c820  8d7804               lea edi, [eax + 4]
// 0057c823  51                   push ecx
// 0057c824  52                   push edx
// 0057c825  50                   push eax
// 0057c826  8bcb                 mov ecx, ebx
// 0057c828  e893f6ffff           call 0x57bec0
// 0057c82d  6a01                 push 1
// 0057c82f  8bcb                 mov ecx, ebx
// 0057c831  8bf0                 mov esi, eax
// 0057c833  e8c8f6ffff           call 0x57bf00
// 0057c838  8937                 mov dword ptr [edi], esi
// 0057c83a  8b4604               mov eax, dword ptr [esi + 4]
// 0057c83d  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0057c843  8930                 mov dword ptr [eax], esi
// 0057c845  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057c849  85c0                 test eax, eax
// 0057c84b  7506                 jne 0x57c853
// 0057c84d  ffd7                 call edi
// 0057c84f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057c853  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057c857  8b4904               mov ecx, dword ptr [ecx + 4]
// 0057c85a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0057c85e  85c0                 test eax, eax
// 0057c860  7404                 je 0x57c866
// 0057c862  8b00                 mov eax, dword ptr [eax]
// 0057c864  eb02                 jmp 0x57c868
// 0057c866  33c0                 xor eax, eax
// 0057c868  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0057c86b  7506                 jne 0x57c873
// 0057c86d  ffd7                 call edi
// 0057c86f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057c873  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057c877  c70600000000         mov dword ptr [esi], 0
// 0057c87d  894e04               mov dword ptr [esi + 4], ecx
// 0057c880  85db                 test ebx, ebx
// 0057c882  7502                 jne 0x57c886
// 0057c884  ffd7                 call edi
// 0057c886  8b13                 mov edx, dword ptr [ebx]
// 0057c888  5f                   pop edi
// 0057c889  8916                 mov dword ptr [esi], edx
// 0057c88b  8bc6                 mov eax, esi
// 0057c88d  5e                   pop esi
// 0057c88e  5b                   pop ebx
// 0057c88f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
