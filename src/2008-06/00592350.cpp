// from server: 100% by auto
// roc 2008-06 00592350  unit: RBX::RootInstance  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592350
//
// 00592350  83ec14               sub esp, 0x14
// 00592353  56                   push esi
// 00592354  8bf1                 mov esi, ecx
// 00592356  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0059235a  57                   push edi
// 0059235b  7521                 jne 0x59237e
// 0059235d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00592361  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00592364  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00592368  50                   push eax
// 00592369  51                   push ecx
// 0059236a  6a01                 push 1
// 0059236c  57                   push edi
// 0059236d  8bce                 mov ecx, esi
// 0059236f  e8fcbff1ff           call 0x4ae370
// 00592374  8bc7                 mov eax, edi
// 00592376  5f                   pop edi
// 00592377  5e                   pop esi
// 00592378  83c414               add esp, 0x14
// 0059237b  c21000               ret 0x10
// 0059237e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00592382  8b5618               mov edx, dword ptr [esi + 0x18]
// 00592385  8b3a                 mov edi, dword ptr [edx]
// 00592387  8b06                 mov eax, dword ptr [esi]
// 00592389  53                   push ebx
// 0059238a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00592390  85c9                 test ecx, ecx
// 00592392  7404                 je 0x592398
// 00592394  3bc8                 cmp ecx, eax
// 00592396  7406                 je 0x59239e
// 00592398  ffd3                 call ebx
// 0059239a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0059239e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005923a2  3bc7                 cmp eax, edi
// 005923a4  752a                 jne 0x5923d0
// 005923a6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005923aa  8b0f                 mov ecx, dword ptr [edi]
// 005923ac  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005923af  0f834b010000         jae 0x592500
// 005923b5  57                   push edi
// 005923b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005923ba  50                   push eax
// 005923bb  6a01                 push 1
// 005923bd  57                   push edi
// 005923be  8bce                 mov ecx, esi
// 005923c0  e8abbff1ff           call 0x4ae370
// 005923c5  5b                   pop ebx
// 005923c6  8bc7                 mov eax, edi
// 005923c8  5f                   pop edi
// 005923c9  5e                   pop esi
// 005923ca  83c414               add esp, 0x14
// 005923cd  c21000               ret 0x10
// 005923d0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005923d3  8b16                 mov edx, dword ptr [esi]
// 005923d5  85c9                 test ecx, ecx
// 005923d7  7404                 je 0x5923dd
// 005923d9  3bca                 cmp ecx, edx
// 005923db  740a                 je 0x5923e7
// 005923dd  ffd3                 call ebx
// 005923df  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005923e3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005923e7  3bc7                 cmp eax, edi
// 005923e9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005923ed  752c                 jne 0x59241b
// 005923ef  8b5618               mov edx, dword ptr [esi + 0x18]
// 005923f2  8b4208               mov eax, dword ptr [edx + 8]
// 005923f5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005923f8  3b0f                 cmp ecx, dword ptr [edi]
// 005923fa  0f8300010000         jae 0x592500
// 00592400  57                   push edi
// 00592401  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00592405  50                   push eax
// 00592406  6a00                 push 0
// 00592408  57                   push edi
// 00592409  8bce                 mov ecx, esi
// 0059240b  e860bff1ff           call 0x4ae370
// 00592410  5b                   pop ebx
// 00592411  8bc7                 mov eax, edi
// 00592413  5f                   pop edi
// 00592414  5e                   pop esi
// 00592415  83c414               add esp, 0x14
// 00592418  c21000               ret 0x10
// 0059241b  8b17                 mov edx, dword ptr [edi]
// 0059241d  39500c               cmp dword ptr [eax + 0xc], edx
// 00592420  7663                 jbe 0x592485
// 00592422  894c240c             mov dword ptr [esp + 0xc], ecx
// 00592426  8d4c240c             lea ecx, [esp + 0xc]
// 0059242a  89442410             mov dword ptr [esp + 0x10], eax
// 0059242e  e80d9bf1ff           call 0x4abf40
// 00592433  8b17                 mov edx, dword ptr [edi]
// 00592435  8b442410             mov eax, dword ptr [esp + 0x10]
// 00592439  39500c               cmp dword ptr [eax + 0xc], edx
// 0059243c  733c                 jae 0x59247a
// 0059243e  8b5008               mov edx, dword ptr [eax + 8]
// 00592441  807a1900             cmp byte ptr [edx + 0x19], 0
// 00592445  57                   push edi
// 00592446  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0059244a  8bce                 mov ecx, esi
// 0059244c  7414                 je 0x592462
// 0059244e  50                   push eax
// 0059244f  6a00                 push 0
// 00592451  57                   push edi
// 00592452  e819bff1ff           call 0x4ae370
// 00592457  5b                   pop ebx
// 00592458  8bc7                 mov eax, edi
// 0059245a  5f                   pop edi
// 0059245b  5e                   pop esi
// 0059245c  83c414               add esp, 0x14
// 0059245f  c21000               ret 0x10
// 00592462  8b442430             mov eax, dword ptr [esp + 0x30]
// 00592466  50                   push eax
// 00592467  6a01                 push 1
// 00592469  57                   push edi
// 0059246a  e801bff1ff           call 0x4ae370
// 0059246f  5b                   pop ebx
// 00592470  8bc7                 mov eax, edi
// 00592472  5f                   pop edi
// 00592473  5e                   pop esi
// 00592474  83c414               add esp, 0x14
// 00592477  c21000               ret 0x10
// 0059247a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0059247e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00592482  39500c               cmp dword ptr [eax + 0xc], edx
// 00592485  7379                 jae 0x592500
// 00592487  8b16                 mov edx, dword ptr [esi]
// 00592489  894c240c             mov dword ptr [esp + 0xc], ecx
// 0059248d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00592490  894c2418             mov dword ptr [esp + 0x18], ecx
// 00592494  8d4c240c             lea ecx, [esp + 0xc]
// 00592498  89442410             mov dword ptr [esp + 0x10], eax
// 0059249c  89542414             mov dword ptr [esp + 0x14], edx
// 005924a0  e8ab4d0200           call 0x5b7250
// 005924a5  8d442414             lea eax, [esp + 0x14]
// 005924a9  50                   push eax
// 005924aa  8d4c2410             lea ecx, [esp + 0x10]
// 005924ae  e8eda70500           call 0x5ecca0
// 005924b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005924b7  84c0                 test al, al
// 005924b9  7507                 jne 0x5924c2
// 005924bb  8b17                 mov edx, dword ptr [edi]
// 005924bd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 005924c0  733e                 jae 0x592500
// 005924c2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005924c6  8b5008               mov edx, dword ptr [eax + 8]
// 005924c9  807a1900             cmp byte ptr [edx + 0x19], 0
// 005924cd  57                   push edi
// 005924ce  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005924d2  7416                 je 0x5924ea
// 005924d4  50                   push eax
// 005924d5  6a00                 push 0
// 005924d7  57                   push edi
// 005924d8  8bce                 mov ecx, esi
// 005924da  e891bef1ff           call 0x4ae370
// 005924df  5b                   pop ebx
// 005924e0  8bc7                 mov eax, edi
// 005924e2  5f                   pop edi
// 005924e3  5e                   pop esi
// 005924e4  83c414               add esp, 0x14
// 005924e7  c21000               ret 0x10
// 005924ea  51                   push ecx
// 005924eb  6a01                 push 1
// 005924ed  57                   push edi
// 005924ee  8bce                 mov ecx, esi
// 005924f0  e87bbef1ff           call 0x4ae370
// 005924f5  5b                   pop ebx
// 005924f6  8bc7                 mov eax, edi
// 005924f8  5f                   pop edi
// 005924f9  5e                   pop esi
// 005924fa  83c414               add esp, 0x14
// 005924fd  c21000               ret 0x10
// 00592500  57                   push edi
// 00592501  8d442418             lea eax, [esp + 0x18]
// 00592505  50                   push eax
// 00592506  8bce                 mov ecx, esi
// 00592508  e863cdf1ff           call 0x4af270
// 0059250d  8b10                 mov edx, dword ptr [eax]
// 0059250f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00592513  5b                   pop ebx
// 00592514  8911                 mov dword ptr [ecx], edx
// 00592516  8b4004               mov eax, dword ptr [eax + 4]
// 00592519  5f                   pop edi
// 0059251a  894104               mov dword ptr [ecx + 4], eax
// 0059251d  8bc1                 mov eax, ecx
// 0059251f  5e                   pop esi
// 00592520  83c414               add esp, 0x14
// 00592523  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
