// from server: 100% by auto
// roc 2010-06 004363d0  unit: IIHAAH::?$CMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004363d0
//
// 004363d0  83ec14               sub esp, 0x14
// 004363d3  56                   push esi
// 004363d4  8bf1                 mov esi, ecx
// 004363d6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 004363da  57                   push edi
// 004363db  7521                 jne 0x4363fe
// 004363dd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004363e1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004363e4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004363e8  50                   push eax
// 004363e9  51                   push ecx
// 004363ea  6a01                 push 1
// 004363ec  57                   push edi
// 004363ed  8bce                 mov ecx, esi
// 004363ef  e85cf0ffff           call 0x435450
// 004363f4  8bc7                 mov eax, edi
// 004363f6  5f                   pop edi
// 004363f7  5e                   pop esi
// 004363f8  83c414               add esp, 0x14
// 004363fb  c21000               ret 0x10
// 004363fe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00436402  8b5618               mov edx, dword ptr [esi + 0x18]
// 00436405  8b3a                 mov edi, dword ptr [edx]
// 00436407  8b06                 mov eax, dword ptr [esi]
// 00436409  53                   push ebx
// 0043640a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00436410  85c9                 test ecx, ecx
// 00436412  7404                 je 0x436418
// 00436414  3bc8                 cmp ecx, eax
// 00436416  7406                 je 0x43641e
// 00436418  ffd3                 call ebx
// 0043641a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043641e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00436422  3bc7                 cmp eax, edi
// 00436424  752a                 jne 0x436450
// 00436426  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043642a  8b0f                 mov ecx, dword ptr [edi]
// 0043642c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0043642f  0f834b010000         jae 0x436580
// 00436435  57                   push edi
// 00436436  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0043643a  50                   push eax
// 0043643b  6a01                 push 1
// 0043643d  57                   push edi
// 0043643e  8bce                 mov ecx, esi
// 00436440  e80bf0ffff           call 0x435450
// 00436445  5b                   pop ebx
// 00436446  8bc7                 mov eax, edi
// 00436448  5f                   pop edi
// 00436449  5e                   pop esi
// 0043644a  83c414               add esp, 0x14
// 0043644d  c21000               ret 0x10
// 00436450  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00436453  8b16                 mov edx, dword ptr [esi]
// 00436455  85c9                 test ecx, ecx
// 00436457  7404                 je 0x43645d
// 00436459  3bca                 cmp ecx, edx
// 0043645b  740a                 je 0x436467
// 0043645d  ffd3                 call ebx
// 0043645f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00436463  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00436467  3bc7                 cmp eax, edi
// 00436469  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0043646d  752c                 jne 0x43649b
// 0043646f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00436472  8b4208               mov eax, dword ptr [edx + 8]
// 00436475  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00436478  3b0f                 cmp ecx, dword ptr [edi]
// 0043647a  0f8300010000         jae 0x436580
// 00436480  57                   push edi
// 00436481  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00436485  50                   push eax
// 00436486  6a00                 push 0
// 00436488  57                   push edi
// 00436489  8bce                 mov ecx, esi
// 0043648b  e8c0efffff           call 0x435450
// 00436490  5b                   pop ebx
// 00436491  8bc7                 mov eax, edi
// 00436493  5f                   pop edi
// 00436494  5e                   pop esi
// 00436495  83c414               add esp, 0x14
// 00436498  c21000               ret 0x10
// 0043649b  8b17                 mov edx, dword ptr [edi]
// 0043649d  39500c               cmp dword ptr [eax + 0xc], edx
// 004364a0  7663                 jbe 0x436505
// 004364a2  894c240c             mov dword ptr [esp + 0xc], ecx
// 004364a6  8d4c240c             lea ecx, [esp + 0xc]
// 004364aa  89442410             mov dword ptr [esp + 0x10], eax
// 004364ae  e80ddeffff           call 0x4342c0
// 004364b3  8b17                 mov edx, dword ptr [edi]
// 004364b5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004364b9  39500c               cmp dword ptr [eax + 0xc], edx
// 004364bc  733c                 jae 0x4364fa
// 004364be  8b5008               mov edx, dword ptr [eax + 8]
// 004364c1  807a1900             cmp byte ptr [edx + 0x19], 0
// 004364c5  57                   push edi
// 004364c6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004364ca  8bce                 mov ecx, esi
// 004364cc  7414                 je 0x4364e2
// 004364ce  50                   push eax
// 004364cf  6a00                 push 0
// 004364d1  57                   push edi
// 004364d2  e879efffff           call 0x435450
// 004364d7  5b                   pop ebx
// 004364d8  8bc7                 mov eax, edi
// 004364da  5f                   pop edi
// 004364db  5e                   pop esi
// 004364dc  83c414               add esp, 0x14
// 004364df  c21000               ret 0x10
// 004364e2  8b442430             mov eax, dword ptr [esp + 0x30]
// 004364e6  50                   push eax
// 004364e7  6a01                 push 1
// 004364e9  57                   push edi
// 004364ea  e861efffff           call 0x435450
// 004364ef  5b                   pop ebx
// 004364f0  8bc7                 mov eax, edi
// 004364f2  5f                   pop edi
// 004364f3  5e                   pop esi
// 004364f4  83c414               add esp, 0x14
// 004364f7  c21000               ret 0x10
// 004364fa  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004364fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00436502  39500c               cmp dword ptr [eax + 0xc], edx
// 00436505  7379                 jae 0x436580
// 00436507  8b16                 mov edx, dword ptr [esi]
// 00436509  894c240c             mov dword ptr [esp + 0xc], ecx
// 0043650d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00436510  894c2418             mov dword ptr [esp + 0x18], ecx
// 00436514  8d4c240c             lea ecx, [esp + 0xc]
// 00436518  89442410             mov dword ptr [esp + 0x10], eax
// 0043651c  89542414             mov dword ptr [esp + 0x14], edx
// 00436520  e80b050b00           call 0x4e6a30
// 00436525  8d442414             lea eax, [esp + 0x14]
// 00436529  50                   push eax
// 0043652a  8d4c2410             lea ecx, [esp + 0x10]
// 0043652e  e84d0a0300           call 0x466f80
// 00436533  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00436537  84c0                 test al, al
// 00436539  7507                 jne 0x436542
// 0043653b  8b17                 mov edx, dword ptr [edi]
// 0043653d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00436540  733e                 jae 0x436580
// 00436542  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00436546  8b5008               mov edx, dword ptr [eax + 8]
// 00436549  807a1900             cmp byte ptr [edx + 0x19], 0
// 0043654d  57                   push edi
// 0043654e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00436552  7416                 je 0x43656a
// 00436554  50                   push eax
// 00436555  6a00                 push 0
// 00436557  57                   push edi
// 00436558  8bce                 mov ecx, esi
// 0043655a  e8f1eeffff           call 0x435450
// 0043655f  5b                   pop ebx
// 00436560  8bc7                 mov eax, edi
// 00436562  5f                   pop edi
// 00436563  5e                   pop esi
// 00436564  83c414               add esp, 0x14
// 00436567  c21000               ret 0x10
// 0043656a  51                   push ecx
// 0043656b  6a01                 push 1
// 0043656d  57                   push edi
// 0043656e  8bce                 mov ecx, esi
// 00436570  e8dbeeffff           call 0x435450
// 00436575  5b                   pop ebx
// 00436576  8bc7                 mov eax, edi
// 00436578  5f                   pop edi
// 00436579  5e                   pop esi
// 0043657a  83c414               add esp, 0x14
// 0043657d  c21000               ret 0x10
// 00436580  57                   push edi
// 00436581  8d442418             lea eax, [esp + 0x18]
// 00436585  50                   push eax
// 00436586  8bce                 mov ecx, esi
// 00436588  e883f7ffff           call 0x435d10
// 0043658d  8b10                 mov edx, dword ptr [eax]
// 0043658f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00436593  5b                   pop ebx
// 00436594  8911                 mov dword ptr [ecx], edx
// 00436596  8b4004               mov eax, dword ptr [eax + 4]
// 00436599  5f                   pop edi
// 0043659a  894104               mov dword ptr [ecx + 4], eax
// 0043659d  8bc1                 mov eax, ecx
// 0043659f  5e                   pop esi
// 004365a0  83c414               add esp, 0x14
// 004365a3  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
