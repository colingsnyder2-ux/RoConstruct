// from server: 100% by auto
// roc 2009-12 00788800  unit: RBX::UniversalTool  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788800
//
// 00788800  8b442408             mov eax, dword ptr [esp + 8]
// 00788804  56                   push esi
// 00788805  8b742408             mov esi, dword ptr [esp + 8]
// 00788809  8bce                 mov ecx, esi
// 0078880b  e8e0fdffff           call 0x7885f0
// 00788810  83c010               add eax, 0x10
// 00788813  3b4608               cmp eax, dword ptr [esi + 8]
// 00788816  7323                 jae 0x78883b
// 00788818  8d48f0               lea ecx, [eax - 0x10]
// 0078881b  eb03                 jmp 0x788820
// 0078881d  8d4900               lea ecx, [ecx]
// 00788820  8b10                 mov edx, dword ptr [eax]
// 00788822  8911                 mov dword ptr [ecx], edx
// 00788824  8b5004               mov edx, dword ptr [eax + 4]
// 00788827  895104               mov dword ptr [ecx + 4], edx
// 0078882a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0078882d  895108               mov dword ptr [ecx + 8], edx
// 00788830  83c010               add eax, 0x10
// 00788833  83c110               add ecx, 0x10
// 00788836  3b4608               cmp eax, dword ptr [esi + 8]
// 00788839  72e5                 jb 0x788820
// 0078883b  834608f0             add dword ptr [esi + 8], -0x10
// 0078883f  5e                   pop esi
// 00788840  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
