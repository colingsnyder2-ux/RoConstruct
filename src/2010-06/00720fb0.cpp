// from server: 100% by auto
// roc 2010-06 00720fb0  unit: RBX::UniversalTool  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720fb0
//
// 00720fb0  8b442408             mov eax, dword ptr [esp + 8]
// 00720fb4  56                   push esi
// 00720fb5  8b742408             mov esi, dword ptr [esp + 8]
// 00720fb9  8bce                 mov ecx, esi
// 00720fbb  e8e0fdffff           call 0x720da0
// 00720fc0  83c010               add eax, 0x10
// 00720fc3  3b4608               cmp eax, dword ptr [esi + 8]
// 00720fc6  7323                 jae 0x720feb
// 00720fc8  8d48f0               lea ecx, [eax - 0x10]
// 00720fcb  eb03                 jmp 0x720fd0
// 00720fcd  8d4900               lea ecx, [ecx]
// 00720fd0  8b10                 mov edx, dword ptr [eax]
// 00720fd2  8911                 mov dword ptr [ecx], edx
// 00720fd4  8b5004               mov edx, dword ptr [eax + 4]
// 00720fd7  895104               mov dword ptr [ecx + 4], edx
// 00720fda  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00720fdd  895108               mov dword ptr [ecx + 8], edx
// 00720fe0  83c010               add eax, 0x10
// 00720fe3  83c110               add ecx, 0x10
// 00720fe6  3b4608               cmp eax, dword ptr [esi + 8]
// 00720fe9  72e5                 jb 0x720fd0
// 00720feb  834608f0             add dword ptr [esi + 8], -0x10
// 00720fef  5e                   pop esi
// 00720ff0  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
