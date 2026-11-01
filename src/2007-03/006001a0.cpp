// from server: 100% by auto
// roc 2007-03 006001a0  unit: seg_00600000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006001a0
//
// 006001a0  56                   push esi
// 006001a1  8b742408             mov esi, dword ptr [esp + 8]
// 006001a5  8b4634               mov eax, dword ptr [esi + 0x34]
// 006001a8  6683403401           add word ptr [eax + 0x34], 1
// 006001ad  8b4634               mov eax, dword ptr [esi + 0x34]
// 006001b0  66817834c800         cmp word ptr [eax + 0x34], 0xc8
// 006001b6  57                   push edi
// 006001b7  7617                 jbe 0x6001d0
// 006001b9  6a00                 push 0
// 006001bb  68e8047c00           push 0x7c04e8
// 006001c0  56                   push esi
// 006001c1  e80a0d0000           call 0x600ed0
// 006001c6  83c40c               add esp, 0xc
// 006001c9  8da42400000000       lea esp, [esp]
// 006001d0  8b4610               mov eax, dword ptr [esi + 0x10]
// 006001d3  05fcfeffff           add eax, 0xfffffefc
// 006001d8  83f81b               cmp eax, 0x1b
// 006001db  770e                 ja 0x6001eb
// 006001dd  0fb68828026000       movzx ecx, byte ptr [eax + 0x600228]
// 006001e4  ff248d20026000       jmp dword ptr [ecx*4 + 0x600220]
// 006001eb  8bc6                 mov eax, esi
// 006001ed  e85efeffff           call 0x600050
// 006001f2  837e103b             cmp dword ptr [esi + 0x10], 0x3b
// 006001f6  8bf8                 mov edi, eax
// 006001f8  7509                 jne 0x600203
// 006001fa  56                   push esi
// 006001fb  e8a0210000           call 0x6023a0
// 00600200  83c404               add esp, 4
// 00600203  85ff                 test edi, edi
// 00600205  8b4630               mov eax, dword ptr [esi + 0x30]
// 00600208  0fb65032             movzx edx, byte ptr [eax + 0x32]
// 0060020c  895024               mov dword ptr [eax + 0x24], edx
// 0060020f  74bf                 je 0x6001d0
// 00600211  8b7634               mov esi, dword ptr [esi + 0x34]
// 00600214  66814634ffff         add word ptr [esi + 0x34], 0xffff
// 0060021a  5f                   pop edi
// 0060021b  5e                   pop esi
// 0060021c  c3                   ret 
// 0060021d  8d4900               lea ecx, [ecx]
// 00600220  1102                 adc dword ptr [edx], eax
// 00600222  60                   pushal 
// 00600223  00eb                 add bl, ch
// 00600225  016000               add dword ptr [eax], esp
// 00600228  0000                 add byte ptr [eax], al
// 0060022a  0001                 add byte ptr [ecx], al
// 0060022c  0101                 add dword ptr [ecx], eax
// 0060022e  0101                 add dword ptr [ecx], eax
// 00600230  0101                 add dword ptr [ecx], eax
// 00600232  0101                 add dword ptr [ecx], eax
// 00600234  0101                 add dword ptr [ecx], eax
// 00600236  0101                 add dword ptr [ecx], eax
// 00600238  0001                 add byte ptr [ecx], al
// 0060023a  0101                 add dword ptr [ecx], eax
// 0060023c  0101                 add dword ptr [ecx], eax
// 0060023e  0101                 add dword ptr [ecx], eax
// 00600240  0101                 add dword ptr [ecx], eax
// 00600242  0100                 add dword ptr [eax], eax
// library lua-5.1.1/lparser.c (function _chunk)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
