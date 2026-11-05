// from server: 100% by auto
// roc 2010-06 00641bd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641bd0
//
// 00641bd0  83ec08               sub esp, 8
// 00641bd3  53                   push ebx
// 00641bd4  55                   push ebp
// 00641bd5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00641bdb  56                   push esi
// 00641bdc  8bf1                 mov esi, ecx
// 00641bde  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641be1  8b18                 mov ebx, dword ptr [eax]
// 00641be3  8b06                 mov eax, dword ptr [esi]
// 00641be5  57                   push edi
// 00641be6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641bea  85ff                 test edi, edi
// 00641bec  7404                 je 0x641bf2
// 00641bee  3bf8                 cmp edi, eax
// 00641bf0  7406                 je 0x641bf8
// 00641bf2  ffd5                 call ebp
// 00641bf4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641bf8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00641bfc  7562                 jne 0x641c60
// 00641bfe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00641c02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00641c05  8b06                 mov eax, dword ptr [esi]
// 00641c07  85c9                 test ecx, ecx
// 00641c09  7404                 je 0x641c0f
// 00641c0b  3bc8                 cmp ecx, eax
// 00641c0d  7406                 je 0x641c15
// 00641c0f  ffd5                 call ebp
// 00641c11  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641c15  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00641c19  7545                 jne 0x641c60
// 00641c1b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00641c1e  8b5104               mov edx, dword ptr [ecx + 4]
// 00641c21  52                   push edx
// 00641c22  8bce                 mov ecx, esi
// 00641c24  e8e7f8ffff           call 0x641510
// 00641c29  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641c2c  894004               mov dword ptr [eax + 4], eax
// 00641c2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641c32  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00641c39  8900                 mov dword ptr [eax], eax
// 00641c3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641c3e  894008               mov dword ptr [eax + 8], eax
// 00641c41  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641c44  8b16                 mov edx, dword ptr [esi]
// 00641c46  8b08                 mov ecx, dword ptr [eax]
// 00641c48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00641c4c  5f                   pop edi
// 00641c4d  5e                   pop esi
// 00641c4e  5d                   pop ebp
// 00641c4f  894804               mov dword ptr [eax + 4], ecx
// 00641c52  8910                 mov dword ptr [eax], edx
// 00641c54  5b                   pop ebx
// 00641c55  83c408               add esp, 8
// 00641c58  c21400               ret 0x14
// 00641c5b  eb03                 jmp 0x641c60
// 00641c5d  8d4900               lea ecx, [ecx]
// 00641c60  85ff                 test edi, edi
// 00641c62  7406                 je 0x641c6a
// 00641c64  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00641c68  7406                 je 0x641c70
// 00641c6a  ffd5                 call ebp
// 00641c6c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641c70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00641c74  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00641c78  741d                 je 0x641c97
// 00641c7a  8d4c2420             lea ecx, [esp + 0x20]
// 00641c7e  e82dd80100           call 0x65f4b0
// 00641c83  53                   push ebx
// 00641c84  57                   push edi
// 00641c85  8d442418             lea eax, [esp + 0x18]
// 00641c89  50                   push eax
// 00641c8a  8bce                 mov ecx, esi
// 00641c8c  e8bff4ffff           call 0x641150
// 00641c91  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641c95  ebc9                 jmp 0x641c60
// 00641c97  8b36                 mov esi, dword ptr [esi]
// 00641c99  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00641c9d  5f                   pop edi
// 00641c9e  8930                 mov dword ptr [eax], esi
// 00641ca0  5e                   pop esi
// 00641ca1  5d                   pop ebp
// 00641ca2  895804               mov dword ptr [eax + 4], ebx
// 00641ca5  5b                   pop ebx
// 00641ca6  83c408               add esp, 8
// 00641ca9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
