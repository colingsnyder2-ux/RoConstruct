// from server: 100% by auto
// roc 2009-12 0057ddd0  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ddd0
//
// 0057ddd0  51                   push ecx
// 0057ddd1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057ddd5  53                   push ebx
// 0057ddd6  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0057dddc  56                   push esi
// 0057dddd  57                   push edi
// 0057ddde  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0057dde2  8b7714               mov esi, dword ptr [edi + 0x14]
// 0057dde5  894c240c             mov dword ptr [esp + 0xc], ecx
// 0057dde9  8b0f                 mov ecx, dword ptr [edi]
// 0057ddeb  85c0                 test eax, eax
// 0057dded  7404                 je 0x57ddf3
// 0057ddef  3bc1                 cmp eax, ecx
// 0057ddf1  7406                 je 0x57ddf9
// 0057ddf3  ffd3                 call ebx
// 0057ddf5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057ddf9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0057ddfd  3bce                 cmp ecx, esi
// 0057ddff  7479                 je 0x57de7a
// 0057de01  55                   push ebp
// 0057de02  8be8                 mov ebp, eax
// 0057de04  8bf1                 mov esi, ecx
// 0057de06  85c0                 test eax, eax
// 0057de08  7577                 jne 0x57de81
// 0057de0a  ffd3                 call ebx
// 0057de0c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057de10  33c9                 xor ecx, ecx
// 0057de12  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 0057de15  7506                 jne 0x57de1d
// 0057de17  ffd3                 call ebx
// 0057de19  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057de1d  8b36                 mov esi, dword ptr [esi]
// 0057de1f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057de23  397c2410             cmp dword ptr [esp + 0x10], edi
// 0057de27  7534                 jne 0x57de5d
// 0057de29  85c9                 test ecx, ecx
// 0057de2b  7404                 je 0x57de31
// 0057de2d  3bc8                 cmp ecx, eax
// 0057de2f  740a                 je 0x57de3b
// 0057de31  ffd3                 call ebx
// 0057de33  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057de37  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057de3b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057de3f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0057de43  7434                 je 0x57de79
// 0057de45  85c9                 test ecx, ecx
// 0057de47  7404                 je 0x57de4d
// 0057de49  3bcd                 cmp ecx, ebp
// 0057de4b  740a                 je 0x57de57
// 0057de4d  ffd3                 call ebx
// 0057de4f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057de53  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057de57  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0057de5b  741c                 je 0x57de79
// 0057de5d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0057de61  6a00                 push 0
// 0057de63  6a01                 push 1
// 0057de65  56                   push esi
// 0057de66  55                   push ebp
// 0057de67  52                   push edx
// 0057de68  50                   push eax
// 0057de69  8b442434             mov eax, dword ptr [esp + 0x34]
// 0057de6d  57                   push edi
// 0057de6e  50                   push eax
// 0057de6f  51                   push ecx
// 0057de70  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0057de74  e837fbffff           call 0x57d9b0
// 0057de79  5d                   pop ebp
// 0057de7a  5f                   pop edi
// 0057de7b  5e                   pop esi
// 0057de7c  5b                   pop ebx
// 0057de7d  59                   pop ecx
// 0057de7e  c21400               ret 0x14
// 0057de81  8b08                 mov ecx, dword ptr [eax]
// 0057de83  eb8d                 jmp 0x57de12
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
