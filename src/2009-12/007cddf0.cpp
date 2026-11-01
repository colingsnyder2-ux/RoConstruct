// from server: 100% by auto
// roc 2009-12 007cddf0  unit: RBX::PartDropTool  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cddf0
//
// 007cddf0  53                   push ebx
// 007cddf1  55                   push ebp
// 007cddf2  56                   push esi
// 007cddf3  bebc000000           mov esi, 0xbc
// 007cddf8  bbd0eb9e00           mov ebx, 0x9eebd0
// 007cddfd  57                   push edi
// 007cddfe  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007cde02  2bde                 sub ebx, esi
// 007cde04  8b0c33               mov ecx, dword ptr [ebx + esi]
// 007cde07  8bc1                 mov eax, ecx
// 007cde09  8d6801               lea ebp, [eax + 1]
// 007cde0c  8d642400             lea esp, [esp]
// 007cde10  8a10                 mov dl, byte ptr [eax]
// 007cde12  40                   inc eax
// 007cde13  84d2                 test dl, dl
// 007cde15  75f9                 jne 0x7cde10
// 007cde17  2bc5                 sub eax, ebp
// 007cde19  50                   push eax
// 007cde1a  51                   push ecx
// 007cde1b  57                   push edi
// 007cde1c  e86f2d0000           call 0x7d0b90
// 007cde21  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007cde24  89040e               mov dword ptr [esi + ecx], eax
// 007cde27  8b5710               mov edx, dword ptr [edi + 0x10]
// 007cde2a  8b0432               mov eax, dword ptr [edx + esi]
// 007cde2d  80480520             or byte ptr [eax + 5], 0x20
// 007cde31  83c604               add esi, 4
// 007cde34  83c40c               add esp, 0xc
// 007cde37  81fe00010000         cmp esi, 0x100
// 007cde3d  7cc5                 jl 0x7cde04
// 007cde3f  5f                   pop edi
// 007cde40  5e                   pop esi
// 007cde41  5d                   pop ebp
// 007cde42  5b                   pop ebx
// 007cde43  c3                   ret 
// library lua-5.1/ltm.c (function _luaT_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltm.c
