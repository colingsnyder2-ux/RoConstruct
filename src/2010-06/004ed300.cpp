// from server: 100% by auto
// roc 2010-06 004ed300  unit: RBX::Network::Replicator::NewInstanceItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed300
//
// 004ed300  83ec14               sub esp, 0x14
// 004ed303  56                   push esi
// 004ed304  8bf1                 mov esi, ecx
// 004ed306  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 004ed30a  57                   push edi
// 004ed30b  7521                 jne 0x4ed32e
// 004ed30d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ed311  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ed314  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed318  50                   push eax
// 004ed319  51                   push ecx
// 004ed31a  6a01                 push 1
// 004ed31c  57                   push edi
// 004ed31d  8bce                 mov ecx, esi
// 004ed31f  e8ccd9ffff           call 0x4eacf0
// 004ed324  8bc7                 mov eax, edi
// 004ed326  5f                   pop edi
// 004ed327  5e                   pop esi
// 004ed328  83c414               add esp, 0x14
// 004ed32b  c21000               ret 0x10
// 004ed32e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ed332  8b5618               mov edx, dword ptr [esi + 0x18]
// 004ed335  8b3a                 mov edi, dword ptr [edx]
// 004ed337  8b06                 mov eax, dword ptr [esi]
// 004ed339  53                   push ebx
// 004ed33a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 004ed340  85c9                 test ecx, ecx
// 004ed342  7404                 je 0x4ed348
// 004ed344  3bc8                 cmp ecx, eax
// 004ed346  7406                 je 0x4ed34e
// 004ed348  ffd3                 call ebx
// 004ed34a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ed34e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ed352  3bc7                 cmp eax, edi
// 004ed354  752a                 jne 0x4ed380
// 004ed356  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004ed35a  8b0f                 mov ecx, dword ptr [edi]
// 004ed35c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004ed35f  0f834b010000         jae 0x4ed4b0
// 004ed365  57                   push edi
// 004ed366  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004ed36a  50                   push eax
// 004ed36b  6a01                 push 1
// 004ed36d  57                   push edi
// 004ed36e  8bce                 mov ecx, esi
// 004ed370  e87bd9ffff           call 0x4eacf0
// 004ed375  5b                   pop ebx
// 004ed376  8bc7                 mov eax, edi
// 004ed378  5f                   pop edi
// 004ed379  5e                   pop esi
// 004ed37a  83c414               add esp, 0x14
// 004ed37d  c21000               ret 0x10
// 004ed380  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004ed383  8b16                 mov edx, dword ptr [esi]
// 004ed385  85c9                 test ecx, ecx
// 004ed387  7404                 je 0x4ed38d
// 004ed389  3bca                 cmp ecx, edx
// 004ed38b  740a                 je 0x4ed397
// 004ed38d  ffd3                 call ebx
// 004ed38f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ed393  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ed397  3bc7                 cmp eax, edi
// 004ed399  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004ed39d  752c                 jne 0x4ed3cb
// 004ed39f  8b5618               mov edx, dword ptr [esi + 0x18]
// 004ed3a2  8b4208               mov eax, dword ptr [edx + 8]
// 004ed3a5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004ed3a8  3b0f                 cmp ecx, dword ptr [edi]
// 004ed3aa  0f8300010000         jae 0x4ed4b0
// 004ed3b0  57                   push edi
// 004ed3b1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004ed3b5  50                   push eax
// 004ed3b6  6a00                 push 0
// 004ed3b8  57                   push edi
// 004ed3b9  8bce                 mov ecx, esi
// 004ed3bb  e830d9ffff           call 0x4eacf0
// 004ed3c0  5b                   pop ebx
// 004ed3c1  8bc7                 mov eax, edi
// 004ed3c3  5f                   pop edi
// 004ed3c4  5e                   pop esi
// 004ed3c5  83c414               add esp, 0x14
// 004ed3c8  c21000               ret 0x10
// 004ed3cb  8b17                 mov edx, dword ptr [edi]
// 004ed3cd  39500c               cmp dword ptr [eax + 0xc], edx
// 004ed3d0  7663                 jbe 0x4ed435
// 004ed3d2  894c240c             mov dword ptr [esp + 0xc], ecx
// 004ed3d6  8d4c240c             lea ecx, [esp + 0xc]
// 004ed3da  89442410             mov dword ptr [esp + 0x10], eax
// 004ed3de  e8dd6ef4ff           call 0x4342c0
// 004ed3e3  8b17                 mov edx, dword ptr [edi]
// 004ed3e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004ed3e9  39500c               cmp dword ptr [eax + 0xc], edx
// 004ed3ec  733c                 jae 0x4ed42a
// 004ed3ee  8b5008               mov edx, dword ptr [eax + 8]
// 004ed3f1  807a1900             cmp byte ptr [edx + 0x19], 0
// 004ed3f5  57                   push edi
// 004ed3f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004ed3fa  8bce                 mov ecx, esi
// 004ed3fc  7414                 je 0x4ed412
// 004ed3fe  50                   push eax
// 004ed3ff  6a00                 push 0
// 004ed401  57                   push edi
// 004ed402  e8e9d8ffff           call 0x4eacf0
// 004ed407  5b                   pop ebx
// 004ed408  8bc7                 mov eax, edi
// 004ed40a  5f                   pop edi
// 004ed40b  5e                   pop esi
// 004ed40c  83c414               add esp, 0x14
// 004ed40f  c21000               ret 0x10
// 004ed412  8b442430             mov eax, dword ptr [esp + 0x30]
// 004ed416  50                   push eax
// 004ed417  6a01                 push 1
// 004ed419  57                   push edi
// 004ed41a  e8d1d8ffff           call 0x4eacf0
// 004ed41f  5b                   pop ebx
// 004ed420  8bc7                 mov eax, edi
// 004ed422  5f                   pop edi
// 004ed423  5e                   pop esi
// 004ed424  83c414               add esp, 0x14
// 004ed427  c21000               ret 0x10
// 004ed42a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ed42e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ed432  39500c               cmp dword ptr [eax + 0xc], edx
// 004ed435  7379                 jae 0x4ed4b0
// 004ed437  8b16                 mov edx, dword ptr [esi]
// 004ed439  894c240c             mov dword ptr [esp + 0xc], ecx
// 004ed43d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ed440  894c2418             mov dword ptr [esp + 0x18], ecx
// 004ed444  8d4c240c             lea ecx, [esp + 0xc]
// 004ed448  89442410             mov dword ptr [esp + 0x10], eax
// 004ed44c  89542414             mov dword ptr [esp + 0x14], edx
// 004ed450  e8db95ffff           call 0x4e6a30
// 004ed455  8d442414             lea eax, [esp + 0x14]
// 004ed459  50                   push eax
// 004ed45a  8d4c2410             lea ecx, [esp + 0x10]
// 004ed45e  e81d9bf7ff           call 0x466f80
// 004ed463  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ed467  84c0                 test al, al
// 004ed469  7507                 jne 0x4ed472
// 004ed46b  8b17                 mov edx, dword ptr [edi]
// 004ed46d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 004ed470  733e                 jae 0x4ed4b0
// 004ed472  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004ed476  8b5008               mov edx, dword ptr [eax + 8]
// 004ed479  807a1900             cmp byte ptr [edx + 0x19], 0
// 004ed47d  57                   push edi
// 004ed47e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004ed482  7416                 je 0x4ed49a
// 004ed484  50                   push eax
// 004ed485  6a00                 push 0
// 004ed487  57                   push edi
// 004ed488  8bce                 mov ecx, esi
// 004ed48a  e861d8ffff           call 0x4eacf0
// 004ed48f  5b                   pop ebx
// 004ed490  8bc7                 mov eax, edi
// 004ed492  5f                   pop edi
// 004ed493  5e                   pop esi
// 004ed494  83c414               add esp, 0x14
// 004ed497  c21000               ret 0x10
// 004ed49a  51                   push ecx
// 004ed49b  6a01                 push 1
// 004ed49d  57                   push edi
// 004ed49e  8bce                 mov ecx, esi
// 004ed4a0  e84bd8ffff           call 0x4eacf0
// 004ed4a5  5b                   pop ebx
// 004ed4a6  8bc7                 mov eax, edi
// 004ed4a8  5f                   pop edi
// 004ed4a9  5e                   pop esi
// 004ed4aa  83c414               add esp, 0x14
// 004ed4ad  c21000               ret 0x10
// 004ed4b0  57                   push edi
// 004ed4b1  8d442418             lea eax, [esp + 0x18]
// 004ed4b5  50                   push eax
// 004ed4b6  8bce                 mov ecx, esi
// 004ed4b8  e883ecffff           call 0x4ec140
// 004ed4bd  8b10                 mov edx, dword ptr [eax]
// 004ed4bf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ed4c3  5b                   pop ebx
// 004ed4c4  8911                 mov dword ptr [ecx], edx
// 004ed4c6  8b4004               mov eax, dword ptr [eax + 4]
// 004ed4c9  5f                   pop edi
// 004ed4ca  894104               mov dword ptr [ecx + 4], eax
// 004ed4cd  8bc1                 mov eax, ecx
// 004ed4cf  5e                   pop esi
// 004ed4d0  83c414               add esp, 0x14
// 004ed4d3  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
