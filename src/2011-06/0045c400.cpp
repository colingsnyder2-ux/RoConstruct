// from server: 100% by auto
// roc 2011-06 0045c400  unit: VCRoblox3D::?$CComObject  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c400
//
// 0045c400  83ec08               sub esp, 8
// 0045c403  8b542410             mov edx, dword ptr [esp + 0x10]
// 0045c407  56                   push esi
// 0045c408  8d442404             lea eax, [esp + 4]
// 0045c40c  50                   push eax
// 0045c40d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0045c411  8d4c240c             lea ecx, [esp + 0xc]
// 0045c415  51                   push ecx
// 0045c416  52                   push edx
// 0045c417  50                   push eax
// 0045c418  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045c420  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0045c428  e8c3f9ffff           call 0x45bdf0
// 0045c42d  8bf0                 mov esi, eax
// 0045c42f  85f6                 test esi, esi
// 0045c431  7c70                 jl 0x45c4a3
// 0045c433  8b442404             mov eax, dword ptr [esp + 4]
// 0045c437  8b08                 mov ecx, dword ptr [eax]
// 0045c439  8d542414             lea edx, [esp + 0x14]
// 0045c43d  52                   push edx
// 0045c43e  50                   push eax
// 0045c43f  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0045c442  ffd0                 call eax
// 0045c444  8bf0                 mov esi, eax
// 0045c446  85f6                 test esi, esi
// 0045c448  7c59                 jl 0x45c4a3
// 0045c44a  803d1816cb0001       cmp byte ptr [0xcb1618], 1
// 0045c451  751f                 jne 0x45c472
// 0045c453  6804e7a600           push 0xa6e704
// 0045c458  ff15e001a400         call dword ptr [0xa401e0]
// 0045c45e  85c0                 test eax, eax
// 0045c460  7410                 je 0x45c472
// 0045c462  68e8e6a600           push 0xa6e6e8
// 0045c467  50                   push eax
// 0045c468  ff156c03a400         call dword ptr [0xa4036c]
// 0045c46e  85c0                 test eax, eax
// 0045c470  7505                 jne 0x45c477
// 0045c472  a1a00aa400           mov eax, dword ptr [0xa40aa0]
// 0045c477  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0045c47b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0045c47e  52                   push edx
// 0045c47f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0045c482  52                   push edx
// 0045c483  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 0045c487  52                   push edx
// 0045c488  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0045c48c  52                   push edx
// 0045c48d  51                   push ecx
// 0045c48e  ffd0                 call eax
// 0045c490  8b542414             mov edx, dword ptr [esp + 0x14]
// 0045c494  8bf0                 mov esi, eax
// 0045c496  8b442404             mov eax, dword ptr [esp + 4]
// 0045c49a  8b08                 mov ecx, dword ptr [eax]
// 0045c49c  52                   push edx
// 0045c49d  50                   push eax
// 0045c49e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0045c4a1  ffd0                 call eax
// 0045c4a3  8b442404             mov eax, dword ptr [esp + 4]
// 0045c4a7  85c0                 test eax, eax
// 0045c4a9  7408                 je 0x45c4b3
// 0045c4ab  8b08                 mov ecx, dword ptr [eax]
// 0045c4ad  8b5108               mov edx, dword ptr [ecx + 8]
// 0045c4b0  50                   push eax
// 0045c4b1  ffd2                 call edx
// 0045c4b3  8b442408             mov eax, dword ptr [esp + 8]
// 0045c4b7  50                   push eax
// 0045c4b8  ff15000ba400         call dword ptr [0xa40b00]
// 0045c4be  8bc6                 mov eax, esi
// 0045c4c0  5e                   pop esi
// 0045c4c1  83c408               add esp, 8
// 0045c4c4  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
