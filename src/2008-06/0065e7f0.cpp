// from server: 100% by auto
// roc 2008-06 0065e7f0  unit: seg_00650000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e7f0
//
// 0065e7f0  8d4f01               lea ecx, [edi + 1]
// 0065e7f3  81f9ffffff0f         cmp ecx, 0xfffffff
// 0065e7f9  771c                 ja 0x65e817
// 0065e7fb  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0065e7fe  8bd7                 mov edx, edi
// 0065e800  c1e204               shl edx, 4
// 0065e803  52                   push edx
// 0065e804  8b560c               mov edx, dword ptr [esi + 0xc]
// 0065e807  c1e104               shl ecx, 4
// 0065e80a  51                   push ecx
// 0065e80b  52                   push edx
// 0065e80c  50                   push eax
// 0065e80d  e8de1e0000           call 0x6606f0
// 0065e812  83c410               add esp, 0x10
// 0065e815  eb09                 jmp 0x65e820
// 0065e817  50                   push eax
// 0065e818  e8b31e0000           call 0x6606d0
// 0065e81d  83c404               add esp, 4
// 0065e820  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0065e823  3bd7                 cmp edx, edi
// 0065e825  89460c               mov dword ptr [esi + 0xc], eax
// 0065e828  7d1c                 jge 0x65e846
// 0065e82a  8bc2                 mov eax, edx
// 0065e82c  8bcf                 mov ecx, edi
// 0065e82e  c1e004               shl eax, 4
// 0065e831  2bca                 sub ecx, edx
// 0065e833  33d2                 xor edx, edx
// 0065e835  53                   push ebx
// 0065e836  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0065e839  89540308             mov dword ptr [ebx + eax + 8], edx
// 0065e83d  83c010               add eax, 0x10
// 0065e840  83e901               sub ecx, 1
// 0065e843  75f1                 jne 0x65e836
// 0065e845  5b                   pop ebx
// 0065e846  897e1c               mov dword ptr [esi + 0x1c], edi
// 0065e849  c3                   ret 
// library lua-5.1/ltable.c (function _setarrayvector)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
