// from server: 100% by auto
// roc 2010-06 00966be0  unit: Ogre::RbxSceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00966be0
//
// 00966be0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00966be4  8b5004               mov edx, dword ptr [eax + 4]
// 00966be7  53                   push ebx
// 00966be8  56                   push esi
// 00966be9  57                   push edi
// 00966bea  8bd9                 mov ebx, ecx
// 00966bec  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00966bf0  8d7804               lea edi, [eax + 4]
// 00966bf3  51                   push ecx
// 00966bf4  52                   push edx
// 00966bf5  50                   push eax
// 00966bf6  8bcb                 mov ecx, ebx
// 00966bf8  e8b3f4ffff           call 0x9660b0
// 00966bfd  6a01                 push 1
// 00966bff  8bcb                 mov ecx, ebx
// 00966c01  8bf0                 mov esi, eax
// 00966c03  e848a5ffff           call 0x961150
// 00966c08  8937                 mov dword ptr [edi], esi
// 00966c0a  8b4604               mov eax, dword ptr [esi + 4]
// 00966c0d  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00966c13  8930                 mov dword ptr [eax], esi
// 00966c15  8b442414             mov eax, dword ptr [esp + 0x14]
// 00966c19  85c0                 test eax, eax
// 00966c1b  7506                 jne 0x966c23
// 00966c1d  ffd7                 call edi
// 00966c1f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00966c23  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00966c27  8b4904               mov ecx, dword ptr [ecx + 4]
// 00966c2a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00966c2e  85c0                 test eax, eax
// 00966c30  7404                 je 0x966c36
// 00966c32  8b00                 mov eax, dword ptr [eax]
// 00966c34  eb02                 jmp 0x966c38
// 00966c36  33c0                 xor eax, eax
// 00966c38  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00966c3b  7506                 jne 0x966c43
// 00966c3d  ffd7                 call edi
// 00966c3f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00966c43  8b742410             mov esi, dword ptr [esp + 0x10]
// 00966c47  c70600000000         mov dword ptr [esi], 0
// 00966c4d  894e04               mov dword ptr [esi + 4], ecx
// 00966c50  85db                 test ebx, ebx
// 00966c52  7502                 jne 0x966c56
// 00966c54  ffd7                 call edi
// 00966c56  8b13                 mov edx, dword ptr [ebx]
// 00966c58  5f                   pop edi
// 00966c59  8916                 mov dword ptr [esi], edx
// 00966c5b  8bc6                 mov eax, esi
// 00966c5d  5e                   pop esi
// 00966c5e  5b                   pop ebx
// 00966c5f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
