// from server: 100% by auto
// roc 2009-12 006f6d20  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6d20
//
// 006f6d20  83ec08               sub esp, 8
// 006f6d23  53                   push ebx
// 006f6d24  55                   push ebp
// 006f6d25  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006f6d2b  56                   push esi
// 006f6d2c  8bf1                 mov esi, ecx
// 006f6d2e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6d31  8b18                 mov ebx, dword ptr [eax]
// 006f6d33  8b06                 mov eax, dword ptr [esi]
// 006f6d35  57                   push edi
// 006f6d36  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6d3a  85ff                 test edi, edi
// 006f6d3c  7404                 je 0x6f6d42
// 006f6d3e  3bf8                 cmp edi, eax
// 006f6d40  7406                 je 0x6f6d48
// 006f6d42  ffd5                 call ebp
// 006f6d44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6d48  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006f6d4c  7562                 jne 0x6f6db0
// 006f6d4e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f6d52  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006f6d55  8b06                 mov eax, dword ptr [esi]
// 006f6d57  85c9                 test ecx, ecx
// 006f6d59  7404                 je 0x6f6d5f
// 006f6d5b  3bc8                 cmp ecx, eax
// 006f6d5d  7406                 je 0x6f6d65
// 006f6d5f  ffd5                 call ebp
// 006f6d61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6d65  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006f6d69  7545                 jne 0x6f6db0
// 006f6d6b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f6d6e  8b5104               mov edx, dword ptr [ecx + 4]
// 006f6d71  52                   push edx
// 006f6d72  8bce                 mov ecx, esi
// 006f6d74  e837f2ffff           call 0x6f5fb0
// 006f6d79  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6d7c  894004               mov dword ptr [eax + 4], eax
// 006f6d7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6d82  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f6d89  8900                 mov dword ptr [eax], eax
// 006f6d8b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6d8e  894008               mov dword ptr [eax + 8], eax
// 006f6d91  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f6d94  8b16                 mov edx, dword ptr [esi]
// 006f6d96  8b08                 mov ecx, dword ptr [eax]
// 006f6d98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f6d9c  5f                   pop edi
// 006f6d9d  5e                   pop esi
// 006f6d9e  5d                   pop ebp
// 006f6d9f  894804               mov dword ptr [eax + 4], ecx
// 006f6da2  8910                 mov dword ptr [eax], edx
// 006f6da4  5b                   pop ebx
// 006f6da5  83c408               add esp, 8
// 006f6da8  c21400               ret 0x14
// 006f6dab  eb03                 jmp 0x6f6db0
// 006f6dad  8d4900               lea ecx, [ecx]
// 006f6db0  85ff                 test edi, edi
// 006f6db2  7406                 je 0x6f6dba
// 006f6db4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006f6db8  7406                 je 0x6f6dc0
// 006f6dba  ffd5                 call ebp
// 006f6dbc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6dc0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006f6dc4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006f6dc8  741d                 je 0x6f6de7
// 006f6dca  8d4c2420             lea ecx, [esp + 0x20]
// 006f6dce  e81d63fbff           call 0x6ad0f0
// 006f6dd3  53                   push ebx
// 006f6dd4  57                   push edi
// 006f6dd5  8d442418             lea eax, [esp + 0x18]
// 006f6dd9  50                   push eax
// 006f6dda  8bce                 mov ecx, esi
// 006f6ddc  e8dfecffff           call 0x6f5ac0
// 006f6de1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6de5  ebc9                 jmp 0x6f6db0
// 006f6de7  8b36                 mov esi, dword ptr [esi]
// 006f6de9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f6ded  5f                   pop edi
// 006f6dee  8930                 mov dword ptr [eax], esi
// 006f6df0  5e                   pop esi
// 006f6df1  5d                   pop ebp
// 006f6df2  895804               mov dword ptr [eax + 4], ebx
// 006f6df5  5b                   pop ebx
// 006f6df6  83c408               add esp, 8
// 006f6df9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
