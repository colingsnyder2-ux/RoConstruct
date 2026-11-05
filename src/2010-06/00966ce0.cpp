// from server: 100% by auto
// roc 2010-06 00966ce0  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00966ce0
//
// 00966ce0  51                   push ecx
// 00966ce1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00966ce5  53                   push ebx
// 00966ce6  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00966cec  56                   push esi
// 00966ced  57                   push edi
// 00966cee  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00966cf2  8b7714               mov esi, dword ptr [edi + 0x14]
// 00966cf5  894c240c             mov dword ptr [esp + 0xc], ecx
// 00966cf9  8b0f                 mov ecx, dword ptr [edi]
// 00966cfb  85c0                 test eax, eax
// 00966cfd  7404                 je 0x966d03
// 00966cff  3bc1                 cmp eax, ecx
// 00966d01  7406                 je 0x966d09
// 00966d03  ffd3                 call ebx
// 00966d05  8b442420             mov eax, dword ptr [esp + 0x20]
// 00966d09  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00966d0d  3bce                 cmp ecx, esi
// 00966d0f  7479                 je 0x966d8a
// 00966d11  55                   push ebp
// 00966d12  8be8                 mov ebp, eax
// 00966d14  8bf1                 mov esi, ecx
// 00966d16  85c0                 test eax, eax
// 00966d18  7577                 jne 0x966d91
// 00966d1a  ffd3                 call ebx
// 00966d1c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00966d20  33c9                 xor ecx, ecx
// 00966d22  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 00966d25  7506                 jne 0x966d2d
// 00966d27  ffd3                 call ebx
// 00966d29  8b442424             mov eax, dword ptr [esp + 0x24]
// 00966d2d  8b36                 mov esi, dword ptr [esi]
// 00966d2f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00966d33  397c2410             cmp dword ptr [esp + 0x10], edi
// 00966d37  7534                 jne 0x966d6d
// 00966d39  85c9                 test ecx, ecx
// 00966d3b  7404                 je 0x966d41
// 00966d3d  3bc8                 cmp ecx, eax
// 00966d3f  740a                 je 0x966d4b
// 00966d41  ffd3                 call ebx
// 00966d43  8b442424             mov eax, dword ptr [esp + 0x24]
// 00966d47  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00966d4b  8b542428             mov edx, dword ptr [esp + 0x28]
// 00966d4f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00966d53  7434                 je 0x966d89
// 00966d55  85c9                 test ecx, ecx
// 00966d57  7404                 je 0x966d5d
// 00966d59  3bcd                 cmp ecx, ebp
// 00966d5b  740a                 je 0x966d67
// 00966d5d  ffd3                 call ebx
// 00966d5f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00966d63  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00966d67  3974241c             cmp dword ptr [esp + 0x1c], esi
// 00966d6b  741c                 je 0x966d89
// 00966d6d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00966d71  6a00                 push 0
// 00966d73  6a01                 push 1
// 00966d75  56                   push esi
// 00966d76  55                   push ebp
// 00966d77  52                   push edx
// 00966d78  50                   push eax
// 00966d79  8b442434             mov eax, dword ptr [esp + 0x34]
// 00966d7d  57                   push edi
// 00966d7e  50                   push eax
// 00966d7f  51                   push ecx
// 00966d80  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00966d84  e8e7feffff           call 0x966c70
// 00966d89  5d                   pop ebp
// 00966d8a  5f                   pop edi
// 00966d8b  5e                   pop esi
// 00966d8c  5b                   pop ebx
// 00966d8d  59                   pop ecx
// 00966d8e  c21400               ret 0x14
// 00966d91  8b08                 mov ecx, dword ptr [eax]
// 00966d93  eb8d                 jmp 0x966d22
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
