// from server: 100% by auto
// roc 2008-06 0044b4c0  unit: CRobloxApp  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b4c0
//
// 0044b4c0  83ec08               sub esp, 8
// 0044b4c3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044b4c7  56                   push esi
// 0044b4c8  8d442404             lea eax, [esp + 4]
// 0044b4cc  50                   push eax
// 0044b4cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044b4d1  8d4c240c             lea ecx, [esp + 0xc]
// 0044b4d5  51                   push ecx
// 0044b4d6  52                   push edx
// 0044b4d7  50                   push eax
// 0044b4d8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044b4e0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044b4e8  e8c3f9ffff           call 0x44aeb0
// 0044b4ed  8bf0                 mov esi, eax
// 0044b4ef  85f6                 test esi, esi
// 0044b4f1  7c70                 jl 0x44b563
// 0044b4f3  8b442404             mov eax, dword ptr [esp + 4]
// 0044b4f7  8b08                 mov ecx, dword ptr [eax]
// 0044b4f9  8d542414             lea edx, [esp + 0x14]
// 0044b4fd  52                   push edx
// 0044b4fe  50                   push eax
// 0044b4ff  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0044b502  ffd0                 call eax
// 0044b504  8bf0                 mov esi, eax
// 0044b506  85f6                 test esi, esi
// 0044b508  7c59                 jl 0x44b563
// 0044b50a  803d64c2960001       cmp byte ptr [0x96c264], 1
// 0044b511  751f                 jne 0x44b532
// 0044b513  68a4698100           push 0x8169a4
// 0044b518  ff1514228000         call dword ptr [0x802214]
// 0044b51e  85c0                 test eax, eax
// 0044b520  7410                 je 0x44b532
// 0044b522  6888698100           push 0x816988
// 0044b527  50                   push eax
// 0044b528  ff15c0218000         call dword ptr [0x8021c0]
// 0044b52e  85c0                 test eax, eax
// 0044b530  7505                 jne 0x44b537
// 0044b532  a1d4288000           mov eax, dword ptr [0x8028d4]
// 0044b537  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044b53b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0044b53e  52                   push edx
// 0044b53f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0044b542  52                   push edx
// 0044b543  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 0044b547  52                   push edx
// 0044b548  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0044b54c  52                   push edx
// 0044b54d  51                   push ecx
// 0044b54e  ffd0                 call eax
// 0044b550  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044b554  8bf0                 mov esi, eax
// 0044b556  8b442404             mov eax, dword ptr [esp + 4]
// 0044b55a  8b08                 mov ecx, dword ptr [eax]
// 0044b55c  52                   push edx
// 0044b55d  50                   push eax
// 0044b55e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0044b561  ffd0                 call eax
// 0044b563  8b442404             mov eax, dword ptr [esp + 4]
// 0044b567  85c0                 test eax, eax
// 0044b569  7408                 je 0x44b573
// 0044b56b  8b08                 mov ecx, dword ptr [eax]
// 0044b56d  8b5108               mov edx, dword ptr [ecx + 8]
// 0044b570  50                   push eax
// 0044b571  ffd2                 call edx
// 0044b573  8b442408             mov eax, dword ptr [esp + 8]
// 0044b577  50                   push eax
// 0044b578  ff1544298000         call dword ptr [0x802944]
// 0044b57e  8bc6                 mov eax, esi
// 0044b580  5e                   pop esi
// 0044b581  83c408               add esp, 8
// 0044b584  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
