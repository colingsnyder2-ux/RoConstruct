// from server: 100% by auto
// roc 2008-06 004bd8f0  unit: ProfiledRakPeer  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd8f0
//
// 004bd8f0  57                   push edi
// 004bd8f1  8bf9                 mov edi, ecx
// 004bd8f3  837f0400             cmp dword ptr [edi + 4], 0
// 004bd8f7  750d                 jne 0x4bd906
// 004bd8f9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bd8fd  c60000               mov byte ptr [eax], 0
// 004bd900  33c0                 xor eax, eax
// 004bd902  5f                   pop edi
// 004bd903  c20c00               ret 0xc
// 004bd906  8b4704               mov eax, dword ptr [edi + 4]
// 004bd909  53                   push ebx
// 004bd90a  55                   push ebp
// 004bd90b  8d68ff               lea ebp, [eax - 1]
// 004bd90e  99                   cdq 
// 004bd90f  2bc2                 sub eax, edx
// 004bd911  8b17                 mov edx, dword ptr [edi]
// 004bd913  56                   push esi
// 004bd914  8bf0                 mov esi, eax
// 004bd916  d1fe                 sar esi, 1
// 004bd918  8d0c76               lea ecx, [esi + esi*2]
// 004bd91b  8d048a               lea eax, [edx + ecx*4]
// 004bd91e  50                   push eax
// 004bd91f  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd923  50                   push eax
// 004bd924  33db                 xor ebx, ebx
// 004bd926  ff542424             call dword ptr [esp + 0x24]
// 004bd92a  83c408               add esp, 8
// 004bd92d  85c0                 test eax, eax
// 004bd92f  7434                 je 0x4bd965
// 004bd931  7d05                 jge 0x4bd938
// 004bd933  8d6eff               lea ebp, [esi - 1]
// 004bd936  eb03                 jmp 0x4bd93b
// 004bd938  8d5e01               lea ebx, [esi + 1]
// 004bd93b  8bc5                 mov eax, ebp
// 004bd93d  2bc3                 sub eax, ebx
// 004bd93f  99                   cdq 
// 004bd940  2bc2                 sub eax, edx
// 004bd942  8bf0                 mov esi, eax
// 004bd944  d1fe                 sar esi, 1
// 004bd946  03f3                 add esi, ebx
// 004bd948  3bdd                 cmp ebx, ebp
// 004bd94a  7f29                 jg 0x4bd975
// 004bd94c  8b17                 mov edx, dword ptr [edi]
// 004bd94e  8d0c76               lea ecx, [esi + esi*2]
// 004bd951  8d048a               lea eax, [edx + ecx*4]
// 004bd954  50                   push eax
// 004bd955  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd959  50                   push eax
// 004bd95a  ff542424             call dword ptr [esp + 0x24]
// 004bd95e  83c408               add esp, 8
// 004bd961  85c0                 test eax, eax
// 004bd963  75cc                 jne 0x4bd931
// 004bd965  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bd969  8bc6                 mov eax, esi
// 004bd96b  5e                   pop esi
// 004bd96c  5d                   pop ebp
// 004bd96d  5b                   pop ebx
// 004bd96e  c60101               mov byte ptr [ecx], 1
// 004bd971  5f                   pop edi
// 004bd972  c20c00               ret 0xc
// 004bd975  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bd979  5e                   pop esi
// 004bd97a  5d                   pop ebp
// 004bd97b  8bc3                 mov eax, ebx
// 004bd97d  5b                   pop ebx
// 004bd97e  c60200               mov byte ptr [edx], 0
// 004bd981  5f                   pop edi
// 004bd982  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?GetIndexFromKey@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QBEIABUSystemAddress@@PA_NP6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
