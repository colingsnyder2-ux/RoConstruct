// from server: 100% by auto
// roc 2009-06 004782d0  unit: Ogre::RbxMeshLoader  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004782d0
//
// 004782d0  83ec08               sub esp, 8
// 004782d3  53                   push ebx
// 004782d4  55                   push ebp
// 004782d5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004782db  56                   push esi
// 004782dc  8bf1                 mov esi, ecx
// 004782de  8b4618               mov eax, dword ptr [esi + 0x18]
// 004782e1  8b18                 mov ebx, dword ptr [eax]
// 004782e3  8b06                 mov eax, dword ptr [esi]
// 004782e5  57                   push edi
// 004782e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004782ea  85ff                 test edi, edi
// 004782ec  7404                 je 0x4782f2
// 004782ee  3bf8                 cmp edi, eax
// 004782f0  7406                 je 0x4782f8
// 004782f2  ffd5                 call ebp
// 004782f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004782f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004782fc  7562                 jne 0x478360
// 004782fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00478302  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00478305  8b06                 mov eax, dword ptr [esi]
// 00478307  85c9                 test ecx, ecx
// 00478309  7404                 je 0x47830f
// 0047830b  3bc8                 cmp ecx, eax
// 0047830d  7406                 je 0x478315
// 0047830f  ffd5                 call ebp
// 00478311  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00478315  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00478319  7545                 jne 0x478360
// 0047831b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0047831e  8b5104               mov edx, dword ptr [ecx + 4]
// 00478321  52                   push edx
// 00478322  8bce                 mov ecx, esi
// 00478324  e867ebffff           call 0x476e90
// 00478329  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047832c  894004               mov dword ptr [eax + 4], eax
// 0047832f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00478332  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00478339  8900                 mov dword ptr [eax], eax
// 0047833b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047833e  894008               mov dword ptr [eax + 8], eax
// 00478341  8b4618               mov eax, dword ptr [esi + 0x18]
// 00478344  8b16                 mov edx, dword ptr [esi]
// 00478346  8b08                 mov ecx, dword ptr [eax]
// 00478348  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047834c  5f                   pop edi
// 0047834d  5e                   pop esi
// 0047834e  5d                   pop ebp
// 0047834f  894804               mov dword ptr [eax + 4], ecx
// 00478352  8910                 mov dword ptr [eax], edx
// 00478354  5b                   pop ebx
// 00478355  83c408               add esp, 8
// 00478358  c21400               ret 0x14
// 0047835b  eb03                 jmp 0x478360
// 0047835d  8d4900               lea ecx, [ecx]
// 00478360  85ff                 test edi, edi
// 00478362  7406                 je 0x47836a
// 00478364  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00478368  7406                 je 0x478370
// 0047836a  ffd5                 call ebp
// 0047836c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00478370  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00478374  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00478378  741d                 je 0x478397
// 0047837a  8d4c2420             lea ecx, [esp + 0x20]
// 0047837e  e8edf40900           call 0x517870
// 00478383  53                   push ebx
// 00478384  57                   push edi
// 00478385  8d442418             lea eax, [esp + 0x18]
// 00478389  50                   push eax
// 0047838a  8bce                 mov ecx, esi
// 0047838c  e81fe8ffff           call 0x476bb0
// 00478391  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00478395  ebc9                 jmp 0x478360
// 00478397  8b36                 mov esi, dword ptr [esi]
// 00478399  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047839d  5f                   pop edi
// 0047839e  8930                 mov dword ptr [eax], esi
// 004783a0  5e                   pop esi
// 004783a1  5d                   pop ebp
// 004783a2  895804               mov dword ptr [eax + 4], ebx
// 004783a5  5b                   pop ebx
// 004783a6  83c408               add esp, 8
// 004783a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
