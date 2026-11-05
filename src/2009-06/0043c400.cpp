// from server: 100% by auto
// roc 2009-06 0043c400  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c400
//
// 0043c400  83ec14               sub esp, 0x14
// 0043c403  56                   push esi
// 0043c404  8bf1                 mov esi, ecx
// 0043c406  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0043c40a  57                   push edi
// 0043c40b  7521                 jne 0x43c42e
// 0043c40d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043c411  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043c414  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c418  50                   push eax
// 0043c419  51                   push ecx
// 0043c41a  6a01                 push 1
// 0043c41c  57                   push edi
// 0043c41d  8bce                 mov ecx, esi
// 0043c41f  e8dceaffff           call 0x43af00
// 0043c424  8bc7                 mov eax, edi
// 0043c426  5f                   pop edi
// 0043c427  5e                   pop esi
// 0043c428  83c414               add esp, 0x14
// 0043c42b  c21000               ret 0x10
// 0043c42e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043c432  8b5618               mov edx, dword ptr [esi + 0x18]
// 0043c435  8b3a                 mov edi, dword ptr [edx]
// 0043c437  8b06                 mov eax, dword ptr [esi]
// 0043c439  53                   push ebx
// 0043c43a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 0043c440  85c9                 test ecx, ecx
// 0043c442  7404                 je 0x43c448
// 0043c444  3bc8                 cmp ecx, eax
// 0043c446  7406                 je 0x43c44e
// 0043c448  ffd3                 call ebx
// 0043c44a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043c44e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043c452  3bc7                 cmp eax, edi
// 0043c454  752a                 jne 0x43c480
// 0043c456  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043c45a  8b0f                 mov ecx, dword ptr [edi]
// 0043c45c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0043c45f  0f834b010000         jae 0x43c5b0
// 0043c465  57                   push edi
// 0043c466  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043c46a  50                   push eax
// 0043c46b  6a01                 push 1
// 0043c46d  57                   push edi
// 0043c46e  8bce                 mov ecx, esi
// 0043c470  e88beaffff           call 0x43af00
// 0043c475  5b                   pop ebx
// 0043c476  8bc7                 mov eax, edi
// 0043c478  5f                   pop edi
// 0043c479  5e                   pop esi
// 0043c47a  83c414               add esp, 0x14
// 0043c47d  c21000               ret 0x10
// 0043c480  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0043c483  8b16                 mov edx, dword ptr [esi]
// 0043c485  85c9                 test ecx, ecx
// 0043c487  7404                 je 0x43c48d
// 0043c489  3bca                 cmp ecx, edx
// 0043c48b  740a                 je 0x43c497
// 0043c48d  ffd3                 call ebx
// 0043c48f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043c493  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043c497  3bc7                 cmp eax, edi
// 0043c499  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043c49d  752c                 jne 0x43c4cb
// 0043c49f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0043c4a2  8b4208               mov eax, dword ptr [edx + 8]
// 0043c4a5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0043c4a8  3b0f                 cmp ecx, dword ptr [edi]
// 0043c4aa  0f8300010000         jae 0x43c5b0
// 0043c4b0  57                   push edi
// 0043c4b1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043c4b5  50                   push eax
// 0043c4b6  6a00                 push 0
// 0043c4b8  57                   push edi
// 0043c4b9  8bce                 mov ecx, esi
// 0043c4bb  e840eaffff           call 0x43af00
// 0043c4c0  5b                   pop ebx
// 0043c4c1  8bc7                 mov eax, edi
// 0043c4c3  5f                   pop edi
// 0043c4c4  5e                   pop esi
// 0043c4c5  83c414               add esp, 0x14
// 0043c4c8  c21000               ret 0x10
// 0043c4cb  8b17                 mov edx, dword ptr [edi]
// 0043c4cd  39500c               cmp dword ptr [eax + 0xc], edx
// 0043c4d0  7663                 jbe 0x43c535
// 0043c4d2  894c240c             mov dword ptr [esp + 0xc], ecx
// 0043c4d6  8d4c240c             lea ecx, [esp + 0xc]
// 0043c4da  89442410             mov dword ptr [esp + 0x10], eax
// 0043c4de  e81db20d00           call 0x517700
// 0043c4e3  8b17                 mov edx, dword ptr [edi]
// 0043c4e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043c4e9  39500c               cmp dword ptr [eax + 0xc], edx
// 0043c4ec  733c                 jae 0x43c52a
// 0043c4ee  8b5008               mov edx, dword ptr [eax + 8]
// 0043c4f1  807a2900             cmp byte ptr [edx + 0x29], 0
// 0043c4f5  57                   push edi
// 0043c4f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043c4fa  8bce                 mov ecx, esi
// 0043c4fc  7414                 je 0x43c512
// 0043c4fe  50                   push eax
// 0043c4ff  6a00                 push 0
// 0043c501  57                   push edi
// 0043c502  e8f9e9ffff           call 0x43af00
// 0043c507  5b                   pop ebx
// 0043c508  8bc7                 mov eax, edi
// 0043c50a  5f                   pop edi
// 0043c50b  5e                   pop esi
// 0043c50c  83c414               add esp, 0x14
// 0043c50f  c21000               ret 0x10
// 0043c512  8b442430             mov eax, dword ptr [esp + 0x30]
// 0043c516  50                   push eax
// 0043c517  6a01                 push 1
// 0043c519  57                   push edi
// 0043c51a  e8e1e9ffff           call 0x43af00
// 0043c51f  5b                   pop ebx
// 0043c520  8bc7                 mov eax, edi
// 0043c522  5f                   pop edi
// 0043c523  5e                   pop esi
// 0043c524  83c414               add esp, 0x14
// 0043c527  c21000               ret 0x10
// 0043c52a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043c52e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043c532  39500c               cmp dword ptr [eax + 0xc], edx
// 0043c535  7379                 jae 0x43c5b0
// 0043c537  8b16                 mov edx, dword ptr [esi]
// 0043c539  894c240c             mov dword ptr [esp + 0xc], ecx
// 0043c53d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043c540  894c2418             mov dword ptr [esp + 0x18], ecx
// 0043c544  8d4c240c             lea ecx, [esp + 0xc]
// 0043c548  89442410             mov dword ptr [esp + 0x10], eax
// 0043c54c  89542414             mov dword ptr [esp + 0x14], edx
// 0043c550  e81bb30d00           call 0x517870
// 0043c555  8d442414             lea eax, [esp + 0x14]
// 0043c559  50                   push eax
// 0043c55a  8d4c2410             lea ecx, [esp + 0x10]
// 0043c55e  e83d6f2000           call 0x6434a0
// 0043c563  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043c567  84c0                 test al, al
// 0043c569  7507                 jne 0x43c572
// 0043c56b  8b17                 mov edx, dword ptr [edi]
// 0043c56d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0043c570  733e                 jae 0x43c5b0
// 0043c572  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043c576  8b5008               mov edx, dword ptr [eax + 8]
// 0043c579  807a2900             cmp byte ptr [edx + 0x29], 0
// 0043c57d  57                   push edi
// 0043c57e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043c582  7416                 je 0x43c59a
// 0043c584  50                   push eax
// 0043c585  6a00                 push 0
// 0043c587  57                   push edi
// 0043c588  8bce                 mov ecx, esi
// 0043c58a  e871e9ffff           call 0x43af00
// 0043c58f  5b                   pop ebx
// 0043c590  8bc7                 mov eax, edi
// 0043c592  5f                   pop edi
// 0043c593  5e                   pop esi
// 0043c594  83c414               add esp, 0x14
// 0043c597  c21000               ret 0x10
// 0043c59a  51                   push ecx
// 0043c59b  6a01                 push 1
// 0043c59d  57                   push edi
// 0043c59e  8bce                 mov ecx, esi
// 0043c5a0  e85be9ffff           call 0x43af00
// 0043c5a5  5b                   pop ebx
// 0043c5a6  8bc7                 mov eax, edi
// 0043c5a8  5f                   pop edi
// 0043c5a9  5e                   pop esi
// 0043c5aa  83c414               add esp, 0x14
// 0043c5ad  c21000               ret 0x10
// 0043c5b0  57                   push edi
// 0043c5b1  8d442418             lea eax, [esp + 0x18]
// 0043c5b5  50                   push eax
// 0043c5b6  8bce                 mov ecx, esi
// 0043c5b8  e873faffff           call 0x43c030
// 0043c5bd  8b10                 mov edx, dword ptr [eax]
// 0043c5bf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043c5c3  5b                   pop ebx
// 0043c5c4  8911                 mov dword ptr [ecx], edx
// 0043c5c6  8b4004               mov eax, dword ptr [eax + 4]
// 0043c5c9  5f                   pop edi
// 0043c5ca  894104               mov dword ptr [ecx + 4], eax
// 0043c5cd  8bc1                 mov eax, ecx
// 0043c5cf  5e                   pop esi
// 0043c5d0  83c414               add esp, 0x14
// 0043c5d3  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
