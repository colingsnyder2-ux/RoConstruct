// from server: 100% by auto
// roc 2009-12 007d09e0  unit: RBX::PartDropTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d09e0
//
// 007d09e0  83ec10               sub esp, 0x10
// 007d09e3  56                   push esi
// 007d09e4  8b742420             mov esi, dword ptr [esp + 0x20]
// 007d09e8  57                   push edi
// 007d09e9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007d09ed  56                   push esi
// 007d09ee  57                   push edi
// 007d09ef  e8fcf8ffff           call 0x7d02f0
// 007d09f4  83c408               add esp, 8
// 007d09f7  3d28aa9e00           cmp eax, 0x9eaa28
// 007d09fc  751f                 jne 0x7d0a1d
// 007d09fe  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d0a02  8d442408             lea eax, [esp + 8]
// 007d0a06  50                   push eax
// 007d0a07  57                   push edi
// 007d0a08  51                   push ecx
// 007d0a09  89742414             mov dword ptr [esp + 0x14], esi
// 007d0a0d  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 007d0a15  e8d6feffff           call 0x7d08f0
// 007d0a1a  83c40c               add esp, 0xc
// 007d0a1d  5f                   pop edi
// 007d0a1e  5e                   pop esi
// 007d0a1f  83c410               add esp, 0x10
// 007d0a22  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
