// from server: 100% by auto
// roc 2009-12 0053c9f0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053c9f0
//
// 0053c9f0  83ec08               sub esp, 8
// 0053c9f3  53                   push ebx
// 0053c9f4  55                   push ebp
// 0053c9f5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0053c9fb  56                   push esi
// 0053c9fc  8bf1                 mov esi, ecx
// 0053c9fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ca01  8b18                 mov ebx, dword ptr [eax]
// 0053ca03  8b06                 mov eax, dword ptr [esi]
// 0053ca05  57                   push edi
// 0053ca06  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ca0a  85ff                 test edi, edi
// 0053ca0c  7404                 je 0x53ca12
// 0053ca0e  3bf8                 cmp edi, eax
// 0053ca10  7406                 je 0x53ca18
// 0053ca12  ffd5                 call ebp
// 0053ca14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ca18  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0053ca1c  7562                 jne 0x53ca80
// 0053ca1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053ca22  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0053ca25  8b06                 mov eax, dword ptr [esi]
// 0053ca27  85c9                 test ecx, ecx
// 0053ca29  7404                 je 0x53ca2f
// 0053ca2b  3bc8                 cmp ecx, eax
// 0053ca2d  7406                 je 0x53ca35
// 0053ca2f  ffd5                 call ebp
// 0053ca31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ca35  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0053ca39  7545                 jne 0x53ca80
// 0053ca3b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053ca3e  8b5104               mov edx, dword ptr [ecx + 4]
// 0053ca41  52                   push edx
// 0053ca42  8bce                 mov ecx, esi
// 0053ca44  e887ccffff           call 0x5396d0
// 0053ca49  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ca4c  894004               mov dword ptr [eax + 4], eax
// 0053ca4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ca52  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053ca59  8900                 mov dword ptr [eax], eax
// 0053ca5b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ca5e  894008               mov dword ptr [eax + 8], eax
// 0053ca61  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ca64  8b16                 mov edx, dword ptr [esi]
// 0053ca66  8b08                 mov ecx, dword ptr [eax]
// 0053ca68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053ca6c  5f                   pop edi
// 0053ca6d  5e                   pop esi
// 0053ca6e  5d                   pop ebp
// 0053ca6f  894804               mov dword ptr [eax + 4], ecx
// 0053ca72  8910                 mov dword ptr [eax], edx
// 0053ca74  5b                   pop ebx
// 0053ca75  83c408               add esp, 8
// 0053ca78  c21400               ret 0x14
// 0053ca7b  eb03                 jmp 0x53ca80
// 0053ca7d  8d4900               lea ecx, [ecx]
// 0053ca80  85ff                 test edi, edi
// 0053ca82  7406                 je 0x53ca8a
// 0053ca84  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0053ca88  7406                 je 0x53ca90
// 0053ca8a  ffd5                 call ebp
// 0053ca8c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ca90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053ca94  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0053ca98  741d                 je 0x53cab7
// 0053ca9a  8d4c2420             lea ecx, [esp + 0x20]
// 0053ca9e  e8ddbaffff           call 0x538580
// 0053caa3  53                   push ebx
// 0053caa4  57                   push edi
// 0053caa5  8d442418             lea eax, [esp + 0x18]
// 0053caa9  50                   push eax
// 0053caaa  8bce                 mov ecx, esi
// 0053caac  e81fe0ffff           call 0x53aad0
// 0053cab1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053cab5  ebc9                 jmp 0x53ca80
// 0053cab7  8b36                 mov esi, dword ptr [esi]
// 0053cab9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053cabd  5f                   pop edi
// 0053cabe  8930                 mov dword ptr [eax], esi
// 0053cac0  5e                   pop esi
// 0053cac1  5d                   pop ebp
// 0053cac2  895804               mov dword ptr [eax + 4], ebx
// 0053cac5  5b                   pop ebx
// 0053cac6  83c408               add esp, 8
// 0053cac9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
