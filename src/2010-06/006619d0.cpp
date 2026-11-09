// from server: 100% by auto
// roc 2010-06 006619d0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006619d0
//
// 006619d0  83ec08               sub esp, 8
// 006619d3  53                   push ebx
// 006619d4  55                   push ebp
// 006619d5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006619db  56                   push esi
// 006619dc  8bf1                 mov esi, ecx
// 006619de  8b4618               mov eax, dword ptr [esi + 0x18]
// 006619e1  8b18                 mov ebx, dword ptr [eax]
// 006619e3  8b06                 mov eax, dword ptr [esi]
// 006619e5  57                   push edi
// 006619e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006619ea  85ff                 test edi, edi
// 006619ec  7404                 je 0x6619f2
// 006619ee  3bf8                 cmp edi, eax
// 006619f0  7406                 je 0x6619f8
// 006619f2  ffd5                 call ebp
// 006619f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006619f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006619fc  7562                 jne 0x661a60
// 006619fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00661a02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00661a05  8b06                 mov eax, dword ptr [esi]
// 00661a07  85c9                 test ecx, ecx
// 00661a09  7404                 je 0x661a0f
// 00661a0b  3bc8                 cmp ecx, eax
// 00661a0d  7406                 je 0x661a15
// 00661a0f  ffd5                 call ebp
// 00661a11  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661a15  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00661a19  7545                 jne 0x661a60
// 00661a1b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00661a1e  8b5104               mov edx, dword ptr [ecx + 4]
// 00661a21  52                   push edx
// 00661a22  8bce                 mov ecx, esi
// 00661a24  e817f5ffff           call 0x660f40
// 00661a29  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661a2c  894004               mov dword ptr [eax + 4], eax
// 00661a2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661a32  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00661a39  8900                 mov dword ptr [eax], eax
// 00661a3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661a3e  894008               mov dword ptr [eax + 8], eax
// 00661a41  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661a44  8b16                 mov edx, dword ptr [esi]
// 00661a46  8b08                 mov ecx, dword ptr [eax]
// 00661a48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00661a4c  5f                   pop edi
// 00661a4d  5e                   pop esi
// 00661a4e  5d                   pop ebp
// 00661a4f  894804               mov dword ptr [eax + 4], ecx
// 00661a52  8910                 mov dword ptr [eax], edx
// 00661a54  5b                   pop ebx
// 00661a55  83c408               add esp, 8
// 00661a58  c21400               ret 0x14
// 00661a5b  eb03                 jmp 0x661a60
// 00661a5d  8d4900               lea ecx, [ecx]
// 00661a60  85ff                 test edi, edi
// 00661a62  7406                 je 0x661a6a
// 00661a64  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00661a68  7406                 je 0x661a70
// 00661a6a  ffd5                 call ebp
// 00661a6c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661a70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00661a74  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00661a78  741d                 je 0x661a97
// 00661a7a  8d4c2420             lea ecx, [esp + 0x20]
// 00661a7e  e8ad4fe8ff           call 0x4e6a30
// 00661a83  53                   push ebx
// 00661a84  57                   push edi
// 00661a85  8d442418             lea eax, [esp + 0x18]
// 00661a89  50                   push eax
// 00661a8a  8bce                 mov ecx, esi
// 00661a8c  e8aff1ffff           call 0x660c40
// 00661a91  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661a95  ebc9                 jmp 0x661a60
// 00661a97  8b36                 mov esi, dword ptr [esi]
// 00661a99  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00661a9d  5f                   pop edi
// 00661a9e  8930                 mov dword ptr [eax], esi
// 00661aa0  5e                   pop esi
// 00661aa1  5d                   pop ebp
// 00661aa2  895804               mov dword ptr [eax + 4], ebx
// 00661aa5  5b                   pop ebx
// 00661aa6  83c408               add esp, 8
// 00661aa9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
