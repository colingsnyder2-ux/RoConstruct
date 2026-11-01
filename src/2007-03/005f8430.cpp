// from server: 100% by auto
// roc 2007-03 005f8430  unit: seg_005f0000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8430
//
// 005f8430  8b442404             mov eax, dword ptr [esp + 4]
// 005f8434  8b5008               mov edx, dword ptr [eax + 8]
// 005f8437  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f843b  3b5108               cmp edx, dword ptr [ecx + 8]
// 005f843e  7403                 je 0x5f8443
// 005f8440  33c0                 xor eax, eax
// 005f8442  c3                   ret 
// 005f8443  83fa03               cmp edx, 3
// 005f8446  771e                 ja 0x5f8466
// 005f8448  ff249574845f00       jmp dword ptr [edx*4 + 0x5f8474]
// 005f844f  b801000000           mov eax, 1
// 005f8454  c3                   ret 
// 005f8455  dd01                 fld qword ptr [ecx]
// 005f8457  dc18                 fcomp qword ptr [eax]
// 005f8459  dfe0                 fnstsw ax
// 005f845b  f6c444               test ah, 0x44
// 005f845e  7ae0                 jp 0x5f8440
// 005f8460  b801000000           mov eax, 1
// 005f8465  c3                   ret 
// 005f8466  8b00                 mov eax, dword ptr [eax]
// 005f8468  33d2                 xor edx, edx
// 005f846a  3b01                 cmp eax, dword ptr [ecx]
// 005f846c  0f94c2               sete dl
// 005f846f  8bc2                 mov eax, edx
// 005f8471  c3                   ret 
// 005f8472  8bff                 mov edi, edi
// 005f8474  4f                   dec edi
// 005f8475  845f00               test byte ptr [edi], bl
// 005f8478  66845f00             test byte ptr [edi], bl
// 005f847c  66845f00             test byte ptr [edi], bl
// 005f8480  55                   push ebp
// 005f8481  845f00               test byte ptr [edi], bl
// library lua-5.1.1/lobject.c (function _luaO_rawequalObj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lobject.c
