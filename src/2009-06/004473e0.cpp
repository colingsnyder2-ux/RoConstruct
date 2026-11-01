// from server: 100% by auto
// roc 2009-06 004473e0  unit: CBrowserDocManager  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004473e0
//
// 004473e0  83ec08               sub esp, 8
// 004473e3  8b542410             mov edx, dword ptr [esp + 0x10]
// 004473e7  56                   push esi
// 004473e8  8d442404             lea eax, [esp + 4]
// 004473ec  50                   push eax
// 004473ed  8b442414             mov eax, dword ptr [esp + 0x14]
// 004473f1  8d4c240c             lea ecx, [esp + 0xc]
// 004473f5  51                   push ecx
// 004473f6  52                   push edx
// 004473f7  50                   push eax
// 004473f8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00447400  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00447408  e8c3f9ffff           call 0x446dd0
// 0044740d  8bf0                 mov esi, eax
// 0044740f  85f6                 test esi, esi
// 00447411  7c70                 jl 0x447483
// 00447413  8b442404             mov eax, dword ptr [esp + 4]
// 00447417  8b08                 mov ecx, dword ptr [eax]
// 00447419  8d542414             lea edx, [esp + 0x14]
// 0044741d  52                   push edx
// 0044741e  50                   push eax
// 0044741f  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 00447422  ffd0                 call eax
// 00447424  8bf0                 mov esi, eax
// 00447426  85f6                 test esi, esi
// 00447428  7c59                 jl 0x447483
// 0044742a  803d5497a30001       cmp byte ptr [0xa39754], 1
// 00447431  751f                 jne 0x447452
// 00447433  68c8718b00           push 0x8b71c8
// 00447438  ff1558e28900         call dword ptr [0x89e258]
// 0044743e  85c0                 test eax, eax
// 00447440  7410                 je 0x447452
// 00447442  68ac718b00           push 0x8b71ac
// 00447447  50                   push eax
// 00447448  ff15e8e18900         call dword ptr [0x89e1e8]
// 0044744e  85c0                 test eax, eax
// 00447450  7505                 jne 0x447457
// 00447452  a10cea8900           mov eax, dword ptr [0x89ea0c]
// 00447457  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044745b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0044745e  52                   push edx
// 0044745f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00447462  52                   push edx
// 00447463  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 00447467  52                   push edx
// 00447468  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0044746c  52                   push edx
// 0044746d  51                   push ecx
// 0044746e  ffd0                 call eax
// 00447470  8b542414             mov edx, dword ptr [esp + 0x14]
// 00447474  8bf0                 mov esi, eax
// 00447476  8b442404             mov eax, dword ptr [esp + 4]
// 0044747a  8b08                 mov ecx, dword ptr [eax]
// 0044747c  52                   push edx
// 0044747d  50                   push eax
// 0044747e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 00447481  ffd0                 call eax
// 00447483  8b442404             mov eax, dword ptr [esp + 4]
// 00447487  85c0                 test eax, eax
// 00447489  7408                 je 0x447493
// 0044748b  8b08                 mov ecx, dword ptr [eax]
// 0044748d  8b5108               mov edx, dword ptr [ecx + 8]
// 00447490  50                   push eax
// 00447491  ffd2                 call edx
// 00447493  8b442408             mov eax, dword ptr [esp + 8]
// 00447497  50                   push eax
// 00447498  ff153cea8900         call dword ptr [0x89ea3c]
// 0044749e  8bc6                 mov eax, esi
// 004474a0  5e                   pop esi
// 004474a1  83c408               add esp, 8
// 004474a4  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
