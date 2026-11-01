// from server: 100% by auto
// roc 2007-03 005fbc70  unit: seg_005f0000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbc70
//
// 005fbc70  53                   push ebx
// 005fbc71  55                   push ebp
// 005fbc72  56                   push esi
// 005fbc73  8bf0                 mov esi, eax
// 005fbc75  33ed                 xor ebp, ebp
// 005fbc77  3bf5                 cmp esi, ebp
// 005fbc79  7519                 jne 0x5fbc94
// 005fbc7b  33db                 xor ebx, ebx
// 005fbc7d  c1e605               shl esi, 5
// 005fbc80  c7471070037c00       mov dword ptr [edi + 0x10], 0x7c0370
// 005fbc87  037710               add esi, dword ptr [edi + 0x10]
// 005fbc8a  885f07               mov byte ptr [edi + 7], bl
// 005fbc8d  897714               mov dword ptr [edi + 0x14], esi
// 005fbc90  5e                   pop esi
// 005fbc91  5d                   pop ebp
// 005fbc92  5b                   pop ebx
// 005fbc93  c3                   ret 
// 005fbc94  83c6ff               add esi, -1
// 005fbc97  56                   push esi
// 005fbc98  e863c7ffff           call 0x5f8400
// 005fbc9d  8bd8                 mov ebx, eax
// 005fbc9f  83c301               add ebx, 1
// 005fbca2  83c404               add esp, 4
// 005fbca5  83fb1a               cmp ebx, 0x1a
// 005fbca8  7e12                 jle 0x5fbcbc
// 005fbcaa  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbcae  68a8037c00           push 0x7c03a8
// 005fbcb3  50                   push eax
// 005fbcb4  e8f773fcff           call 0x5c30b0
// 005fbcb9  83c408               add esp, 8
// 005fbcbc  8bcb                 mov ecx, ebx
// 005fbcbe  be01000000           mov esi, 1
// 005fbcc3  d3e6                 shl esi, cl
// 005fbcc5  8d4e01               lea ecx, [esi + 1]
// 005fbcc8  81f9ffffff07         cmp ecx, 0x7ffffff
// 005fbcce  7717                 ja 0x5fbce7
// 005fbcd0  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbcd4  8bd6                 mov edx, esi
// 005fbcd6  c1e205               shl edx, 5
// 005fbcd9  52                   push edx
// 005fbcda  55                   push ebp
// 005fbcdb  55                   push ebp
// 005fbcdc  50                   push eax
// 005fbcdd  e8be160000           call 0x5fd3a0
// 005fbce2  83c410               add esp, 0x10
// 005fbce5  eb0d                 jmp 0x5fbcf4
// 005fbce7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005fbceb  51                   push ecx
// 005fbcec  e88f160000           call 0x5fd380
// 005fbcf1  83c404               add esp, 4
// 005fbcf4  3bf5                 cmp esi, ebp
// 005fbcf6  894710               mov dword ptr [edi + 0x10], eax
// 005fbcf9  7e1b                 jle 0x5fbd16
// 005fbcfb  33c9                 xor ecx, ecx
// 005fbcfd  8bd6                 mov edx, esi
// 005fbcff  90                   nop 
// 005fbd00  8b4710               mov eax, dword ptr [edi + 0x10]
// 005fbd03  03c1                 add eax, ecx
// 005fbd05  83c120               add ecx, 0x20
// 005fbd08  83ea01               sub edx, 1
// 005fbd0b  89681c               mov dword ptr [eax + 0x1c], ebp
// 005fbd0e  896818               mov dword ptr [eax + 0x18], ebp
// 005fbd11  896808               mov dword ptr [eax + 8], ebp
// 005fbd14  75ea                 jne 0x5fbd00
// 005fbd16  c1e605               shl esi, 5
// 005fbd19  037710               add esi, dword ptr [edi + 0x10]
// 005fbd1c  885f07               mov byte ptr [edi + 7], bl
// 005fbd1f  897714               mov dword ptr [edi + 0x14], esi
// 005fbd22  5e                   pop esi
// 005fbd23  5d                   pop ebp
// 005fbd24  5b                   pop ebx
// 005fbd25  c3                   ret 
// library lua-5.1.1/ltable.c (function _setnodevector)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
