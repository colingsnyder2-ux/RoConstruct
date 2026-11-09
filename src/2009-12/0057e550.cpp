// from server: 100% by auto
// roc 2009-12 0057e550  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e550
//
// 0057e550  51                   push ecx
// 0057e551  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057e555  53                   push ebx
// 0057e556  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0057e55c  56                   push esi
// 0057e55d  57                   push edi
// 0057e55e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0057e562  8b7714               mov esi, dword ptr [edi + 0x14]
// 0057e565  894c240c             mov dword ptr [esp + 0xc], ecx
// 0057e569  8b0f                 mov ecx, dword ptr [edi]
// 0057e56b  85c0                 test eax, eax
// 0057e56d  7404                 je 0x57e573
// 0057e56f  3bc1                 cmp eax, ecx
// 0057e571  7406                 je 0x57e579
// 0057e573  ffd3                 call ebx
// 0057e575  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057e579  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0057e57d  3bce                 cmp ecx, esi
// 0057e57f  7479                 je 0x57e5fa
// 0057e581  55                   push ebp
// 0057e582  8be8                 mov ebp, eax
// 0057e584  8bf1                 mov esi, ecx
// 0057e586  85c0                 test eax, eax
// 0057e588  7577                 jne 0x57e601
// 0057e58a  ffd3                 call ebx
// 0057e58c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e590  33c9                 xor ecx, ecx
// 0057e592  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0057e595  7506                 jne 0x57e59d
// 0057e597  ffd3                 call ebx
// 0057e599  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e59d  8b36                 mov esi, dword ptr [esi]
// 0057e59f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e5a3  397c2410             cmp dword ptr [esp + 0x10], edi
// 0057e5a7  7534                 jne 0x57e5dd
// 0057e5a9  85c9                 test ecx, ecx
// 0057e5ab  7404                 je 0x57e5b1
// 0057e5ad  3bc8                 cmp ecx, eax
// 0057e5af  740a                 je 0x57e5bb
// 0057e5b1  ffd3                 call ebx
// 0057e5b3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e5b7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e5bb  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057e5bf  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0057e5c3  7434                 je 0x57e5f9
// 0057e5c5  85c9                 test ecx, ecx
// 0057e5c7  7404                 je 0x57e5cd
// 0057e5c9  3bcd                 cmp ecx, ebp
// 0057e5cb  740a                 je 0x57e5d7
// 0057e5cd  ffd3                 call ebx
// 0057e5cf  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057e5d3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e5d7  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0057e5db  741c                 je 0x57e5f9
// 0057e5dd  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057e5e1  6a00                 push 0
// 0057e5e3  6a01                 push 1
// 0057e5e5  56                   push esi
// 0057e5e6  55                   push ebp
// 0057e5e7  52                   push edx
// 0057e5e8  50                   push eax
// 0057e5e9  8b442434             mov eax, dword ptr [esp + 0x34]
// 0057e5ed  57                   push edi
// 0057e5ee  50                   push eax
// 0057e5ef  51                   push ecx
// 0057e5f0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0057e5f4  e817cff2ff           call 0x4ab510
// 0057e5f9  5d                   pop ebp
// 0057e5fa  5f                   pop edi
// 0057e5fb  5e                   pop esi
// 0057e5fc  5b                   pop ebx
// 0057e5fd  59                   pop ecx
// 0057e5fe  c21400               ret 0x14
// 0057e601  8b08                 mov ecx, dword ptr [eax]
// 0057e603  eb8d                 jmp 0x57e592
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
