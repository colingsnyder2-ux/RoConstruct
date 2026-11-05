// from server: 100% by auto
// roc 2009-06 00622d20  unit: RBX::RootInstance  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622d20
//
// 00622d20  83ec08               sub esp, 8
// 00622d23  53                   push ebx
// 00622d24  55                   push ebp
// 00622d25  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00622d2b  56                   push esi
// 00622d2c  8bf1                 mov esi, ecx
// 00622d2e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00622d31  8b18                 mov ebx, dword ptr [eax]
// 00622d33  8b06                 mov eax, dword ptr [esi]
// 00622d35  57                   push edi
// 00622d36  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622d3a  85ff                 test edi, edi
// 00622d3c  7404                 je 0x622d42
// 00622d3e  3bf8                 cmp edi, eax
// 00622d40  7406                 je 0x622d48
// 00622d42  ffd5                 call ebp
// 00622d44  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622d48  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00622d4c  7562                 jne 0x622db0
// 00622d4e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00622d52  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00622d55  8b06                 mov eax, dword ptr [esi]
// 00622d57  85c9                 test ecx, ecx
// 00622d59  7404                 je 0x622d5f
// 00622d5b  3bc8                 cmp ecx, eax
// 00622d5d  7406                 je 0x622d65
// 00622d5f  ffd5                 call ebp
// 00622d61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622d65  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00622d69  7545                 jne 0x622db0
// 00622d6b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00622d6e  8b5104               mov edx, dword ptr [ecx + 4]
// 00622d71  52                   push edx
// 00622d72  8bce                 mov ecx, esi
// 00622d74  e847fbffff           call 0x6228c0
// 00622d79  8b4618               mov eax, dword ptr [esi + 0x18]
// 00622d7c  894004               mov dword ptr [eax + 4], eax
// 00622d7f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00622d82  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00622d89  8900                 mov dword ptr [eax], eax
// 00622d8b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00622d8e  894008               mov dword ptr [eax + 8], eax
// 00622d91  8b4618               mov eax, dword ptr [esi + 0x18]
// 00622d94  8b16                 mov edx, dword ptr [esi]
// 00622d96  8b08                 mov ecx, dword ptr [eax]
// 00622d98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00622d9c  5f                   pop edi
// 00622d9d  5e                   pop esi
// 00622d9e  5d                   pop ebp
// 00622d9f  894804               mov dword ptr [eax + 4], ecx
// 00622da2  8910                 mov dword ptr [eax], edx
// 00622da4  5b                   pop ebx
// 00622da5  83c408               add esp, 8
// 00622da8  c21400               ret 0x14
// 00622dab  eb03                 jmp 0x622db0
// 00622dad  8d4900               lea ecx, [ecx]
// 00622db0  85ff                 test edi, edi
// 00622db2  7406                 je 0x622dba
// 00622db4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00622db8  7406                 je 0x622dc0
// 00622dba  ffd5                 call ebp
// 00622dbc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622dc0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00622dc4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00622dc8  741d                 je 0x622de7
// 00622dca  8d4c2420             lea ecx, [esp + 0x20]
// 00622dce  e8ddf40b00           call 0x6e22b0
// 00622dd3  53                   push ebx
// 00622dd4  57                   push edi
// 00622dd5  8d442418             lea eax, [esp + 0x18]
// 00622dd9  50                   push eax
// 00622dda  8bce                 mov ecx, esi
// 00622ddc  e8fff7ffff           call 0x6225e0
// 00622de1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00622de5  ebc9                 jmp 0x622db0
// 00622de7  8b36                 mov esi, dword ptr [esi]
// 00622de9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00622ded  5f                   pop edi
// 00622dee  8930                 mov dword ptr [eax], esi
// 00622df0  5e                   pop esi
// 00622df1  5d                   pop ebp
// 00622df2  895804               mov dword ptr [eax + 4], ebx
// 00622df5  5b                   pop ebx
// 00622df6  83c408               add esp, 8
// 00622df9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
