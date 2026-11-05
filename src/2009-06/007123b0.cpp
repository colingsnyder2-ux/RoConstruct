// from server: 100% by auto
// roc 2009-06 007123b0  unit: W4_D3DFORMAT::?$EnumDesc  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007123b0
//
// 007123b0  83ec14               sub esp, 0x14
// 007123b3  56                   push esi
// 007123b4  8bf1                 mov esi, ecx
// 007123b6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007123ba  57                   push edi
// 007123bb  7521                 jne 0x7123de
// 007123bd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007123c1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007123c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007123c8  50                   push eax
// 007123c9  51                   push ecx
// 007123ca  6a01                 push 1
// 007123cc  57                   push edi
// 007123cd  8bce                 mov ecx, esi
// 007123cf  e89cfcffff           call 0x712070
// 007123d4  8bc7                 mov eax, edi
// 007123d6  5f                   pop edi
// 007123d7  5e                   pop esi
// 007123d8  83c414               add esp, 0x14
// 007123db  c21000               ret 0x10
// 007123de  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007123e2  8b5618               mov edx, dword ptr [esi + 0x18]
// 007123e5  8b3a                 mov edi, dword ptr [edx]
// 007123e7  8b06                 mov eax, dword ptr [esi]
// 007123e9  53                   push ebx
// 007123ea  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 007123f0  85c9                 test ecx, ecx
// 007123f2  7404                 je 0x7123f8
// 007123f4  3bc8                 cmp ecx, eax
// 007123f6  7406                 je 0x7123fe
// 007123f8  ffd3                 call ebx
// 007123fa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007123fe  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00712402  3bc7                 cmp eax, edi
// 00712404  752a                 jne 0x712430
// 00712406  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0071240a  8b0f                 mov ecx, dword ptr [edi]
// 0071240c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0071240f  0f834b010000         jae 0x712560
// 00712415  57                   push edi
// 00712416  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0071241a  50                   push eax
// 0071241b  6a01                 push 1
// 0071241d  57                   push edi
// 0071241e  8bce                 mov ecx, esi
// 00712420  e84bfcffff           call 0x712070
// 00712425  5b                   pop ebx
// 00712426  8bc7                 mov eax, edi
// 00712428  5f                   pop edi
// 00712429  5e                   pop esi
// 0071242a  83c414               add esp, 0x14
// 0071242d  c21000               ret 0x10
// 00712430  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00712433  8b16                 mov edx, dword ptr [esi]
// 00712435  85c9                 test ecx, ecx
// 00712437  7404                 je 0x71243d
// 00712439  3bca                 cmp ecx, edx
// 0071243b  740a                 je 0x712447
// 0071243d  ffd3                 call ebx
// 0071243f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00712443  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00712447  3bc7                 cmp eax, edi
// 00712449  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0071244d  752c                 jne 0x71247b
// 0071244f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00712452  8b4208               mov eax, dword ptr [edx + 8]
// 00712455  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00712458  3b0f                 cmp ecx, dword ptr [edi]
// 0071245a  0f8300010000         jae 0x712560
// 00712460  57                   push edi
// 00712461  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00712465  50                   push eax
// 00712466  6a00                 push 0
// 00712468  57                   push edi
// 00712469  8bce                 mov ecx, esi
// 0071246b  e800fcffff           call 0x712070
// 00712470  5b                   pop ebx
// 00712471  8bc7                 mov eax, edi
// 00712473  5f                   pop edi
// 00712474  5e                   pop esi
// 00712475  83c414               add esp, 0x14
// 00712478  c21000               ret 0x10
// 0071247b  8b17                 mov edx, dword ptr [edi]
// 0071247d  39500c               cmp dword ptr [eax + 0xc], edx
// 00712480  7663                 jbe 0x7124e5
// 00712482  894c240c             mov dword ptr [esp + 0xc], ecx
// 00712486  8d4c240c             lea ecx, [esp + 0xc]
// 0071248a  89442410             mov dword ptr [esp + 0x10], eax
// 0071248e  e85d36f9ff           call 0x6a5af0
// 00712493  8b17                 mov edx, dword ptr [edi]
// 00712495  8b442410             mov eax, dword ptr [esp + 0x10]
// 00712499  39500c               cmp dword ptr [eax + 0xc], edx
// 0071249c  733c                 jae 0x7124da
// 0071249e  8b5008               mov edx, dword ptr [eax + 8]
// 007124a1  807a1500             cmp byte ptr [edx + 0x15], 0
// 007124a5  57                   push edi
// 007124a6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007124aa  8bce                 mov ecx, esi
// 007124ac  7414                 je 0x7124c2
// 007124ae  50                   push eax
// 007124af  6a00                 push 0
// 007124b1  57                   push edi
// 007124b2  e8b9fbffff           call 0x712070
// 007124b7  5b                   pop ebx
// 007124b8  8bc7                 mov eax, edi
// 007124ba  5f                   pop edi
// 007124bb  5e                   pop esi
// 007124bc  83c414               add esp, 0x14
// 007124bf  c21000               ret 0x10
// 007124c2  8b442430             mov eax, dword ptr [esp + 0x30]
// 007124c6  50                   push eax
// 007124c7  6a01                 push 1
// 007124c9  57                   push edi
// 007124ca  e8a1fbffff           call 0x712070
// 007124cf  5b                   pop ebx
// 007124d0  8bc7                 mov eax, edi
// 007124d2  5f                   pop edi
// 007124d3  5e                   pop esi
// 007124d4  83c414               add esp, 0x14
// 007124d7  c21000               ret 0x10
// 007124da  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007124de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007124e2  39500c               cmp dword ptr [eax + 0xc], edx
// 007124e5  7379                 jae 0x712560
// 007124e7  8b16                 mov edx, dword ptr [esi]
// 007124e9  894c240c             mov dword ptr [esp + 0xc], ecx
// 007124ed  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007124f0  894c2418             mov dword ptr [esp + 0x18], ecx
// 007124f4  8d4c240c             lea ecx, [esp + 0xc]
// 007124f8  89442410             mov dword ptr [esp + 0x10], eax
// 007124fc  89542414             mov dword ptr [esp + 0x14], edx
// 00712500  e86b6cedff           call 0x5e9170
// 00712505  8d442414             lea eax, [esp + 0x14]
// 00712509  50                   push eax
// 0071250a  8d4c2410             lea ecx, [esp + 0x10]
// 0071250e  e88d0ff3ff           call 0x6434a0
// 00712513  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00712517  84c0                 test al, al
// 00712519  7507                 jne 0x712522
// 0071251b  8b17                 mov edx, dword ptr [edi]
// 0071251d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00712520  733e                 jae 0x712560
// 00712522  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00712526  8b5008               mov edx, dword ptr [eax + 8]
// 00712529  807a1500             cmp byte ptr [edx + 0x15], 0
// 0071252d  57                   push edi
// 0071252e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00712532  7416                 je 0x71254a
// 00712534  50                   push eax
// 00712535  6a00                 push 0
// 00712537  57                   push edi
// 00712538  8bce                 mov ecx, esi
// 0071253a  e831fbffff           call 0x712070
// 0071253f  5b                   pop ebx
// 00712540  8bc7                 mov eax, edi
// 00712542  5f                   pop edi
// 00712543  5e                   pop esi
// 00712544  83c414               add esp, 0x14
// 00712547  c21000               ret 0x10
// 0071254a  51                   push ecx
// 0071254b  6a01                 push 1
// 0071254d  57                   push edi
// 0071254e  8bce                 mov ecx, esi
// 00712550  e81bfbffff           call 0x712070
// 00712555  5b                   pop ebx
// 00712556  8bc7                 mov eax, edi
// 00712558  5f                   pop edi
// 00712559  5e                   pop esi
// 0071255a  83c414               add esp, 0x14
// 0071255d  c21000               ret 0x10
// 00712560  57                   push edi
// 00712561  8d442418             lea eax, [esp + 0x18]
// 00712565  50                   push eax
// 00712566  8bce                 mov ecx, esi
// 00712568  e853fdffff           call 0x7122c0
// 0071256d  8b10                 mov edx, dword ptr [eax]
// 0071256f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00712573  5b                   pop ebx
// 00712574  8911                 mov dword ptr [ecx], edx
// 00712576  8b4004               mov eax, dword ptr [eax + 4]
// 00712579  5f                   pop edi
// 0071257a  894104               mov dword ptr [ecx + 4], eax
// 0071257d  8bc1                 mov eax, ecx
// 0071257f  5e                   pop esi
// 00712580  83c414               add esp, 0x14
// 00712583  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
