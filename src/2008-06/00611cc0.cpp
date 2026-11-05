// from server: 100% by auto
// roc 2008-06 00611cc0  unit: seg_00610000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611cc0
//
// 00611cc0  8b442408             mov eax, dword ptr [esp + 8]
// 00611cc4  56                   push esi
// 00611cc5  8b742408             mov esi, dword ptr [esp + 8]
// 00611cc9  8bce                 mov ecx, esi
// 00611ccb  e8c0fdffff           call 0x611a90
// 00611cd0  8b5608               mov edx, dword ptr [esi + 8]
// 00611cd3  3bd0                 cmp edx, eax
// 00611cd5  7624                 jbe 0x611cfb
// 00611cd7  8d4af0               lea ecx, [edx - 0x10]
// 00611cda  57                   push edi
// 00611cdb  eb03                 jmp 0x611ce0
// 00611cdd  8d4900               lea ecx, [ecx]
// 00611ce0  8b39                 mov edi, dword ptr [ecx]
// 00611ce2  893a                 mov dword ptr [edx], edi
// 00611ce4  8b7904               mov edi, dword ptr [ecx + 4]
// 00611ce7  897a04               mov dword ptr [edx + 4], edi
// 00611cea  8b7908               mov edi, dword ptr [ecx + 8]
// 00611ced  897918               mov dword ptr [ecx + 0x18], edi
// 00611cf0  83ea10               sub edx, 0x10
// 00611cf3  83e910               sub ecx, 0x10
// 00611cf6  3bd0                 cmp edx, eax
// 00611cf8  77e6                 ja 0x611ce0
// 00611cfa  5f                   pop edi
// 00611cfb  8b4e08               mov ecx, dword ptr [esi + 8]
// 00611cfe  8b11                 mov edx, dword ptr [ecx]
// 00611d00  8910                 mov dword ptr [eax], edx
// 00611d02  8b5104               mov edx, dword ptr [ecx + 4]
// 00611d05  895004               mov dword ptr [eax + 4], edx
// 00611d08  8b4908               mov ecx, dword ptr [ecx + 8]
// 00611d0b  894808               mov dword ptr [eax + 8], ecx
// 00611d0e  5e                   pop esi
// 00611d0f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
