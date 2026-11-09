// from server: 100% by auto
// roc 2009-12 0044d5b0  unit: CRbxPlayDocTemplate  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d5b0
//
// 0044d5b0  83ec08               sub esp, 8
// 0044d5b3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044d5b7  56                   push esi
// 0044d5b8  8d442404             lea eax, [esp + 4]
// 0044d5bc  50                   push eax
// 0044d5bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044d5c1  8d4c240c             lea ecx, [esp + 0xc]
// 0044d5c5  51                   push ecx
// 0044d5c6  52                   push edx
// 0044d5c7  50                   push eax
// 0044d5c8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044d5d0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044d5d8  e8c3f9ffff           call 0x44cfa0
// 0044d5dd  8bf0                 mov esi, eax
// 0044d5df  85f6                 test esi, esi
// 0044d5e1  7c70                 jl 0x44d653
// 0044d5e3  8b442404             mov eax, dword ptr [esp + 4]
// 0044d5e7  8b08                 mov ecx, dword ptr [eax]
// 0044d5e9  8d542414             lea edx, [esp + 0x14]
// 0044d5ed  52                   push edx
// 0044d5ee  50                   push eax
// 0044d5ef  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044d5f2  ffd0                 call eax
// 0044d5f4  8bf0                 mov esi, eax
// 0044d5f6  85f6                 test esi, esi
// 0044d5f8  7c59                 jl 0x44d653
// 0044d5fa  803d3c95b70001       cmp byte ptr [0xb7953c], 1
// 0044d601  751f                 jne 0x44d622
// 0044d603  6838b49a00           push 0x9ab438
// 0044d608  ff1584b29800         call dword ptr [0x98b284]
// 0044d60e  85c0                 test eax, eax
// 0044d610  7410                 je 0x44d622
// 0044d612  681cb49a00           push 0x9ab41c
// 0044d617  50                   push eax
// 0044d618  ff1520b29800         call dword ptr [0x98b220]
// 0044d61e  85c0                 test eax, eax
// 0044d620  7505                 jne 0x44d627
// 0044d622  a164ba9800           mov eax, dword ptr [0x98ba64]
// 0044d627  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044d62b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0044d62e  52                   push edx
// 0044d62f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0044d632  52                   push edx
// 0044d633  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 0044d637  52                   push edx
// 0044d638  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0044d63c  52                   push edx
// 0044d63d  51                   push ecx
// 0044d63e  ffd0                 call eax
// 0044d640  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044d644  8bf0                 mov esi, eax
// 0044d646  8b442404             mov eax, dword ptr [esp + 4]
// 0044d64a  8b08                 mov ecx, dword ptr [eax]
// 0044d64c  52                   push edx
// 0044d64d  50                   push eax
// 0044d64e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0044d651  ffd0                 call eax
// 0044d653  8b442404             mov eax, dword ptr [esp + 4]
// 0044d657  85c0                 test eax, eax
// 0044d659  7408                 je 0x44d663
// 0044d65b  8b08                 mov ecx, dword ptr [eax]
// 0044d65d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044d660  50                   push eax
// 0044d661  ffd2                 call edx
// 0044d663  8b442408             mov eax, dword ptr [esp + 8]
// 0044d667  50                   push eax
// 0044d668  ff1590ba9800         call dword ptr [0x98ba90]
// 0044d66e  8bc6                 mov eax, esi
// 0044d670  5e                   pop esi
// 0044d671  83c408               add esp, 8
// 0044d674  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
