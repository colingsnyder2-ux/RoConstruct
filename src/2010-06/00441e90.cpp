// from server: 100% by auto
// roc 2010-06 00441e90  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00441e90
//
// 00441e90  83ec14               sub esp, 0x14
// 00441e93  56                   push esi
// 00441e94  8bf1                 mov esi, ecx
// 00441e96  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00441e9a  57                   push edi
// 00441e9b  7521                 jne 0x441ebe
// 00441e9d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441ea1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00441ea4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00441ea8  50                   push eax
// 00441ea9  51                   push ecx
// 00441eaa  6a01                 push 1
// 00441eac  57                   push edi
// 00441ead  8bce                 mov ecx, esi
// 00441eaf  e85ce7ffff           call 0x440610
// 00441eb4  8bc7                 mov eax, edi
// 00441eb6  5f                   pop edi
// 00441eb7  5e                   pop esi
// 00441eb8  83c414               add esp, 0x14
// 00441ebb  c21000               ret 0x10
// 00441ebe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00441ec2  8b5618               mov edx, dword ptr [esi + 0x18]
// 00441ec5  8b3a                 mov edi, dword ptr [edx]
// 00441ec7  8b06                 mov eax, dword ptr [esi]
// 00441ec9  53                   push ebx
// 00441eca  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00441ed0  85c9                 test ecx, ecx
// 00441ed2  7404                 je 0x441ed8
// 00441ed4  3bc8                 cmp ecx, eax
// 00441ed6  7406                 je 0x441ede
// 00441ed8  ffd3                 call ebx
// 00441eda  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441ede  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441ee2  3bc7                 cmp eax, edi
// 00441ee4  752a                 jne 0x441f10
// 00441ee6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00441eea  8b0f                 mov ecx, dword ptr [edi]
// 00441eec  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00441eef  0f834b010000         jae 0x442040
// 00441ef5  57                   push edi
// 00441ef6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00441efa  50                   push eax
// 00441efb  6a01                 push 1
// 00441efd  57                   push edi
// 00441efe  8bce                 mov ecx, esi
// 00441f00  e80be7ffff           call 0x440610
// 00441f05  5b                   pop ebx
// 00441f06  8bc7                 mov eax, edi
// 00441f08  5f                   pop edi
// 00441f09  5e                   pop esi
// 00441f0a  83c414               add esp, 0x14
// 00441f0d  c21000               ret 0x10
// 00441f10  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00441f13  8b16                 mov edx, dword ptr [esi]
// 00441f15  85c9                 test ecx, ecx
// 00441f17  7404                 je 0x441f1d
// 00441f19  3bca                 cmp ecx, edx
// 00441f1b  740a                 je 0x441f27
// 00441f1d  ffd3                 call ebx
// 00441f1f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441f23  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441f27  3bc7                 cmp eax, edi
// 00441f29  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00441f2d  752c                 jne 0x441f5b
// 00441f2f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00441f32  8b4208               mov eax, dword ptr [edx + 8]
// 00441f35  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00441f38  3b0f                 cmp ecx, dword ptr [edi]
// 00441f3a  0f8300010000         jae 0x442040
// 00441f40  57                   push edi
// 00441f41  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00441f45  50                   push eax
// 00441f46  6a00                 push 0
// 00441f48  57                   push edi
// 00441f49  8bce                 mov ecx, esi
// 00441f4b  e8c0e6ffff           call 0x440610
// 00441f50  5b                   pop ebx
// 00441f51  8bc7                 mov eax, edi
// 00441f53  5f                   pop edi
// 00441f54  5e                   pop esi
// 00441f55  83c414               add esp, 0x14
// 00441f58  c21000               ret 0x10
// 00441f5b  8b17                 mov edx, dword ptr [edi]
// 00441f5d  39500c               cmp dword ptr [eax + 0xc], edx
// 00441f60  7663                 jbe 0x441fc5
// 00441f62  894c240c             mov dword ptr [esp + 0xc], ecx
// 00441f66  8d4c240c             lea ecx, [esp + 0xc]
// 00441f6a  89442410             mov dword ptr [esp + 0x10], eax
// 00441f6e  e84db92400           call 0x68d8c0
// 00441f73  8b17                 mov edx, dword ptr [edi]
// 00441f75  8b442410             mov eax, dword ptr [esp + 0x10]
// 00441f79  39500c               cmp dword ptr [eax + 0xc], edx
// 00441f7c  733c                 jae 0x441fba
// 00441f7e  8b5008               mov edx, dword ptr [eax + 8]
// 00441f81  807a2900             cmp byte ptr [edx + 0x29], 0
// 00441f85  57                   push edi
// 00441f86  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00441f8a  8bce                 mov ecx, esi
// 00441f8c  7414                 je 0x441fa2
// 00441f8e  50                   push eax
// 00441f8f  6a00                 push 0
// 00441f91  57                   push edi
// 00441f92  e879e6ffff           call 0x440610
// 00441f97  5b                   pop ebx
// 00441f98  8bc7                 mov eax, edi
// 00441f9a  5f                   pop edi
// 00441f9b  5e                   pop esi
// 00441f9c  83c414               add esp, 0x14
// 00441f9f  c21000               ret 0x10
// 00441fa2  8b442430             mov eax, dword ptr [esp + 0x30]
// 00441fa6  50                   push eax
// 00441fa7  6a01                 push 1
// 00441fa9  57                   push edi
// 00441faa  e861e6ffff           call 0x440610
// 00441faf  5b                   pop ebx
// 00441fb0  8bc7                 mov eax, edi
// 00441fb2  5f                   pop edi
// 00441fb3  5e                   pop esi
// 00441fb4  83c414               add esp, 0x14
// 00441fb7  c21000               ret 0x10
// 00441fba  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00441fbe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441fc2  39500c               cmp dword ptr [eax + 0xc], edx
// 00441fc5  7379                 jae 0x442040
// 00441fc7  8b16                 mov edx, dword ptr [esi]
// 00441fc9  894c240c             mov dword ptr [esp + 0xc], ecx
// 00441fcd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00441fd0  894c2418             mov dword ptr [esp + 0x18], ecx
// 00441fd4  8d4c240c             lea ecx, [esp + 0xc]
// 00441fd8  89442410             mov dword ptr [esp + 0x10], eax
// 00441fdc  89542414             mov dword ptr [esp + 0x14], edx
// 00441fe0  e8cbd53200           call 0x76f5b0
// 00441fe5  8d442414             lea eax, [esp + 0x14]
// 00441fe9  50                   push eax
// 00441fea  8d4c2410             lea ecx, [esp + 0x10]
// 00441fee  e88d4f0200           call 0x466f80
// 00441ff3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441ff7  84c0                 test al, al
// 00441ff9  7507                 jne 0x442002
// 00441ffb  8b17                 mov edx, dword ptr [edi]
// 00441ffd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00442000  733e                 jae 0x442040
// 00442002  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00442006  8b5008               mov edx, dword ptr [eax + 8]
// 00442009  807a2900             cmp byte ptr [edx + 0x29], 0
// 0044200d  57                   push edi
// 0044200e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00442012  7416                 je 0x44202a
// 00442014  50                   push eax
// 00442015  6a00                 push 0
// 00442017  57                   push edi
// 00442018  8bce                 mov ecx, esi
// 0044201a  e8f1e5ffff           call 0x440610
// 0044201f  5b                   pop ebx
// 00442020  8bc7                 mov eax, edi
// 00442022  5f                   pop edi
// 00442023  5e                   pop esi
// 00442024  83c414               add esp, 0x14
// 00442027  c21000               ret 0x10
// 0044202a  51                   push ecx
// 0044202b  6a01                 push 1
// 0044202d  57                   push edi
// 0044202e  8bce                 mov ecx, esi
// 00442030  e8dbe5ffff           call 0x440610
// 00442035  5b                   pop ebx
// 00442036  8bc7                 mov eax, edi
// 00442038  5f                   pop edi
// 00442039  5e                   pop esi
// 0044203a  83c414               add esp, 0x14
// 0044203d  c21000               ret 0x10
// 00442040  57                   push edi
// 00442041  8d442418             lea eax, [esp + 0x18]
// 00442045  50                   push eax
// 00442046  8bce                 mov ecx, esi
// 00442048  e873faffff           call 0x441ac0
// 0044204d  8b10                 mov edx, dword ptr [eax]
// 0044204f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00442053  5b                   pop ebx
// 00442054  8911                 mov dword ptr [ecx], edx
// 00442056  8b4004               mov eax, dword ptr [eax + 4]
// 00442059  5f                   pop edi
// 0044205a  894104               mov dword ptr [ecx + 4], eax
// 0044205d  8bc1                 mov eax, ecx
// 0044205f  5e                   pop esi
// 00442060  83c414               add esp, 0x14
// 00442063  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
