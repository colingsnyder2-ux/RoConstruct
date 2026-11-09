// from server: 100% by auto
// roc 2009-06 00838a80  unit: RBX::RenderNew::TextureProxy  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00838a80
//
// 00838a80  83ec08               sub esp, 8
// 00838a83  53                   push ebx
// 00838a84  55                   push ebp
// 00838a85  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00838a8b  56                   push esi
// 00838a8c  8bf1                 mov esi, ecx
// 00838a8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838a91  8b18                 mov ebx, dword ptr [eax]
// 00838a93  8b06                 mov eax, dword ptr [esi]
// 00838a95  57                   push edi
// 00838a96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00838a9a  85ff                 test edi, edi
// 00838a9c  7404                 je 0x838aa2
// 00838a9e  3bf8                 cmp edi, eax
// 00838aa0  7406                 je 0x838aa8
// 00838aa2  ffd5                 call ebp
// 00838aa4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00838aa8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00838aac  7562                 jne 0x838b10
// 00838aae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00838ab2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00838ab5  8b06                 mov eax, dword ptr [esi]
// 00838ab7  85c9                 test ecx, ecx
// 00838ab9  7404                 je 0x838abf
// 00838abb  3bc8                 cmp ecx, eax
// 00838abd  7406                 je 0x838ac5
// 00838abf  ffd5                 call ebp
// 00838ac1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00838ac5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00838ac9  7545                 jne 0x838b10
// 00838acb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00838ace  8b5104               mov edx, dword ptr [ecx + 4]
// 00838ad1  52                   push edx
// 00838ad2  8bce                 mov ecx, esi
// 00838ad4  e8f760e0ff           call 0x63ebd0
// 00838ad9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838adc  894004               mov dword ptr [eax + 4], eax
// 00838adf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838ae2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00838ae9  8900                 mov dword ptr [eax], eax
// 00838aeb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838aee  894008               mov dword ptr [eax + 8], eax
// 00838af1  8b4618               mov eax, dword ptr [esi + 0x18]
// 00838af4  8b16                 mov edx, dword ptr [esi]
// 00838af6  8b08                 mov ecx, dword ptr [eax]
// 00838af8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00838afc  5f                   pop edi
// 00838afd  5e                   pop esi
// 00838afe  5d                   pop ebp
// 00838aff  894804               mov dword ptr [eax + 4], ecx
// 00838b02  8910                 mov dword ptr [eax], edx
// 00838b04  5b                   pop ebx
// 00838b05  83c408               add esp, 8
// 00838b08  c21400               ret 0x14
// 00838b0b  eb03                 jmp 0x838b10
// 00838b0d  8d4900               lea ecx, [ecx]
// 00838b10  85ff                 test edi, edi
// 00838b12  7406                 je 0x838b1a
// 00838b14  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00838b18  7406                 je 0x838b20
// 00838b1a  ffd5                 call ebp
// 00838b1c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00838b20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00838b24  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00838b28  741d                 je 0x838b47
// 00838b2a  8d4c2420             lea ecx, [esp + 0x20]
// 00838b2e  e8dddfcdff           call 0x516b10
// 00838b33  53                   push ebx
// 00838b34  57                   push edi
// 00838b35  8d442418             lea eax, [esp + 0x18]
// 00838b39  50                   push eax
// 00838b3a  8bce                 mov ecx, esi
// 00838b3c  e8dffbffff           call 0x838720
// 00838b41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00838b45  ebc9                 jmp 0x838b10
// 00838b47  8b36                 mov esi, dword ptr [esi]
// 00838b49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00838b4d  5f                   pop edi
// 00838b4e  8930                 mov dword ptr [eax], esi
// 00838b50  5e                   pop esi
// 00838b51  5d                   pop ebp
// 00838b52  895804               mov dword ptr [eax + 4], ebx
// 00838b55  5b                   pop ebx
// 00838b56  83c408               add esp, 8
// 00838b59  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
