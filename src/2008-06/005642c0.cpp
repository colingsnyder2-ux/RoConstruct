// from server: 100% by auto
// roc 2008-06 005642c0  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005642c0
//
// 005642c0  83ec14               sub esp, 0x14
// 005642c3  56                   push esi
// 005642c4  8bf1                 mov esi, ecx
// 005642c6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005642ca  57                   push edi
// 005642cb  7521                 jne 0x5642ee
// 005642cd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005642d1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005642d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005642d8  50                   push eax
// 005642d9  51                   push ecx
// 005642da  6a01                 push 1
// 005642dc  57                   push edi
// 005642dd  8bce                 mov ecx, esi
// 005642df  e82c3d1000           call 0x668010
// 005642e4  8bc7                 mov eax, edi
// 005642e6  5f                   pop edi
// 005642e7  5e                   pop esi
// 005642e8  83c414               add esp, 0x14
// 005642eb  c21000               ret 0x10
// 005642ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005642f2  8b5618               mov edx, dword ptr [esi + 0x18]
// 005642f5  8b3a                 mov edi, dword ptr [edx]
// 005642f7  8b06                 mov eax, dword ptr [esi]
// 005642f9  53                   push ebx
// 005642fa  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00564300  85c9                 test ecx, ecx
// 00564302  7404                 je 0x564308
// 00564304  3bc8                 cmp ecx, eax
// 00564306  7406                 je 0x56430e
// 00564308  ffd3                 call ebx
// 0056430a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056430e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00564312  3bc7                 cmp eax, edi
// 00564314  752a                 jne 0x564340
// 00564316  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0056431a  8b0f                 mov ecx, dword ptr [edi]
// 0056431c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0056431f  0f834b010000         jae 0x564470
// 00564325  57                   push edi
// 00564326  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056432a  50                   push eax
// 0056432b  6a01                 push 1
// 0056432d  57                   push edi
// 0056432e  8bce                 mov ecx, esi
// 00564330  e8db3c1000           call 0x668010
// 00564335  5b                   pop ebx
// 00564336  8bc7                 mov eax, edi
// 00564338  5f                   pop edi
// 00564339  5e                   pop esi
// 0056433a  83c414               add esp, 0x14
// 0056433d  c21000               ret 0x10
// 00564340  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00564343  8b16                 mov edx, dword ptr [esi]
// 00564345  85c9                 test ecx, ecx
// 00564347  7404                 je 0x56434d
// 00564349  3bca                 cmp ecx, edx
// 0056434b  740a                 je 0x564357
// 0056434d  ffd3                 call ebx
// 0056434f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00564353  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00564357  3bc7                 cmp eax, edi
// 00564359  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0056435d  752c                 jne 0x56438b
// 0056435f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00564362  8b4208               mov eax, dword ptr [edx + 8]
// 00564365  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00564368  3b0f                 cmp ecx, dword ptr [edi]
// 0056436a  0f8300010000         jae 0x564470
// 00564370  57                   push edi
// 00564371  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00564375  50                   push eax
// 00564376  6a00                 push 0
// 00564378  57                   push edi
// 00564379  8bce                 mov ecx, esi
// 0056437b  e8903c1000           call 0x668010
// 00564380  5b                   pop ebx
// 00564381  8bc7                 mov eax, edi
// 00564383  5f                   pop edi
// 00564384  5e                   pop esi
// 00564385  83c414               add esp, 0x14
// 00564388  c21000               ret 0x10
// 0056438b  8b17                 mov edx, dword ptr [edi]
// 0056438d  39500c               cmp dword ptr [eax + 0xc], edx
// 00564390  7663                 jbe 0x5643f5
// 00564392  894c240c             mov dword ptr [esp + 0xc], ecx
// 00564396  8d4c240c             lea ecx, [esp + 0xc]
// 0056439a  89442410             mov dword ptr [esp + 0x10], eax
// 0056439e  e82d580a00           call 0x609bd0
// 005643a3  8b17                 mov edx, dword ptr [edi]
// 005643a5  8b442410             mov eax, dword ptr [esp + 0x10]
// 005643a9  39500c               cmp dword ptr [eax + 0xc], edx
// 005643ac  733c                 jae 0x5643ea
// 005643ae  8b5008               mov edx, dword ptr [eax + 8]
// 005643b1  807a1500             cmp byte ptr [edx + 0x15], 0
// 005643b5  57                   push edi
// 005643b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005643ba  8bce                 mov ecx, esi
// 005643bc  7414                 je 0x5643d2
// 005643be  50                   push eax
// 005643bf  6a00                 push 0
// 005643c1  57                   push edi
// 005643c2  e8493c1000           call 0x668010
// 005643c7  5b                   pop ebx
// 005643c8  8bc7                 mov eax, edi
// 005643ca  5f                   pop edi
// 005643cb  5e                   pop esi
// 005643cc  83c414               add esp, 0x14
// 005643cf  c21000               ret 0x10
// 005643d2  8b442430             mov eax, dword ptr [esp + 0x30]
// 005643d6  50                   push eax
// 005643d7  6a01                 push 1
// 005643d9  57                   push edi
// 005643da  e8313c1000           call 0x668010
// 005643df  5b                   pop ebx
// 005643e0  8bc7                 mov eax, edi
// 005643e2  5f                   pop edi
// 005643e3  5e                   pop esi
// 005643e4  83c414               add esp, 0x14
// 005643e7  c21000               ret 0x10
// 005643ea  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005643ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005643f2  39500c               cmp dword ptr [eax + 0xc], edx
// 005643f5  7379                 jae 0x564470
// 005643f7  8b16                 mov edx, dword ptr [esi]
// 005643f9  894c240c             mov dword ptr [esp + 0xc], ecx
// 005643fd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00564400  894c2418             mov dword ptr [esp + 0x18], ecx
// 00564404  8d4c240c             lea ecx, [esp + 0xc]
// 00564408  89442410             mov dword ptr [esp + 0x10], eax
// 0056440c  89542414             mov dword ptr [esp + 0x14], edx
// 00564410  e88b9b1200           call 0x68dfa0
// 00564415  8d442414             lea eax, [esp + 0x14]
// 00564419  50                   push eax
// 0056441a  8d4c2410             lea ecx, [esp + 0x10]
// 0056441e  e87d880800           call 0x5ecca0
// 00564423  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00564427  84c0                 test al, al
// 00564429  7507                 jne 0x564432
// 0056442b  8b17                 mov edx, dword ptr [edi]
// 0056442d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00564430  733e                 jae 0x564470
// 00564432  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00564436  8b5008               mov edx, dword ptr [eax + 8]
// 00564439  807a1500             cmp byte ptr [edx + 0x15], 0
// 0056443d  57                   push edi
// 0056443e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00564442  7416                 je 0x56445a
// 00564444  50                   push eax
// 00564445  6a00                 push 0
// 00564447  57                   push edi
// 00564448  8bce                 mov ecx, esi
// 0056444a  e8c13b1000           call 0x668010
// 0056444f  5b                   pop ebx
// 00564450  8bc7                 mov eax, edi
// 00564452  5f                   pop edi
// 00564453  5e                   pop esi
// 00564454  83c414               add esp, 0x14
// 00564457  c21000               ret 0x10
// 0056445a  51                   push ecx
// 0056445b  6a01                 push 1
// 0056445d  57                   push edi
// 0056445e  8bce                 mov ecx, esi
// 00564460  e8ab3b1000           call 0x668010
// 00564465  5b                   pop ebx
// 00564466  8bc7                 mov eax, edi
// 00564468  5f                   pop edi
// 00564469  5e                   pop esi
// 0056446a  83c414               add esp, 0x14
// 0056446d  c21000               ret 0x10
// 00564470  57                   push edi
// 00564471  8d442418             lea eax, [esp + 0x18]
// 00564475  50                   push eax
// 00564476  8bce                 mov ecx, esi
// 00564478  e8d3d51100           call 0x681a50
// 0056447d  8b10                 mov edx, dword ptr [eax]
// 0056447f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00564483  5b                   pop ebx
// 00564484  8911                 mov dword ptr [ecx], edx
// 00564486  8b4004               mov eax, dword ptr [eax + 4]
// 00564489  5f                   pop edi
// 0056448a  894104               mov dword ptr [ecx + 4], eax
// 0056448d  8bc1                 mov eax, ecx
// 0056448f  5e                   pop esi
// 00564490  83c414               add esp, 0x14
// 00564493  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
