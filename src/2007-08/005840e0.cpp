// from server: 100% by auto
// roc 2007-08 005840e0  unit: RBX::VHat::?$FactoryProduct  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005840e0
//
// 005840e0  83ec0c               sub esp, 0xc
// 005840e3  56                   push esi
// 005840e4  8bf1                 mov esi, ecx
// 005840e6  837e0800             cmp dword ptr [esi + 8], 0
// 005840ea  57                   push edi
// 005840eb  7521                 jne 0x58410e
// 005840ed  8b442424             mov eax, dword ptr [esp + 0x24]
// 005840f1  8b4e04               mov ecx, dword ptr [esi + 4]
// 005840f4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005840f8  50                   push eax
// 005840f9  51                   push ecx
// 005840fa  6a01                 push 1
// 005840fc  57                   push edi
// 005840fd  8bce                 mov ecx, esi
// 005840ff  e82cf5ffff           call 0x583630
// 00584104  8bc7                 mov eax, edi
// 00584106  5f                   pop edi
// 00584107  5e                   pop esi
// 00584108  83c40c               add esp, 0xc
// 0058410b  c21000               ret 0x10
// 0058410e  8b5604               mov edx, dword ptr [esi + 4]
// 00584111  8b3a                 mov edi, dword ptr [edx]
// 00584113  55                   push ebp
// 00584114  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00584118  85ed                 test ebp, ebp
// 0058411a  7404                 je 0x584120
// 0058411c  3bee                 cmp ebp, esi
// 0058411e  7406                 je 0x584126
// 00584120  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584126  53                   push ebx
// 00584127  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058412b  3bdf                 cmp ebx, edi
// 0058412d  752b                 jne 0x58415a
// 0058412f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584133  8b07                 mov eax, dword ptr [edi]
// 00584135  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 00584138  0f8d39010000         jge 0x584277
// 0058413e  57                   push edi
// 0058413f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584143  53                   push ebx
// 00584144  6a01                 push 1
// 00584146  57                   push edi
// 00584147  8bce                 mov ecx, esi
// 00584149  e8e2f4ffff           call 0x583630
// 0058414e  5b                   pop ebx
// 0058414f  5d                   pop ebp
// 00584150  8bc7                 mov eax, edi
// 00584152  5f                   pop edi
// 00584153  5e                   pop esi
// 00584154  83c40c               add esp, 0xc
// 00584157  c21000               ret 0x10
// 0058415a  85ed                 test ebp, ebp
// 0058415c  8b7e04               mov edi, dword ptr [esi + 4]
// 0058415f  7404                 je 0x584165
// 00584161  3bee                 cmp ebp, esi
// 00584163  7406                 je 0x58416b
// 00584165  ff15d8e67700         call dword ptr [0x77e6d8]
// 0058416b  3bdf                 cmp ebx, edi
// 0058416d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00584171  752d                 jne 0x5841a0
// 00584173  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584176  8b4108               mov eax, dword ptr [ecx + 8]
// 00584179  8b500c               mov edx, dword ptr [eax + 0xc]
// 0058417c  3b17                 cmp edx, dword ptr [edi]
// 0058417e  0f8df3000000         jge 0x584277
// 00584184  57                   push edi
// 00584185  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584189  50                   push eax
// 0058418a  6a00                 push 0
// 0058418c  57                   push edi
// 0058418d  8bce                 mov ecx, esi
// 0058418f  e89cf4ffff           call 0x583630
// 00584194  5b                   pop ebx
// 00584195  5d                   pop ebp
// 00584196  8bc7                 mov eax, edi
// 00584198  5f                   pop edi
// 00584199  5e                   pop esi
// 0058419a  83c40c               add esp, 0xc
// 0058419d  c21000               ret 0x10
// 005841a0  8b07                 mov eax, dword ptr [edi]
// 005841a2  39430c               cmp dword ptr [ebx + 0xc], eax
// 005841a5  7e5b                 jle 0x584202
// 005841a7  8d4c2424             lea ecx, [esp + 0x24]
// 005841ab  896c2424             mov dword ptr [esp + 0x24], ebp
// 005841af  895c2428             mov dword ptr [esp + 0x28], ebx
// 005841b3  e8f8c1f1ff           call 0x4a03b0
// 005841b8  8b07                 mov eax, dword ptr [edi]
// 005841ba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005841be  39410c               cmp dword ptr [ecx + 0xc], eax
// 005841c1  7d3c                 jge 0x5841ff
// 005841c3  8b4108               mov eax, dword ptr [ecx + 8]
// 005841c6  80782100             cmp byte ptr [eax + 0x21], 0
// 005841ca  57                   push edi
// 005841cb  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005841cf  7417                 je 0x5841e8
// 005841d1  51                   push ecx
// 005841d2  6a00                 push 0
// 005841d4  57                   push edi
// 005841d5  8bce                 mov ecx, esi
// 005841d7  e854f4ffff           call 0x583630
// 005841dc  5b                   pop ebx
// 005841dd  5d                   pop ebp
// 005841de  8bc7                 mov eax, edi
// 005841e0  5f                   pop edi
// 005841e1  5e                   pop esi
// 005841e2  83c40c               add esp, 0xc
// 005841e5  c21000               ret 0x10
// 005841e8  53                   push ebx
// 005841e9  6a01                 push 1
// 005841eb  57                   push edi
// 005841ec  8bce                 mov ecx, esi
// 005841ee  e83df4ffff           call 0x583630
// 005841f3  5b                   pop ebx
// 005841f4  5d                   pop ebp
// 005841f5  8bc7                 mov eax, edi
// 005841f7  5f                   pop edi
// 005841f8  5e                   pop esi
// 005841f9  83c40c               add esp, 0xc
// 005841fc  c21000               ret 0x10
// 005841ff  39430c               cmp dword ptr [ebx + 0xc], eax
// 00584202  7d73                 jge 0x584277
// 00584204  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584207  894c2414             mov dword ptr [esp + 0x14], ecx
// 0058420b  8d4c2424             lea ecx, [esp + 0x24]
// 0058420f  896c2424             mov dword ptr [esp + 0x24], ebp
// 00584213  895c2428             mov dword ptr [esp + 0x28], ebx
// 00584217  89742410             mov dword ptr [esp + 0x10], esi
// 0058421b  e850c6f4ff           call 0x4d0870
// 00584220  8d542410             lea edx, [esp + 0x10]
// 00584224  52                   push edx
// 00584225  8d4c2428             lea ecx, [esp + 0x28]
// 00584229  e88228eeff           call 0x466ab0
// 0058422e  84c0                 test al, al
// 00584230  8b442428             mov eax, dword ptr [esp + 0x28]
// 00584234  7507                 jne 0x58423d
// 00584236  8b0f                 mov ecx, dword ptr [edi]
// 00584238  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0058423b  7d3a                 jge 0x584277
// 0058423d  8b5308               mov edx, dword ptr [ebx + 8]
// 00584240  807a2100             cmp byte ptr [edx + 0x21], 0
// 00584244  57                   push edi
// 00584245  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584249  8bce                 mov ecx, esi
// 0058424b  7415                 je 0x584262
// 0058424d  53                   push ebx
// 0058424e  6a00                 push 0
// 00584250  57                   push edi
// 00584251  e8daf3ffff           call 0x583630
// 00584256  5b                   pop ebx
// 00584257  5d                   pop ebp
// 00584258  8bc7                 mov eax, edi
// 0058425a  5f                   pop edi
// 0058425b  5e                   pop esi
// 0058425c  83c40c               add esp, 0xc
// 0058425f  c21000               ret 0x10
// 00584262  50                   push eax
// 00584263  6a01                 push 1
// 00584265  57                   push edi
// 00584266  e8c5f3ffff           call 0x583630
// 0058426b  5b                   pop ebx
// 0058426c  5d                   pop ebp
// 0058426d  8bc7                 mov eax, edi
// 0058426f  5f                   pop edi
// 00584270  5e                   pop esi
// 00584271  83c40c               add esp, 0xc
// 00584274  c21000               ret 0x10
// 00584277  57                   push edi
// 00584278  8d442414             lea eax, [esp + 0x14]
// 0058427c  50                   push eax
// 0058427d  8bce                 mov ecx, esi
// 0058427f  e86cfcffff           call 0x583ef0
// 00584284  8b10                 mov edx, dword ptr [eax]
// 00584286  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0058428a  5b                   pop ebx
// 0058428b  5d                   pop ebp
// 0058428c  8911                 mov dword ptr [ecx], edx
// 0058428e  8b4004               mov eax, dword ptr [eax + 4]
// 00584291  5f                   pop edi
// 00584292  894104               mov dword ptr [ecx + 4], eax
// 00584295  8bc1                 mov eax, ecx
// 00584297  5e                   pop esi
// 00584298  83c40c               add esp, 0xc
// 0058429b  c21000               ret 0x10
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
