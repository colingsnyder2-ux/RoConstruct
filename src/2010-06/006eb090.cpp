// from server: 100% by auto
// roc 2010-06 006eb090  unit: RBX::VBadgeService::?$BoundFuncDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006eb090
//
// 006eb090  83ec14               sub esp, 0x14
// 006eb093  56                   push esi
// 006eb094  8bf1                 mov esi, ecx
// 006eb096  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006eb09a  57                   push edi
// 006eb09b  7521                 jne 0x6eb0be
// 006eb09d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006eb0a1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006eb0a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006eb0a8  50                   push eax
// 006eb0a9  51                   push ecx
// 006eb0aa  6a01                 push 1
// 006eb0ac  57                   push edi
// 006eb0ad  8bce                 mov ecx, esi
// 006eb0af  e82ce9ffff           call 0x6e99e0
// 006eb0b4  8bc7                 mov eax, edi
// 006eb0b6  5f                   pop edi
// 006eb0b7  5e                   pop esi
// 006eb0b8  83c414               add esp, 0x14
// 006eb0bb  c21000               ret 0x10
// 006eb0be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006eb0c2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006eb0c5  8b3a                 mov edi, dword ptr [edx]
// 006eb0c7  8b06                 mov eax, dword ptr [esi]
// 006eb0c9  53                   push ebx
// 006eb0ca  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006eb0d0  85c9                 test ecx, ecx
// 006eb0d2  7404                 je 0x6eb0d8
// 006eb0d4  3bc8                 cmp ecx, eax
// 006eb0d6  7406                 je 0x6eb0de
// 006eb0d8  ffd3                 call ebx
// 006eb0da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006eb0de  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006eb0e2  3bc7                 cmp eax, edi
// 006eb0e4  752a                 jne 0x6eb110
// 006eb0e6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006eb0ea  8b0f                 mov ecx, dword ptr [edi]
// 006eb0ec  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006eb0ef  0f8d4b010000         jge 0x6eb240
// 006eb0f5  57                   push edi
// 006eb0f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006eb0fa  50                   push eax
// 006eb0fb  6a01                 push 1
// 006eb0fd  57                   push edi
// 006eb0fe  8bce                 mov ecx, esi
// 006eb100  e8dbe8ffff           call 0x6e99e0
// 006eb105  5b                   pop ebx
// 006eb106  8bc7                 mov eax, edi
// 006eb108  5f                   pop edi
// 006eb109  5e                   pop esi
// 006eb10a  83c414               add esp, 0x14
// 006eb10d  c21000               ret 0x10
// 006eb110  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006eb113  8b16                 mov edx, dword ptr [esi]
// 006eb115  85c9                 test ecx, ecx
// 006eb117  7404                 je 0x6eb11d
// 006eb119  3bca                 cmp ecx, edx
// 006eb11b  740a                 je 0x6eb127
// 006eb11d  ffd3                 call ebx
// 006eb11f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006eb123  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006eb127  3bc7                 cmp eax, edi
// 006eb129  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006eb12d  752c                 jne 0x6eb15b
// 006eb12f  8b5618               mov edx, dword ptr [esi + 0x18]
// 006eb132  8b4208               mov eax, dword ptr [edx + 8]
// 006eb135  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006eb138  3b0f                 cmp ecx, dword ptr [edi]
// 006eb13a  0f8d00010000         jge 0x6eb240
// 006eb140  57                   push edi
// 006eb141  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006eb145  50                   push eax
// 006eb146  6a00                 push 0
// 006eb148  57                   push edi
// 006eb149  8bce                 mov ecx, esi
// 006eb14b  e890e8ffff           call 0x6e99e0
// 006eb150  5b                   pop ebx
// 006eb151  8bc7                 mov eax, edi
// 006eb153  5f                   pop edi
// 006eb154  5e                   pop esi
// 006eb155  83c414               add esp, 0x14
// 006eb158  c21000               ret 0x10
// 006eb15b  8b17                 mov edx, dword ptr [edi]
// 006eb15d  39500c               cmp dword ptr [eax + 0xc], edx
// 006eb160  7e63                 jle 0x6eb1c5
// 006eb162  894c240c             mov dword ptr [esp + 0xc], ecx
// 006eb166  8d4c240c             lea ecx, [esp + 0xc]
// 006eb16a  89442410             mov dword ptr [esp + 0x10], eax
// 006eb16e  e86d83d8ff           call 0x4734e0
// 006eb173  8b17                 mov edx, dword ptr [edi]
// 006eb175  8b442410             mov eax, dword ptr [esp + 0x10]
// 006eb179  39500c               cmp dword ptr [eax + 0xc], edx
// 006eb17c  7d3c                 jge 0x6eb1ba
// 006eb17e  8b5008               mov edx, dword ptr [eax + 8]
// 006eb181  807a3100             cmp byte ptr [edx + 0x31], 0
// 006eb185  57                   push edi
// 006eb186  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006eb18a  8bce                 mov ecx, esi
// 006eb18c  7414                 je 0x6eb1a2
// 006eb18e  50                   push eax
// 006eb18f  6a00                 push 0
// 006eb191  57                   push edi
// 006eb192  e849e8ffff           call 0x6e99e0
// 006eb197  5b                   pop ebx
// 006eb198  8bc7                 mov eax, edi
// 006eb19a  5f                   pop edi
// 006eb19b  5e                   pop esi
// 006eb19c  83c414               add esp, 0x14
// 006eb19f  c21000               ret 0x10
// 006eb1a2  8b442430             mov eax, dword ptr [esp + 0x30]
// 006eb1a6  50                   push eax
// 006eb1a7  6a01                 push 1
// 006eb1a9  57                   push edi
// 006eb1aa  e831e8ffff           call 0x6e99e0
// 006eb1af  5b                   pop ebx
// 006eb1b0  8bc7                 mov eax, edi
// 006eb1b2  5f                   pop edi
// 006eb1b3  5e                   pop esi
// 006eb1b4  83c414               add esp, 0x14
// 006eb1b7  c21000               ret 0x10
// 006eb1ba  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006eb1be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006eb1c2  39500c               cmp dword ptr [eax + 0xc], edx
// 006eb1c5  7d79                 jge 0x6eb240
// 006eb1c7  8b16                 mov edx, dword ptr [esi]
// 006eb1c9  894c240c             mov dword ptr [esp + 0xc], ecx
// 006eb1cd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006eb1d0  894c2418             mov dword ptr [esp + 0x18], ecx
// 006eb1d4  8d4c240c             lea ecx, [esp + 0xc]
// 006eb1d8  89442410             mov dword ptr [esp + 0x10], eax
// 006eb1dc  89542414             mov dword ptr [esp + 0x14], edx
// 006eb1e0  e8cb42f7ff           call 0x65f4b0
// 006eb1e5  8d442414             lea eax, [esp + 0x14]
// 006eb1e9  50                   push eax
// 006eb1ea  8d4c2410             lea ecx, [esp + 0x10]
// 006eb1ee  e88dbdd7ff           call 0x466f80
// 006eb1f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006eb1f7  84c0                 test al, al
// 006eb1f9  7507                 jne 0x6eb202
// 006eb1fb  8b17                 mov edx, dword ptr [edi]
// 006eb1fd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006eb200  7d3e                 jge 0x6eb240
// 006eb202  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006eb206  8b5008               mov edx, dword ptr [eax + 8]
// 006eb209  807a3100             cmp byte ptr [edx + 0x31], 0
// 006eb20d  57                   push edi
// 006eb20e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006eb212  7416                 je 0x6eb22a
// 006eb214  50                   push eax
// 006eb215  6a00                 push 0
// 006eb217  57                   push edi
// 006eb218  8bce                 mov ecx, esi
// 006eb21a  e8c1e7ffff           call 0x6e99e0
// 006eb21f  5b                   pop ebx
// 006eb220  8bc7                 mov eax, edi
// 006eb222  5f                   pop edi
// 006eb223  5e                   pop esi
// 006eb224  83c414               add esp, 0x14
// 006eb227  c21000               ret 0x10
// 006eb22a  51                   push ecx
// 006eb22b  6a01                 push 1
// 006eb22d  57                   push edi
// 006eb22e  8bce                 mov ecx, esi
// 006eb230  e8abe7ffff           call 0x6e99e0
// 006eb235  5b                   pop ebx
// 006eb236  8bc7                 mov eax, edi
// 006eb238  5f                   pop edi
// 006eb239  5e                   pop esi
// 006eb23a  83c414               add esp, 0x14
// 006eb23d  c21000               ret 0x10
// 006eb240  57                   push edi
// 006eb241  8d442418             lea eax, [esp + 0x18]
// 006eb245  50                   push eax
// 006eb246  8bce                 mov ecx, esi
// 006eb248  e853f6ffff           call 0x6ea8a0
// 006eb24d  8b10                 mov edx, dword ptr [eax]
// 006eb24f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006eb253  5b                   pop ebx
// 006eb254  8911                 mov dword ptr [ecx], edx
// 006eb256  8b4004               mov eax, dword ptr [eax + 4]
// 006eb259  5f                   pop edi
// 006eb25a  894104               mov dword ptr [ecx + 4], eax
// 006eb25d  8bc1                 mov eax, ecx
// 006eb25f  5e                   pop esi
// 006eb260  83c414               add esp, 0x14
// 006eb263  c21000               ret 0x10
// standard library map_int<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
