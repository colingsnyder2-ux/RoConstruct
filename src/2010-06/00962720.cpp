// from server: 100% by auto
// roc 2010-06 00962720  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962720
//
// 00962720  51                   push ecx
// 00962721  8b442414             mov eax, dword ptr [esp + 0x14]
// 00962725  53                   push ebx
// 00962726  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0096272c  56                   push esi
// 0096272d  57                   push edi
// 0096272e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00962732  8b7714               mov esi, dword ptr [edi + 0x14]
// 00962735  894c240c             mov dword ptr [esp + 0xc], ecx
// 00962739  8b0f                 mov ecx, dword ptr [edi]
// 0096273b  85c0                 test eax, eax
// 0096273d  7404                 je 0x962743
// 0096273f  3bc1                 cmp eax, ecx
// 00962741  7406                 je 0x962749
// 00962743  ffd3                 call ebx
// 00962745  8b442420             mov eax, dword ptr [esp + 0x20]
// 00962749  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096274d  3bce                 cmp ecx, esi
// 0096274f  7479                 je 0x9627ca
// 00962751  55                   push ebp
// 00962752  8be8                 mov ebp, eax
// 00962754  8bf1                 mov esi, ecx
// 00962756  85c0                 test eax, eax
// 00962758  7577                 jne 0x9627d1
// 0096275a  ffd3                 call ebx
// 0096275c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962760  33c9                 xor ecx, ecx
// 00962762  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 00962765  7506                 jne 0x96276d
// 00962767  ffd3                 call ebx
// 00962769  8b442424             mov eax, dword ptr [esp + 0x24]
// 0096276d  8b36                 mov esi, dword ptr [esi]
// 0096276f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962773  397c2410             cmp dword ptr [esp + 0x10], edi
// 00962777  7534                 jne 0x9627ad
// 00962779  85c9                 test ecx, ecx
// 0096277b  7404                 je 0x962781
// 0096277d  3bc8                 cmp ecx, eax
// 0096277f  740a                 je 0x96278b
// 00962781  ffd3                 call ebx
// 00962783  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962787  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0096278b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0096278f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00962793  7434                 je 0x9627c9
// 00962795  85c9                 test ecx, ecx
// 00962797  7404                 je 0x96279d
// 00962799  3bcd                 cmp ecx, ebp
// 0096279b  740a                 je 0x9627a7
// 0096279d  ffd3                 call ebx
// 0096279f  8b442424             mov eax, dword ptr [esp + 0x24]
// 009627a3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009627a7  3974241c             cmp dword ptr [esp + 0x1c], esi
// 009627ab  741c                 je 0x9627c9
// 009627ad  8b542428             mov edx, dword ptr [esp + 0x28]
// 009627b1  6a00                 push 0
// 009627b3  6a01                 push 1
// 009627b5  56                   push esi
// 009627b6  55                   push ebp
// 009627b7  52                   push edx
// 009627b8  50                   push eax
// 009627b9  8b442434             mov eax, dword ptr [esp + 0x34]
// 009627bd  57                   push edi
// 009627be  50                   push eax
// 009627bf  51                   push ecx
// 009627c0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 009627c4  e8d7fbffff           call 0x9623a0
// 009627c9  5d                   pop ebp
// 009627ca  5f                   pop edi
// 009627cb  5e                   pop esi
// 009627cc  5b                   pop ebx
// 009627cd  59                   pop ecx
// 009627ce  c21400               ret 0x14
// 009627d1  8b08                 mov ecx, dword ptr [eax]
// 009627d3  eb8d                 jmp 0x962762
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
