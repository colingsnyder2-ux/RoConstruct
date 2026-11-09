// from server: 100% by auto
// roc 2010-06 008fe7b0  unit: Ogre::RbxSceneUpdater  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe7b0
//
// 008fe7b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008fe7b4  8b5004               mov edx, dword ptr [eax + 4]
// 008fe7b7  53                   push ebx
// 008fe7b8  56                   push esi
// 008fe7b9  57                   push edi
// 008fe7ba  8bd9                 mov ebx, ecx
// 008fe7bc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008fe7c0  8d7804               lea edi, [eax + 4]
// 008fe7c3  51                   push ecx
// 008fe7c4  52                   push edx
// 008fe7c5  50                   push eax
// 008fe7c6  8bcb                 mov ecx, ebx
// 008fe7c8  e81368dcff           call 0x6c4fe0
// 008fe7cd  6a01                 push 1
// 008fe7cf  8bcb                 mov ecx, ebx
// 008fe7d1  8bf0                 mov esi, eax
// 008fe7d3  e838b4ceff           call 0x5e9c10
// 008fe7d8  8937                 mov dword ptr [edi], esi
// 008fe7da  8b4604               mov eax, dword ptr [esi + 4]
// 008fe7dd  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 008fe7e3  8930                 mov dword ptr [eax], esi
// 008fe7e5  8b442414             mov eax, dword ptr [esp + 0x14]
// 008fe7e9  85c0                 test eax, eax
// 008fe7eb  7506                 jne 0x8fe7f3
// 008fe7ed  ffd7                 call edi
// 008fe7ef  8b442414             mov eax, dword ptr [esp + 0x14]
// 008fe7f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008fe7f7  8b4904               mov ecx, dword ptr [ecx + 4]
// 008fe7fa  894c2418             mov dword ptr [esp + 0x18], ecx
// 008fe7fe  85c0                 test eax, eax
// 008fe800  7404                 je 0x8fe806
// 008fe802  8b00                 mov eax, dword ptr [eax]
// 008fe804  eb02                 jmp 0x8fe808
// 008fe806  33c0                 xor eax, eax
// 008fe808  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 008fe80b  7506                 jne 0x8fe813
// 008fe80d  ffd7                 call edi
// 008fe80f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008fe813  8b742410             mov esi, dword ptr [esp + 0x10]
// 008fe817  c70600000000         mov dword ptr [esi], 0
// 008fe81d  894e04               mov dword ptr [esi + 4], ecx
// 008fe820  85db                 test ebx, ebx
// 008fe822  7502                 jne 0x8fe826
// 008fe824  ffd7                 call edi
// 008fe826  8b13                 mov edx, dword ptr [ebx]
// 008fe828  5f                   pop edi
// 008fe829  8916                 mov dword ptr [esi], edx
// 008fe82b  8bc6                 mov eax, esi
// 008fe82d  5e                   pop esi
// 008fe82e  5b                   pop ebx
// 008fe82f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
