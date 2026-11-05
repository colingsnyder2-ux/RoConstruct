// from server: 100% by auto
// roc 2009-06 006b8de0  unit: RBX::UniversalTool  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8de0
//
// 006b8de0  8b442408             mov eax, dword ptr [esp + 8]
// 006b8de4  56                   push esi
// 006b8de5  8b742408             mov esi, dword ptr [esp + 8]
// 006b8de9  8bce                 mov ecx, esi
// 006b8deb  e8e0fdffff           call 0x6b8bd0
// 006b8df0  83c010               add eax, 0x10
// 006b8df3  3b4608               cmp eax, dword ptr [esi + 8]
// 006b8df6  7323                 jae 0x6b8e1b
// 006b8df8  8d48f0               lea ecx, [eax - 0x10]
// 006b8dfb  eb03                 jmp 0x6b8e00
// 006b8dfd  8d4900               lea ecx, [ecx]
// 006b8e00  8b10                 mov edx, dword ptr [eax]
// 006b8e02  8911                 mov dword ptr [ecx], edx
// 006b8e04  8b5004               mov edx, dword ptr [eax + 4]
// 006b8e07  895104               mov dword ptr [ecx + 4], edx
// 006b8e0a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 006b8e0d  895108               mov dword ptr [ecx + 8], edx
// 006b8e10  83c010               add eax, 0x10
// 006b8e13  83c110               add ecx, 0x10
// 006b8e16  3b4608               cmp eax, dword ptr [esi + 8]
// 006b8e19  72e5                 jb 0x6b8e00
// 006b8e1b  834608f0             add dword ptr [esi + 8], -0x10
// 006b8e1f  5e                   pop esi
// 006b8e20  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
