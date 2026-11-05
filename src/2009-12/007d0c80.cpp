// from server: 100% by auto
// roc 2009-12 007d0c80  unit: RBX::PartDropTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0c80
//
// 007d0c80  56                   push esi
// 007d0c81  8b742408             mov esi, dword ptr [esp + 8]
// 007d0c85  57                   push edi
// 007d0c86  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d0c8a  83ffe5               cmp edi, -0x1b
// 007d0c8d  7609                 jbe 0x7d0c98
// 007d0c8f  56                   push esi
// 007d0c90  e8fb0a0000           call 0x7d1790
// 007d0c95  83c404               add esp, 4
// 007d0c98  8d4718               lea eax, [edi + 0x18]
// 007d0c9b  50                   push eax
// 007d0c9c  6a00                 push 0
// 007d0c9e  6a00                 push 0
// 007d0ca0  56                   push esi
// 007d0ca1  e80a0b0000           call 0x7d17b0
// 007d0ca6  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d0ca9  8a5114               mov dl, byte ptr [ecx + 0x14]
// 007d0cac  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007d0cb0  897810               mov dword ptr [eax + 0x10], edi
// 007d0cb3  80e203               and dl, 3
// 007d0cb6  885005               mov byte ptr [eax + 5], dl
// 007d0cb9  c6400407             mov byte ptr [eax + 4], 7
// 007d0cbd  c7400800000000       mov dword ptr [eax + 8], 0
// 007d0cc4  89480c               mov dword ptr [eax + 0xc], ecx
// 007d0cc7  8b5610               mov edx, dword ptr [esi + 0x10]
// 007d0cca  8b4a70               mov ecx, dword ptr [edx + 0x70]
// 007d0ccd  8b11                 mov edx, dword ptr [ecx]
// 007d0ccf  8910                 mov dword ptr [eax], edx
// 007d0cd1  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d0cd4  8b5170               mov edx, dword ptr [ecx + 0x70]
// 007d0cd7  83c410               add esp, 0x10
// 007d0cda  5f                   pop edi
// 007d0cdb  8902                 mov dword ptr [edx], eax
// 007d0cdd  5e                   pop esi
// 007d0cde  c3                   ret 
// library lua-5.1/lstring.c (function _luaS_newudata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstring.c
