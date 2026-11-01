// from server: 100% by auto
// roc 2007-03 005fbc10  unit: seg_005f0000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbc10
//
// 005fbc10  8d4f01               lea ecx, [edi + 1]
// 005fbc13  81f9ffffff0f         cmp ecx, 0xfffffff
// 005fbc19  771c                 ja 0x5fbc37
// 005fbc1b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005fbc1e  8bd7                 mov edx, edi
// 005fbc20  c1e204               shl edx, 4
// 005fbc23  52                   push edx
// 005fbc24  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fbc27  c1e104               shl ecx, 4
// 005fbc2a  51                   push ecx
// 005fbc2b  52                   push edx
// 005fbc2c  50                   push eax
// 005fbc2d  e86e170000           call 0x5fd3a0
// 005fbc32  83c410               add esp, 0x10
// 005fbc35  eb09                 jmp 0x5fbc40
// 005fbc37  50                   push eax
// 005fbc38  e843170000           call 0x5fd380
// 005fbc3d  83c404               add esp, 4
// 005fbc40  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005fbc43  3bd7                 cmp edx, edi
// 005fbc45  89460c               mov dword ptr [esi + 0xc], eax
// 005fbc48  7d1c                 jge 0x5fbc66
// 005fbc4a  8bc2                 mov eax, edx
// 005fbc4c  8bcf                 mov ecx, edi
// 005fbc4e  c1e004               shl eax, 4
// 005fbc51  2bca                 sub ecx, edx
// 005fbc53  33d2                 xor edx, edx
// 005fbc55  53                   push ebx
// 005fbc56  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005fbc59  89540308             mov dword ptr [ebx + eax + 8], edx
// 005fbc5d  83c010               add eax, 0x10
// 005fbc60  83e901               sub ecx, 1
// 005fbc63  75f1                 jne 0x5fbc56
// 005fbc65  5b                   pop ebx
// 005fbc66  897e1c               mov dword ptr [esi + 0x1c], edi
// 005fbc69  c3                   ret 
// library lua-5.1.1/ltable.c (function _setarrayvector)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
