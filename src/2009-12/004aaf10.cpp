// from server: 100% by auto
// roc 2009-12 004aaf10  unit: Ogre::RbxSceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aaf10
//
// 004aaf10  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004aaf14  8b5004               mov edx, dword ptr [eax + 4]
// 004aaf17  53                   push ebx
// 004aaf18  56                   push esi
// 004aaf19  57                   push edi
// 004aaf1a  8bd9                 mov ebx, ecx
// 004aaf1c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004aaf20  8d7804               lea edi, [eax + 4]
// 004aaf23  51                   push ecx
// 004aaf24  52                   push edx
// 004aaf25  50                   push eax
// 004aaf26  8bcb                 mov ecx, ebx
// 004aaf28  e843a32900           call 0x745270
// 004aaf2d  6a01                 push 1
// 004aaf2f  8bcb                 mov ecx, ebx
// 004aaf31  8bf0                 mov esi, eax
// 004aaf33  e838742700           call 0x722370
// 004aaf38  8937                 mov dword ptr [edi], esi
// 004aaf3a  8b4604               mov eax, dword ptr [esi + 4]
// 004aaf3d  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 004aaf43  8930                 mov dword ptr [eax], esi
// 004aaf45  8b442414             mov eax, dword ptr [esp + 0x14]
// 004aaf49  85c0                 test eax, eax
// 004aaf4b  7506                 jne 0x4aaf53
// 004aaf4d  ffd7                 call edi
// 004aaf4f  8b442414             mov eax, dword ptr [esp + 0x14]
// 004aaf53  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aaf57  8b4904               mov ecx, dword ptr [ecx + 4]
// 004aaf5a  894c2418             mov dword ptr [esp + 0x18], ecx
// 004aaf5e  85c0                 test eax, eax
// 004aaf60  7404                 je 0x4aaf66
// 004aaf62  8b00                 mov eax, dword ptr [eax]
// 004aaf64  eb02                 jmp 0x4aaf68
// 004aaf66  33c0                 xor eax, eax
// 004aaf68  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004aaf6b  7506                 jne 0x4aaf73
// 004aaf6d  ffd7                 call edi
// 004aaf6f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aaf73  8b742410             mov esi, dword ptr [esp + 0x10]
// 004aaf77  c70600000000         mov dword ptr [esi], 0
// 004aaf7d  894e04               mov dword ptr [esi + 4], ecx
// 004aaf80  85db                 test ebx, ebx
// 004aaf82  7502                 jne 0x4aaf86
// 004aaf84  ffd7                 call edi
// 004aaf86  8b13                 mov edx, dword ptr [ebx]
// 004aaf88  5f                   pop edi
// 004aaf89  8916                 mov dword ptr [esi], edx
// 004aaf8b  8bc6                 mov eax, esi
// 004aaf8d  5e                   pop esi
// 004aaf8e  5b                   pop ebx
// 004aaf8f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
