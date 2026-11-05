// from server: 100% by auto
// roc 2008-06 00611c70  unit: seg_00610000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611c70
//
// 00611c70  8b442408             mov eax, dword ptr [esp + 8]
// 00611c74  56                   push esi
// 00611c75  8b742408             mov esi, dword ptr [esp + 8]
// 00611c79  8bce                 mov ecx, esi
// 00611c7b  e810feffff           call 0x611a90
// 00611c80  83c010               add eax, 0x10
// 00611c83  3b4608               cmp eax, dword ptr [esi + 8]
// 00611c86  7323                 jae 0x611cab
// 00611c88  8d48f0               lea ecx, [eax - 0x10]
// 00611c8b  eb03                 jmp 0x611c90
// 00611c8d  8d4900               lea ecx, [ecx]
// 00611c90  8b10                 mov edx, dword ptr [eax]
// 00611c92  8911                 mov dword ptr [ecx], edx
// 00611c94  8b5004               mov edx, dword ptr [eax + 4]
// 00611c97  895104               mov dword ptr [ecx + 4], edx
// 00611c9a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00611c9d  895108               mov dword ptr [ecx + 8], edx
// 00611ca0  83c010               add eax, 0x10
// 00611ca3  83c110               add ecx, 0x10
// 00611ca6  3b4608               cmp eax, dword ptr [esi + 8]
// 00611ca9  72e5                 jb 0x611c90
// 00611cab  834608f0             add dword ptr [esi + 8], -0x10
// 00611caf  5e                   pop esi
// 00611cb0  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
