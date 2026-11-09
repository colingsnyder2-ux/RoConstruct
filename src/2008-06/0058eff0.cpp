// from server: 100% by auto
// roc 2008-06 0058eff0  unit: TextXmlWriter  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058eff0
//
// 0058eff0  83ec14               sub esp, 0x14
// 0058eff3  56                   push esi
// 0058eff4  8bf1                 mov esi, ecx
// 0058eff6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0058effa  57                   push edi
// 0058effb  7521                 jne 0x58f01e
// 0058effd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0058f001  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0058f004  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058f008  50                   push eax
// 0058f009  51                   push ecx
// 0058f00a  6a01                 push 1
// 0058f00c  57                   push edi
// 0058f00d  8bce                 mov ecx, esi
// 0058f00f  e80cf8ffff           call 0x58e820
// 0058f014  8bc7                 mov eax, edi
// 0058f016  5f                   pop edi
// 0058f017  5e                   pop esi
// 0058f018  83c414               add esp, 0x14
// 0058f01b  c21000               ret 0x10
// 0058f01e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058f022  8b5618               mov edx, dword ptr [esi + 0x18]
// 0058f025  8b3a                 mov edi, dword ptr [edx]
// 0058f027  8b0e                 mov ecx, dword ptr [esi]
// 0058f029  53                   push ebx
// 0058f02a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0058f030  85c0                 test eax, eax
// 0058f032  7404                 je 0x58f038
// 0058f034  3bc1                 cmp eax, ecx
// 0058f036  7406                 je 0x58f03e
// 0058f038  ffd3                 call ebx
// 0058f03a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058f03e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0058f042  55                   push ebp
// 0058f043  3bd7                 cmp edx, edi
// 0058f045  753a                 jne 0x58f081
// 0058f047  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0058f04b  83c20c               add edx, 0xc
// 0058f04e  52                   push edx
// 0058f04f  57                   push edi
// 0058f050  ff155c238000         call dword ptr [0x80235c]
// 0058f056  83c408               add esp, 8
// 0058f059  84c0                 test al, al
// 0058f05b  0f849a010000         je 0x58f1fb
// 0058f061  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058f065  57                   push edi
// 0058f066  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058f06a  50                   push eax
// 0058f06b  6a01                 push 1
// 0058f06d  57                   push edi
// 0058f06e  8bce                 mov ecx, esi
// 0058f070  e8abf7ffff           call 0x58e820
// 0058f075  5d                   pop ebp
// 0058f076  5b                   pop ebx
// 0058f077  8bc7                 mov eax, edi
// 0058f079  5f                   pop edi
// 0058f07a  5e                   pop esi
// 0058f07b  83c414               add esp, 0x14
// 0058f07e  c21000               ret 0x10
// 0058f081  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0058f084  8b0e                 mov ecx, dword ptr [esi]
// 0058f086  85c0                 test eax, eax
// 0058f088  7404                 je 0x58f08e
// 0058f08a  3bc1                 cmp eax, ecx
// 0058f08c  7406                 je 0x58f094
// 0058f08e  ffd3                 call ebx
// 0058f090  8b542430             mov edx, dword ptr [esp + 0x30]
// 0058f094  3bd7                 cmp edx, edi
// 0058f096  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0058f09a  753e                 jne 0x58f0da
// 0058f09c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0058f09f  8b4108               mov eax, dword ptr [ecx + 8]
// 0058f0a2  83c00c               add eax, 0xc
// 0058f0a5  57                   push edi
// 0058f0a6  50                   push eax
// 0058f0a7  ff155c238000         call dword ptr [0x80235c]
// 0058f0ad  83c408               add esp, 8
// 0058f0b0  84c0                 test al, al
// 0058f0b2  0f8443010000         je 0x58f1fb
// 0058f0b8  8b5618               mov edx, dword ptr [esi + 0x18]
// 0058f0bb  8b4208               mov eax, dword ptr [edx + 8]
// 0058f0be  57                   push edi
// 0058f0bf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058f0c3  50                   push eax
// 0058f0c4  6a00                 push 0
// 0058f0c6  57                   push edi
// 0058f0c7  8bce                 mov ecx, esi
// 0058f0c9  e852f7ffff           call 0x58e820
// 0058f0ce  5d                   pop ebp
// 0058f0cf  5b                   pop ebx
// 0058f0d0  8bc7                 mov eax, edi
// 0058f0d2  5f                   pop edi
// 0058f0d3  5e                   pop esi
// 0058f0d4  83c414               add esp, 0x14
// 0058f0d7  c21000               ret 0x10
// 0058f0da  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 0058f0e0  83c20c               add edx, 0xc
// 0058f0e3  52                   push edx
// 0058f0e4  57                   push edi
// 0058f0e5  ffd5                 call ebp
// 0058f0e7  83c408               add esp, 8
// 0058f0ea  84c0                 test al, al
// 0058f0ec  746c                 je 0x58f15a
// 0058f0ee  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0058f0f2  8b542430             mov edx, dword ptr [esp + 0x30]
// 0058f0f6  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058f0fa  8d4c2410             lea ecx, [esp + 0x10]
// 0058f0fe  89542414             mov dword ptr [esp + 0x14], edx
// 0058f102  e8e9e5ffff           call 0x58d6f0
// 0058f107  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0058f10b  57                   push edi
// 0058f10c  8d430c               lea eax, [ebx + 0xc]
// 0058f10f  50                   push eax
// 0058f110  8d4e08               lea ecx, [esi + 8]
// 0058f113  e8e8cefcff           call 0x55c000
// 0058f118  84c0                 test al, al
// 0058f11a  743e                 je 0x58f15a
// 0058f11c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0058f11f  80794500             cmp byte ptr [ecx + 0x45], 0
// 0058f123  57                   push edi
// 0058f124  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058f128  8bce                 mov ecx, esi
// 0058f12a  7415                 je 0x58f141
// 0058f12c  53                   push ebx
// 0058f12d  6a00                 push 0
// 0058f12f  57                   push edi
// 0058f130  e8ebf6ffff           call 0x58e820
// 0058f135  5d                   pop ebp
// 0058f136  5b                   pop ebx
// 0058f137  8bc7                 mov eax, edi
// 0058f139  5f                   pop edi
// 0058f13a  5e                   pop esi
// 0058f13b  83c414               add esp, 0x14
// 0058f13e  c21000               ret 0x10
// 0058f141  8b542434             mov edx, dword ptr [esp + 0x34]
// 0058f145  52                   push edx
// 0058f146  6a01                 push 1
// 0058f148  57                   push edi
// 0058f149  e8d2f6ffff           call 0x58e820
// 0058f14e  5d                   pop ebp
// 0058f14f  5b                   pop ebx
// 0058f150  8bc7                 mov eax, edi
// 0058f152  5f                   pop edi
// 0058f153  5e                   pop esi
// 0058f154  83c414               add esp, 0x14
// 0058f157  c21000               ret 0x10
// 0058f15a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058f15e  83c00c               add eax, 0xc
// 0058f161  57                   push edi
// 0058f162  50                   push eax
// 0058f163  ffd5                 call ebp
// 0058f165  83c408               add esp, 8
// 0058f168  84c0                 test al, al
// 0058f16a  0f848b000000         je 0x58f1fb
// 0058f170  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0058f174  8b542430             mov edx, dword ptr [esp + 0x30]
// 0058f178  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058f17b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0058f17f  8b0e                 mov ecx, dword ptr [esi]
// 0058f181  894c2418             mov dword ptr [esp + 0x18], ecx
// 0058f185  8d4c2410             lea ecx, [esp + 0x10]
// 0058f189  89542414             mov dword ptr [esp + 0x14], edx
// 0058f18d  8944241c             mov dword ptr [esp + 0x1c], eax
// 0058f191  e81a48e8ff           call 0x4139b0
// 0058f196  8d542418             lea edx, [esp + 0x18]
// 0058f19a  52                   push edx
// 0058f19b  8d4c2414             lea ecx, [esp + 0x14]
// 0058f19f  e8fcda0500           call 0x5ecca0
// 0058f1a4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0058f1a8  84c0                 test al, al
// 0058f1aa  7511                 jne 0x58f1bd
// 0058f1ac  8d430c               lea eax, [ebx + 0xc]
// 0058f1af  50                   push eax
// 0058f1b0  57                   push edi
// 0058f1b1  8d4e08               lea ecx, [esi + 8]
// 0058f1b4  e847cefcff           call 0x55c000
// 0058f1b9  84c0                 test al, al
// 0058f1bb  743e                 je 0x58f1fb
// 0058f1bd  8b442430             mov eax, dword ptr [esp + 0x30]
// 0058f1c1  8b4808               mov ecx, dword ptr [eax + 8]
// 0058f1c4  80794500             cmp byte ptr [ecx + 0x45], 0
// 0058f1c8  57                   push edi
// 0058f1c9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058f1cd  8bce                 mov ecx, esi
// 0058f1cf  7415                 je 0x58f1e6
// 0058f1d1  50                   push eax
// 0058f1d2  6a00                 push 0
// 0058f1d4  57                   push edi
// 0058f1d5  e846f6ffff           call 0x58e820
// 0058f1da  5d                   pop ebp
// 0058f1db  5b                   pop ebx
// 0058f1dc  8bc7                 mov eax, edi
// 0058f1de  5f                   pop edi
// 0058f1df  5e                   pop esi
// 0058f1e0  83c414               add esp, 0x14
// 0058f1e3  c21000               ret 0x10
// 0058f1e6  53                   push ebx
// 0058f1e7  6a01                 push 1
// 0058f1e9  57                   push edi
// 0058f1ea  e831f6ffff           call 0x58e820
// 0058f1ef  5d                   pop ebp
// 0058f1f0  5b                   pop ebx
// 0058f1f1  8bc7                 mov eax, edi
// 0058f1f3  5f                   pop edi
// 0058f1f4  5e                   pop esi
// 0058f1f5  83c414               add esp, 0x14
// 0058f1f8  c21000               ret 0x10
// 0058f1fb  57                   push edi
// 0058f1fc  8d54241c             lea edx, [esp + 0x1c]
// 0058f200  52                   push edx
// 0058f201  8bce                 mov ecx, esi
// 0058f203  e818f8ffff           call 0x58ea20
// 0058f208  8b10                 mov edx, dword ptr [eax]
// 0058f20a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058f20e  5d                   pop ebp
// 0058f20f  5b                   pop ebx
// 0058f210  8911                 mov dword ptr [ecx], edx
// 0058f212  8b4004               mov eax, dword ptr [eax + 4]
// 0058f215  5f                   pop edi
// 0058f216  894104               mov dword ptr [ecx + 4], eax
// 0058f219  8bc1                 mov eax, ecx
// 0058f21b  5e                   pop esi
// 0058f21c  83c414               add esp, 0x14
// 0058f21f  c21000               ret 0x10
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
