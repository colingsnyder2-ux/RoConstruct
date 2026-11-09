// from server: 100% by auto
// roc 2009-12 00706cd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00706cd0
//
// 00706cd0  83ec08               sub esp, 8
// 00706cd3  53                   push ebx
// 00706cd4  55                   push ebp
// 00706cd5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00706cdb  56                   push esi
// 00706cdc  8bf1                 mov esi, ecx
// 00706cde  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706ce1  8b18                 mov ebx, dword ptr [eax]
// 00706ce3  8b06                 mov eax, dword ptr [esi]
// 00706ce5  57                   push edi
// 00706ce6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00706cea  85ff                 test edi, edi
// 00706cec  7404                 je 0x706cf2
// 00706cee  3bf8                 cmp edi, eax
// 00706cf0  7406                 je 0x706cf8
// 00706cf2  ffd5                 call ebp
// 00706cf4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00706cf8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00706cfc  7562                 jne 0x706d60
// 00706cfe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00706d02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00706d05  8b06                 mov eax, dword ptr [esi]
// 00706d07  85c9                 test ecx, ecx
// 00706d09  7404                 je 0x706d0f
// 00706d0b  3bc8                 cmp ecx, eax
// 00706d0d  7406                 je 0x706d15
// 00706d0f  ffd5                 call ebp
// 00706d11  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00706d15  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00706d19  7545                 jne 0x706d60
// 00706d1b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00706d1e  8b5104               mov edx, dword ptr [ecx + 4]
// 00706d21  52                   push edx
// 00706d22  8bce                 mov ecx, esi
// 00706d24  e847deffff           call 0x704b70
// 00706d29  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706d2c  894004               mov dword ptr [eax + 4], eax
// 00706d2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706d32  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00706d39  8900                 mov dword ptr [eax], eax
// 00706d3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706d3e  894008               mov dword ptr [eax + 8], eax
// 00706d41  8b4618               mov eax, dword ptr [esi + 0x18]
// 00706d44  8b16                 mov edx, dword ptr [esi]
// 00706d46  8b08                 mov ecx, dword ptr [eax]
// 00706d48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00706d4c  5f                   pop edi
// 00706d4d  5e                   pop esi
// 00706d4e  5d                   pop ebp
// 00706d4f  894804               mov dword ptr [eax + 4], ecx
// 00706d52  8910                 mov dword ptr [eax], edx
// 00706d54  5b                   pop ebx
// 00706d55  83c408               add esp, 8
// 00706d58  c21400               ret 0x14
// 00706d5b  eb03                 jmp 0x706d60
// 00706d5d  8d4900               lea ecx, [ecx]
// 00706d60  85ff                 test edi, edi
// 00706d62  7406                 je 0x706d6a
// 00706d64  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00706d68  7406                 je 0x706d70
// 00706d6a  ffd5                 call ebp
// 00706d6c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00706d70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00706d74  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00706d78  741d                 je 0x706d97
// 00706d7a  8d4c2420             lea ecx, [esp + 0x20]
// 00706d7e  e86dcbe0ff           call 0x5138f0
// 00706d83  53                   push ebx
// 00706d84  57                   push edi
// 00706d85  8d442418             lea eax, [esp + 0x18]
// 00706d89  50                   push eax
// 00706d8a  8bce                 mov ecx, esi
// 00706d8c  e8dfdaffff           call 0x704870
// 00706d91  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00706d95  ebc9                 jmp 0x706d60
// 00706d97  8b36                 mov esi, dword ptr [esi]
// 00706d99  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00706d9d  5f                   pop edi
// 00706d9e  8930                 mov dword ptr [eax], esi
// 00706da0  5e                   pop esi
// 00706da1  5d                   pop ebp
// 00706da2  895804               mov dword ptr [eax + 4], ebx
// 00706da5  5b                   pop ebx
// 00706da6  83c408               add esp, 8
// 00706da9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
