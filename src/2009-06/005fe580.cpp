// from server: 100% by auto
// roc 2009-06 005fe580  unit: RBX::VInstance::?$NonFactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fe580
//
// 005fe580  83ec14               sub esp, 0x14
// 005fe583  56                   push esi
// 005fe584  8bf1                 mov esi, ecx
// 005fe586  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005fe58a  57                   push edi
// 005fe58b  7521                 jne 0x5fe5ae
// 005fe58d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fe591  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005fe594  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005fe598  50                   push eax
// 005fe599  51                   push ecx
// 005fe59a  6a01                 push 1
// 005fe59c  57                   push edi
// 005fe59d  8bce                 mov ecx, esi
// 005fe59f  e8ac630400           call 0x644950
// 005fe5a4  8bc7                 mov eax, edi
// 005fe5a6  5f                   pop edi
// 005fe5a7  5e                   pop esi
// 005fe5a8  83c414               add esp, 0x14
// 005fe5ab  c21000               ret 0x10
// 005fe5ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005fe5b2  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fe5b5  8b3a                 mov edi, dword ptr [edx]
// 005fe5b7  8b06                 mov eax, dword ptr [esi]
// 005fe5b9  53                   push ebx
// 005fe5ba  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 005fe5c0  85c9                 test ecx, ecx
// 005fe5c2  7404                 je 0x5fe5c8
// 005fe5c4  3bc8                 cmp ecx, eax
// 005fe5c6  7406                 je 0x5fe5ce
// 005fe5c8  ffd3                 call ebx
// 005fe5ca  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005fe5ce  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fe5d2  3bc7                 cmp eax, edi
// 005fe5d4  752a                 jne 0x5fe600
// 005fe5d6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005fe5da  8b0f                 mov ecx, dword ptr [edi]
// 005fe5dc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005fe5df  0f8d4b010000         jge 0x5fe730
// 005fe5e5  57                   push edi
// 005fe5e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005fe5ea  50                   push eax
// 005fe5eb  6a01                 push 1
// 005fe5ed  57                   push edi
// 005fe5ee  8bce                 mov ecx, esi
// 005fe5f0  e85b630400           call 0x644950
// 005fe5f5  5b                   pop ebx
// 005fe5f6  8bc7                 mov eax, edi
// 005fe5f8  5f                   pop edi
// 005fe5f9  5e                   pop esi
// 005fe5fa  83c414               add esp, 0x14
// 005fe5fd  c21000               ret 0x10
// 005fe600  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005fe603  8b16                 mov edx, dword ptr [esi]
// 005fe605  85c9                 test ecx, ecx
// 005fe607  7404                 je 0x5fe60d
// 005fe609  3bca                 cmp ecx, edx
// 005fe60b  740a                 je 0x5fe617
// 005fe60d  ffd3                 call ebx
// 005fe60f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fe613  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005fe617  3bc7                 cmp eax, edi
// 005fe619  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005fe61d  752c                 jne 0x5fe64b
// 005fe61f  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fe622  8b4208               mov eax, dword ptr [edx + 8]
// 005fe625  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005fe628  3b0f                 cmp ecx, dword ptr [edi]
// 005fe62a  0f8d00010000         jge 0x5fe730
// 005fe630  57                   push edi
// 005fe631  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005fe635  50                   push eax
// 005fe636  6a00                 push 0
// 005fe638  57                   push edi
// 005fe639  8bce                 mov ecx, esi
// 005fe63b  e810630400           call 0x644950
// 005fe640  5b                   pop ebx
// 005fe641  8bc7                 mov eax, edi
// 005fe643  5f                   pop edi
// 005fe644  5e                   pop esi
// 005fe645  83c414               add esp, 0x14
// 005fe648  c21000               ret 0x10
// 005fe64b  8b17                 mov edx, dword ptr [edi]
// 005fe64d  39500c               cmp dword ptr [eax + 0xc], edx
// 005fe650  7e63                 jle 0x5fe6b5
// 005fe652  894c240c             mov dword ptr [esp + 0xc], ecx
// 005fe656  8d4c240c             lea ecx, [esp + 0xc]
// 005fe65a  89442410             mov dword ptr [esp + 0x10], eax
// 005fe65e  e84d58eeff           call 0x4e3eb0
// 005fe663  8b17                 mov edx, dword ptr [edi]
// 005fe665  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fe669  39500c               cmp dword ptr [eax + 0xc], edx
// 005fe66c  7d3c                 jge 0x5fe6aa
// 005fe66e  8b5008               mov edx, dword ptr [eax + 8]
// 005fe671  807a1900             cmp byte ptr [edx + 0x19], 0
// 005fe675  57                   push edi
// 005fe676  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005fe67a  8bce                 mov ecx, esi
// 005fe67c  7414                 je 0x5fe692
// 005fe67e  50                   push eax
// 005fe67f  6a00                 push 0
// 005fe681  57                   push edi
// 005fe682  e8c9620400           call 0x644950
// 005fe687  5b                   pop ebx
// 005fe688  8bc7                 mov eax, edi
// 005fe68a  5f                   pop edi
// 005fe68b  5e                   pop esi
// 005fe68c  83c414               add esp, 0x14
// 005fe68f  c21000               ret 0x10
// 005fe692  8b442430             mov eax, dword ptr [esp + 0x30]
// 005fe696  50                   push eax
// 005fe697  6a01                 push 1
// 005fe699  57                   push edi
// 005fe69a  e8b1620400           call 0x644950
// 005fe69f  5b                   pop ebx
// 005fe6a0  8bc7                 mov eax, edi
// 005fe6a2  5f                   pop edi
// 005fe6a3  5e                   pop esi
// 005fe6a4  83c414               add esp, 0x14
// 005fe6a7  c21000               ret 0x10
// 005fe6aa  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fe6ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005fe6b2  39500c               cmp dword ptr [eax + 0xc], edx
// 005fe6b5  7d79                 jge 0x5fe730
// 005fe6b7  8b16                 mov edx, dword ptr [esi]
// 005fe6b9  894c240c             mov dword ptr [esp + 0xc], ecx
// 005fe6bd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005fe6c0  894c2418             mov dword ptr [esp + 0x18], ecx
// 005fe6c4  8d4c240c             lea ecx, [esp + 0xc]
// 005fe6c8  89442410             mov dword ptr [esp + 0x10], eax
// 005fe6cc  89542414             mov dword ptr [esp + 0x14], edx
// 005fe6d0  e8eb3b0200           call 0x6222c0
// 005fe6d5  8d442414             lea eax, [esp + 0x14]
// 005fe6d9  50                   push eax
// 005fe6da  8d4c2410             lea ecx, [esp + 0x10]
// 005fe6de  e8bd4d0400           call 0x6434a0
// 005fe6e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005fe6e7  84c0                 test al, al
// 005fe6e9  7507                 jne 0x5fe6f2
// 005fe6eb  8b17                 mov edx, dword ptr [edi]
// 005fe6ed  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 005fe6f0  7d3e                 jge 0x5fe730
// 005fe6f2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005fe6f6  8b5008               mov edx, dword ptr [eax + 8]
// 005fe6f9  807a1900             cmp byte ptr [edx + 0x19], 0
// 005fe6fd  57                   push edi
// 005fe6fe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005fe702  7416                 je 0x5fe71a
// 005fe704  50                   push eax
// 005fe705  6a00                 push 0
// 005fe707  57                   push edi
// 005fe708  8bce                 mov ecx, esi
// 005fe70a  e841620400           call 0x644950
// 005fe70f  5b                   pop ebx
// 005fe710  8bc7                 mov eax, edi
// 005fe712  5f                   pop edi
// 005fe713  5e                   pop esi
// 005fe714  83c414               add esp, 0x14
// 005fe717  c21000               ret 0x10
// 005fe71a  51                   push ecx
// 005fe71b  6a01                 push 1
// 005fe71d  57                   push edi
// 005fe71e  8bce                 mov ecx, esi
// 005fe720  e82b620400           call 0x644950
// 005fe725  5b                   pop ebx
// 005fe726  8bc7                 mov eax, edi
// 005fe728  5f                   pop edi
// 005fe729  5e                   pop esi
// 005fe72a  83c414               add esp, 0x14
// 005fe72d  c21000               ret 0x10
// 005fe730  57                   push edi
// 005fe731  8d442418             lea eax, [esp + 0x18]
// 005fe735  50                   push eax
// 005fe736  8bce                 mov ecx, esi
// 005fe738  e8436a0400           call 0x645180
// 005fe73d  8b10                 mov edx, dword ptr [eax]
// 005fe73f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005fe743  5b                   pop ebx
// 005fe744  8911                 mov dword ptr [ecx], edx
// 005fe746  8b4004               mov eax, dword ptr [eax + 4]
// 005fe749  5f                   pop edi
// 005fe74a  894104               mov dword ptr [ecx + 4], eax
// 005fe74d  8bc1                 mov eax, ecx
// 005fe74f  5e                   pop esi
// 005fe750  83c414               add esp, 0x14
// 005fe753  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
