// from server: 100% by auto
// roc 2009-06 0063fa90  unit: RBX::Accoutrement  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063fa90
//
// 0063fa90  83ec08               sub esp, 8
// 0063fa93  53                   push ebx
// 0063fa94  55                   push ebp
// 0063fa95  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0063fa9b  56                   push esi
// 0063fa9c  8bf1                 mov esi, ecx
// 0063fa9e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063faa1  8b18                 mov ebx, dword ptr [eax]
// 0063faa3  8b06                 mov eax, dword ptr [esi]
// 0063faa5  57                   push edi
// 0063faa6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063faaa  85ff                 test edi, edi
// 0063faac  7404                 je 0x63fab2
// 0063faae  3bf8                 cmp edi, eax
// 0063fab0  7406                 je 0x63fab8
// 0063fab2  ffd5                 call ebp
// 0063fab4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063fab8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0063fabc  7562                 jne 0x63fb20
// 0063fabe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0063fac2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0063fac5  8b06                 mov eax, dword ptr [esi]
// 0063fac7  85c9                 test ecx, ecx
// 0063fac9  7404                 je 0x63facf
// 0063facb  3bc8                 cmp ecx, eax
// 0063facd  7406                 je 0x63fad5
// 0063facf  ffd5                 call ebp
// 0063fad1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063fad5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0063fad9  7545                 jne 0x63fb20
// 0063fadb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063fade  8b5104               mov edx, dword ptr [ecx + 4]
// 0063fae1  52                   push edx
// 0063fae2  8bce                 mov ecx, esi
// 0063fae4  e807f8ffff           call 0x63f2f0
// 0063fae9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063faec  894004               mov dword ptr [eax + 4], eax
// 0063faef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063faf2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0063faf9  8900                 mov dword ptr [eax], eax
// 0063fafb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063fafe  894008               mov dword ptr [eax + 8], eax
// 0063fb01  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063fb04  8b16                 mov edx, dword ptr [esi]
// 0063fb06  8b08                 mov ecx, dword ptr [eax]
// 0063fb08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063fb0c  5f                   pop edi
// 0063fb0d  5e                   pop esi
// 0063fb0e  5d                   pop ebp
// 0063fb0f  894804               mov dword ptr [eax + 4], ecx
// 0063fb12  8910                 mov dword ptr [eax], edx
// 0063fb14  5b                   pop ebx
// 0063fb15  83c408               add esp, 8
// 0063fb18  c21400               ret 0x14
// 0063fb1b  eb03                 jmp 0x63fb20
// 0063fb1d  8d4900               lea ecx, [ecx]
// 0063fb20  85ff                 test edi, edi
// 0063fb22  7406                 je 0x63fb2a
// 0063fb24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0063fb28  7406                 je 0x63fb30
// 0063fb2a  ffd5                 call ebp
// 0063fb2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063fb30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0063fb34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0063fb38  741d                 je 0x63fb57
// 0063fb3a  8d4c2420             lea ecx, [esp + 0x20]
// 0063fb3e  e8cdeeffff           call 0x63ea10
// 0063fb43  53                   push ebx
// 0063fb44  57                   push edi
// 0063fb45  8d442418             lea eax, [esp + 0x18]
// 0063fb49  50                   push eax
// 0063fb4a  8bce                 mov ecx, esi
// 0063fb4c  e8bff4ffff           call 0x63f010
// 0063fb51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0063fb55  ebc9                 jmp 0x63fb20
// 0063fb57  8b36                 mov esi, dword ptr [esi]
// 0063fb59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063fb5d  5f                   pop edi
// 0063fb5e  8930                 mov dword ptr [eax], esi
// 0063fb60  5e                   pop esi
// 0063fb61  5d                   pop ebp
// 0063fb62  895804               mov dword ptr [eax + 4], ebx
// 0063fb65  5b                   pop ebx
// 0063fb66  83c408               add esp, 8
// 0063fb69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
