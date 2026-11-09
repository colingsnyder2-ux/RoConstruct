// from server: 100% by auto
// roc 2008-06 0065e420  unit: seg_00650000  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e420
//
// 0065e420  56                   push esi
// 0065e421  8bf0                 mov esi, eax
// 0065e423  8b4208               mov eax, dword ptr [edx + 8]
// 0065e426  48                   dec eax
// 0065e427  57                   push edi
// 0065e428  83f803               cmp eax, 3
// 0065e42b  7749                 ja 0x65e476
// 0065e42d  ff248598e46500       jmp dword ptr [eax*4 + 0x65e498]
// 0065e434  dd02                 fld qword ptr [edx]
// 0065e436  83ec08               sub esp, 8
// 0065e439  dd1c24               fstp qword ptr [esp]
// 0065e43c  e89fffffff           call 0x65e3e0
// 0065e441  83c408               add esp, 8
// 0065e444  5f                   pop edi
// 0065e445  5e                   pop esi
// 0065e446  c3                   ret 
// 0065e447  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e44a  b801000000           mov eax, 1
// 0065e44f  d3e0                 shl eax, cl
// 0065e451  8b0a                 mov ecx, dword ptr [edx]
// 0065e453  5f                   pop edi
// 0065e454  48                   dec eax
// 0065e455  234108               and eax, dword ptr [ecx + 8]
// 0065e458  c1e005               shl eax, 5
// 0065e45b  034610               add eax, dword ptr [esi + 0x10]
// 0065e45e  5e                   pop esi
// 0065e45f  c3                   ret 
// 0065e460  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e463  b801000000           mov eax, 1
// 0065e468  d3e0                 shl eax, cl
// 0065e46a  5f                   pop edi
// 0065e46b  48                   dec eax
// 0065e46c  2302                 and eax, dword ptr [edx]
// 0065e46e  c1e005               shl eax, 5
// 0065e471  034610               add eax, dword ptr [esi + 0x10]
// 0065e474  5e                   pop esi
// 0065e475  c3                   ret 
// 0065e476  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e479  8b02                 mov eax, dword ptr [edx]
// 0065e47b  bf01000000           mov edi, 1
// 0065e480  d3e7                 shl edi, cl
// 0065e482  33d2                 xor edx, edx
// 0065e484  4f                   dec edi
// 0065e485  83cf01               or edi, 1
// 0065e488  f7f7                 div edi
// 0065e48a  5f                   pop edi
// 0065e48b  8bc2                 mov eax, edx
// 0065e48d  c1e005               shl eax, 5
// 0065e490  034610               add eax, dword ptr [esi + 0x10]
// 0065e493  5e                   pop esi
// 0065e494  c3                   ret 
// 0065e495  8d4900               lea ecx, [ecx]
// 0065e498  60                   pushal 
// 0065e499  e465                 in al, 0x65
// 0065e49b  0076e4               add byte ptr [esi - 0x1c], dh
// 0065e49e  650034e4             add byte ptr gs:[esp], dh
// 0065e4a2  650047e4             add byte ptr gs:[edi - 0x1c], al
// library lua-5.1/ltable.c (function _mainposition)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
