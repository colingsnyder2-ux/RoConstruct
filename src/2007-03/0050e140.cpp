// from server: 100% by auto
// roc 2007-03 0050e140  unit: seg_00500000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e140
//
// 0050e140  8b542404             mov edx, dword ptr [esp + 4]
// 0050e144  807a0910             cmp byte ptr [edx + 9], 0x10
// 0050e148  7529                 jne 0x50e173
// 0050e14a  0fb64a0a             movzx ecx, byte ptr [edx + 0xa]
// 0050e14e  0faf0a               imul ecx, dword ptr [edx]
// 0050e151  85c9                 test ecx, ecx
// 0050e153  8b442408             mov eax, dword ptr [esp + 8]
// 0050e157  761a                 jbe 0x50e173
// 0050e159  56                   push esi
// 0050e15a  8bf1                 mov esi, ecx
// 0050e15c  8d642400             lea esp, [esp]
// 0050e160  8a08                 mov cl, byte ptr [eax]
// 0050e162  8a5001               mov dl, byte ptr [eax + 1]
// 0050e165  8810                 mov byte ptr [eax], dl
// 0050e167  884801               mov byte ptr [eax + 1], cl
// 0050e16a  83c002               add eax, 2
// 0050e16d  83ee01               sub esi, 1
// 0050e170  75ee                 jne 0x50e160
// 0050e172  5e                   pop esi
// 0050e173  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_do_swap)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
