// from server: 100% by auto
// roc 2009-06 006e51c0  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e51c0
//
// 006e51c0  83ec14               sub esp, 0x14
// 006e51c3  56                   push esi
// 006e51c4  8bf1                 mov esi, ecx
// 006e51c6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006e51ca  57                   push edi
// 006e51cb  7521                 jne 0x6e51ee
// 006e51cd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e51d1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e51d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e51d8  50                   push eax
// 006e51d9  51                   push ecx
// 006e51da  6a01                 push 1
// 006e51dc  57                   push edi
// 006e51dd  8bce                 mov ecx, esi
// 006e51df  e86ceaffff           call 0x6e3c50
// 006e51e4  8bc7                 mov eax, edi
// 006e51e6  5f                   pop edi
// 006e51e7  5e                   pop esi
// 006e51e8  83c414               add esp, 0x14
// 006e51eb  c21000               ret 0x10
// 006e51ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006e51f2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e51f5  8b3a                 mov edi, dword ptr [edx]
// 006e51f7  8b06                 mov eax, dword ptr [esi]
// 006e51f9  53                   push ebx
// 006e51fa  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006e5200  85c9                 test ecx, ecx
// 006e5202  7404                 je 0x6e5208
// 006e5204  3bc8                 cmp ecx, eax
// 006e5206  7406                 je 0x6e520e
// 006e5208  ffd3                 call ebx
// 006e520a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e520e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e5212  3bc7                 cmp eax, edi
// 006e5214  752a                 jne 0x6e5240
// 006e5216  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006e521a  8b0f                 mov ecx, dword ptr [edi]
// 006e521c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006e521f  0f834b010000         jae 0x6e5370
// 006e5225  57                   push edi
// 006e5226  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e522a  50                   push eax
// 006e522b  6a01                 push 1
// 006e522d  57                   push edi
// 006e522e  8bce                 mov ecx, esi
// 006e5230  e81beaffff           call 0x6e3c50
// 006e5235  5b                   pop ebx
// 006e5236  8bc7                 mov eax, edi
// 006e5238  5f                   pop edi
// 006e5239  5e                   pop esi
// 006e523a  83c414               add esp, 0x14
// 006e523d  c21000               ret 0x10
// 006e5240  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006e5243  8b16                 mov edx, dword ptr [esi]
// 006e5245  85c9                 test ecx, ecx
// 006e5247  7404                 je 0x6e524d
// 006e5249  3bca                 cmp ecx, edx
// 006e524b  740a                 je 0x6e5257
// 006e524d  ffd3                 call ebx
// 006e524f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e5253  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e5257  3bc7                 cmp eax, edi
// 006e5259  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006e525d  752c                 jne 0x6e528b
// 006e525f  8b5618               mov edx, dword ptr [esi + 0x18]
// 006e5262  8b4208               mov eax, dword ptr [edx + 8]
// 006e5265  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006e5268  3b0f                 cmp ecx, dword ptr [edi]
// 006e526a  0f8300010000         jae 0x6e5370
// 006e5270  57                   push edi
// 006e5271  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e5275  50                   push eax
// 006e5276  6a00                 push 0
// 006e5278  57                   push edi
// 006e5279  8bce                 mov ecx, esi
// 006e527b  e8d0e9ffff           call 0x6e3c50
// 006e5280  5b                   pop ebx
// 006e5281  8bc7                 mov eax, edi
// 006e5283  5f                   pop edi
// 006e5284  5e                   pop esi
// 006e5285  83c414               add esp, 0x14
// 006e5288  c21000               ret 0x10
// 006e528b  8b17                 mov edx, dword ptr [edi]
// 006e528d  39500c               cmp dword ptr [eax + 0xc], edx
// 006e5290  7663                 jbe 0x6e52f5
// 006e5292  894c240c             mov dword ptr [esp + 0xc], ecx
// 006e5296  8d4c240c             lea ecx, [esp + 0xc]
// 006e529a  89442410             mov dword ptr [esp + 0x10], eax
// 006e529e  e80de1f3ff           call 0x6233b0
// 006e52a3  8b17                 mov edx, dword ptr [edi]
// 006e52a5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006e52a9  39500c               cmp dword ptr [eax + 0xc], edx
// 006e52ac  733c                 jae 0x6e52ea
// 006e52ae  8b5008               mov edx, dword ptr [eax + 8]
// 006e52b1  807a3100             cmp byte ptr [edx + 0x31], 0
// 006e52b5  57                   push edi
// 006e52b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e52ba  8bce                 mov ecx, esi
// 006e52bc  7414                 je 0x6e52d2
// 006e52be  50                   push eax
// 006e52bf  6a00                 push 0
// 006e52c1  57                   push edi
// 006e52c2  e889e9ffff           call 0x6e3c50
// 006e52c7  5b                   pop ebx
// 006e52c8  8bc7                 mov eax, edi
// 006e52ca  5f                   pop edi
// 006e52cb  5e                   pop esi
// 006e52cc  83c414               add esp, 0x14
// 006e52cf  c21000               ret 0x10
// 006e52d2  8b442430             mov eax, dword ptr [esp + 0x30]
// 006e52d6  50                   push eax
// 006e52d7  6a01                 push 1
// 006e52d9  57                   push edi
// 006e52da  e871e9ffff           call 0x6e3c50
// 006e52df  5b                   pop ebx
// 006e52e0  8bc7                 mov eax, edi
// 006e52e2  5f                   pop edi
// 006e52e3  5e                   pop esi
// 006e52e4  83c414               add esp, 0x14
// 006e52e7  c21000               ret 0x10
// 006e52ea  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e52ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e52f2  39500c               cmp dword ptr [eax + 0xc], edx
// 006e52f5  7379                 jae 0x6e5370
// 006e52f7  8b16                 mov edx, dword ptr [esi]
// 006e52f9  894c240c             mov dword ptr [esp + 0xc], ecx
// 006e52fd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e5300  894c2418             mov dword ptr [esp + 0x18], ecx
// 006e5304  8d4c240c             lea ecx, [esp + 0xc]
// 006e5308  89442410             mov dword ptr [esp + 0x10], eax
// 006e530c  89542414             mov dword ptr [esp + 0x14], edx
// 006e5310  e89bcfffff           call 0x6e22b0
// 006e5315  8d442414             lea eax, [esp + 0x14]
// 006e5319  50                   push eax
// 006e531a  8d4c2410             lea ecx, [esp + 0x10]
// 006e531e  e87de1f5ff           call 0x6434a0
// 006e5323  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e5327  84c0                 test al, al
// 006e5329  7507                 jne 0x6e5332
// 006e532b  8b17                 mov edx, dword ptr [edi]
// 006e532d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006e5330  733e                 jae 0x6e5370
// 006e5332  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e5336  8b5008               mov edx, dword ptr [eax + 8]
// 006e5339  807a3100             cmp byte ptr [edx + 0x31], 0
// 006e533d  57                   push edi
// 006e533e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006e5342  7416                 je 0x6e535a
// 006e5344  50                   push eax
// 006e5345  6a00                 push 0
// 006e5347  57                   push edi
// 006e5348  8bce                 mov ecx, esi
// 006e534a  e801e9ffff           call 0x6e3c50
// 006e534f  5b                   pop ebx
// 006e5350  8bc7                 mov eax, edi
// 006e5352  5f                   pop edi
// 006e5353  5e                   pop esi
// 006e5354  83c414               add esp, 0x14
// 006e5357  c21000               ret 0x10
// 006e535a  51                   push ecx
// 006e535b  6a01                 push 1
// 006e535d  57                   push edi
// 006e535e  8bce                 mov ecx, esi
// 006e5360  e8ebe8ffff           call 0x6e3c50
// 006e5365  5b                   pop ebx
// 006e5366  8bc7                 mov eax, edi
// 006e5368  5f                   pop edi
// 006e5369  5e                   pop esi
// 006e536a  83c414               add esp, 0x14
// 006e536d  c21000               ret 0x10
// 006e5370  57                   push edi
// 006e5371  8d442418             lea eax, [esp + 0x18]
// 006e5375  50                   push eax
// 006e5376  8bce                 mov ecx, esi
// 006e5378  e8e3f2ffff           call 0x6e4660
// 006e537d  8b10                 mov edx, dword ptr [eax]
// 006e537f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006e5383  5b                   pop ebx
// 006e5384  8911                 mov dword ptr [ecx], edx
// 006e5386  8b4004               mov eax, dword ptr [eax + 4]
// 006e5389  5f                   pop edi
// 006e538a  894104               mov dword ptr [ecx + 4], eax
// 006e538d  8bc1                 mov eax, ecx
// 006e538f  5e                   pop esi
// 006e5390  83c414               add esp, 0x14
// 006e5393  c21000               ret 0x10
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
