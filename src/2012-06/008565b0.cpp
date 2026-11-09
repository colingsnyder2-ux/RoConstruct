// roc 2012-06 008565b0  unit: lua_exception  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008565b0
//
// 008565b0  81ec10020000         sub esp, 0x210
// 008565b6  53                   push ebx
// 008565b7  56                   push esi
// 008565b8  57                   push edi
// 008565b9  8bbc2420020000       mov edi, dword ptr [esp + 0x220]
// 008565c0  8d44240c             lea eax, [esp + 0xc]
// 008565c4  50                   push eax
// 008565c5  6a01                 push 1
// 008565c7  57                   push edi
// 008565c8  e853d3fdff           call 0x833920
// 008565cd  6a02                 push 2
// 008565cf  57                   push edi
// 008565d0  8bd8                 mov ebx, eax
// 008565d2  e889d4fdff           call 0x833a60
// 008565d7  8d4c2424             lea ecx, [esp + 0x24]
// 008565db  51                   push ecx
// 008565dc  57                   push edi
// 008565dd  8bf0                 mov esi, eax
// 008565df  e8fcccfdff           call 0x8332e0
// 008565e4  83c41c               add esp, 0x1c
// 008565e7  85f6                 test esi, esi
// 008565e9  7e1d                 jle 0x856608
// 008565eb  eb03                 jmp 0x8565f0
// 008565ed  8d4900               lea ecx, [ecx]
// 008565f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008565f4  52                   push edx
// 008565f5  8d442414             lea eax, [esp + 0x14]
// 008565f9  53                   push ebx
// 008565fa  50                   push eax
// 008565fb  4e                   dec esi
// 008565fc  e8bfcbfdff           call 0x8331c0
// 00856601  83c40c               add esp, 0xc
// 00856604  85f6                 test esi, esi
// 00856606  7fe8                 jg 0x8565f0
// 00856608  8d4c2410             lea ecx, [esp + 0x10]
// 0085660c  51                   push ecx
// 0085660d  e80eccfdff           call 0x833220
// 00856612  83c404               add esp, 4
// 00856615  5f                   pop edi
// 00856616  5e                   pop esi
// 00856617  b801000000           mov eax, 1
// 0085661c  5b                   pop ebx
// 0085661d  81c410020000         add esp, 0x210
// 00856623  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_rep)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
