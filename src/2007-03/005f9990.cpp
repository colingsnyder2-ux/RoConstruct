// from server: 100% by auto
// roc 2007-03 005f9990  unit: seg_005f0000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9990
//
// 005f9990  53                   push ebx
// 005f9991  55                   push ebp
// 005f9992  56                   push esi
// 005f9993  bebc000000           mov esi, 0xbc
// 005f9998  bb30027c00           mov ebx, 0x7c0230
// 005f999d  57                   push edi
// 005f999e  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005f99a2  2bde                 sub ebx, esi
// 005f99a4  8b0c33               mov ecx, dword ptr [ebx + esi]
// 005f99a7  8bc1                 mov eax, ecx
// 005f99a9  8d6801               lea ebp, [eax + 1]
// 005f99ac  8d642400             lea esp, [esp]
// 005f99b0  8a10                 mov dl, byte ptr [eax]
// 005f99b2  83c001               add eax, 1
// 005f99b5  84d2                 test dl, dl
// 005f99b7  75f7                 jne 0x5f99b0
// 005f99b9  2bc5                 sub eax, ebp
// 005f99bb  50                   push eax
// 005f99bc  51                   push ecx
// 005f99bd  57                   push edi
// 005f99be  e85d2d0000           call 0x5fc720
// 005f99c3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005f99c6  89040e               mov dword ptr [esi + ecx], eax
// 005f99c9  8b5710               mov edx, dword ptr [edi + 0x10]
// 005f99cc  8b0432               mov eax, dword ptr [edx + esi]
// 005f99cf  80480520             or byte ptr [eax + 5], 0x20
// 005f99d3  83c604               add esi, 4
// 005f99d6  83c40c               add esp, 0xc
// 005f99d9  81fe00010000         cmp esi, 0x100
// 005f99df  7cc3                 jl 0x5f99a4
// 005f99e1  5f                   pop edi
// 005f99e2  5e                   pop esi
// 005f99e3  5d                   pop ebp
// 005f99e4  5b                   pop ebx
// 005f99e5  c3                   ret 
// library lua-5.1.1/ltm.c (function _luaT_init)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltm.c
