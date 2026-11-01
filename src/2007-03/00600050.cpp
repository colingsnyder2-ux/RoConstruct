// from server: 100% by auto
// roc 2007-03 00600050  unit: seg_00600000  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600050
//
// 00600050  53                   push ebx
// 00600051  56                   push esi
// 00600052  8bf0                 mov esi, eax
// 00600054  8b4610               mov eax, dword ptr [esi + 0x10]
// 00600057  05fefeffff           add eax, 0xfffffefe
// 0060005c  83f813               cmp eax, 0x13
// 0060005f  57                   push edi
// 00600060  8b7e04               mov edi, dword ptr [esi + 4]
// 00600063  0f87e2000000         ja 0x60014b
// 00600069  0fb68080016000       movzx eax, byte ptr [eax + 0x600180]
// 00600070  ff248558016000       jmp dword ptr [eax*4 + 0x600158]
// 00600077  57                   push edi
// 00600078  8bc6                 mov eax, esi
// 0060007a  e831faffff           call 0x5ffab0
// 0060007f  83c404               add esp, 4
// 00600082  5f                   pop edi
// 00600083  5e                   pop esi
// 00600084  33c0                 xor eax, eax
// 00600086  5b                   pop ebx
// 00600087  c3                   ret 
// 00600088  57                   push edi
// 00600089  8bc6                 mov eax, esi
// 0060008b  e8c0efffff           call 0x5ff050
// 00600090  83c404               add esp, 4
// 00600093  5f                   pop edi
// 00600094  5e                   pop esi
// 00600095  33c0                 xor eax, eax
// 00600097  5b                   pop ebx
// 00600098  c3                   ret 
// 00600099  56                   push esi
// 0060009a  e801230000           call 0x6023a0
// 0060009f  8bc6                 mov eax, esi
// 006000a1  e83aedffff           call 0x5fede0
// 006000a6  8bc7                 mov eax, edi
// 006000a8  6803010000           push 0x103
// 006000ad  bf06010000           mov edi, 0x106
// 006000b2  e819d4ffff           call 0x5fd4d0
// 006000b7  83c408               add esp, 8
// 006000ba  5f                   pop edi
// 006000bb  5e                   pop esi
// 006000bc  33c0                 xor eax, eax
// 006000be  5b                   pop ebx
// 006000bf  c3                   ret 
// 006000c0  57                   push edi
// 006000c1  8bc6                 mov eax, esi
// 006000c3  e848f8ffff           call 0x5ff910
// 006000c8  83c404               add esp, 4
// 006000cb  5f                   pop edi
// 006000cc  5e                   pop esi
// 006000cd  33c0                 xor eax, eax
// 006000cf  5b                   pop ebx
// 006000d0  c3                   ret 
// 006000d1  57                   push edi
// 006000d2  8bde                 mov ebx, esi
// 006000d4  e8a7f0ffff           call 0x5ff180
// 006000d9  83c404               add esp, 4
// 006000dc  5f                   pop edi
// 006000dd  5e                   pop esi
// 006000de  33c0                 xor eax, eax
// 006000e0  5b                   pop ebx
// 006000e1  c3                   ret 
// 006000e2  e899fdffff           call 0x5ffe80
// 006000e7  5f                   pop edi
// 006000e8  5e                   pop esi
// 006000e9  33c0                 xor eax, eax
// 006000eb  5b                   pop ebx
// 006000ec  c3                   ret 
// 006000ed  56                   push esi
// 006000ee  e8ad220000           call 0x6023a0
// 006000f3  83c404               add esp, 4
// 006000f6  817e1009010000       cmp dword ptr [esi + 0x10], 0x109
// 006000fd  7516                 jne 0x600115
// 006000ff  56                   push esi
// 00600100  e89b220000           call 0x6023a0
// 00600105  83c404               add esp, 4
// 00600108  8bde                 mov ebx, esi
// 0060010a  e861faffff           call 0x5ffb70
// 0060010f  5f                   pop edi
// 00600110  5e                   pop esi
// 00600111  33c0                 xor eax, eax
// 00600113  5b                   pop ebx
// 00600114  c3                   ret 
// 00600115  8bc6                 mov eax, esi
// 00600117  e864fbffff           call 0x5ffc80
// 0060011c  5f                   pop edi
// 0060011d  5e                   pop esi
// 0060011e  33c0                 xor eax, eax
// 00600120  5b                   pop ebx
// 00600121  c3                   ret 
// 00600122  8bc6                 mov eax, esi
// 00600124  e807feffff           call 0x5fff30
// 00600129  5f                   pop edi
// 0060012a  5e                   pop esi
// 0060012b  b801000000           mov eax, 1
// 00600130  5b                   pop ebx
// 00600131  c3                   ret 
// 00600132  56                   push esi
// 00600133  e868220000           call 0x6023a0
// 00600138  83c404               add esp, 4
// 0060013b  8bc6                 mov eax, esi
// 0060013d  e8aeeeffff           call 0x5feff0
// 00600142  5f                   pop edi
// 00600143  5e                   pop esi
// 00600144  b801000000           mov eax, 1
// 00600149  5b                   pop ebx
// 0060014a  c3                   ret 
// 0060014b  8bc6                 mov eax, esi
// 0060014d  e87efdffff           call 0x5ffed0
// 00600152  5f                   pop edi
// 00600153  5e                   pop esi
// 00600154  33c0                 xor eax, eax
// 00600156  5b                   pop ebx
// 00600157  c3                   ret 
// 00600158  3201                 xor al, byte ptr [ecx]
// 0060015a  60                   pushal 
// 0060015b  0099006000c0         add byte ptr [ecx - 0x3fffa000], bl
// 00600161  006000               add byte ptr [eax], ah
// 00600164  e200                 loop 0x600166
// 00600166  60                   pushal 
// 00600167  007700               add byte ptr [edi], dh
// 0060016a  60                   pushal 
// 0060016b  00ed                 add ch, ch
// 0060016d  006000               add byte ptr [eax], ah
// 00600170  d100                 rol dword ptr [eax], 1
// 00600172  60                   pushal 
// 00600173  0022                 add byte ptr [edx], ah
// 00600175  016000               add dword ptr [eax], esp
// 00600178  8800                 mov byte ptr [eax], al
// 0060017a  60                   pushal 
// 0060017b  004b01               add byte ptr [ebx + 1], cl
// 0060017e  60                   pushal 
// 0060017f  0000                 add byte ptr [eax], al
// 00600181  0109                 add dword ptr [ecx], ecx
// 00600183  0909                 or dword ptr [ecx], ecx
// 00600185  0902                 or dword ptr [edx], eax
// 00600187  030409               add eax, dword ptr [ecx + ecx]
// 0060018a  0509090906           add eax, 0x6090909
// 0060018f  07                   pop es
// 00600190  0909                 or dword ptr [ecx], ecx
// 00600192  0908                 or dword ptr [eax], ecx
// library lua-5.1.1/lparser.c (function _statement)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
