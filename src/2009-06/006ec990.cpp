// from server: 100% by auto
// roc 2009-06 006ec990  unit: RBX::PartDropTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ec990
//
// 006ec990  83ec10               sub esp, 0x10
// 006ec993  56                   push esi
// 006ec994  8b742420             mov esi, dword ptr [esp + 0x20]
// 006ec998  57                   push edi
// 006ec999  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ec99d  56                   push esi
// 006ec99e  57                   push edi
// 006ec99f  e8fcf8ffff           call 0x6ec2a0
// 006ec9a4  83c408               add esp, 8
// 006ec9a7  3d78c38e00           cmp eax, 0x8ec378
// 006ec9ac  751f                 jne 0x6ec9cd
// 006ec9ae  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006ec9b2  8d442408             lea eax, [esp + 8]
// 006ec9b6  50                   push eax
// 006ec9b7  57                   push edi
// 006ec9b8  51                   push ecx
// 006ec9b9  89742414             mov dword ptr [esp + 0x14], esi
// 006ec9bd  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 006ec9c5  e8d6feffff           call 0x6ec8a0
// 006ec9ca  83c40c               add esp, 0xc
// 006ec9cd  5f                   pop edi
// 006ec9ce  5e                   pop esi
// 006ec9cf  83c410               add esp, 0x10
// 006ec9d2  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
