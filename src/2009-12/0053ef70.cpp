// from server: 100% by auto
// roc 2009-12 0053ef70  unit: RBX::Network::Replicator::NewInstanceItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053ef70
//
// 0053ef70  83ec14               sub esp, 0x14
// 0053ef73  56                   push esi
// 0053ef74  8bf1                 mov esi, ecx
// 0053ef76  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0053ef7a  57                   push edi
// 0053ef7b  7521                 jne 0x53ef9e
// 0053ef7d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0053ef81  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053ef84  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053ef88  50                   push eax
// 0053ef89  51                   push ecx
// 0053ef8a  6a01                 push 1
// 0053ef8c  57                   push edi
// 0053ef8d  8bce                 mov ecx, esi
// 0053ef8f  e85cd8ffff           call 0x53c7f0
// 0053ef94  8bc7                 mov eax, edi
// 0053ef96  5f                   pop edi
// 0053ef97  5e                   pop esi
// 0053ef98  83c414               add esp, 0x14
// 0053ef9b  c21000               ret 0x10
// 0053ef9e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0053efa2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0053efa5  8b3a                 mov edi, dword ptr [edx]
// 0053efa7  8b06                 mov eax, dword ptr [esi]
// 0053efa9  53                   push ebx
// 0053efaa  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0053efb0  85c9                 test ecx, ecx
// 0053efb2  7404                 je 0x53efb8
// 0053efb4  3bc8                 cmp ecx, eax
// 0053efb6  7406                 je 0x53efbe
// 0053efb8  ffd3                 call ebx
// 0053efba  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053efbe  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0053efc2  3bc7                 cmp eax, edi
// 0053efc4  752a                 jne 0x53eff0
// 0053efc6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0053efca  8b0f                 mov ecx, dword ptr [edi]
// 0053efcc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0053efcf  0f834b010000         jae 0x53f120
// 0053efd5  57                   push edi
// 0053efd6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0053efda  50                   push eax
// 0053efdb  6a01                 push 1
// 0053efdd  57                   push edi
// 0053efde  8bce                 mov ecx, esi
// 0053efe0  e80bd8ffff           call 0x53c7f0
// 0053efe5  5b                   pop ebx
// 0053efe6  8bc7                 mov eax, edi
// 0053efe8  5f                   pop edi
// 0053efe9  5e                   pop esi
// 0053efea  83c414               add esp, 0x14
// 0053efed  c21000               ret 0x10
// 0053eff0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0053eff3  8b16                 mov edx, dword ptr [esi]
// 0053eff5  85c9                 test ecx, ecx
// 0053eff7  7404                 je 0x53effd
// 0053eff9  3bca                 cmp ecx, edx
// 0053effb  740a                 je 0x53f007
// 0053effd  ffd3                 call ebx
// 0053efff  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0053f003  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053f007  3bc7                 cmp eax, edi
// 0053f009  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0053f00d  752c                 jne 0x53f03b
// 0053f00f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0053f012  8b4208               mov eax, dword ptr [edx + 8]
// 0053f015  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0053f018  3b0f                 cmp ecx, dword ptr [edi]
// 0053f01a  0f8300010000         jae 0x53f120
// 0053f020  57                   push edi
// 0053f021  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0053f025  50                   push eax
// 0053f026  6a00                 push 0
// 0053f028  57                   push edi
// 0053f029  8bce                 mov ecx, esi
// 0053f02b  e8c0d7ffff           call 0x53c7f0
// 0053f030  5b                   pop ebx
// 0053f031  8bc7                 mov eax, edi
// 0053f033  5f                   pop edi
// 0053f034  5e                   pop esi
// 0053f035  83c414               add esp, 0x14
// 0053f038  c21000               ret 0x10
// 0053f03b  8b17                 mov edx, dword ptr [edi]
// 0053f03d  39500c               cmp dword ptr [eax + 0xc], edx
// 0053f040  7663                 jbe 0x53f0a5
// 0053f042  894c240c             mov dword ptr [esp + 0xc], ecx
// 0053f046  8d4c240c             lea ecx, [esp + 0xc]
// 0053f04a  89442410             mov dword ptr [esp + 0x10], eax
// 0053f04e  e85d7e1300           call 0x676eb0
// 0053f053  8b17                 mov edx, dword ptr [edi]
// 0053f055  8b442410             mov eax, dword ptr [esp + 0x10]
// 0053f059  39500c               cmp dword ptr [eax + 0xc], edx
// 0053f05c  733c                 jae 0x53f09a
// 0053f05e  8b5008               mov edx, dword ptr [eax + 8]
// 0053f061  807a1900             cmp byte ptr [edx + 0x19], 0
// 0053f065  57                   push edi
// 0053f066  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0053f06a  8bce                 mov ecx, esi
// 0053f06c  7414                 je 0x53f082
// 0053f06e  50                   push eax
// 0053f06f  6a00                 push 0
// 0053f071  57                   push edi
// 0053f072  e879d7ffff           call 0x53c7f0
// 0053f077  5b                   pop ebx
// 0053f078  8bc7                 mov eax, edi
// 0053f07a  5f                   pop edi
// 0053f07b  5e                   pop esi
// 0053f07c  83c414               add esp, 0x14
// 0053f07f  c21000               ret 0x10
// 0053f082  8b442430             mov eax, dword ptr [esp + 0x30]
// 0053f086  50                   push eax
// 0053f087  6a01                 push 1
// 0053f089  57                   push edi
// 0053f08a  e861d7ffff           call 0x53c7f0
// 0053f08f  5b                   pop ebx
// 0053f090  8bc7                 mov eax, edi
// 0053f092  5f                   pop edi
// 0053f093  5e                   pop esi
// 0053f094  83c414               add esp, 0x14
// 0053f097  c21000               ret 0x10
// 0053f09a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0053f09e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053f0a2  39500c               cmp dword ptr [eax + 0xc], edx
// 0053f0a5  7379                 jae 0x53f120
// 0053f0a7  8b16                 mov edx, dword ptr [esi]
// 0053f0a9  894c240c             mov dword ptr [esp + 0xc], ecx
// 0053f0ad  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053f0b0  894c2418             mov dword ptr [esp + 0x18], ecx
// 0053f0b4  8d4c240c             lea ecx, [esp + 0xc]
// 0053f0b8  89442410             mov dword ptr [esp + 0x10], eax
// 0053f0bc  89542414             mov dword ptr [esp + 0x14], edx
// 0053f0c0  e8bb94ffff           call 0x538580
// 0053f0c5  8d442414             lea eax, [esp + 0x14]
// 0053f0c9  50                   push eax
// 0053f0ca  8d4c2410             lea ecx, [esp + 0x10]
// 0053f0ce  e88dd20800           call 0x5cc360
// 0053f0d3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053f0d7  84c0                 test al, al
// 0053f0d9  7507                 jne 0x53f0e2
// 0053f0db  8b17                 mov edx, dword ptr [edi]
// 0053f0dd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0053f0e0  733e                 jae 0x53f120
// 0053f0e2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0053f0e6  8b5008               mov edx, dword ptr [eax + 8]
// 0053f0e9  807a1900             cmp byte ptr [edx + 0x19], 0
// 0053f0ed  57                   push edi
// 0053f0ee  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0053f0f2  7416                 je 0x53f10a
// 0053f0f4  50                   push eax
// 0053f0f5  6a00                 push 0
// 0053f0f7  57                   push edi
// 0053f0f8  8bce                 mov ecx, esi
// 0053f0fa  e8f1d6ffff           call 0x53c7f0
// 0053f0ff  5b                   pop ebx
// 0053f100  8bc7                 mov eax, edi
// 0053f102  5f                   pop edi
// 0053f103  5e                   pop esi
// 0053f104  83c414               add esp, 0x14
// 0053f107  c21000               ret 0x10
// 0053f10a  51                   push ecx
// 0053f10b  6a01                 push 1
// 0053f10d  57                   push edi
// 0053f10e  8bce                 mov ecx, esi
// 0053f110  e8dbd6ffff           call 0x53c7f0
// 0053f115  5b                   pop ebx
// 0053f116  8bc7                 mov eax, edi
// 0053f118  5f                   pop edi
// 0053f119  5e                   pop esi
// 0053f11a  83c414               add esp, 0x14
// 0053f11d  c21000               ret 0x10
// 0053f120  57                   push edi
// 0053f121  8d442418             lea eax, [esp + 0x18]
// 0053f125  50                   push eax
// 0053f126  8bce                 mov ecx, esi
// 0053f128  e8a3edffff           call 0x53ded0
// 0053f12d  8b10                 mov edx, dword ptr [eax]
// 0053f12f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0053f133  5b                   pop ebx
// 0053f134  8911                 mov dword ptr [ecx], edx
// 0053f136  8b4004               mov eax, dword ptr [eax + 4]
// 0053f139  5f                   pop edi
// 0053f13a  894104               mov dword ptr [ecx + 4], eax
// 0053f13d  8bc1                 mov eax, ecx
// 0053f13f  5e                   pop esi
// 0053f140  83c414               add esp, 0x14
// 0053f143  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
