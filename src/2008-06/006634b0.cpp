// from server: 100% by auto
// roc 2008-06 006634b0  unit: RBX::FilterStairs  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006634b0
//
// 006634b0  56                   push esi
// 006634b1  8b742408             mov esi, dword ptr [esp + 8]
// 006634b5  8b4634               mov eax, dword ptr [esi + 0x34]
// 006634b8  66ff4034             inc word ptr [eax + 0x34]
// 006634bc  8b4634               mov eax, dword ptr [esi + 0x34]
// 006634bf  b9c8000000           mov ecx, 0xc8
// 006634c4  57                   push edi
// 006634c5  66394834             cmp word ptr [eax + 0x34], cx
// 006634c9  7615                 jbe 0x6634e0
// 006634cb  6a00                 push 0
// 006634cd  6880c58400           push 0x84c580
// 006634d2  56                   push esi
// 006634d3  e8980c0000           call 0x664170
// 006634d8  83c40c               add esp, 0xc
// 006634db  eb03                 jmp 0x6634e0
// 006634dd  8d4900               lea ecx, [ecx]
// 006634e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 006634e3  05fcfeffff           add eax, 0xfffffefc
// 006634e8  83f81b               cmp eax, 0x1b
// 006634eb  770e                 ja 0x6634fb
// 006634ed  0fb69038356600       movzx edx, byte ptr [eax + 0x663538]
// 006634f4  ff249530356600       jmp dword ptr [edx*4 + 0x663530]
// 006634fb  8bc6                 mov eax, esi
// 006634fd  e85efeffff           call 0x663360
// 00663502  837e103b             cmp dword ptr [esi + 0x10], 0x3b
// 00663506  8bf8                 mov edi, eax
// 00663508  7509                 jne 0x663513
// 0066350a  56                   push esi
// 0066350b  e8f0200000           call 0x665600
// 00663510  83c404               add esp, 4
// 00663513  8b4630               mov eax, dword ptr [esi + 0x30]
// 00663516  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 0066351a  894824               mov dword ptr [eax + 0x24], ecx
// 0066351d  85ff                 test edi, edi
// 0066351f  74bf                 je 0x6634e0
// 00663521  8b7634               mov esi, dword ptr [esi + 0x34]
// 00663524  baffff0000           mov edx, 0xffff
// 00663529  66015634             add word ptr [esi + 0x34], dx
// 0066352d  5f                   pop edi
// 0066352e  5e                   pop esi
// 0066352f  c3                   ret 
// 00663530  21356600fb34         and dword ptr [0x34fb0066], esi
// 00663536  660000               add byte ptr [eax], al
// 00663539  0000                 add byte ptr [eax], al
// 0066353b  0101                 add dword ptr [ecx], eax
// 0066353d  0101                 add dword ptr [ecx], eax
// 0066353f  0101                 add dword ptr [ecx], eax
// 00663541  0101                 add dword ptr [ecx], eax
// 00663543  0101                 add dword ptr [ecx], eax
// 00663545  0101                 add dword ptr [ecx], eax
// 00663547  0100                 add dword ptr [eax], eax
// 00663549  0101                 add dword ptr [ecx], eax
// 0066354b  0101                 add dword ptr [ecx], eax
// 0066354d  0101                 add dword ptr [ecx], eax
// 0066354f  0101                 add dword ptr [ecx], eax
// 00663551  0101                 add dword ptr [ecx], eax
// library lua-5.1/lparser.c (function _chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
