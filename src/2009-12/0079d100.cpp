// from server: 100% by auto
// roc 2009-12 0079d100  unit: seg_00790000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d100
//
// 0079d100  81ec0c020000         sub esp, 0x20c
// 0079d106  55                   push ebp
// 0079d107  56                   push esi
// 0079d108  57                   push edi
// 0079d109  8bbc241c020000       mov edi, dword ptr [esp + 0x21c]
// 0079d110  57                   push edi
// 0079d111  e88ab6feff           call 0x7887a0
// 0079d116  8be8                 mov ebp, eax
// 0079d118  8d442410             lea eax, [esp + 0x10]
// 0079d11c  50                   push eax
// 0079d11d  57                   push edi
// 0079d11e  e80dd0feff           call 0x78a130
// 0079d123  be01000000           mov esi, 1
// 0079d128  83c40c               add esp, 0xc
// 0079d12b  3bee                 cmp ebp, esi
// 0079d12d  7c4d                 jl 0x79d17c
// 0079d12f  53                   push ebx
// 0079d130  56                   push esi
// 0079d131  57                   push edi
// 0079d132  e879d7feff           call 0x78a8b0
// 0079d137  8bd8                 mov ebx, eax
// 0079d139  0fb6cb               movzx ecx, bl
// 0079d13c  83c408               add esp, 8
// 0079d13f  3bcb                 cmp ecx, ebx
// 0079d141  740f                 je 0x79d152
// 0079d143  6888b09e00           push 0x9eb088
// 0079d148  56                   push esi
// 0079d149  57                   push edi
// 0079d14a  e831d4feff           call 0x78a580
// 0079d14f  83c40c               add esp, 0xc
// 0079d152  8d94241c020000       lea edx, [esp + 0x21c]
// 0079d159  39542410             cmp dword ptr [esp + 0x10], edx
// 0079d15d  720d                 jb 0x79d16c
// 0079d15f  8d442410             lea eax, [esp + 0x10]
// 0079d163  50                   push eax
// 0079d164  e867cefeff           call 0x789fd0
// 0079d169  83c404               add esp, 4
// 0079d16c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079d170  8819                 mov byte ptr [ecx], bl
// 0079d172  ff442410             inc dword ptr [esp + 0x10]
// 0079d176  46                   inc esi
// 0079d177  3bf5                 cmp esi, ebp
// 0079d179  7eb5                 jle 0x79d130
// 0079d17b  5b                   pop ebx
// 0079d17c  8d54240c             lea edx, [esp + 0xc]
// 0079d180  52                   push edx
// 0079d181  e8eacefeff           call 0x78a070
// 0079d186  83c404               add esp, 4
// 0079d189  5f                   pop edi
// 0079d18a  5e                   pop esi
// 0079d18b  b801000000           mov eax, 1
// 0079d190  5d                   pop ebp
// 0079d191  81c40c020000         add esp, 0x20c
// 0079d197  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_char)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
