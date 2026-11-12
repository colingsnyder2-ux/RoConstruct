// from server: 100% by auto
// roc 2008-06 004c0ee0  unit: ProfiledRakPeer  size: 758 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0ee0
//
// 004c0ee0  81ecc0000000         sub esp, 0xc0
// 004c0ee6  33c0                 xor eax, eax
// 004c0ee8  53                   push ebx
// 004c0ee9  8b9c24c8000000       mov ebx, dword ptr [esp + 0xc8]
// 004c0ef0  56                   push esi
// 004c0ef1  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c0ef5  89442430             mov dword ptr [esp + 0x30], eax
// 004c0ef9  89442434             mov dword ptr [esp + 0x34], eax
// 004c0efd  89442438             mov dword ptr [esp + 0x38], eax
// 004c0f01  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c0f05  89442440             mov dword ptr [esp + 0x40], eax
// 004c0f09  89442444             mov dword ptr [esp + 0x44], eax
// 004c0f0d  57                   push edi
// 004c0f0e  8d44240c             lea eax, [esp + 0xc]
// 004c0f12  50                   push eax
// 004c0f13  53                   push ebx
// 004c0f14  c744243401000000     mov dword ptr [esp + 0x34], 1
// 004c0f1c  e87ff8ffff           call 0x4c07a0
// 004c0f21  8d4c2474             lea ecx, [esp + 0x74]
// 004c0f25  51                   push ecx
// 004c0f26  8d542458             lea edx, [esp + 0x58]
// 004c0f2a  52                   push edx
// 004c0f2b  8d44241c             lea eax, [esp + 0x1c]
// 004c0f2f  50                   push eax
// 004c0f30  53                   push ebx
// 004c0f31  e86addffff           call 0x4beca0
// 004c0f36  83c418               add esp, 0x18
// 004c0f39  33c0                 xor eax, eax
// 004c0f3b  eb03                 jmp 0x4c0f40
// 004c0f3d  8d4900               lea ecx, [ecx]
// 004c0f40  837c846c00           cmp dword ptr [esp + eax*4 + 0x6c], 0
// 004c0f45  7522                 jne 0x4c0f69
// 004c0f47  40                   inc eax
// 004c0f48  83f808               cmp eax, 8
// 004c0f4b  72f3                 jb 0x4c0f40
// 004c0f4d  8bbc24d4000000       mov edi, dword ptr [esp + 0xd4]
// 004c0f54  8d74242c             lea esi, [esp + 0x2c]
// 004c0f58  b908000000           mov ecx, 8
// 004c0f5d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c0f5f  5f                   pop edi
// 004c0f60  5e                   pop esi
// 004c0f61  5b                   pop ebx
// 004c0f62  81c4c0000000         add esp, 0xc0
// 004c0f68  c3                   ret 
// 004c0f69  b908000000           mov ecx, 8
// 004c0f6e  8bf3                 mov esi, ebx
// 004c0f70  8dbc248c000000       lea edi, [esp + 0x8c]
// 004c0f77  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c0f79  8d4c244c             lea ecx, [esp + 0x4c]
// 004c0f7d  51                   push ecx
// 004c0f7e  8d942490000000       lea edx, [esp + 0x90]
// 004c0f85  52                   push edx
// 004c0f86  e875b9ffff           call 0x4bc900
// 004c0f8b  8d442414             lea eax, [esp + 0x14]
// 004c0f8f  50                   push eax
// 004c0f90  8d4c2458             lea ecx, [esp + 0x58]
// 004c0f94  51                   push ecx
// 004c0f95  8d54247c             lea edx, [esp + 0x7c]
// 004c0f99  52                   push edx
// 004c0f9a  50                   push eax
// 004c0f9b  e800ddffff           call 0x4beca0
// 004c0fa0  83c418               add esp, 0x18
// 004c0fa3  33c0                 xor eax, eax
// 004c0fa5  837c840c00           cmp dword ptr [esp + eax*4 + 0xc], 0
// 004c0faa  7525                 jne 0x4c0fd1
// 004c0fac  40                   inc eax
// 004c0fad  83f808               cmp eax, 8
// 004c0fb0  72f3                 jb 0x4c0fa5
// 004c0fb2  8bbc24d4000000       mov edi, dword ptr [esp + 0xd4]
// 004c0fb9  8db4248c000000       lea esi, [esp + 0x8c]
// 004c0fc0  b908000000           mov ecx, 8
// 004c0fc5  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c0fc7  5f                   pop edi
// 004c0fc8  5e                   pop esi
// 004c0fc9  5b                   pop ebx
// 004c0fca  81c4c0000000         add esp, 0xc0
// 004c0fd0  c3                   ret 
// 004c0fd1  8d8c24ac000000       lea ecx, [esp + 0xac]
// 004c0fd8  51                   push ecx
// 004c0fd9  53                   push ebx
// 004c0fda  8d542434             lea edx, [esp + 0x34]
// 004c0fde  52                   push edx
// 004c0fdf  8d842498000000       lea eax, [esp + 0x98]
// 004c0fe6  50                   push eax
// 004c0fe7  8d4c245c             lea ecx, [esp + 0x5c]
// 004c0feb  51                   push ecx
// 004c0fec  e8cfe2ffff           call 0x4bf2c0
// 004c0ff1  8d942480000000       lea edx, [esp + 0x80]
// 004c0ff8  52                   push edx
// 004c0ff9  8d442464             lea eax, [esp + 0x64]
// 004c0ffd  50                   push eax
// 004c0ffe  8d4c2428             lea ecx, [esp + 0x28]
// 004c1002  51                   push ecx
// 004c1003  52                   push edx
// 004c1004  e897dcffff           call 0x4beca0
// 004c1009  83c424               add esp, 0x24
// 004c100c  33c0                 xor eax, eax
// 004c100e  8bff                 mov edi, edi
// 004c1010  837c846c00           cmp dword ptr [esp + eax*4 + 0x6c], 0
// 004c1015  7525                 jne 0x4c103c
// 004c1017  40                   inc eax
// 004c1018  83f808               cmp eax, 8
// 004c101b  72f3                 jb 0x4c1010
// 004c101d  8bbc24d4000000       mov edi, dword ptr [esp + 0xd4]
// 004c1024  8db424ac000000       lea esi, [esp + 0xac]
// 004c102b  b908000000           mov ecx, 8
// 004c1030  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c1032  5f                   pop edi
// 004c1033  5e                   pop esi
// 004c1034  5b                   pop ebx
// 004c1035  81c4c0000000         add esp, 0xc0
// 004c103b  c3                   ret 
// 004c103c  8d44242c             lea eax, [esp + 0x2c]
// 004c1040  50                   push eax
// 004c1041  53                   push ebx
// 004c1042  8d8c2494000000       lea ecx, [esp + 0x94]
// 004c1049  51                   push ecx
// 004c104a  8d9424b8000000       lea edx, [esp + 0xb8]
// 004c1051  52                   push edx
// 004c1052  8d44245c             lea eax, [esp + 0x5c]
// 004c1056  50                   push eax
// 004c1057  e864e2ffff           call 0x4bf2c0
// 004c105c  8d4c2420             lea ecx, [esp + 0x20]
// 004c1060  51                   push ecx
// 004c1061  8d542464             lea edx, [esp + 0x64]
// 004c1065  52                   push edx
// 004c1066  8d842488000000       lea eax, [esp + 0x88]
// 004c106d  50                   push eax
// 004c106e  51                   push ecx
// 004c106f  e82cdcffff           call 0x4beca0
// 004c1074  83c424               add esp, 0x24
// 004c1077  33c0                 xor eax, eax
// 004c1079  8da42400000000       lea esp, [esp]
// 004c1080  837c840c00           cmp dword ptr [esp + eax*4 + 0xc], 0
// 004c1085  750b                 jne 0x4c1092
// 004c1087  40                   inc eax
// 004c1088  83f808               cmp eax, 8
// 004c108b  72f3                 jb 0x4c1080
// 004c108d  e9bbfeffff           jmp 0x4c0f4d
// 004c1092  8d94248c000000       lea edx, [esp + 0x8c]
// 004c1099  52                   push edx
// 004c109a  53                   push ebx
// 004c109b  8d8424b4000000       lea eax, [esp + 0xb4]
// 004c10a2  50                   push eax
// 004c10a3  8d4c2438             lea ecx, [esp + 0x38]
// 004c10a7  51                   push ecx
// 004c10a8  8d54245c             lea edx, [esp + 0x5c]
// 004c10ac  52                   push edx
// 004c10ad  e80ee2ffff           call 0x4bf2c0
// 004c10b2  8d842480000000       lea eax, [esp + 0x80]
// 004c10b9  50                   push eax
// 004c10ba  8d4c2464             lea ecx, [esp + 0x64]
// 004c10be  51                   push ecx
// 004c10bf  8d542428             lea edx, [esp + 0x28]
// 004c10c3  52                   push edx
// 004c10c4  50                   push eax
// 004c10c5  e8d6dbffff           call 0x4beca0
// 004c10ca  83c424               add esp, 0x24
// 004c10cd  33c0                 xor eax, eax
// 004c10cf  90                   nop 
// 004c10d0  837c846c00           cmp dword ptr [esp + eax*4 + 0x6c], 0
// 004c10d5  750b                 jne 0x4c10e2
// 004c10d7  40                   inc eax
// 004c10d8  83f808               cmp eax, 8
// 004c10db  72f3                 jb 0x4c10d0
// 004c10dd  e9d0feffff           jmp 0x4c0fb2
// 004c10e2  8d8c24ac000000       lea ecx, [esp + 0xac]
// 004c10e9  51                   push ecx
// 004c10ea  53                   push ebx
// 004c10eb  8d542434             lea edx, [esp + 0x34]
// 004c10ef  52                   push edx
// 004c10f0  8d842498000000       lea eax, [esp + 0x98]
// 004c10f7  50                   push eax
// 004c10f8  8d4c245c             lea ecx, [esp + 0x5c]
// 004c10fc  51                   push ecx
// 004c10fd  e8bee1ffff           call 0x4bf2c0
// 004c1102  8d542420             lea edx, [esp + 0x20]
// 004c1106  52                   push edx
// 004c1107  8d442464             lea eax, [esp + 0x64]
// 004c110b  50                   push eax
// 004c110c  8d8c2488000000       lea ecx, [esp + 0x88]
// 004c1113  51                   push ecx
// 004c1114  52                   push edx
// 004c1115  e886dbffff           call 0x4beca0
// 004c111a  83c424               add esp, 0x24
// 004c111d  33c0                 xor eax, eax
// 004c111f  90                   nop 
// 004c1120  837c840c00           cmp dword ptr [esp + eax*4 + 0xc], 0
// 004c1125  750b                 jne 0x4c1132
// 004c1127  40                   inc eax
// 004c1128  83f808               cmp eax, 8
// 004c112b  72f3                 jb 0x4c1120
// 004c112d  e9ebfeffff           jmp 0x4c101d
// 004c1132  8d44242c             lea eax, [esp + 0x2c]
// 004c1136  50                   push eax
// 004c1137  53                   push ebx
// 004c1138  8d8c2494000000       lea ecx, [esp + 0x94]
// 004c113f  51                   push ecx
// 004c1140  8d9424b8000000       lea edx, [esp + 0xb8]
// 004c1147  52                   push edx
// 004c1148  8d44245c             lea eax, [esp + 0x5c]
// 004c114c  50                   push eax
// 004c114d  e86ee1ffff           call 0x4bf2c0
// 004c1152  8d8c2480000000       lea ecx, [esp + 0x80]
// 004c1159  51                   push ecx
// 004c115a  8d542464             lea edx, [esp + 0x64]
// 004c115e  52                   push edx
// 004c115f  8d442428             lea eax, [esp + 0x28]
// 004c1163  50                   push eax
// 004c1164  51                   push ecx
// 004c1165  e836dbffff           call 0x4beca0
// 004c116a  83c424               add esp, 0x24
// 004c116d  33c0                 xor eax, eax
// 004c116f  90                   nop 
// 004c1170  837c846c00           cmp dword ptr [esp + eax*4 + 0x6c], 0
// 004c1175  750b                 jne 0x4c1182
// 004c1177  40                   inc eax
// 004c1178  83f808               cmp eax, 8
// 004c117b  72f3                 jb 0x4c1170
// 004c117d  e9cbfdffff           jmp 0x4c0f4d
// 004c1182  8d94248c000000       lea edx, [esp + 0x8c]
// 004c1189  52                   push edx
// 004c118a  53                   push ebx
// 004c118b  8d8424b4000000       lea eax, [esp + 0xb4]
// 004c1192  50                   push eax
// 004c1193  8d4c2438             lea ecx, [esp + 0x38]
// 004c1197  51                   push ecx
// 004c1198  8d54245c             lea edx, [esp + 0x5c]
// 004c119c  52                   push edx
// 004c119d  e81ee1ffff           call 0x4bf2c0
// 004c11a2  8d442420             lea eax, [esp + 0x20]
// 004c11a6  50                   push eax
// 004c11a7  8d4c2464             lea ecx, [esp + 0x64]
// 004c11ab  51                   push ecx
// 004c11ac  8d942488000000       lea edx, [esp + 0x88]
// 004c11b3  52                   push edx
// 004c11b4  50                   push eax
// 004c11b5  e8e6daffff           call 0x4beca0
// 004c11ba  83c424               add esp, 0x24
// 004c11bd  33c0                 xor eax, eax
// 004c11bf  90                   nop 
// 004c11c0  837c840c00           cmp dword ptr [esp + eax*4 + 0xc], 0
// 004c11c5  0f8506feffff         jne 0x4c0fd1
// 004c11cb  40                   inc eax
// 004c11cc  83f808               cmp eax, 8
// 004c11cf  72ef                 jb 0x4c11c0
// 004c11d1  e9dcfdffff           jmp 0x4c0fb2
// library openrbx-raknet/RakPeer.cpp (function ??$computeRinverse@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
