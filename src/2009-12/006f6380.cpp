// from server: 100% by auto
// roc 2009-12 006f6380  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6380
//
// 006f6380  83ec14               sub esp, 0x14
// 006f6383  56                   push esi
// 006f6384  8bf1                 mov esi, ecx
// 006f6386  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006f638a  57                   push edi
// 006f638b  7521                 jne 0x6f63ae
// 006f638d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6391  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f6394  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f6398  50                   push eax
// 006f6399  51                   push ecx
// 006f639a  6a01                 push 1
// 006f639c  57                   push edi
// 006f639d  8bce                 mov ecx, esi
// 006f639f  e87c6ffbff           call 0x6ad320
// 006f63a4  8bc7                 mov eax, edi
// 006f63a6  5f                   pop edi
// 006f63a7  5e                   pop esi
// 006f63a8  83c414               add esp, 0x14
// 006f63ab  c21000               ret 0x10
// 006f63ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f63b2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f63b5  8b3a                 mov edi, dword ptr [edx]
// 006f63b7  8b06                 mov eax, dword ptr [esi]
// 006f63b9  53                   push ebx
// 006f63ba  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006f63c0  85c9                 test ecx, ecx
// 006f63c2  7404                 je 0x6f63c8
// 006f63c4  3bc8                 cmp ecx, eax
// 006f63c6  7406                 je 0x6f63ce
// 006f63c8  ffd3                 call ebx
// 006f63ca  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f63ce  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f63d2  3bc7                 cmp eax, edi
// 006f63d4  752a                 jne 0x6f6400
// 006f63d6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f63da  8b0f                 mov ecx, dword ptr [edi]
// 006f63dc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006f63df  0f8d4b010000         jge 0x6f6530
// 006f63e5  57                   push edi
// 006f63e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f63ea  50                   push eax
// 006f63eb  6a01                 push 1
// 006f63ed  57                   push edi
// 006f63ee  8bce                 mov ecx, esi
// 006f63f0  e82b6ffbff           call 0x6ad320
// 006f63f5  5b                   pop ebx
// 006f63f6  8bc7                 mov eax, edi
// 006f63f8  5f                   pop edi
// 006f63f9  5e                   pop esi
// 006f63fa  83c414               add esp, 0x14
// 006f63fd  c21000               ret 0x10
// 006f6400  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006f6403  8b16                 mov edx, dword ptr [esi]
// 006f6405  85c9                 test ecx, ecx
// 006f6407  7404                 je 0x6f640d
// 006f6409  3bca                 cmp ecx, edx
// 006f640b  740a                 je 0x6f6417
// 006f640d  ffd3                 call ebx
// 006f640f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f6413  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f6417  3bc7                 cmp eax, edi
// 006f6419  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006f641d  752c                 jne 0x6f644b
// 006f641f  8b5618               mov edx, dword ptr [esi + 0x18]
// 006f6422  8b4208               mov eax, dword ptr [edx + 8]
// 006f6425  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006f6428  3b0f                 cmp ecx, dword ptr [edi]
// 006f642a  0f8d00010000         jge 0x6f6530
// 006f6430  57                   push edi
// 006f6431  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6435  50                   push eax
// 006f6436  6a00                 push 0
// 006f6438  57                   push edi
// 006f6439  8bce                 mov ecx, esi
// 006f643b  e8e06efbff           call 0x6ad320
// 006f6440  5b                   pop ebx
// 006f6441  8bc7                 mov eax, edi
// 006f6443  5f                   pop edi
// 006f6444  5e                   pop esi
// 006f6445  83c414               add esp, 0x14
// 006f6448  c21000               ret 0x10
// 006f644b  8b17                 mov edx, dword ptr [edi]
// 006f644d  39500c               cmp dword ptr [eax + 0xc], edx
// 006f6450  7e63                 jle 0x6f64b5
// 006f6452  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f6456  8d4c240c             lea ecx, [esp + 0xc]
// 006f645a  89442410             mov dword ptr [esp + 0x10], eax
// 006f645e  e8cdddd4ff           call 0x444230
// 006f6463  8b17                 mov edx, dword ptr [edi]
// 006f6465  8b442410             mov eax, dword ptr [esp + 0x10]
// 006f6469  39500c               cmp dword ptr [eax + 0xc], edx
// 006f646c  7d3c                 jge 0x6f64aa
// 006f646e  8b5008               mov edx, dword ptr [eax + 8]
// 006f6471  807a1500             cmp byte ptr [edx + 0x15], 0
// 006f6475  57                   push edi
// 006f6476  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f647a  8bce                 mov ecx, esi
// 006f647c  7414                 je 0x6f6492
// 006f647e  50                   push eax
// 006f647f  6a00                 push 0
// 006f6481  57                   push edi
// 006f6482  e8996efbff           call 0x6ad320
// 006f6487  5b                   pop ebx
// 006f6488  8bc7                 mov eax, edi
// 006f648a  5f                   pop edi
// 006f648b  5e                   pop esi
// 006f648c  83c414               add esp, 0x14
// 006f648f  c21000               ret 0x10
// 006f6492  8b442430             mov eax, dword ptr [esp + 0x30]
// 006f6496  50                   push eax
// 006f6497  6a01                 push 1
// 006f6499  57                   push edi
// 006f649a  e8816efbff           call 0x6ad320
// 006f649f  5b                   pop ebx
// 006f64a0  8bc7                 mov eax, edi
// 006f64a2  5f                   pop edi
// 006f64a3  5e                   pop esi
// 006f64a4  83c414               add esp, 0x14
// 006f64a7  c21000               ret 0x10
// 006f64aa  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f64ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f64b2  39500c               cmp dword ptr [eax + 0xc], edx
// 006f64b5  7d79                 jge 0x6f6530
// 006f64b7  8b16                 mov edx, dword ptr [esi]
// 006f64b9  894c240c             mov dword ptr [esp + 0xc], ecx
// 006f64bd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f64c0  894c2418             mov dword ptr [esp + 0x18], ecx
// 006f64c4  8d4c240c             lea ecx, [esp + 0xc]
// 006f64c8  89442410             mov dword ptr [esp + 0x10], eax
// 006f64cc  89542414             mov dword ptr [esp + 0x14], edx
// 006f64d0  e81b6cfbff           call 0x6ad0f0
// 006f64d5  8d442414             lea eax, [esp + 0x14]
// 006f64d9  50                   push eax
// 006f64da  8d4c2410             lea ecx, [esp + 0x10]
// 006f64de  e87d5eedff           call 0x5cc360
// 006f64e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006f64e7  84c0                 test al, al
// 006f64e9  7507                 jne 0x6f64f2
// 006f64eb  8b17                 mov edx, dword ptr [edi]
// 006f64ed  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006f64f0  7d3e                 jge 0x6f6530
// 006f64f2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006f64f6  8b5008               mov edx, dword ptr [eax + 8]
// 006f64f9  807a1500             cmp byte ptr [edx + 0x15], 0
// 006f64fd  57                   push edi
// 006f64fe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006f6502  7416                 je 0x6f651a
// 006f6504  50                   push eax
// 006f6505  6a00                 push 0
// 006f6507  57                   push edi
// 006f6508  8bce                 mov ecx, esi
// 006f650a  e8116efbff           call 0x6ad320
// 006f650f  5b                   pop ebx
// 006f6510  8bc7                 mov eax, edi
// 006f6512  5f                   pop edi
// 006f6513  5e                   pop esi
// 006f6514  83c414               add esp, 0x14
// 006f6517  c21000               ret 0x10
// 006f651a  51                   push ecx
// 006f651b  6a01                 push 1
// 006f651d  57                   push edi
// 006f651e  8bce                 mov ecx, esi
// 006f6520  e8fb6dfbff           call 0x6ad320
// 006f6525  5b                   pop ebx
// 006f6526  8bc7                 mov eax, edi
// 006f6528  5f                   pop edi
// 006f6529  5e                   pop esi
// 006f652a  83c414               add esp, 0x14
// 006f652d  c21000               ret 0x10
// 006f6530  57                   push edi
// 006f6531  8d442418             lea eax, [esp + 0x18]
// 006f6535  50                   push eax
// 006f6536  8bce                 mov ecx, esi
// 006f6538  e80375fbff           call 0x6ada40
// 006f653d  8b10                 mov edx, dword ptr [eax]
// 006f653f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006f6543  5b                   pop ebx
// 006f6544  8911                 mov dword ptr [ecx], edx
// 006f6546  8b4004               mov eax, dword ptr [eax + 4]
// 006f6549  5f                   pop edi
// 006f654a  894104               mov dword ptr [ecx + 4], eax
// 006f654d  8bc1                 mov eax, ecx
// 006f654f  5e                   pop esi
// 006f6550  83c414               add esp, 0x14
// 006f6553  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
