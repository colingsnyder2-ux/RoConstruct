// from server: 100% by auto
// roc 2008-06 0066ba20  unit: RBX::GroupDragTool  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ba20
//
// 0066ba20  53                   push ebx
// 0066ba21  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0066ba25  56                   push esi
// 0066ba26  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0066ba2a  57                   push edi
// 0066ba2b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0066ba2f  8b07                 mov eax, dword ptr [edi]
// 0066ba31  83c0fa               add eax, -6
// 0066ba34  83f803               cmp eax, 3
// 0066ba37  0f879f000000         ja 0x66badc
// 0066ba3d  ff2485fcba6600       jmp dword ptr [eax*4 + 0x66bafc]
// 0066ba44  8bc3                 mov eax, ebx
// 0066ba46  83380c               cmp dword ptr [eax], 0xc
// 0066ba49  8bce                 mov ecx, esi
// 0066ba4b  7516                 jne 0x66ba63
// 0066ba4d  8b5008               mov edx, dword ptr [eax + 8]
// 0066ba50  f7c200010000         test edx, 0x100
// 0066ba56  750b                 jne 0x66ba63
// 0066ba58  0fb67132             movzx esi, byte ptr [ecx + 0x32]
// 0066ba5c  3bd6                 cmp edx, esi
// 0066ba5e  7c03                 jl 0x66ba63
// 0066ba60  ff4924               dec dword ptr [ecx + 0x24]
// 0066ba63  8b5708               mov edx, dword ptr [edi + 8]
// 0066ba66  52                   push edx
// 0066ba67  e8a4fcffff           call 0x66b710
// 0066ba6c  83c404               add esp, 4
// 0066ba6f  5f                   pop edi
// 0066ba70  5e                   pop esi
// 0066ba71  5b                   pop ebx
// 0066ba72  c3                   ret 
// 0066ba73  53                   push ebx
// 0066ba74  56                   push esi
// 0066ba75  e836feffff           call 0x66b8b0
// 0066ba7a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0066ba7d  8b5108               mov edx, dword ptr [ecx + 8]
// 0066ba80  8b4f08               mov ecx, dword ptr [edi + 8]
// 0066ba83  c1e111               shl ecx, 0x11
// 0066ba86  0bc8                 or ecx, eax
// 0066ba88  c1e106               shl ecx, 6
// 0066ba8b  52                   push edx
// 0066ba8c  83c908               or ecx, 8
// 0066ba8f  51                   push ecx
// 0066ba90  e8fbf6ffff           call 0x66b190
// 0066ba95  83c410               add esp, 0x10
// 0066ba98  eb42                 jmp 0x66badc
// 0066ba9a  53                   push ebx
// 0066ba9b  56                   push esi
// 0066ba9c  e80ffeffff           call 0x66b8b0
// 0066baa1  8b560c               mov edx, dword ptr [esi + 0xc]
// 0066baa4  8b4a08               mov ecx, dword ptr [edx + 8]
// 0066baa7  8b5708               mov edx, dword ptr [edi + 8]
// 0066baaa  c1e208               shl edx, 8
// 0066baad  0bd0                 or edx, eax
// 0066baaf  c1e206               shl edx, 6
// 0066bab2  51                   push ecx
// 0066bab3  83ca07               or edx, 7
// 0066bab6  52                   push edx
// 0066bab7  e8d4f6ffff           call 0x66b190
// 0066babc  83c410               add esp, 0x10
// 0066babf  eb1b                 jmp 0x66badc
// 0066bac1  53                   push ebx
// 0066bac2  56                   push esi
// 0066bac3  e858feffff           call 0x66b920
// 0066bac8  8b4f08               mov ecx, dword ptr [edi + 8]
// 0066bacb  50                   push eax
// 0066bacc  8b470c               mov eax, dword ptr [edi + 0xc]
// 0066bacf  50                   push eax
// 0066bad0  51                   push ecx
// 0066bad1  6a09                 push 9
// 0066bad3  56                   push esi
// 0066bad4  e857f7ffff           call 0x66b230
// 0066bad9  83c41c               add esp, 0x1c
// 0066badc  833b0c               cmp dword ptr [ebx], 0xc
// 0066badf  7516                 jne 0x66baf7
// 0066bae1  8b5b08               mov ebx, dword ptr [ebx + 8]
// 0066bae4  f7c300010000         test ebx, 0x100
// 0066baea  750b                 jne 0x66baf7
// 0066baec  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 0066baf0  3bda                 cmp ebx, edx
// 0066baf2  7c03                 jl 0x66baf7
// 0066baf4  ff4e24               dec dword ptr [esi + 0x24]
// 0066baf7  5f                   pop edi
// 0066baf8  5e                   pop esi
// 0066baf9  5b                   pop ebx
// 0066bafa  c3                   ret 
// 0066bafb  90                   nop 
// 0066bafc  44                   inc esp
// 0066bafd  ba660073ba           mov edx, 0xba730066
// 0066bb02  66009aba6600c1       add byte ptr [edx - 0x3eff9946], bl
// library lua-5.1/lcode.c (function _luaK_storevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
