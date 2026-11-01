// from server: 100% by auto
// roc 2007-03 0050df90  unit: seg_00500000  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050df90
//
// 0050df90  51                   push ecx
// 0050df91  8b442408             mov eax, dword ptr [esp + 8]
// 0050df95  53                   push ebx
// 0050df96  55                   push ebp
// 0050df97  56                   push esi
// 0050df98  57                   push edi
// 0050df99  33f6                 xor esi, esi
// 0050df9b  33ff                 xor edi, edi
// 0050df9d  85c0                 test eax, eax
// 0050df9f  89742410             mov dword ptr [esp + 0x10], esi
// 0050dfa3  7402                 je 0x50dfa7
// 0050dfa5  8b30                 mov esi, dword ptr [eax]
// 0050dfa7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050dfab  85c0                 test eax, eax
// 0050dfad  7402                 je 0x50dfb1
// 0050dfaf  8b38                 mov edi, dword ptr [eax]
// 0050dfb1  8b442420             mov eax, dword ptr [esp + 0x20]
// 0050dfb5  85c0                 test eax, eax
// 0050dfb7  7406                 je 0x50dfbf
// 0050dfb9  8b00                 mov eax, dword ptr [eax]
// 0050dfbb  89442410             mov dword ptr [esp + 0x10], eax
// 0050dfbf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0050dfc3  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 0050dfc9  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 0050dfcf  51                   push ecx
// 0050dfd0  57                   push edi
// 0050dfd1  56                   push esi
// 0050dfd2  e8f9fcffff           call 0x50dcd0
// 0050dfd7  83c40c               add esp, 0xc
// 0050dfda  85ff                 test edi, edi
// 0050dfdc  7423                 je 0x50e001
// 0050dfde  6aff                 push -1
// 0050dfe0  6800400000           push 0x4000
// 0050dfe5  57                   push edi
// 0050dfe6  56                   push esi
// 0050dfe7  e894c7ffff           call 0x50a780
// 0050dfec  55                   push ebp
// 0050dfed  53                   push ebx
// 0050dfee  57                   push edi
// 0050dfef  e83cae0000           call 0x518e30
// 0050dff4  8b542438             mov edx, dword ptr [esp + 0x38]
// 0050dff8  83c41c               add esp, 0x1c
// 0050dffb  c70200000000         mov dword ptr [edx], 0
// 0050e001  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0050e005  85ff                 test edi, edi
// 0050e007  7423                 je 0x50e02c
// 0050e009  6aff                 push -1
// 0050e00b  6800400000           push 0x4000
// 0050e010  57                   push edi
// 0050e011  56                   push esi
// 0050e012  e869c7ffff           call 0x50a780
// 0050e017  55                   push ebp
// 0050e018  53                   push ebx
// 0050e019  57                   push edi
// 0050e01a  e811ae0000           call 0x518e30
// 0050e01f  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0050e023  83c41c               add esp, 0x1c
// 0050e026  c70000000000         mov dword ptr [eax], 0
// 0050e02c  55                   push ebp
// 0050e02d  53                   push ebx
// 0050e02e  56                   push esi
// 0050e02f  e8fcad0000           call 0x518e30
// 0050e034  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0050e038  83c40c               add esp, 0xc
// 0050e03b  5f                   pop edi
// 0050e03c  5e                   pop esi
// 0050e03d  5d                   pop ebp
// 0050e03e  c70100000000         mov dword ptr [ecx], 0
// 0050e044  5b                   pop ebx
// 0050e045  59                   pop ecx
// 0050e046  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
