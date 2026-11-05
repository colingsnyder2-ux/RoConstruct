// from server: 100% by auto
// roc 2009-12 0054db80  unit: RBX::Network::VReplicator::?$EventDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054db80
//
// 0054db80  83ec08               sub esp, 8
// 0054db83  53                   push ebx
// 0054db84  55                   push ebp
// 0054db85  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0054db8b  56                   push esi
// 0054db8c  8bf1                 mov esi, ecx
// 0054db8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054db91  8b18                 mov ebx, dword ptr [eax]
// 0054db93  8b06                 mov eax, dword ptr [esi]
// 0054db95  57                   push edi
// 0054db96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054db9a  85ff                 test edi, edi
// 0054db9c  7404                 je 0x54dba2
// 0054db9e  3bf8                 cmp edi, eax
// 0054dba0  7406                 je 0x54dba8
// 0054dba2  ffd5                 call ebp
// 0054dba4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054dba8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0054dbac  7562                 jne 0x54dc10
// 0054dbae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0054dbb2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0054dbb5  8b06                 mov eax, dword ptr [esi]
// 0054dbb7  85c9                 test ecx, ecx
// 0054dbb9  7404                 je 0x54dbbf
// 0054dbbb  3bc8                 cmp ecx, eax
// 0054dbbd  7406                 je 0x54dbc5
// 0054dbbf  ffd5                 call ebp
// 0054dbc1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054dbc5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0054dbc9  7545                 jne 0x54dc10
// 0054dbcb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0054dbce  8b5104               mov edx, dword ptr [ecx + 4]
// 0054dbd1  52                   push edx
// 0054dbd2  8bce                 mov ecx, esi
// 0054dbd4  e8d7d8ffff           call 0x54b4b0
// 0054dbd9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054dbdc  894004               mov dword ptr [eax + 4], eax
// 0054dbdf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054dbe2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0054dbe9  8900                 mov dword ptr [eax], eax
// 0054dbeb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054dbee  894008               mov dword ptr [eax + 8], eax
// 0054dbf1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054dbf4  8b16                 mov edx, dword ptr [esi]
// 0054dbf6  8b08                 mov ecx, dword ptr [eax]
// 0054dbf8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054dbfc  5f                   pop edi
// 0054dbfd  5e                   pop esi
// 0054dbfe  5d                   pop ebp
// 0054dbff  894804               mov dword ptr [eax + 4], ecx
// 0054dc02  8910                 mov dword ptr [eax], edx
// 0054dc04  5b                   pop ebx
// 0054dc05  83c408               add esp, 8
// 0054dc08  c21400               ret 0x14
// 0054dc0b  eb03                 jmp 0x54dc10
// 0054dc0d  8d4900               lea ecx, [ecx]
// 0054dc10  85ff                 test edi, edi
// 0054dc12  7406                 je 0x54dc1a
// 0054dc14  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0054dc18  7406                 je 0x54dc20
// 0054dc1a  ffd5                 call ebp
// 0054dc1c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054dc20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0054dc24  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0054dc28  741d                 je 0x54dc47
// 0054dc2a  8d4c2420             lea ecx, [esp + 0x20]
// 0054dc2e  e8ddccf2ff           call 0x47a910
// 0054dc33  53                   push ebx
// 0054dc34  57                   push edi
// 0054dc35  8d442418             lea eax, [esp + 0x18]
// 0054dc39  50                   push eax
// 0054dc3a  8bce                 mov ecx, esi
// 0054dc3c  e80f8bfeff           call 0x536750
// 0054dc41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054dc45  ebc9                 jmp 0x54dc10
// 0054dc47  8b36                 mov esi, dword ptr [esi]
// 0054dc49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054dc4d  5f                   pop edi
// 0054dc4e  8930                 mov dword ptr [eax], esi
// 0054dc50  5e                   pop esi
// 0054dc51  5d                   pop ebp
// 0054dc52  895804               mov dword ptr [eax + 4], ebx
// 0054dc55  5b                   pop ebx
// 0054dc56  83c408               add esp, 8
// 0054dc59  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
