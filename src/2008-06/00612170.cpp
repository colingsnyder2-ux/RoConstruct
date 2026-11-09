// from server: 100% by auto
// roc 2008-06 00612170  unit: seg_00610000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612170
//
// 00612170  56                   push esi
// 00612171  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00612175  57                   push edi
// 00612176  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0061217a  8bc6                 mov eax, esi
// 0061217c  8bcf                 mov ecx, edi
// 0061217e  e80df9ffff           call 0x611a90
// 00612183  8b4808               mov ecx, dword ptr [eax + 8]
// 00612186  83c1fe               add ecx, -2
// 00612189  83f906               cmp ecx, 6
// 0061218c  772a                 ja 0x6121b8
// 0061218e  ff248dc0216100       jmp dword ptr [ecx*4 + 0x6121c0]
// 00612195  8b00                 mov eax, dword ptr [eax]
// 00612197  5f                   pop edi
// 00612198  5e                   pop esi
// 00612199  c3                   ret 
// 0061219a  8bc6                 mov eax, esi
// 0061219c  8bcf                 mov ecx, edi
// 0061219e  e8edf8ffff           call 0x611a90
// 006121a3  8b4808               mov ecx, dword ptr [eax + 8]
// 006121a6  83e902               sub ecx, 2
// 006121a9  74ea                 je 0x612195
// 006121ab  83e905               sub ecx, 5
// 006121ae  7508                 jne 0x6121b8
// 006121b0  8b00                 mov eax, dword ptr [eax]
// 006121b2  5f                   pop edi
// 006121b3  83c018               add eax, 0x18
// 006121b6  5e                   pop esi
// 006121b7  c3                   ret 
// 006121b8  5f                   pop edi
// 006121b9  33c0                 xor eax, eax
// 006121bb  5e                   pop esi
// 006121bc  c3                   ret 
// 006121bd  8d4900               lea ecx, [ecx]
// 006121c0  9a216100b82161       lcall 0x6121, 0xb8006121
// 006121c7  00b821610095         add byte ptr [eax - 0x6aff9edf], bh
// 006121cd  216100               and dword ptr [ecx], esp
// 006121d0  95                   xchg ebp, eax
// 006121d1  216100               and dword ptr [ecx], esp
// 006121d4  9a216100952161       lcall 0x6121, 0x95006121
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
