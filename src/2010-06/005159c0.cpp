// from server: 100% by auto
// roc 2010-06 005159c0  unit: RakPeer  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005159c0
//
// 005159c0  57                   push edi
// 005159c1  8bf9                 mov edi, ecx
// 005159c3  837f0400             cmp dword ptr [edi + 4], 0
// 005159c7  750d                 jne 0x5159d6
// 005159c9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005159cd  c60000               mov byte ptr [eax], 0
// 005159d0  33c0                 xor eax, eax
// 005159d2  5f                   pop edi
// 005159d3  c20c00               ret 0xc
// 005159d6  8b4704               mov eax, dword ptr [edi + 4]
// 005159d9  53                   push ebx
// 005159da  55                   push ebp
// 005159db  8d68ff               lea ebp, [eax - 1]
// 005159de  99                   cdq 
// 005159df  2bc2                 sub eax, edx
// 005159e1  8b17                 mov edx, dword ptr [edi]
// 005159e3  56                   push esi
// 005159e4  8bf0                 mov esi, eax
// 005159e6  d1fe                 sar esi, 1
// 005159e8  8d0c76               lea ecx, [esi + esi*2]
// 005159eb  8d048a               lea eax, [edx + ecx*4]
// 005159ee  50                   push eax
// 005159ef  8b442418             mov eax, dword ptr [esp + 0x18]
// 005159f3  50                   push eax
// 005159f4  33db                 xor ebx, ebx
// 005159f6  ff542424             call dword ptr [esp + 0x24]
// 005159fa  83c408               add esp, 8
// 005159fd  85c0                 test eax, eax
// 005159ff  7434                 je 0x515a35
// 00515a01  7d05                 jge 0x515a08
// 00515a03  8d6eff               lea ebp, [esi - 1]
// 00515a06  eb03                 jmp 0x515a0b
// 00515a08  8d5e01               lea ebx, [esi + 1]
// 00515a0b  8bc5                 mov eax, ebp
// 00515a0d  2bc3                 sub eax, ebx
// 00515a0f  99                   cdq 
// 00515a10  2bc2                 sub eax, edx
// 00515a12  8bf0                 mov esi, eax
// 00515a14  d1fe                 sar esi, 1
// 00515a16  03f3                 add esi, ebx
// 00515a18  3bdd                 cmp ebx, ebp
// 00515a1a  7f29                 jg 0x515a45
// 00515a1c  8b17                 mov edx, dword ptr [edi]
// 00515a1e  8d0c76               lea ecx, [esi + esi*2]
// 00515a21  8d048a               lea eax, [edx + ecx*4]
// 00515a24  50                   push eax
// 00515a25  8b442418             mov eax, dword ptr [esp + 0x18]
// 00515a29  50                   push eax
// 00515a2a  ff542424             call dword ptr [esp + 0x24]
// 00515a2e  83c408               add esp, 8
// 00515a31  85c0                 test eax, eax
// 00515a33  75cc                 jne 0x515a01
// 00515a35  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00515a39  8bc6                 mov eax, esi
// 00515a3b  5e                   pop esi
// 00515a3c  5d                   pop ebp
// 00515a3d  5b                   pop ebx
// 00515a3e  c60101               mov byte ptr [ecx], 1
// 00515a41  5f                   pop edi
// 00515a42  c20c00               ret 0xc
// 00515a45  8b542418             mov edx, dword ptr [esp + 0x18]
// 00515a49  5e                   pop esi
// 00515a4a  5d                   pop ebp
// 00515a4b  8bc3                 mov eax, ebx
// 00515a4d  5b                   pop ebx
// 00515a4e  c60200               mov byte ptr [edx], 0
// 00515a51  5f                   pop edi
// 00515a52  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?GetIndexFromKey@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QBEIABUSystemAddress@@PA_NP6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
