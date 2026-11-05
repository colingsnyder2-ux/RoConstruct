// from server: 100% by auto
// roc 2010-06 00721fa0  unit: RBX::UniversalTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721fa0
//
// 00721fa0  56                   push esi
// 00721fa1  8b742408             mov esi, dword ptr [esp + 8]
// 00721fa5  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721fa8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00721fab  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00721fae  7209                 jb 0x721fb9
// 00721fb0  56                   push esi
// 00721fb1  e8aa8e0500           call 0x77ae60
// 00721fb6  83c404               add esp, 4
// 00721fb9  8b4614               mov eax, dword ptr [esi + 0x14]
// 00721fbc  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00721fbf  7505                 jne 0x721fc6
// 00721fc1  8b4648               mov eax, dword ptr [esi + 0x48]
// 00721fc4  eb08                 jmp 0x721fce
// 00721fc6  8b5004               mov edx, dword ptr [eax + 4]
// 00721fc9  8b02                 mov eax, dword ptr [edx]
// 00721fcb  8b400c               mov eax, dword ptr [eax + 0xc]
// 00721fce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00721fd2  50                   push eax
// 00721fd3  51                   push ecx
// 00721fd4  56                   push esi
// 00721fd5  e8f6be0500           call 0x77ded0
// 00721fda  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721fdd  8901                 mov dword ptr [ecx], eax
// 00721fdf  83c40c               add esp, 0xc
// 00721fe2  c7410807000000       mov dword ptr [ecx + 8], 7
// 00721fe9  83460810             add dword ptr [esi + 8], 0x10
// 00721fed  83c018               add eax, 0x18
// 00721ff0  5e                   pop esi
// 00721ff1  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
