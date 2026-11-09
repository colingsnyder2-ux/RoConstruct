// from server: 100% by auto
// roc 2009-12 005e6e30  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e6e30
//
// 005e6e30  83ec08               sub esp, 8
// 005e6e33  53                   push ebx
// 005e6e34  55                   push ebp
// 005e6e35  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 005e6e3b  56                   push esi
// 005e6e3c  8bf1                 mov esi, ecx
// 005e6e3e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e6e41  8b18                 mov ebx, dword ptr [eax]
// 005e6e43  8b06                 mov eax, dword ptr [esi]
// 005e6e45  57                   push edi
// 005e6e46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005e6e4a  85ff                 test edi, edi
// 005e6e4c  7404                 je 0x5e6e52
// 005e6e4e  3bf8                 cmp edi, eax
// 005e6e50  7406                 je 0x5e6e58
// 005e6e52  ffd5                 call ebp
// 005e6e54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005e6e58  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005e6e5c  7562                 jne 0x5e6ec0
// 005e6e5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005e6e62  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005e6e65  8b06                 mov eax, dword ptr [esi]
// 005e6e67  85c9                 test ecx, ecx
// 005e6e69  7404                 je 0x5e6e6f
// 005e6e6b  3bc8                 cmp ecx, eax
// 005e6e6d  7406                 je 0x5e6e75
// 005e6e6f  ffd5                 call ebp
// 005e6e71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005e6e75  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005e6e79  7545                 jne 0x5e6ec0
// 005e6e7b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005e6e7e  8b5104               mov edx, dword ptr [ecx + 4]
// 005e6e81  52                   push edx
// 005e6e82  8bce                 mov ecx, esi
// 005e6e84  e827fbffff           call 0x5e69b0
// 005e6e89  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e6e8c  894004               mov dword ptr [eax + 4], eax
// 005e6e8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e6e92  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005e6e99  8900                 mov dword ptr [eax], eax
// 005e6e9b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e6e9e  894008               mov dword ptr [eax + 8], eax
// 005e6ea1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e6ea4  8b16                 mov edx, dword ptr [esi]
// 005e6ea6  8b08                 mov ecx, dword ptr [eax]
// 005e6ea8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005e6eac  5f                   pop edi
// 005e6ead  5e                   pop esi
// 005e6eae  5d                   pop ebp
// 005e6eaf  894804               mov dword ptr [eax + 4], ecx
// 005e6eb2  8910                 mov dword ptr [eax], edx
// 005e6eb4  5b                   pop ebx
// 005e6eb5  83c408               add esp, 8
// 005e6eb8  c21400               ret 0x14
// 005e6ebb  eb03                 jmp 0x5e6ec0
// 005e6ebd  8d4900               lea ecx, [ecx]
// 005e6ec0  85ff                 test edi, edi
// 005e6ec2  7406                 je 0x5e6eca
// 005e6ec4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005e6ec8  7406                 je 0x5e6ed0
// 005e6eca  ffd5                 call ebp
// 005e6ecc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005e6ed0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005e6ed4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005e6ed8  741d                 je 0x5e6ef7
// 005e6eda  8d4c2420             lea ecx, [esp + 0x20]
// 005e6ede  e8ddf1ffff           call 0x5e60c0
// 005e6ee3  53                   push ebx
// 005e6ee4  57                   push edi
// 005e6ee5  8d442418             lea eax, [esp + 0x18]
// 005e6ee9  50                   push eax
// 005e6eea  8bce                 mov ecx, esi
// 005e6eec  e87ff5ffff           call 0x5e6470
// 005e6ef1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005e6ef5  ebc9                 jmp 0x5e6ec0
// 005e6ef7  8b36                 mov esi, dword ptr [esi]
// 005e6ef9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005e6efd  5f                   pop edi
// 005e6efe  8930                 mov dword ptr [eax], esi
// 005e6f00  5e                   pop esi
// 005e6f01  5d                   pop ebp
// 005e6f02  895804               mov dword ptr [eax + 4], ebx
// 005e6f05  5b                   pop ebx
// 005e6f06  83c408               add esp, 8
// 005e6f09  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
