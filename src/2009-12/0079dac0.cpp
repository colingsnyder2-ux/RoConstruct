// from server: 100% by auto
// roc 2009-12 0079dac0  unit: seg_00790000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079dac0
//
// 0079dac0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0079dac3  7c27                 jl 0x79daec
// 0079dac5  85ff                 test edi, edi
// 0079dac7  7511                 jne 0x79dada
// 0079dac9  2bc1                 sub eax, ecx
// 0079dacb  50                   push eax
// 0079dacc  8b4608               mov eax, dword ptr [esi + 8]
// 0079dacf  51                   push ecx
// 0079dad0  50                   push eax
// 0079dad1  e8cab2feff           call 0x788da0
// 0079dad6  83c40c               add esp, 0xc
// 0079dad9  c3                   ret 
// 0079dada  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079dadd  68b8b09e00           push 0x9eb0b8
// 0079dae2  51                   push ecx
// 0079dae3  e808c2feff           call 0x789cf0
// 0079dae8  83c408               add esp, 8
// 0079daeb  c3                   ret 
// 0079daec  53                   push ebx
// 0079daed  8b5cfe14             mov ebx, dword ptr [esi + edi*8 + 0x14]
// 0079daf1  83fbff               cmp ebx, -1
// 0079daf4  7525                 jne 0x79db1b
// 0079daf6  8b5608               mov edx, dword ptr [esi + 8]
// 0079daf9  6878b19e00           push 0x9eb178
// 0079dafe  52                   push edx
// 0079daff  e8ecc1feff           call 0x789cf0
// 0079db04  83c408               add esp, 8
// 0079db07  8b54fe10             mov edx, dword ptr [esi + edi*8 + 0x10]
// 0079db0b  8b4608               mov eax, dword ptr [esi + 8]
// 0079db0e  53                   push ebx
// 0079db0f  52                   push edx
// 0079db10  50                   push eax
// 0079db11  e88ab2feff           call 0x788da0
// 0079db16  83c40c               add esp, 0xc
// 0079db19  5b                   pop ebx
// 0079db1a  c3                   ret 
// 0079db1b  83fbfe               cmp ebx, -2
// 0079db1e  75e7                 jne 0x79db07
// 0079db20  8b44fe10             mov eax, dword ptr [esi + edi*8 + 0x10]
// 0079db24  2b06                 sub eax, dword ptr [esi]
// 0079db26  8b4e08               mov ecx, dword ptr [esi + 8]
// 0079db29  40                   inc eax
// 0079db2a  50                   push eax
// 0079db2b  51                   push ecx
// 0079db2c  e84fb2feff           call 0x788d80
// 0079db31  83c408               add esp, 8
// 0079db34  5b                   pop ebx
// 0079db35  c3                   ret 
// library lua-5.1/lstrlib.c (function _push_onecapture)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
