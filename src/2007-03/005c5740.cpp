// from server: 100% by auto
// roc 2007-03 005c5740  unit: seg_005c0000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5740
//
// 005c5740  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005c5743  7c27                 jl 0x5c576c
// 005c5745  85ff                 test edi, edi
// 005c5747  7511                 jne 0x5c575a
// 005c5749  2bc1                 sub eax, ecx
// 005c574b  50                   push eax
// 005c574c  8b4608               mov eax, dword ptr [esi + 8]
// 005c574f  51                   push ecx
// 005c5750  50                   push eax
// 005c5751  e82a39ffff           call 0x5b9080
// 005c5756  83c40c               add esp, 0xc
// 005c5759  c3                   ret 
// 005c575a  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c575d  68689f7b00           push 0x7b9f68
// 005c5762  51                   push ecx
// 005c5763  e8e843ffff           call 0x5b9b50
// 005c5768  83c408               add esp, 8
// 005c576b  c3                   ret 
// 005c576c  53                   push ebx
// 005c576d  8b5cfe14             mov ebx, dword ptr [esi + edi*8 + 0x14]
// 005c5771  83fbff               cmp ebx, -1
// 005c5774  7525                 jne 0x5c579b
// 005c5776  8b5608               mov edx, dword ptr [esi + 8]
// 005c5779  6828a07b00           push 0x7ba028
// 005c577e  52                   push edx
// 005c577f  e8cc43ffff           call 0x5b9b50
// 005c5784  83c408               add esp, 8
// 005c5787  8b54fe10             mov edx, dword ptr [esi + edi*8 + 0x10]
// 005c578b  8b4608               mov eax, dword ptr [esi + 8]
// 005c578e  53                   push ebx
// 005c578f  52                   push edx
// 005c5790  50                   push eax
// 005c5791  e8ea38ffff           call 0x5b9080
// 005c5796  83c40c               add esp, 0xc
// 005c5799  5b                   pop ebx
// 005c579a  c3                   ret 
// 005c579b  83fbfe               cmp ebx, -2
// 005c579e  75e7                 jne 0x5c5787
// 005c57a0  8b44fe10             mov eax, dword ptr [esi + edi*8 + 0x10]
// 005c57a4  2b06                 sub eax, dword ptr [esi]
// 005c57a6  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c57a9  83c001               add eax, 1
// 005c57ac  50                   push eax
// 005c57ad  51                   push ecx
// 005c57ae  e8ad38ffff           call 0x5b9060
// 005c57b3  83c408               add esp, 8
// 005c57b6  5b                   pop ebx
// 005c57b7  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _push_onecapture)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
