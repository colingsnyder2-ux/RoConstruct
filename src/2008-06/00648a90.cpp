// from server: 100% by auto
// roc 2008-06 00648a90  unit: RBX::Block  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648a90
//
// 00648a90  83ec08               sub esp, 8
// 00648a93  53                   push ebx
// 00648a94  55                   push ebp
// 00648a95  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00648a9b  56                   push esi
// 00648a9c  8bf1                 mov esi, ecx
// 00648a9e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648aa1  8b18                 mov ebx, dword ptr [eax]
// 00648aa3  8b06                 mov eax, dword ptr [esi]
// 00648aa5  57                   push edi
// 00648aa6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00648aaa  85ff                 test edi, edi
// 00648aac  7404                 je 0x648ab2
// 00648aae  3bf8                 cmp edi, eax
// 00648ab0  7406                 je 0x648ab8
// 00648ab2  ffd5                 call ebp
// 00648ab4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00648ab8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00648abc  7562                 jne 0x648b20
// 00648abe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00648ac2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00648ac5  8b06                 mov eax, dword ptr [esi]
// 00648ac7  85c9                 test ecx, ecx
// 00648ac9  7404                 je 0x648acf
// 00648acb  3bc8                 cmp ecx, eax
// 00648acd  7406                 je 0x648ad5
// 00648acf  ffd5                 call ebp
// 00648ad1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00648ad5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00648ad9  7545                 jne 0x648b20
// 00648adb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00648ade  8b5104               mov edx, dword ptr [ecx + 4]
// 00648ae1  52                   push edx
// 00648ae2  8bce                 mov ecx, esi
// 00648ae4  e867f9ffff           call 0x648450
// 00648ae9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648aec  894004               mov dword ptr [eax + 4], eax
// 00648aef  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648af2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00648af9  8900                 mov dword ptr [eax], eax
// 00648afb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648afe  894008               mov dword ptr [eax + 8], eax
// 00648b01  8b4618               mov eax, dword ptr [esi + 0x18]
// 00648b04  8b16                 mov edx, dword ptr [esi]
// 00648b06  8b08                 mov ecx, dword ptr [eax]
// 00648b08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00648b0c  5f                   pop edi
// 00648b0d  5e                   pop esi
// 00648b0e  5d                   pop ebp
// 00648b0f  894804               mov dword ptr [eax + 4], ecx
// 00648b12  8910                 mov dword ptr [eax], edx
// 00648b14  5b                   pop ebx
// 00648b15  83c408               add esp, 8
// 00648b18  c21400               ret 0x14
// 00648b1b  eb03                 jmp 0x648b20
// 00648b1d  8d4900               lea ecx, [ecx]
// 00648b20  85ff                 test edi, edi
// 00648b22  7406                 je 0x648b2a
// 00648b24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00648b28  7406                 je 0x648b30
// 00648b2a  ffd5                 call ebp
// 00648b2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00648b30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00648b34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00648b38  741d                 je 0x648b57
// 00648b3a  8d4c2420             lea ecx, [esp + 0x20]
// 00648b3e  e8ddf5ffff           call 0x648120
// 00648b43  53                   push ebx
// 00648b44  57                   push edi
// 00648b45  8d442418             lea eax, [esp + 0x18]
// 00648b49  50                   push eax
// 00648b4a  8bce                 mov ecx, esi
// 00648b4c  e83ffbffff           call 0x648690
// 00648b51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00648b55  ebc9                 jmp 0x648b20
// 00648b57  8b36                 mov esi, dword ptr [esi]
// 00648b59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00648b5d  5f                   pop edi
// 00648b5e  8930                 mov dword ptr [eax], esi
// 00648b60  5e                   pop esi
// 00648b61  5d                   pop ebp
// 00648b62  895804               mov dword ptr [eax + 4], ebx
// 00648b65  5b                   pop ebx
// 00648b66  83c408               add esp, 8
// 00648b69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
