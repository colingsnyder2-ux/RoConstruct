// from server: 100% by auto
// roc 2009-12 0057e490  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e490
//
// 0057e490  51                   push ecx
// 0057e491  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057e495  53                   push ebx
// 0057e496  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0057e49c  56                   push esi
// 0057e49d  57                   push edi
// 0057e49e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0057e4a2  8b7714               mov esi, dword ptr [edi + 0x14]
// 0057e4a5  894c240c             mov dword ptr [esp + 0xc], ecx
// 0057e4a9  8b0f                 mov ecx, dword ptr [edi]
// 0057e4ab  85c0                 test eax, eax
// 0057e4ad  7404                 je 0x57e4b3
// 0057e4af  3bc1                 cmp eax, ecx
// 0057e4b1  7406                 je 0x57e4b9
// 0057e4b3  ffd3                 call ebx
// 0057e4b5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057e4b9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0057e4bd  3bce                 cmp ecx, esi
// 0057e4bf  7479                 je 0x57e53a
// 0057e4c1  55                   push ebp
// 0057e4c2  8be8                 mov ebp, eax
// 0057e4c4  8bf1                 mov esi, ecx
// 0057e4c6  85c0                 test eax, eax
// 0057e4c8  7577                 jne 0x57e541
// 0057e4ca  ffd3                 call ebx
// 0057e4cc  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e4d0  33c9                 xor ecx, ecx
// 0057e4d2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0057e4d5  7506                 jne 0x57e4dd
// 0057e4d7  ffd3                 call ebx
// 0057e4d9  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e4dd  8b36                 mov esi, dword ptr [esi]
// 0057e4df  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e4e3  397c2410             cmp dword ptr [esp + 0x10], edi
// 0057e4e7  7534                 jne 0x57e51d
// 0057e4e9  85c9                 test ecx, ecx
// 0057e4eb  7404                 je 0x57e4f1
// 0057e4ed  3bc8                 cmp ecx, eax
// 0057e4ef  740a                 je 0x57e4fb
// 0057e4f1  ffd3                 call ebx
// 0057e4f3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e4f7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e4fb  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057e4ff  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0057e503  7434                 je 0x57e539
// 0057e505  85c9                 test ecx, ecx
// 0057e507  7404                 je 0x57e50d
// 0057e509  3bcd                 cmp ecx, ebp
// 0057e50b  740a                 je 0x57e517
// 0057e50d  ffd3                 call ebx
// 0057e50f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e513  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e517  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0057e51b  741c                 je 0x57e539
// 0057e51d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057e521  6a00                 push 0
// 0057e523  6a01                 push 1
// 0057e525  56                   push esi
// 0057e526  55                   push ebp
// 0057e527  52                   push edx
// 0057e528  50                   push eax
// 0057e529  8b442434             mov eax, dword ptr [esp + 0x34]
// 0057e52d  57                   push edi
// 0057e52e  50                   push eax
// 0057e52f  51                   push ecx
// 0057e530  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0057e534  e857f9ffff           call 0x57de90
// 0057e539  5d                   pop ebp
// 0057e53a  5f                   pop edi
// 0057e53b  5e                   pop esi
// 0057e53c  5b                   pop ebx
// 0057e53d  59                   pop ecx
// 0057e53e  c21400               ret 0x14
// 0057e541  8b08                 mov ecx, dword ptr [eax]
// 0057e543  eb8d                 jmp 0x57e4d2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
