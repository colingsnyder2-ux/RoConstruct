// from server: 100% by auto
// roc 2007-08 006122c0  unit: seg_00610000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006122c0
//
// 006122c0  53                   push ebx
// 006122c1  55                   push ebp
// 006122c2  56                   push esi
// 006122c3  8bf0                 mov esi, eax
// 006122c5  33ed                 xor ebp, ebp
// 006122c7  3bf5                 cmp esi, ebp
// 006122c9  7519                 jne 0x6122e4
// 006122cb  33db                 xor ebx, ebx
// 006122cd  c1e605               shl esi, 5
// 006122d0  c74710b8327c00       mov dword ptr [edi + 0x10], 0x7c32b8
// 006122d7  037710               add esi, dword ptr [edi + 0x10]
// 006122da  885f07               mov byte ptr [edi + 7], bl
// 006122dd  897714               mov dword ptr [edi + 0x14], esi
// 006122e0  5e                   pop esi
// 006122e1  5d                   pop ebp
// 006122e2  5b                   pop ebx
// 006122e3  c3                   ret 
// 006122e4  83c6ff               add esi, -1
// 006122e7  56                   push esi
// 006122e8  e863c7ffff           call 0x60ea50
// 006122ed  8bd8                 mov ebx, eax
// 006122ef  83c301               add ebx, 1
// 006122f2  83c404               add esp, 4
// 006122f5  83fb1a               cmp ebx, 0x1a
// 006122f8  7e12                 jle 0x61230c
// 006122fa  8b442410             mov eax, dword ptr [esp + 0x10]
// 006122fe  68f0327c00           push 0x7c32f0
// 00612303  50                   push eax
// 00612304  e8f74cfbff           call 0x5c7000
// 00612309  83c408               add esp, 8
// 0061230c  8bcb                 mov ecx, ebx
// 0061230e  be01000000           mov esi, 1
// 00612313  d3e6                 shl esi, cl
// 00612315  8d4e01               lea ecx, [esi + 1]
// 00612318  81f9ffffff07         cmp ecx, 0x7ffffff
// 0061231e  7717                 ja 0x612337
// 00612320  8b442410             mov eax, dword ptr [esp + 0x10]
// 00612324  8bd6                 mov edx, esi
// 00612326  c1e205               shl edx, 5
// 00612329  52                   push edx
// 0061232a  55                   push ebp
// 0061232b  55                   push ebp
// 0061232c  50                   push eax
// 0061232d  e8be160000           call 0x6139f0
// 00612332  83c410               add esp, 0x10
// 00612335  eb0d                 jmp 0x612344
// 00612337  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061233b  51                   push ecx
// 0061233c  e88f160000           call 0x6139d0
// 00612341  83c404               add esp, 4
// 00612344  3bf5                 cmp esi, ebp
// 00612346  894710               mov dword ptr [edi + 0x10], eax
// 00612349  7e1b                 jle 0x612366
// 0061234b  33c9                 xor ecx, ecx
// 0061234d  8bd6                 mov edx, esi
// 0061234f  90                   nop 
// 00612350  8b4710               mov eax, dword ptr [edi + 0x10]
// 00612353  03c1                 add eax, ecx
// 00612355  83c120               add ecx, 0x20
// 00612358  83ea01               sub edx, 1
// 0061235b  89681c               mov dword ptr [eax + 0x1c], ebp
// 0061235e  896818               mov dword ptr [eax + 0x18], ebp
// 00612361  896808               mov dword ptr [eax + 8], ebp
// 00612364  75ea                 jne 0x612350
// 00612366  c1e605               shl esi, 5
// 00612369  037710               add esi, dword ptr [edi + 0x10]
// 0061236c  885f07               mov byte ptr [edi + 7], bl
// 0061236f  897714               mov dword ptr [edi + 0x14], esi
// 00612372  5e                   pop esi
// 00612373  5d                   pop ebp
// 00612374  5b                   pop ebx
// 00612375  c3                   ret 
// library lua-5.1/ltable.c (function _setnodevector)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
