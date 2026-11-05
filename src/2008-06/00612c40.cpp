// from server: 100% by auto
// roc 2008-06 00612c40  unit: seg_00610000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612c40
//
// 00612c40  56                   push esi
// 00612c41  8b742408             mov esi, dword ptr [esp + 8]
// 00612c45  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612c48  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00612c4b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00612c4e  7209                 jb 0x612c59
// 00612c50  56                   push esi
// 00612c51  e83a970400           call 0x65c390
// 00612c56  83c404               add esp, 4
// 00612c59  8b4614               mov eax, dword ptr [esi + 0x14]
// 00612c5c  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00612c5f  7505                 jne 0x612c66
// 00612c61  8b4648               mov eax, dword ptr [esi + 0x48]
// 00612c64  eb08                 jmp 0x612c6e
// 00612c66  8b5004               mov edx, dword ptr [eax + 4]
// 00612c69  8b02                 mov eax, dword ptr [edx]
// 00612c6b  8b400c               mov eax, dword ptr [eax + 0xc]
// 00612c6e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00612c72  50                   push eax
// 00612c73  51                   push ecx
// 00612c74  56                   push esi
// 00612c75  e876c70400           call 0x65f3f0
// 00612c7a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612c7d  8901                 mov dword ptr [ecx], eax
// 00612c7f  83c40c               add esp, 0xc
// 00612c82  c7410807000000       mov dword ptr [ecx + 8], 7
// 00612c89  83460810             add dword ptr [esi + 8], 0x10
// 00612c8d  83c018               add eax, 0x18
// 00612c90  5e                   pop esi
// 00612c91  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
