// from server: 100% by auto
// roc 2007-03 005fbac0  unit: seg_005f0000  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbac0
//
// 005fbac0  51                   push ecx
// 005fbac1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fbac5  53                   push ebx
// 005fbac6  55                   push ebp
// 005fbac7  56                   push esi
// 005fbac8  57                   push edi
// 005fbac9  33ff                 xor edi, edi
// 005fbacb  bd01000000           mov ebp, 1
// 005fbad0  897c2410             mov dword ptr [esp + 0x10], edi
// 005fbad4  8bd5                 mov edx, ebp
// 005fbad6  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fbada  8b761c               mov esi, dword ptr [esi + 0x1c]
// 005fbadd  33db                 xor ebx, ebx
// 005fbadf  3bd6                 cmp edx, esi
// 005fbae1  8bca                 mov ecx, edx
// 005fbae3  7e08                 jle 0x5fbaed
// 005fbae5  8bce                 mov ecx, esi
// 005fbae7  3be9                 cmp ebp, ecx
// 005fbae9  7f42                 jg 0x5fbb2d
// 005fbaeb  eb04                 jmp 0x5fbaf1
// 005fbaed  3bea                 cmp ebp, edx
// 005fbaef  7f2b                 jg 0x5fbb1c
// 005fbaf1  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fbaf5  8b760c               mov esi, dword ptr [esi + 0xc]
// 005fbaf8  8bc5                 mov eax, ebp
// 005fbafa  2bcd                 sub ecx, ebp
// 005fbafc  c1e004               shl eax, 4
// 005fbaff  83c101               add ecx, 1
// 005fbb02  8d7430f8             lea esi, [eax + esi - 8]
// 005fbb06  03e9                 add ebp, ecx
// 005fbb08  833e00               cmp dword ptr [esi], 0
// 005fbb0b  7403                 je 0x5fbb10
// 005fbb0d  83c301               add ebx, 1
// 005fbb10  83c610               add esi, 0x10
// 005fbb13  83e901               sub ecx, 1
// 005fbb16  75f0                 jne 0x5fbb08
// 005fbb18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005fbb1c  011cb8               add dword ptr [eax + edi*4], ebx
// 005fbb1f  015c2410             add dword ptr [esp + 0x10], ebx
// 005fbb23  83c701               add edi, 1
// 005fbb26  03d2                 add edx, edx
// 005fbb28  83ff1a               cmp edi, 0x1a
// 005fbb2b  7ea9                 jle 0x5fbad6
// 005fbb2d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbb31  5f                   pop edi
// 005fbb32  5e                   pop esi
// 005fbb33  5d                   pop ebp
// 005fbb34  5b                   pop ebx
// 005fbb35  59                   pop ecx
// 005fbb36  c3                   ret 
// library lua-5.1.1/ltable.c (function _numusearray)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
