// from server: 100% by auto
// roc 2010-06 00962e80  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962e80
//
// 00962e80  51                   push ecx
// 00962e81  8b442414             mov eax, dword ptr [esp + 0x14]
// 00962e85  53                   push ebx
// 00962e86  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00962e8c  56                   push esi
// 00962e8d  57                   push edi
// 00962e8e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00962e92  8b7714               mov esi, dword ptr [edi + 0x14]
// 00962e95  894c240c             mov dword ptr [esp + 0xc], ecx
// 00962e99  8b0f                 mov ecx, dword ptr [edi]
// 00962e9b  85c0                 test eax, eax
// 00962e9d  7404                 je 0x962ea3
// 00962e9f  3bc1                 cmp eax, ecx
// 00962ea1  7406                 je 0x962ea9
// 00962ea3  ffd3                 call ebx
// 00962ea5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00962ea9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00962ead  3bce                 cmp ecx, esi
// 00962eaf  7479                 je 0x962f2a
// 00962eb1  55                   push ebp
// 00962eb2  8be8                 mov ebp, eax
// 00962eb4  8bf1                 mov esi, ecx
// 00962eb6  85c0                 test eax, eax
// 00962eb8  7577                 jne 0x962f31
// 00962eba  ffd3                 call ebx
// 00962ebc  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962ec0  33c9                 xor ecx, ecx
// 00962ec2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 00962ec5  7506                 jne 0x962ecd
// 00962ec7  ffd3                 call ebx
// 00962ec9  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962ecd  8b36                 mov esi, dword ptr [esi]
// 00962ecf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962ed3  397c2410             cmp dword ptr [esp + 0x10], edi
// 00962ed7  7534                 jne 0x962f0d
// 00962ed9  85c9                 test ecx, ecx
// 00962edb  7404                 je 0x962ee1
// 00962edd  3bc8                 cmp ecx, eax
// 00962edf  740a                 je 0x962eeb
// 00962ee1  ffd3                 call ebx
// 00962ee3  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962ee7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962eeb  8b542428             mov edx, dword ptr [esp + 0x28]
// 00962eef  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00962ef3  7434                 je 0x962f29
// 00962ef5  85c9                 test ecx, ecx
// 00962ef7  7404                 je 0x962efd
// 00962ef9  3bcd                 cmp ecx, ebp
// 00962efb  740a                 je 0x962f07
// 00962efd  ffd3                 call ebx
// 00962eff  8b442424             mov eax, dword ptr [esp + 0x24]
// 00962f03  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962f07  3974241c             cmp dword ptr [esp + 0x1c], esi
// 00962f0b  741c                 je 0x962f29
// 00962f0d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00962f11  6a00                 push 0
// 00962f13  6a01                 push 1
// 00962f15  56                   push esi
// 00962f16  55                   push ebp
// 00962f17  52                   push edx
// 00962f18  50                   push eax
// 00962f19  8b442434             mov eax, dword ptr [esp + 0x34]
// 00962f1d  57                   push edi
// 00962f1e  50                   push eax
// 00962f1f  51                   push ecx
// 00962f20  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00962f24  e857dcbdff           call 0x540b80
// 00962f29  5d                   pop ebp
// 00962f2a  5f                   pop edi
// 00962f2b  5e                   pop esi
// 00962f2c  5b                   pop ebx
// 00962f2d  59                   pop ecx
// 00962f2e  c21400               ret 0x14
// 00962f31  8b08                 mov ecx, dword ptr [eax]
// 00962f33  eb8d                 jmp 0x962ec2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
