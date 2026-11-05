// from server: 100% by auto
// roc 2009-12 0079d650  unit: seg_00790000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d650
//
// 0079d650  8b460c               mov eax, dword ptr [esi + 0xc]
// 0079d653  83e801               sub eax, 1
// 0079d656  57                   push edi
// 0079d657  7814                 js 0x79d66d
// 0079d659  8d4cc614             lea ecx, [esi + eax*8 + 0x14]
// 0079d65d  8d4900               lea ecx, [ecx]
// 0079d660  8339ff               cmp dword ptr [ecx], -1
// 0079d663  7419                 je 0x79d67e
// 0079d665  48                   dec eax
// 0079d666  83e908               sub ecx, 8
// 0079d669  85c0                 test eax, eax
// 0079d66b  7df3                 jge 0x79d660
// 0079d66d  8b4608               mov eax, dword ptr [esi + 8]
// 0079d670  68d0b09e00           push 0x9eb0d0
// 0079d675  50                   push eax
// 0079d676  e875c6feff           call 0x789cf0
// 0079d67b  83c408               add esp, 8
// 0079d67e  8b542408             mov edx, dword ptr [esp + 8]
// 0079d682  8bf8                 mov edi, eax
// 0079d684  52                   push edx
// 0079d685  8bcb                 mov ecx, ebx
// 0079d687  2b4cfe10             sub ecx, dword ptr [esi + edi*8 + 0x10]
// 0079d68b  53                   push ebx
// 0079d68c  56                   push esi
// 0079d68d  894cfe14             mov dword ptr [esi + edi*8 + 0x14], ecx
// 0079d691  e8aa000000           call 0x79d740
// 0079d696  83c40c               add esp, 0xc
// 0079d699  85c0                 test eax, eax
// 0079d69b  7508                 jne 0x79d6a5
// 0079d69d  c744fe14ffffffff     mov dword ptr [esi + edi*8 + 0x14], 0xffffffff
// 0079d6a5  5f                   pop edi
// 0079d6a6  c3                   ret 
// library lua-5.1/lstrlib.c (function _end_capture)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
