// from server: 100% by auto
// roc 2007-08 00612260  unit: seg_00610000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612260
//
// 00612260  8d4f01               lea ecx, [edi + 1]
// 00612263  81f9ffffff0f         cmp ecx, 0xfffffff
// 00612269  771c                 ja 0x612287
// 0061226b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0061226e  8bd7                 mov edx, edi
// 00612270  c1e204               shl edx, 4
// 00612273  52                   push edx
// 00612274  8b560c               mov edx, dword ptr [esi + 0xc]
// 00612277  c1e104               shl ecx, 4
// 0061227a  51                   push ecx
// 0061227b  52                   push edx
// 0061227c  50                   push eax
// 0061227d  e86e170000           call 0x6139f0
// 00612282  83c410               add esp, 0x10
// 00612285  eb09                 jmp 0x612290
// 00612287  50                   push eax
// 00612288  e843170000           call 0x6139d0
// 0061228d  83c404               add esp, 4
// 00612290  8b561c               mov edx, dword ptr [esi + 0x1c]
// 00612293  3bd7                 cmp edx, edi
// 00612295  89460c               mov dword ptr [esi + 0xc], eax
// 00612298  7d1c                 jge 0x6122b6
// 0061229a  8bc2                 mov eax, edx
// 0061229c  8bcf                 mov ecx, edi
// 0061229e  c1e004               shl eax, 4
// 006122a1  2bca                 sub ecx, edx
// 006122a3  33d2                 xor edx, edx
// 006122a5  53                   push ebx
// 006122a6  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006122a9  89540308             mov dword ptr [ebx + eax + 8], edx
// 006122ad  83c010               add eax, 0x10
// 006122b0  83e901               sub ecx, 1
// 006122b3  75f1                 jne 0x6122a6
// 006122b5  5b                   pop ebx
// 006122b6  897e1c               mov dword ptr [esi + 0x1c], edi
// 006122b9  c3                   ret 
// library lua-5.1/ltable.c (function _setarrayvector)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
