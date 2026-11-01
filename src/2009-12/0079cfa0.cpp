// from server: 100% by auto
// roc 2009-12 0079cfa0  unit: seg_00790000  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079cfa0
//
// 0079cfa0  81ec10020000         sub esp, 0x210
// 0079cfa6  53                   push ebx
// 0079cfa7  56                   push esi
// 0079cfa8  57                   push edi
// 0079cfa9  8bbc2420020000       mov edi, dword ptr [esp + 0x220]
// 0079cfb0  8d44240c             lea eax, [esp + 0xc]
// 0079cfb4  50                   push eax
// 0079cfb5  6a01                 push 1
// 0079cfb7  57                   push edi
// 0079cfb8  e8b3d7feff           call 0x78a770
// 0079cfbd  6a02                 push 2
// 0079cfbf  57                   push edi
// 0079cfc0  8bd8                 mov ebx, eax
// 0079cfc2  e8e9d8feff           call 0x78a8b0
// 0079cfc7  8d4c2424             lea ecx, [esp + 0x24]
// 0079cfcb  51                   push ecx
// 0079cfcc  57                   push edi
// 0079cfcd  8bf0                 mov esi, eax
// 0079cfcf  e85cd1feff           call 0x78a130
// 0079cfd4  83c41c               add esp, 0x1c
// 0079cfd7  85f6                 test esi, esi
// 0079cfd9  7e1d                 jle 0x79cff8
// 0079cfdb  eb03                 jmp 0x79cfe0
// 0079cfdd  8d4900               lea ecx, [ecx]
// 0079cfe0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079cfe4  52                   push edx
// 0079cfe5  8d442414             lea eax, [esp + 0x14]
// 0079cfe9  53                   push ebx
// 0079cfea  50                   push eax
// 0079cfeb  4e                   dec esi
// 0079cfec  e81fd0feff           call 0x78a010
// 0079cff1  83c40c               add esp, 0xc
// 0079cff4  85f6                 test esi, esi
// 0079cff6  7fe8                 jg 0x79cfe0
// 0079cff8  8d4c2410             lea ecx, [esp + 0x10]
// 0079cffc  51                   push ecx
// 0079cffd  e86ed0feff           call 0x78a070
// 0079d002  83c404               add esp, 4
// 0079d005  5f                   pop edi
// 0079d006  5e                   pop esi
// 0079d007  b801000000           mov eax, 1
// 0079d00c  5b                   pop ebx
// 0079d00d  81c410020000         add esp, 0x210
// 0079d013  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_rep)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
