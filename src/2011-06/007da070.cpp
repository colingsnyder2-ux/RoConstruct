// from server: 100% by auto
// roc 2011-06 007da070  unit: seg_007d0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007da070
//
// 007da070  83ec10               sub esp, 0x10
// 007da073  56                   push esi
// 007da074  8b742420             mov esi, dword ptr [esp + 0x20]
// 007da078  57                   push edi
// 007da079  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007da07d  56                   push esi
// 007da07e  57                   push edi
// 007da07f  e8ecf8ffff           call 0x7d9970
// 007da084  83c408               add esp, 8
// 007da087  3db875ab00           cmp eax, 0xab75b8
// 007da08c  751f                 jne 0x7da0ad
// 007da08e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007da092  8d442408             lea eax, [esp + 8]
// 007da096  50                   push eax
// 007da097  57                   push edi
// 007da098  51                   push ecx
// 007da099  89742414             mov dword ptr [esp + 0x14], esi
// 007da09d  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 007da0a5  e8d6feffff           call 0x7d9f80
// 007da0aa  83c40c               add esp, 0xc
// 007da0ad  5f                   pop edi
// 007da0ae  5e                   pop esi
// 007da0af  83c410               add esp, 0x10
// 007da0b2  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
