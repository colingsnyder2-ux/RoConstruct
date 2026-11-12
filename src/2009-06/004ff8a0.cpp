// from server: 100% by auto
// roc 2009-06 004ff8a0  unit: RakPeer  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ff8a0
//
// 004ff8a0  57                   push edi
// 004ff8a1  8bf9                 mov edi, ecx
// 004ff8a3  837f0400             cmp dword ptr [edi + 4], 0
// 004ff8a7  750d                 jne 0x4ff8b6
// 004ff8a9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ff8ad  c60000               mov byte ptr [eax], 0
// 004ff8b0  33c0                 xor eax, eax
// 004ff8b2  5f                   pop edi
// 004ff8b3  c20c00               ret 0xc
// 004ff8b6  8b4704               mov eax, dword ptr [edi + 4]
// 004ff8b9  53                   push ebx
// 004ff8ba  55                   push ebp
// 004ff8bb  8d68ff               lea ebp, [eax - 1]
// 004ff8be  99                   cdq 
// 004ff8bf  2bc2                 sub eax, edx
// 004ff8c1  8b17                 mov edx, dword ptr [edi]
// 004ff8c3  56                   push esi
// 004ff8c4  8bf0                 mov esi, eax
// 004ff8c6  d1fe                 sar esi, 1
// 004ff8c8  8d0c76               lea ecx, [esi + esi*2]
// 004ff8cb  8d048a               lea eax, [edx + ecx*4]
// 004ff8ce  50                   push eax
// 004ff8cf  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ff8d3  50                   push eax
// 004ff8d4  33db                 xor ebx, ebx
// 004ff8d6  ff542424             call dword ptr [esp + 0x24]
// 004ff8da  83c408               add esp, 8
// 004ff8dd  85c0                 test eax, eax
// 004ff8df  7434                 je 0x4ff915
// 004ff8e1  7d05                 jge 0x4ff8e8
// 004ff8e3  8d6eff               lea ebp, [esi - 1]
// 004ff8e6  eb03                 jmp 0x4ff8eb
// 004ff8e8  8d5e01               lea ebx, [esi + 1]
// 004ff8eb  8bc5                 mov eax, ebp
// 004ff8ed  2bc3                 sub eax, ebx
// 004ff8ef  99                   cdq 
// 004ff8f0  2bc2                 sub eax, edx
// 004ff8f2  8bf0                 mov esi, eax
// 004ff8f4  d1fe                 sar esi, 1
// 004ff8f6  03f3                 add esi, ebx
// 004ff8f8  3bdd                 cmp ebx, ebp
// 004ff8fa  7f29                 jg 0x4ff925
// 004ff8fc  8b17                 mov edx, dword ptr [edi]
// 004ff8fe  8d0c76               lea ecx, [esi + esi*2]
// 004ff901  8d048a               lea eax, [edx + ecx*4]
// 004ff904  50                   push eax
// 004ff905  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ff909  50                   push eax
// 004ff90a  ff542424             call dword ptr [esp + 0x24]
// 004ff90e  83c408               add esp, 8
// 004ff911  85c0                 test eax, eax
// 004ff913  75cc                 jne 0x4ff8e1
// 004ff915  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ff919  8bc6                 mov eax, esi
// 004ff91b  5e                   pop esi
// 004ff91c  5d                   pop ebp
// 004ff91d  5b                   pop ebx
// 004ff91e  c60101               mov byte ptr [ecx], 1
// 004ff921  5f                   pop edi
// 004ff922  c20c00               ret 0xc
// 004ff925  8b542418             mov edx, dword ptr [esp + 0x18]
// 004ff929  5e                   pop esi
// 004ff92a  5d                   pop ebp
// 004ff92b  8bc3                 mov eax, ebx
// 004ff92d  5b                   pop ebx
// 004ff92e  c60200               mov byte ptr [edx], 0
// 004ff931  5f                   pop edi
// 004ff932  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?GetIndexFromKey@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QBEIABUSystemAddress@@PA_NP6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
