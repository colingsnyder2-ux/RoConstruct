// from server: 100% by auto
// roc 2008-06 005ba480  unit: RBX::Soundscape::SoundChannel  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ba480
//
// 005ba480  83ec14               sub esp, 0x14
// 005ba483  56                   push esi
// 005ba484  8bf1                 mov esi, ecx
// 005ba486  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005ba48a  57                   push edi
// 005ba48b  7521                 jne 0x5ba4ae
// 005ba48d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ba491  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ba494  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba498  50                   push eax
// 005ba499  51                   push ecx
// 005ba49a  6a01                 push 1
// 005ba49c  57                   push edi
// 005ba49d  8bce                 mov ecx, esi
// 005ba49f  e8cc3eefff           call 0x4ae370
// 005ba4a4  8bc7                 mov eax, edi
// 005ba4a6  5f                   pop edi
// 005ba4a7  5e                   pop esi
// 005ba4a8  83c414               add esp, 0x14
// 005ba4ab  c21000               ret 0x10
// 005ba4ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005ba4b2  8b5618               mov edx, dword ptr [esi + 0x18]
// 005ba4b5  8b3a                 mov edi, dword ptr [edx]
// 005ba4b7  8b06                 mov eax, dword ptr [esi]
// 005ba4b9  53                   push ebx
// 005ba4ba  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005ba4c0  85c9                 test ecx, ecx
// 005ba4c2  7404                 je 0x5ba4c8
// 005ba4c4  3bc8                 cmp ecx, eax
// 005ba4c6  7406                 je 0x5ba4ce
// 005ba4c8  ffd3                 call ebx
// 005ba4ca  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ba4ce  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ba4d2  3bc7                 cmp eax, edi
// 005ba4d4  752a                 jne 0x5ba500
// 005ba4d6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005ba4da  8b0f                 mov ecx, dword ptr [edi]
// 005ba4dc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005ba4df  0f8d4b010000         jge 0x5ba630
// 005ba4e5  57                   push edi
// 005ba4e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005ba4ea  50                   push eax
// 005ba4eb  6a01                 push 1
// 005ba4ed  57                   push edi
// 005ba4ee  8bce                 mov ecx, esi
// 005ba4f0  e87b3eefff           call 0x4ae370
// 005ba4f5  5b                   pop ebx
// 005ba4f6  8bc7                 mov eax, edi
// 005ba4f8  5f                   pop edi
// 005ba4f9  5e                   pop esi
// 005ba4fa  83c414               add esp, 0x14
// 005ba4fd  c21000               ret 0x10
// 005ba500  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005ba503  8b16                 mov edx, dword ptr [esi]
// 005ba505  85c9                 test ecx, ecx
// 005ba507  7404                 je 0x5ba50d
// 005ba509  3bca                 cmp ecx, edx
// 005ba50b  740a                 je 0x5ba517
// 005ba50d  ffd3                 call ebx
// 005ba50f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ba513  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ba517  3bc7                 cmp eax, edi
// 005ba519  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005ba51d  752c                 jne 0x5ba54b
// 005ba51f  8b5618               mov edx, dword ptr [esi + 0x18]
// 005ba522  8b4208               mov eax, dword ptr [edx + 8]
// 005ba525  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005ba528  3b0f                 cmp ecx, dword ptr [edi]
// 005ba52a  0f8d00010000         jge 0x5ba630
// 005ba530  57                   push edi
// 005ba531  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005ba535  50                   push eax
// 005ba536  6a00                 push 0
// 005ba538  57                   push edi
// 005ba539  8bce                 mov ecx, esi
// 005ba53b  e8303eefff           call 0x4ae370
// 005ba540  5b                   pop ebx
// 005ba541  8bc7                 mov eax, edi
// 005ba543  5f                   pop edi
// 005ba544  5e                   pop esi
// 005ba545  83c414               add esp, 0x14
// 005ba548  c21000               ret 0x10
// 005ba54b  8b17                 mov edx, dword ptr [edi]
// 005ba54d  39500c               cmp dword ptr [eax + 0xc], edx
// 005ba550  7e63                 jle 0x5ba5b5
// 005ba552  894c240c             mov dword ptr [esp + 0xc], ecx
// 005ba556  8d4c240c             lea ecx, [esp + 0xc]
// 005ba55a  89442410             mov dword ptr [esp + 0x10], eax
// 005ba55e  e8dd19efff           call 0x4abf40
// 005ba563  8b17                 mov edx, dword ptr [edi]
// 005ba565  8b442410             mov eax, dword ptr [esp + 0x10]
// 005ba569  39500c               cmp dword ptr [eax + 0xc], edx
// 005ba56c  7d3c                 jge 0x5ba5aa
// 005ba56e  8b5008               mov edx, dword ptr [eax + 8]
// 005ba571  807a1900             cmp byte ptr [edx + 0x19], 0
// 005ba575  57                   push edi
// 005ba576  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005ba57a  8bce                 mov ecx, esi
// 005ba57c  7414                 je 0x5ba592
// 005ba57e  50                   push eax
// 005ba57f  6a00                 push 0
// 005ba581  57                   push edi
// 005ba582  e8e93defff           call 0x4ae370
// 005ba587  5b                   pop ebx
// 005ba588  8bc7                 mov eax, edi
// 005ba58a  5f                   pop edi
// 005ba58b  5e                   pop esi
// 005ba58c  83c414               add esp, 0x14
// 005ba58f  c21000               ret 0x10
// 005ba592  8b442430             mov eax, dword ptr [esp + 0x30]
// 005ba596  50                   push eax
// 005ba597  6a01                 push 1
// 005ba599  57                   push edi
// 005ba59a  e8d13defff           call 0x4ae370
// 005ba59f  5b                   pop ebx
// 005ba5a0  8bc7                 mov eax, edi
// 005ba5a2  5f                   pop edi
// 005ba5a3  5e                   pop esi
// 005ba5a4  83c414               add esp, 0x14
// 005ba5a7  c21000               ret 0x10
// 005ba5aa  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ba5ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ba5b2  39500c               cmp dword ptr [eax + 0xc], edx
// 005ba5b5  7d79                 jge 0x5ba630
// 005ba5b7  8b16                 mov edx, dword ptr [esi]
// 005ba5b9  894c240c             mov dword ptr [esp + 0xc], ecx
// 005ba5bd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ba5c0  894c2418             mov dword ptr [esp + 0x18], ecx
// 005ba5c4  8d4c240c             lea ecx, [esp + 0xc]
// 005ba5c8  89442410             mov dword ptr [esp + 0x10], eax
// 005ba5cc  89542414             mov dword ptr [esp + 0x14], edx
// 005ba5d0  e87bccffff           call 0x5b7250
// 005ba5d5  8d442414             lea eax, [esp + 0x14]
// 005ba5d9  50                   push eax
// 005ba5da  8d4c2410             lea ecx, [esp + 0x10]
// 005ba5de  e8bd260300           call 0x5ecca0
// 005ba5e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ba5e7  84c0                 test al, al
// 005ba5e9  7507                 jne 0x5ba5f2
// 005ba5eb  8b17                 mov edx, dword ptr [edi]
// 005ba5ed  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 005ba5f0  7d3e                 jge 0x5ba630
// 005ba5f2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ba5f6  8b5008               mov edx, dword ptr [eax + 8]
// 005ba5f9  807a1900             cmp byte ptr [edx + 0x19], 0
// 005ba5fd  57                   push edi
// 005ba5fe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005ba602  7416                 je 0x5ba61a
// 005ba604  50                   push eax
// 005ba605  6a00                 push 0
// 005ba607  57                   push edi
// 005ba608  8bce                 mov ecx, esi
// 005ba60a  e8613defff           call 0x4ae370
// 005ba60f  5b                   pop ebx
// 005ba610  8bc7                 mov eax, edi
// 005ba612  5f                   pop edi
// 005ba613  5e                   pop esi
// 005ba614  83c414               add esp, 0x14
// 005ba617  c21000               ret 0x10
// 005ba61a  51                   push ecx
// 005ba61b  6a01                 push 1
// 005ba61d  57                   push edi
// 005ba61e  8bce                 mov ecx, esi
// 005ba620  e84b3defff           call 0x4ae370
// 005ba625  5b                   pop ebx
// 005ba626  8bc7                 mov eax, edi
// 005ba628  5f                   pop edi
// 005ba629  5e                   pop esi
// 005ba62a  83c414               add esp, 0x14
// 005ba62d  c21000               ret 0x10
// 005ba630  57                   push edi
// 005ba631  8d442418             lea eax, [esp + 0x18]
// 005ba635  50                   push eax
// 005ba636  8bce                 mov ecx, esi
// 005ba638  e803f8ffff           call 0x5b9e40
// 005ba63d  8b10                 mov edx, dword ptr [eax]
// 005ba63f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005ba643  5b                   pop ebx
// 005ba644  8911                 mov dword ptr [ecx], edx
// 005ba646  8b4004               mov eax, dword ptr [eax + 4]
// 005ba649  5f                   pop edi
// 005ba64a  894104               mov dword ptr [ecx + 4], eax
// 005ba64d  8bc1                 mov eax, ecx
// 005ba64f  5e                   pop esi
// 005ba650  83c414               add esp, 0x14
// 005ba653  c21000               ret 0x10
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
