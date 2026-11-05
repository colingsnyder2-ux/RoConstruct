// from server: 100% by auto
// roc 2007-08 0060ea80  unit: RBX::Ball  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060ea80
//
// 0060ea80  8b442404             mov eax, dword ptr [esp + 4]
// 0060ea84  8b5008               mov edx, dword ptr [eax + 8]
// 0060ea87  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0060ea8b  3b5108               cmp edx, dword ptr [ecx + 8]
// 0060ea8e  7403                 je 0x60ea93
// 0060ea90  33c0                 xor eax, eax
// 0060ea92  c3                   ret 
// 0060ea93  83fa03               cmp edx, 3
// 0060ea96  771e                 ja 0x60eab6
// 0060ea98  ff2495c4ea6000       jmp dword ptr [edx*4 + 0x60eac4]
// 0060ea9f  b801000000           mov eax, 1
// 0060eaa4  c3                   ret 
// 0060eaa5  dd01                 fld qword ptr [ecx]
// 0060eaa7  dc18                 fcomp qword ptr [eax]
// 0060eaa9  dfe0                 fnstsw ax
// 0060eaab  f6c444               test ah, 0x44
// 0060eaae  7ae0                 jp 0x60ea90
// 0060eab0  b801000000           mov eax, 1
// 0060eab5  c3                   ret 
// 0060eab6  8b00                 mov eax, dword ptr [eax]
// 0060eab8  33d2                 xor edx, edx
// 0060eaba  3b01                 cmp eax, dword ptr [ecx]
// 0060eabc  0f94c2               sete dl
// 0060eabf  8bc2                 mov eax, edx
// 0060eac1  c3                   ret 
// 0060eac2  8bff                 mov edi, edi
// 0060eac4  9f                   lahf 
// 0060eac5  ea6000b6ea6000       ljmp 0x60:0xeab60060
// 0060eacc  b6ea                 mov dh, 0xea
// 0060eace  60                   pushal 
// library lua-5.1/lobject.c (function _luaO_rawequalObj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
