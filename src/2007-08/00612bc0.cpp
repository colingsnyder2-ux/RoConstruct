// from server: 100% by auto
// roc 2007-08 00612bc0  unit: seg_00610000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612bc0
//
// 00612bc0  83ec10               sub esp, 0x10
// 00612bc3  56                   push esi
// 00612bc4  8b742420             mov esi, dword ptr [esp + 0x20]
// 00612bc8  57                   push edi
// 00612bc9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00612bcd  56                   push esi
// 00612bce  57                   push edi
// 00612bcf  e8fcf8ffff           call 0x6124d0
// 00612bd4  83c408               add esp, 8
// 00612bd7  3de82f7c00           cmp eax, 0x7c2fe8
// 00612bdc  751f                 jne 0x612bfd
// 00612bde  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00612be2  8d442408             lea eax, [esp + 8]
// 00612be6  50                   push eax
// 00612be7  57                   push edi
// 00612be8  51                   push ecx
// 00612be9  89742414             mov dword ptr [esp + 0x14], esi
// 00612bed  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 00612bf5  e8d6feffff           call 0x612ad0
// 00612bfa  83c40c               add esp, 0xc
// 00612bfd  5f                   pop edi
// 00612bfe  5e                   pop esi
// 00612bff  83c410               add esp, 0x10
// 00612c02  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
