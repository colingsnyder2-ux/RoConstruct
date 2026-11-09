// from server: 100% by auto
// roc 2009-06 00414af0  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414af0
//
// 00414af0  83ec08               sub esp, 8
// 00414af3  53                   push ebx
// 00414af4  55                   push ebp
// 00414af5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00414afb  56                   push esi
// 00414afc  8bf1                 mov esi, ecx
// 00414afe  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414b01  8b18                 mov ebx, dword ptr [eax]
// 00414b03  8b06                 mov eax, dword ptr [esi]
// 00414b05  57                   push edi
// 00414b06  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414b0a  85ff                 test edi, edi
// 00414b0c  7404                 je 0x414b12
// 00414b0e  3bf8                 cmp edi, eax
// 00414b10  7406                 je 0x414b18
// 00414b12  ffd5                 call ebp
// 00414b14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414b18  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00414b1c  7562                 jne 0x414b80
// 00414b1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414b22  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414b25  8b06                 mov eax, dword ptr [esi]
// 00414b27  85c9                 test ecx, ecx
// 00414b29  7404                 je 0x414b2f
// 00414b2b  3bc8                 cmp ecx, eax
// 00414b2d  7406                 je 0x414b35
// 00414b2f  ffd5                 call ebp
// 00414b31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414b35  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414b39  7545                 jne 0x414b80
// 00414b3b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00414b3e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414b41  52                   push edx
// 00414b42  8bce                 mov ecx, esi
// 00414b44  e807feffff           call 0x414950
// 00414b49  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414b4c  894004               mov dword ptr [eax + 4], eax
// 00414b4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414b52  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414b59  8900                 mov dword ptr [eax], eax
// 00414b5b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414b5e  894008               mov dword ptr [eax + 8], eax
// 00414b61  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414b64  8b16                 mov edx, dword ptr [esi]
// 00414b66  8b08                 mov ecx, dword ptr [eax]
// 00414b68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00414b6c  5f                   pop edi
// 00414b6d  5e                   pop esi
// 00414b6e  5d                   pop ebp
// 00414b6f  894804               mov dword ptr [eax + 4], ecx
// 00414b72  8910                 mov dword ptr [eax], edx
// 00414b74  5b                   pop ebx
// 00414b75  83c408               add esp, 8
// 00414b78  c21400               ret 0x14
// 00414b7b  eb03                 jmp 0x414b80
// 00414b7d  8d4900               lea ecx, [ecx]
// 00414b80  85ff                 test edi, edi
// 00414b82  7406                 je 0x414b8a
// 00414b84  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00414b88  7406                 je 0x414b90
// 00414b8a  ffd5                 call ebp
// 00414b8c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414b90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00414b94  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00414b98  741d                 je 0x414bb7
// 00414b9a  8d4c2420             lea ecx, [esp + 0x20]
// 00414b9e  e81dd72000           call 0x6222c0
// 00414ba3  53                   push ebx
// 00414ba4  57                   push edi
// 00414ba5  8d442418             lea eax, [esp + 0x18]
// 00414ba9  50                   push eax
// 00414baa  8bce                 mov ecx, esi
// 00414bac  e89ff7ffff           call 0x414350
// 00414bb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414bb5  ebc9                 jmp 0x414b80
// 00414bb7  8b36                 mov esi, dword ptr [esi]
// 00414bb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00414bbd  5f                   pop edi
// 00414bbe  8930                 mov dword ptr [eax], esi
// 00414bc0  5e                   pop esi
// 00414bc1  5d                   pop ebp
// 00414bc2  895804               mov dword ptr [eax + 4], ebx
// 00414bc5  5b                   pop ebx
// 00414bc6  83c408               add esp, 8
// 00414bc9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
