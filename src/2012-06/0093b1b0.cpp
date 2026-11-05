// roc 2012-06 0093b1b0  unit: seg_00930000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093b1b0
//
// 0093b1b0  56                   push esi
// 0093b1b1  8b742408             mov esi, dword ptr [esp + 8]
// 0093b1b5  8b4634               mov eax, dword ptr [esi + 0x34]
// 0093b1b8  66ff4034             inc word ptr [eax + 0x34]
// 0093b1bc  8b4634               mov eax, dword ptr [esi + 0x34]
// 0093b1bf  b9c8000000           mov ecx, 0xc8
// 0093b1c4  57                   push edi
// 0093b1c5  66394834             cmp word ptr [eax + 0x34], cx
// 0093b1c9  7615                 jbe 0x93b1e0
// 0093b1cb  6a00                 push 0
// 0093b1cd  68ecfbbf00           push 0xbffbec
// 0093b1d2  56                   push esi
// 0093b1d3  e898bfffff           call 0x937170
// 0093b1d8  83c40c               add esp, 0xc
// 0093b1db  eb03                 jmp 0x93b1e0
// 0093b1dd  8d4900               lea ecx, [ecx]
// 0093b1e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0093b1e3  05fcfeffff           add eax, 0xfffffefc
// 0093b1e8  83f81b               cmp eax, 0x1b
// 0093b1eb  770e                 ja 0x93b1fb
// 0093b1ed  0fb69038b29300       movzx edx, byte ptr [eax + 0x93b238]
// 0093b1f4  ff249530b29300       jmp dword ptr [edx*4 + 0x93b230]
// 0093b1fb  8bc6                 mov eax, esi
// 0093b1fd  e86efeffff           call 0x93b070
// 0093b202  837e103b             cmp dword ptr [esi + 0x10], 0x3b
// 0093b206  8bf8                 mov edi, eax
// 0093b208  7509                 jne 0x93b213
// 0093b20a  56                   push esi
// 0093b20b  e8b0d1ffff           call 0x9383c0
// 0093b210  83c404               add esp, 4
// 0093b213  8b4630               mov eax, dword ptr [esi + 0x30]
// 0093b216  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 0093b21a  894824               mov dword ptr [eax + 0x24], ecx
// 0093b21d  85ff                 test edi, edi
// 0093b21f  74bf                 je 0x93b1e0
// 0093b221  8b7634               mov esi, dword ptr [esi + 0x34]
// 0093b224  baffff0000           mov edx, 0xffff
// 0093b229  66015634             add word ptr [esi + 0x34], dx
// 0093b22d  5f                   pop edi
// 0093b22e  5e                   pop esi
// 0093b22f  c3                   ret 
// 0093b230  21b29300fbb1         and dword ptr [edx - 0x4e04ff6d], esi
// 0093b236  93                   xchg ebx, eax
// 0093b237  0000                 add byte ptr [eax], al
// 0093b239  0000                 add byte ptr [eax], al
// 0093b23b  0101                 add dword ptr [ecx], eax
// 0093b23d  0101                 add dword ptr [ecx], eax
// 0093b23f  0101                 add dword ptr [ecx], eax
// 0093b241  0101                 add dword ptr [ecx], eax
// 0093b243  0101                 add dword ptr [ecx], eax
// 0093b245  0101                 add dword ptr [ecx], eax
// 0093b247  0100                 add dword ptr [eax], eax
// 0093b249  0101                 add dword ptr [ecx], eax
// 0093b24b  0101                 add dword ptr [ecx], eax
// 0093b24d  0101                 add dword ptr [ecx], eax
// 0093b24f  0101                 add dword ptr [ecx], eax
// 0093b251  0101                 add dword ptr [ecx], eax
// library lua-5.1/lparser.c (function _chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
