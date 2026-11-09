// from server: 100% by auto
// roc 2009-12 007edab0  unit: W4_D3DFORMAT::?$EnumDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007edab0
//
// 007edab0  83ec14               sub esp, 0x14
// 007edab3  56                   push esi
// 007edab4  8bf1                 mov esi, ecx
// 007edab6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007edaba  57                   push edi
// 007edabb  7521                 jne 0x7edade
// 007edabd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007edac1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007edac4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007edac8  50                   push eax
// 007edac9  51                   push ecx
// 007edaca  6a01                 push 1
// 007edacc  57                   push edi
// 007edacd  8bce                 mov ecx, esi
// 007edacf  e89cfcffff           call 0x7ed770
// 007edad4  8bc7                 mov eax, edi
// 007edad6  5f                   pop edi
// 007edad7  5e                   pop esi
// 007edad8  83c414               add esp, 0x14
// 007edadb  c21000               ret 0x10
// 007edade  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007edae2  8b5618               mov edx, dword ptr [esi + 0x18]
// 007edae5  8b3a                 mov edi, dword ptr [edx]
// 007edae7  8b06                 mov eax, dword ptr [esi]
// 007edae9  53                   push ebx
// 007edaea  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007edaf0  85c9                 test ecx, ecx
// 007edaf2  7404                 je 0x7edaf8
// 007edaf4  3bc8                 cmp ecx, eax
// 007edaf6  7406                 je 0x7edafe
// 007edaf8  ffd3                 call ebx
// 007edafa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007edafe  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007edb02  3bc7                 cmp eax, edi
// 007edb04  752a                 jne 0x7edb30
// 007edb06  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007edb0a  8b0f                 mov ecx, dword ptr [edi]
// 007edb0c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007edb0f  0f834b010000         jae 0x7edc60
// 007edb15  57                   push edi
// 007edb16  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007edb1a  50                   push eax
// 007edb1b  6a01                 push 1
// 007edb1d  57                   push edi
// 007edb1e  8bce                 mov ecx, esi
// 007edb20  e84bfcffff           call 0x7ed770
// 007edb25  5b                   pop ebx
// 007edb26  8bc7                 mov eax, edi
// 007edb28  5f                   pop edi
// 007edb29  5e                   pop esi
// 007edb2a  83c414               add esp, 0x14
// 007edb2d  c21000               ret 0x10
// 007edb30  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007edb33  8b16                 mov edx, dword ptr [esi]
// 007edb35  85c9                 test ecx, ecx
// 007edb37  7404                 je 0x7edb3d
// 007edb39  3bca                 cmp ecx, edx
// 007edb3b  740a                 je 0x7edb47
// 007edb3d  ffd3                 call ebx
// 007edb3f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007edb43  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007edb47  3bc7                 cmp eax, edi
// 007edb49  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007edb4d  752c                 jne 0x7edb7b
// 007edb4f  8b5618               mov edx, dword ptr [esi + 0x18]
// 007edb52  8b4208               mov eax, dword ptr [edx + 8]
// 007edb55  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007edb58  3b0f                 cmp ecx, dword ptr [edi]
// 007edb5a  0f8300010000         jae 0x7edc60
// 007edb60  57                   push edi
// 007edb61  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007edb65  50                   push eax
// 007edb66  6a00                 push 0
// 007edb68  57                   push edi
// 007edb69  8bce                 mov ecx, esi
// 007edb6b  e800fcffff           call 0x7ed770
// 007edb70  5b                   pop ebx
// 007edb71  8bc7                 mov eax, edi
// 007edb73  5f                   pop edi
// 007edb74  5e                   pop esi
// 007edb75  83c414               add esp, 0x14
// 007edb78  c21000               ret 0x10
// 007edb7b  8b17                 mov edx, dword ptr [edi]
// 007edb7d  39500c               cmp dword ptr [eax + 0xc], edx
// 007edb80  7663                 jbe 0x7edbe5
// 007edb82  894c240c             mov dword ptr [esp + 0xc], ecx
// 007edb86  8d4c240c             lea ecx, [esp + 0xc]
// 007edb8a  89442410             mov dword ptr [esp + 0x10], eax
// 007edb8e  e89d66c5ff           call 0x444230
// 007edb93  8b17                 mov edx, dword ptr [edi]
// 007edb95  8b442410             mov eax, dword ptr [esp + 0x10]
// 007edb99  39500c               cmp dword ptr [eax + 0xc], edx
// 007edb9c  733c                 jae 0x7edbda
// 007edb9e  8b5008               mov edx, dword ptr [eax + 8]
// 007edba1  807a1500             cmp byte ptr [edx + 0x15], 0
// 007edba5  57                   push edi
// 007edba6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007edbaa  8bce                 mov ecx, esi
// 007edbac  7414                 je 0x7edbc2
// 007edbae  50                   push eax
// 007edbaf  6a00                 push 0
// 007edbb1  57                   push edi
// 007edbb2  e8b9fbffff           call 0x7ed770
// 007edbb7  5b                   pop ebx
// 007edbb8  8bc7                 mov eax, edi
// 007edbba  5f                   pop edi
// 007edbbb  5e                   pop esi
// 007edbbc  83c414               add esp, 0x14
// 007edbbf  c21000               ret 0x10
// 007edbc2  8b442430             mov eax, dword ptr [esp + 0x30]
// 007edbc6  50                   push eax
// 007edbc7  6a01                 push 1
// 007edbc9  57                   push edi
// 007edbca  e8a1fbffff           call 0x7ed770
// 007edbcf  5b                   pop ebx
// 007edbd0  8bc7                 mov eax, edi
// 007edbd2  5f                   pop edi
// 007edbd3  5e                   pop esi
// 007edbd4  83c414               add esp, 0x14
// 007edbd7  c21000               ret 0x10
// 007edbda  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007edbde  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007edbe2  39500c               cmp dword ptr [eax + 0xc], edx
// 007edbe5  7379                 jae 0x7edc60
// 007edbe7  8b16                 mov edx, dword ptr [esi]
// 007edbe9  894c240c             mov dword ptr [esp + 0xc], ecx
// 007edbed  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007edbf0  894c2418             mov dword ptr [esp + 0x18], ecx
// 007edbf4  8d4c240c             lea ecx, [esp + 0xc]
// 007edbf8  89442410             mov dword ptr [esp + 0x10], eax
// 007edbfc  89542414             mov dword ptr [esp + 0x14], edx
// 007edc00  e8ebf4ebff           call 0x6ad0f0
// 007edc05  8d442414             lea eax, [esp + 0x14]
// 007edc09  50                   push eax
// 007edc0a  8d4c2410             lea ecx, [esp + 0x10]
// 007edc0e  e84de7ddff           call 0x5cc360
// 007edc13  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007edc17  84c0                 test al, al
// 007edc19  7507                 jne 0x7edc22
// 007edc1b  8b17                 mov edx, dword ptr [edi]
// 007edc1d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007edc20  733e                 jae 0x7edc60
// 007edc22  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007edc26  8b5008               mov edx, dword ptr [eax + 8]
// 007edc29  807a1500             cmp byte ptr [edx + 0x15], 0
// 007edc2d  57                   push edi
// 007edc2e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007edc32  7416                 je 0x7edc4a
// 007edc34  50                   push eax
// 007edc35  6a00                 push 0
// 007edc37  57                   push edi
// 007edc38  8bce                 mov ecx, esi
// 007edc3a  e831fbffff           call 0x7ed770
// 007edc3f  5b                   pop ebx
// 007edc40  8bc7                 mov eax, edi
// 007edc42  5f                   pop edi
// 007edc43  5e                   pop esi
// 007edc44  83c414               add esp, 0x14
// 007edc47  c21000               ret 0x10
// 007edc4a  51                   push ecx
// 007edc4b  6a01                 push 1
// 007edc4d  57                   push edi
// 007edc4e  8bce                 mov ecx, esi
// 007edc50  e81bfbffff           call 0x7ed770
// 007edc55  5b                   pop ebx
// 007edc56  8bc7                 mov eax, edi
// 007edc58  5f                   pop edi
// 007edc59  5e                   pop esi
// 007edc5a  83c414               add esp, 0x14
// 007edc5d  c21000               ret 0x10
// 007edc60  57                   push edi
// 007edc61  8d442418             lea eax, [esp + 0x18]
// 007edc65  50                   push eax
// 007edc66  8bce                 mov ecx, esi
// 007edc68  e853fdffff           call 0x7ed9c0
// 007edc6d  8b10                 mov edx, dword ptr [eax]
// 007edc6f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007edc73  5b                   pop ebx
// 007edc74  8911                 mov dword ptr [ecx], edx
// 007edc76  8b4004               mov eax, dword ptr [eax + 4]
// 007edc79  5f                   pop edi
// 007edc7a  894104               mov dword ptr [ecx + 4], eax
// 007edc7d  8bc1                 mov eax, ecx
// 007edc7f  5e                   pop esi
// 007edc80  83c414               add esp, 0x14
// 007edc83  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
