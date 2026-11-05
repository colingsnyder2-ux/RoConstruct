// from server: 100% by auto
// roc 2010-06 009627e0  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009627e0
//
// 009627e0  51                   push ecx
// 009627e1  8b442414             mov eax, dword ptr [esp + 0x14]
// 009627e5  53                   push ebx
// 009627e6  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 009627ec  56                   push esi
// 009627ed  57                   push edi
// 009627ee  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 009627f2  8b7714               mov esi, dword ptr [edi + 0x14]
// 009627f5  894c240c             mov dword ptr [esp + 0xc], ecx
// 009627f9  8b0f                 mov ecx, dword ptr [edi]
// 009627fb  85c0                 test eax, eax
// 009627fd  7404                 je 0x962803
// 009627ff  3bc1                 cmp eax, ecx
// 00962801  7406                 je 0x962809
// 00962803  ffd3                 call ebx
// 00962805  8b442420             mov eax, dword ptr [esp + 0x20]
// 00962809  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096280d  3bce                 cmp ecx, esi
// 0096280f  7479                 je 0x96288a
// 00962811  55                   push ebp
// 00962812  8be8                 mov ebp, eax
// 00962814  8bf1                 mov esi, ecx
// 00962816  85c0                 test eax, eax
// 00962818  7577                 jne 0x962891
// 0096281a  ffd3                 call ebx
// 0096281c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962820  33c9                 xor ecx, ecx
// 00962822  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 00962825  7506                 jne 0x96282d
// 00962827  ffd3                 call ebx
// 00962829  8b442424             mov eax, dword ptr [esp + 0x24]
// 0096282d  8b36                 mov esi, dword ptr [esi]
// 0096282f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962833  397c2410             cmp dword ptr [esp + 0x10], edi
// 00962837  7534                 jne 0x96286d
// 00962839  85c9                 test ecx, ecx
// 0096283b  7404                 je 0x962841
// 0096283d  3bc8                 cmp ecx, eax
// 0096283f  740a                 je 0x96284b
// 00962841  ffd3                 call ebx
// 00962843  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962847  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0096284b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0096284f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00962853  7434                 je 0x962889
// 00962855  85c9                 test ecx, ecx
// 00962857  7404                 je 0x96285d
// 00962859  3bcd                 cmp ecx, ebp
// 0096285b  740a                 je 0x962867
// 0096285d  ffd3                 call ebx
// 0096285f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962863  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962867  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0096286b  741c                 je 0x962889
// 0096286d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00962871  6a00                 push 0
// 00962873  6a01                 push 1
// 00962875  56                   push esi
// 00962876  55                   push ebp
// 00962877  52                   push edx
// 00962878  50                   push eax
// 00962879  8b442434             mov eax, dword ptr [esp + 0x34]
// 0096287d  57                   push edi
// 0096287e  50                   push eax
// 0096287f  51                   push ecx
// 00962880  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00962884  e887fbffff           call 0x962410
// 00962889  5d                   pop ebp
// 0096288a  5f                   pop edi
// 0096288b  5e                   pop esi
// 0096288c  5b                   pop ebx
// 0096288d  59                   pop ecx
// 0096288e  c21400               ret 0x14
// 00962891  8b08                 mov ecx, dword ptr [eax]
// 00962893  eb8d                 jmp 0x962822
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
