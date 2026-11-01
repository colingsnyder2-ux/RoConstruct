// from server: 100% by auto
// roc 2009-06 006c8c50  unit: seg_006c0000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c8c50
//
// 006c8c50  8b442404             mov eax, dword ptr [esp + 4]
// 006c8c54  8b5008               mov edx, dword ptr [eax + 8]
// 006c8c57  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006c8c5b  3b5108               cmp edx, dword ptr [ecx + 8]
// 006c8c5e  7403                 je 0x6c8c63
// 006c8c60  33c0                 xor eax, eax
// 006c8c62  c3                   ret 
// 006c8c63  83fa03               cmp edx, 3
// 006c8c66  771e                 ja 0x6c8c86
// 006c8c68  ff2495948c6c00       jmp dword ptr [edx*4 + 0x6c8c94]
// 006c8c6f  b801000000           mov eax, 1
// 006c8c74  c3                   ret 
// 006c8c75  dd01                 fld qword ptr [ecx]
// 006c8c77  dc18                 fcomp qword ptr [eax]
// 006c8c79  dfe0                 fnstsw ax
// 006c8c7b  f6c444               test ah, 0x44
// 006c8c7e  7ae0                 jp 0x6c8c60
// 006c8c80  b801000000           mov eax, 1
// 006c8c85  c3                   ret 
// 006c8c86  8b00                 mov eax, dword ptr [eax]
// 006c8c88  33d2                 xor edx, edx
// 006c8c8a  3b01                 cmp eax, dword ptr [ecx]
// 006c8c8c  0f94c2               sete dl
// 006c8c8f  8bc2                 mov eax, edx
// 006c8c91  c3                   ret 
// 006c8c92  8bff                 mov edi, edi
// 006c8c94  6f                   outsd dx, dword ptr [esi]
// 006c8c95  8c6c0086             mov word ptr [eax + eax - 0x7a], gs
// 006c8c99  8c6c0086             mov word ptr [eax + eax - 0x7a], gs
// 006c8c9d  8c6c0075             mov word ptr [eax + eax + 0x75], gs
// library lua-5.1/lobject.c (function _luaO_rawequalObj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
