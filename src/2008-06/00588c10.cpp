// from server: 100% by auto
// roc 2008-06 00588c10  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588c10
//
// 00588c10  83ec08               sub esp, 8
// 00588c13  53                   push ebx
// 00588c14  55                   push ebp
// 00588c15  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00588c1b  56                   push esi
// 00588c1c  8bf1                 mov esi, ecx
// 00588c1e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588c21  8b18                 mov ebx, dword ptr [eax]
// 00588c23  8b06                 mov eax, dword ptr [esi]
// 00588c25  57                   push edi
// 00588c26  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588c2a  85ff                 test edi, edi
// 00588c2c  7404                 je 0x588c32
// 00588c2e  3bf8                 cmp edi, eax
// 00588c30  7406                 je 0x588c38
// 00588c32  ffd5                 call ebp
// 00588c34  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588c38  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00588c3c  7562                 jne 0x588ca0
// 00588c3e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00588c42  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00588c45  8b06                 mov eax, dword ptr [esi]
// 00588c47  85c9                 test ecx, ecx
// 00588c49  7404                 je 0x588c4f
// 00588c4b  3bc8                 cmp ecx, eax
// 00588c4d  7406                 je 0x588c55
// 00588c4f  ffd5                 call ebp
// 00588c51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588c55  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00588c59  7545                 jne 0x588ca0
// 00588c5b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00588c5e  8b5104               mov edx, dword ptr [ecx + 4]
// 00588c61  52                   push edx
// 00588c62  8bce                 mov ecx, esi
// 00588c64  e807f1ffff           call 0x587d70
// 00588c69  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588c6c  894004               mov dword ptr [eax + 4], eax
// 00588c6f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588c72  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00588c79  8900                 mov dword ptr [eax], eax
// 00588c7b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588c7e  894008               mov dword ptr [eax + 8], eax
// 00588c81  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588c84  8b16                 mov edx, dword ptr [esi]
// 00588c86  8b08                 mov ecx, dword ptr [eax]
// 00588c88  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00588c8c  5f                   pop edi
// 00588c8d  5e                   pop esi
// 00588c8e  5d                   pop ebp
// 00588c8f  894804               mov dword ptr [eax + 4], ecx
// 00588c92  8910                 mov dword ptr [eax], edx
// 00588c94  5b                   pop ebx
// 00588c95  83c408               add esp, 8
// 00588c98  c21400               ret 0x14
// 00588c9b  eb03                 jmp 0x588ca0
// 00588c9d  8d4900               lea ecx, [ecx]
// 00588ca0  85ff                 test edi, edi
// 00588ca2  7406                 je 0x588caa
// 00588ca4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00588ca8  7406                 je 0x588cb0
// 00588caa  ffd5                 call ebp
// 00588cac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588cb0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00588cb4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00588cb8  741d                 je 0x588cd7
// 00588cba  8d4c2420             lea ecx, [esp + 0x20]
// 00588cbe  e88de50200           call 0x5b7250
// 00588cc3  53                   push ebx
// 00588cc4  57                   push edi
// 00588cc5  8d442418             lea eax, [esp + 0x18]
// 00588cc9  50                   push eax
// 00588cca  8bce                 mov ecx, esi
// 00588ccc  e8dff1ffff           call 0x587eb0
// 00588cd1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00588cd5  ebc9                 jmp 0x588ca0
// 00588cd7  8b36                 mov esi, dword ptr [esi]
// 00588cd9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00588cdd  5f                   pop edi
// 00588cde  8930                 mov dword ptr [eax], esi
// 00588ce0  5e                   pop esi
// 00588ce1  5d                   pop ebp
// 00588ce2  895804               mov dword ptr [eax + 4], ebx
// 00588ce5  5b                   pop ebx
// 00588ce6  83c408               add esp, 8
// 00588ce9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
