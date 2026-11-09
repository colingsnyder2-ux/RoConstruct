// from server: 100% by auto
// roc 2009-06 00414bd0  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414bd0
//
// 00414bd0  83ec08               sub esp, 8
// 00414bd3  53                   push ebx
// 00414bd4  55                   push ebp
// 00414bd5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00414bdb  56                   push esi
// 00414bdc  8bf1                 mov esi, ecx
// 00414bde  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414be1  8b18                 mov ebx, dword ptr [eax]
// 00414be3  8b06                 mov eax, dword ptr [esi]
// 00414be5  57                   push edi
// 00414be6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414bea  85ff                 test edi, edi
// 00414bec  7404                 je 0x414bf2
// 00414bee  3bf8                 cmp edi, eax
// 00414bf0  7406                 je 0x414bf8
// 00414bf2  ffd5                 call ebp
// 00414bf4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414bf8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00414bfc  7562                 jne 0x414c60
// 00414bfe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414c02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414c05  8b06                 mov eax, dword ptr [esi]
// 00414c07  85c9                 test ecx, ecx
// 00414c09  7404                 je 0x414c0f
// 00414c0b  3bc8                 cmp ecx, eax
// 00414c0d  7406                 je 0x414c15
// 00414c0f  ffd5                 call ebp
// 00414c11  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414c15  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414c19  7545                 jne 0x414c60
// 00414c1b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00414c1e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414c21  52                   push edx
// 00414c22  8bce                 mov ecx, esi
// 00414c24  e897fdffff           call 0x4149c0
// 00414c29  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414c2c  894004               mov dword ptr [eax + 4], eax
// 00414c2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414c32  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414c39  8900                 mov dword ptr [eax], eax
// 00414c3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414c3e  894008               mov dword ptr [eax + 8], eax
// 00414c41  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414c44  8b16                 mov edx, dword ptr [esi]
// 00414c46  8b08                 mov ecx, dword ptr [eax]
// 00414c48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00414c4c  5f                   pop edi
// 00414c4d  5e                   pop esi
// 00414c4e  5d                   pop ebp
// 00414c4f  894804               mov dword ptr [eax + 4], ecx
// 00414c52  8910                 mov dword ptr [eax], edx
// 00414c54  5b                   pop ebx
// 00414c55  83c408               add esp, 8
// 00414c58  c21400               ret 0x14
// 00414c5b  eb03                 jmp 0x414c60
// 00414c5d  8d4900               lea ecx, [ecx]
// 00414c60  85ff                 test edi, edi
// 00414c62  7406                 je 0x414c6a
// 00414c64  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00414c68  7406                 je 0x414c70
// 00414c6a  ffd5                 call ebp
// 00414c6c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414c70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00414c74  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00414c78  741d                 je 0x414c97
// 00414c7a  8d4c2420             lea ecx, [esp + 0x20]
// 00414c7e  e82df3ffff           call 0x413fb0
// 00414c83  53                   push ebx
// 00414c84  57                   push edi
// 00414c85  8d442418             lea eax, [esp + 0x18]
// 00414c89  50                   push eax
// 00414c8a  8bce                 mov ecx, esi
// 00414c8c  e8bff9ffff           call 0x414650
// 00414c91  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414c95  ebc9                 jmp 0x414c60
// 00414c97  8b36                 mov esi, dword ptr [esi]
// 00414c99  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00414c9d  5f                   pop edi
// 00414c9e  8930                 mov dword ptr [eax], esi
// 00414ca0  5e                   pop esi
// 00414ca1  5d                   pop ebp
// 00414ca2  895804               mov dword ptr [eax + 4], ebx
// 00414ca5  5b                   pop ebx
// 00414ca6  83c408               add esp, 8
// 00414ca9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
