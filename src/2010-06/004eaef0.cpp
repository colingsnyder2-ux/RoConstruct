// from server: 100% by auto
// roc 2010-06 004eaef0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004eaef0
//
// 004eaef0  83ec08               sub esp, 8
// 004eaef3  53                   push ebx
// 004eaef4  55                   push ebp
// 004eaef5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004eaefb  56                   push esi
// 004eaefc  8bf1                 mov esi, ecx
// 004eaefe  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eaf01  8b18                 mov ebx, dword ptr [eax]
// 004eaf03  8b06                 mov eax, dword ptr [esi]
// 004eaf05  57                   push edi
// 004eaf06  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004eaf0a  85ff                 test edi, edi
// 004eaf0c  7404                 je 0x4eaf12
// 004eaf0e  3bf8                 cmp edi, eax
// 004eaf10  7406                 je 0x4eaf18
// 004eaf12  ffd5                 call ebp
// 004eaf14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004eaf18  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004eaf1c  7562                 jne 0x4eaf80
// 004eaf1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004eaf22  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004eaf25  8b06                 mov eax, dword ptr [esi]
// 004eaf27  85c9                 test ecx, ecx
// 004eaf29  7404                 je 0x4eaf2f
// 004eaf2b  3bc8                 cmp ecx, eax
// 004eaf2d  7406                 je 0x4eaf35
// 004eaf2f  ffd5                 call ebp
// 004eaf31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004eaf35  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004eaf39  7545                 jne 0x4eaf80
// 004eaf3b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004eaf3e  8b5104               mov edx, dword ptr [ecx + 4]
// 004eaf41  52                   push edx
// 004eaf42  8bce                 mov ecx, esi
// 004eaf44  e8a71affff           call 0x4dc9f0
// 004eaf49  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eaf4c  894004               mov dword ptr [eax + 4], eax
// 004eaf4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eaf52  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004eaf59  8900                 mov dword ptr [eax], eax
// 004eaf5b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eaf5e  894008               mov dword ptr [eax + 8], eax
// 004eaf61  8b4618               mov eax, dword ptr [esi + 0x18]
// 004eaf64  8b16                 mov edx, dword ptr [esi]
// 004eaf66  8b08                 mov ecx, dword ptr [eax]
// 004eaf68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004eaf6c  5f                   pop edi
// 004eaf6d  5e                   pop esi
// 004eaf6e  5d                   pop ebp
// 004eaf6f  894804               mov dword ptr [eax + 4], ecx
// 004eaf72  8910                 mov dword ptr [eax], edx
// 004eaf74  5b                   pop ebx
// 004eaf75  83c408               add esp, 8
// 004eaf78  c21400               ret 0x14
// 004eaf7b  eb03                 jmp 0x4eaf80
// 004eaf7d  8d4900               lea ecx, [ecx]
// 004eaf80  85ff                 test edi, edi
// 004eaf82  7406                 je 0x4eaf8a
// 004eaf84  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004eaf88  7406                 je 0x4eaf90
// 004eaf8a  ffd5                 call ebp
// 004eaf8c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004eaf90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004eaf94  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004eaf98  741d                 je 0x4eafb7
// 004eaf9a  8d4c2420             lea ecx, [esp + 0x20]
// 004eaf9e  e88dbaffff           call 0x4e6a30
// 004eafa3  53                   push ebx
// 004eafa4  57                   push edi
// 004eafa5  8d442418             lea eax, [esp + 0x18]
// 004eafa9  50                   push eax
// 004eafaa  8bce                 mov ecx, esi
// 004eafac  e83fe0ffff           call 0x4e8ff0
// 004eafb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004eafb5  ebc9                 jmp 0x4eaf80
// 004eafb7  8b36                 mov esi, dword ptr [esi]
// 004eafb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004eafbd  5f                   pop edi
// 004eafbe  8930                 mov dword ptr [eax], esi
// 004eafc0  5e                   pop esi
// 004eafc1  5d                   pop ebp
// 004eafc2  895804               mov dword ptr [eax + 4], ebx
// 004eafc5  5b                   pop ebx
// 004eafc6  83c408               add esp, 8
// 004eafc9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
