// from server: 100% by auto
// roc 2007-03 005fc860  unit: seg_005f0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc860
//
// 005fc860  56                   push esi
// 005fc861  8b742408             mov esi, dword ptr [esp + 8]
// 005fc865  57                   push edi
// 005fc866  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005fc86a  83ffe5               cmp edi, -0x1b
// 005fc86d  7609                 jbe 0x5fc878
// 005fc86f  56                   push esi
// 005fc870  e80b0b0000           call 0x5fd380
// 005fc875  83c404               add esp, 4
// 005fc878  8d4718               lea eax, [edi + 0x18]
// 005fc87b  50                   push eax
// 005fc87c  6a00                 push 0
// 005fc87e  6a00                 push 0
// 005fc880  56                   push esi
// 005fc881  e81a0b0000           call 0x5fd3a0
// 005fc886  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fc889  8a5114               mov dl, byte ptr [ecx + 0x14]
// 005fc88c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005fc890  897810               mov dword ptr [eax + 0x10], edi
// 005fc893  80e203               and dl, 3
// 005fc896  885005               mov byte ptr [eax + 5], dl
// 005fc899  c6400407             mov byte ptr [eax + 4], 7
// 005fc89d  c7400800000000       mov dword ptr [eax + 8], 0
// 005fc8a4  89480c               mov dword ptr [eax + 0xc], ecx
// 005fc8a7  8b5610               mov edx, dword ptr [esi + 0x10]
// 005fc8aa  8b4a70               mov ecx, dword ptr [edx + 0x70]
// 005fc8ad  8b11                 mov edx, dword ptr [ecx]
// 005fc8af  8910                 mov dword ptr [eax], edx
// 005fc8b1  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fc8b4  8b5170               mov edx, dword ptr [ecx + 0x70]
// 005fc8b7  83c410               add esp, 0x10
// 005fc8ba  5f                   pop edi
// 005fc8bb  8902                 mov dword ptr [edx], eax
// 005fc8bd  5e                   pop esi
// 005fc8be  c3                   ret 
// library lua-5.1.1/lstring.c (function _luaS_newudata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstring.c
