// from server: 100% by auto
// roc 2010-06 00790360  unit: RBX::GroupDragTool  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00790360
//
// 00790360  53                   push ebx
// 00790361  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00790365  56                   push esi
// 00790366  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079036a  57                   push edi
// 0079036b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0079036f  8b07                 mov eax, dword ptr [edi]
// 00790371  83c0fa               add eax, -6
// 00790374  83f803               cmp eax, 3
// 00790377  0f879f000000         ja 0x79041c
// 0079037d  ff24853c047900       jmp dword ptr [eax*4 + 0x79043c]
// 00790384  8bc3                 mov eax, ebx
// 00790386  83380c               cmp dword ptr [eax], 0xc
// 00790389  8bce                 mov ecx, esi
// 0079038b  7516                 jne 0x7903a3
// 0079038d  8b5008               mov edx, dword ptr [eax + 8]
// 00790390  f7c200010000         test edx, 0x100
// 00790396  750b                 jne 0x7903a3
// 00790398  0fb67132             movzx esi, byte ptr [ecx + 0x32]
// 0079039c  3bd6                 cmp edx, esi
// 0079039e  7c03                 jl 0x7903a3
// 007903a0  ff4924               dec dword ptr [ecx + 0x24]
// 007903a3  8b5708               mov edx, dword ptr [edi + 8]
// 007903a6  52                   push edx
// 007903a7  e8a4fcffff           call 0x790050
// 007903ac  83c404               add esp, 4
// 007903af  5f                   pop edi
// 007903b0  5e                   pop esi
// 007903b1  5b                   pop ebx
// 007903b2  c3                   ret 
// 007903b3  53                   push ebx
// 007903b4  56                   push esi
// 007903b5  e836feffff           call 0x7901f0
// 007903ba  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007903bd  8b5108               mov edx, dword ptr [ecx + 8]
// 007903c0  8b4f08               mov ecx, dword ptr [edi + 8]
// 007903c3  c1e111               shl ecx, 0x11
// 007903c6  0bc8                 or ecx, eax
// 007903c8  c1e106               shl ecx, 6
// 007903cb  52                   push edx
// 007903cc  83c908               or ecx, 8
// 007903cf  51                   push ecx
// 007903d0  e8ebf6ffff           call 0x78fac0
// 007903d5  83c410               add esp, 0x10
// 007903d8  eb42                 jmp 0x79041c
// 007903da  53                   push ebx
// 007903db  56                   push esi
// 007903dc  e80ffeffff           call 0x7901f0
// 007903e1  8b560c               mov edx, dword ptr [esi + 0xc]
// 007903e4  8b4a08               mov ecx, dword ptr [edx + 8]
// 007903e7  8b5708               mov edx, dword ptr [edi + 8]
// 007903ea  c1e208               shl edx, 8
// 007903ed  0bd0                 or edx, eax
// 007903ef  c1e206               shl edx, 6
// 007903f2  51                   push ecx
// 007903f3  83ca07               or edx, 7
// 007903f6  52                   push edx
// 007903f7  e8c4f6ffff           call 0x78fac0
// 007903fc  83c410               add esp, 0x10
// 007903ff  eb1b                 jmp 0x79041c
// 00790401  53                   push ebx
// 00790402  56                   push esi
// 00790403  e858feffff           call 0x790260
// 00790408  8b4f08               mov ecx, dword ptr [edi + 8]
// 0079040b  50                   push eax
// 0079040c  8b470c               mov eax, dword ptr [edi + 0xc]
// 0079040f  50                   push eax
// 00790410  51                   push ecx
// 00790411  6a09                 push 9
// 00790413  56                   push esi
// 00790414  e847f7ffff           call 0x78fb60
// 00790419  83c41c               add esp, 0x1c
// 0079041c  833b0c               cmp dword ptr [ebx], 0xc
// 0079041f  7516                 jne 0x790437
// 00790421  8b5b08               mov ebx, dword ptr [ebx + 8]
// 00790424  f7c300010000         test ebx, 0x100
// 0079042a  750b                 jne 0x790437
// 0079042c  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 00790430  3bda                 cmp ebx, edx
// 00790432  7c03                 jl 0x790437
// 00790434  ff4e24               dec dword ptr [esi + 0x24]
// 00790437  5f                   pop edi
// 00790438  5e                   pop esi
// 00790439  5b                   pop ebx
// 0079043a  c3                   ret 
// 0079043b  90                   nop 
// 0079043c  8403                 test byte ptr [ebx], al
// 0079043e  7900                 jns 0x790440
// 00790440  b303                 mov bl, 3
// 00790442  7900                 jns 0x790444
// 00790444  da03                 fiadd dword ptr [ebx]
// 00790446  7900                 jns 0x790448
// 00790448  010479               add dword ptr [ecx + edi*2], eax
// library lua-5.1/lcode.c (function _luaK_storevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
