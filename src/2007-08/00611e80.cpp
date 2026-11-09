// from server: 100% by auto
// roc 2007-08 00611e80  unit: seg_00610000  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00611e80
//
// 00611e80  56                   push esi
// 00611e81  8bf0                 mov esi, eax
// 00611e83  8b4208               mov eax, dword ptr [edx + 8]
// 00611e86  83c0ff               add eax, -1
// 00611e89  83f803               cmp eax, 3
// 00611e8c  57                   push edi
// 00611e8d  774d                 ja 0x611edc
// 00611e8f  ff2485001f6100       jmp dword ptr [eax*4 + 0x611f00]
// 00611e96  dd02                 fld qword ptr [edx]
// 00611e98  83ec08               sub esp, 8
// 00611e9b  dd1c24               fstp qword ptr [esp]
// 00611e9e  e89dffffff           call 0x611e40
// 00611ea3  83c408               add esp, 8
// 00611ea6  5f                   pop edi
// 00611ea7  5e                   pop esi
// 00611ea8  c3                   ret 
// 00611ea9  8a4e07               mov cl, byte ptr [esi + 7]
// 00611eac  b801000000           mov eax, 1
// 00611eb1  d3e0                 shl eax, cl
// 00611eb3  8b0a                 mov ecx, dword ptr [edx]
// 00611eb5  5f                   pop edi
// 00611eb6  83e801               sub eax, 1
// 00611eb9  234108               and eax, dword ptr [ecx + 8]
// 00611ebc  c1e005               shl eax, 5
// 00611ebf  034610               add eax, dword ptr [esi + 0x10]
// 00611ec2  5e                   pop esi
// 00611ec3  c3                   ret 
// 00611ec4  8a4e07               mov cl, byte ptr [esi + 7]
// 00611ec7  b801000000           mov eax, 1
// 00611ecc  d3e0                 shl eax, cl
// 00611ece  5f                   pop edi
// 00611ecf  83e801               sub eax, 1
// 00611ed2  2302                 and eax, dword ptr [edx]
// 00611ed4  c1e005               shl eax, 5
// 00611ed7  034610               add eax, dword ptr [esi + 0x10]
// 00611eda  5e                   pop esi
// 00611edb  c3                   ret 
// 00611edc  8a4e07               mov cl, byte ptr [esi + 7]
// 00611edf  8b02                 mov eax, dword ptr [edx]
// 00611ee1  bf01000000           mov edi, 1
// 00611ee6  d3e7                 shl edi, cl
// 00611ee8  33d2                 xor edx, edx
// 00611eea  83ef01               sub edi, 1
// 00611eed  83cf01               or edi, 1
// 00611ef0  f7f7                 div edi
// 00611ef2  5f                   pop edi
// 00611ef3  8bc2                 mov eax, edx
// 00611ef5  c1e005               shl eax, 5
// 00611ef8  034610               add eax, dword ptr [esi + 0x10]
// 00611efb  5e                   pop esi
// 00611efc  c3                   ret 
// 00611efd  8d4900               lea ecx, [ecx]
// 00611f00  c41e                 les ebx, ptr [esi]
// 00611f02  61                   popal 
// 00611f03  00dc                 add ah, bl
// 00611f05  1e                   push ds
// 00611f06  61                   popal 
// 00611f07  00961e6100a9         add byte ptr [esi - 0x56ff9ee2], dl
// 00611f0d  1e                   push ds
// 00611f0e  61                   popal 
// library lua-5.1/ltable.c (function _mainposition)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
