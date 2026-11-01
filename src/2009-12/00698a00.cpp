// from server: 100% by auto
// roc 2009-12 00698a00  unit: RBX::$$A6AXABVHeartbeat::?$signal::slot  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00698a00
//
// 00698a00  83ec08               sub esp, 8
// 00698a03  53                   push ebx
// 00698a04  55                   push ebp
// 00698a05  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00698a0b  56                   push esi
// 00698a0c  8bf1                 mov esi, ecx
// 00698a0e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00698a11  8b18                 mov ebx, dword ptr [eax]
// 00698a13  8b06                 mov eax, dword ptr [esi]
// 00698a15  57                   push edi
// 00698a16  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00698a1a  85ff                 test edi, edi
// 00698a1c  7404                 je 0x698a22
// 00698a1e  3bf8                 cmp edi, eax
// 00698a20  7406                 je 0x698a28
// 00698a22  ffd5                 call ebp
// 00698a24  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00698a28  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00698a2c  7562                 jne 0x698a90
// 00698a2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00698a32  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00698a35  8b06                 mov eax, dword ptr [esi]
// 00698a37  85c9                 test ecx, ecx
// 00698a39  7404                 je 0x698a3f
// 00698a3b  3bc8                 cmp ecx, eax
// 00698a3d  7406                 je 0x698a45
// 00698a3f  ffd5                 call ebp
// 00698a41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00698a45  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00698a49  7545                 jne 0x698a90
// 00698a4b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00698a4e  8b5104               mov edx, dword ptr [ecx + 4]
// 00698a51  52                   push edx
// 00698a52  8bce                 mov ecx, esi
// 00698a54  e877fbffff           call 0x6985d0
// 00698a59  8b4618               mov eax, dword ptr [esi + 0x18]
// 00698a5c  894004               mov dword ptr [eax + 4], eax
// 00698a5f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00698a62  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00698a69  8900                 mov dword ptr [eax], eax
// 00698a6b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00698a6e  894008               mov dword ptr [eax + 8], eax
// 00698a71  8b4618               mov eax, dword ptr [esi + 0x18]
// 00698a74  8b16                 mov edx, dword ptr [esi]
// 00698a76  8b08                 mov ecx, dword ptr [eax]
// 00698a78  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00698a7c  5f                   pop edi
// 00698a7d  5e                   pop esi
// 00698a7e  5d                   pop ebp
// 00698a7f  894804               mov dword ptr [eax + 4], ecx
// 00698a82  8910                 mov dword ptr [eax], edx
// 00698a84  5b                   pop ebx
// 00698a85  83c408               add esp, 8
// 00698a88  c21400               ret 0x14
// 00698a8b  eb03                 jmp 0x698a90
// 00698a8d  8d4900               lea ecx, [ecx]
// 00698a90  85ff                 test edi, edi
// 00698a92  7406                 je 0x698a9a
// 00698a94  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00698a98  7406                 je 0x698aa0
// 00698a9a  ffd5                 call ebp
// 00698a9c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00698aa0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00698aa4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00698aa8  741d                 je 0x698ac7
// 00698aaa  8d4c2420             lea ecx, [esp + 0x20]
// 00698aae  e8ad47f3ff           call 0x5cd260
// 00698ab3  53                   push ebx
// 00698ab4  57                   push edi
// 00698ab5  8d442418             lea eax, [esp + 0x18]
// 00698ab9  50                   push eax
// 00698aba  8bce                 mov ecx, esi
// 00698abc  e81ff8ffff           call 0x6982e0
// 00698ac1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00698ac5  ebc9                 jmp 0x698a90
// 00698ac7  8b36                 mov esi, dword ptr [esi]
// 00698ac9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00698acd  5f                   pop edi
// 00698ace  8930                 mov dword ptr [eax], esi
// 00698ad0  5e                   pop esi
// 00698ad1  5d                   pop ebp
// 00698ad2  895804               mov dword ptr [eax + 4], ebx
// 00698ad5  5b                   pop ebx
// 00698ad6  83c408               add esp, 8
// 00698ad9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
