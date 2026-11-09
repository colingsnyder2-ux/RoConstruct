// from server: 100% by auto
// roc 2009-06 006b9dd0  unit: RBX::UniversalTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9dd0
//
// 006b9dd0  56                   push esi
// 006b9dd1  8b742408             mov esi, dword ptr [esp + 8]
// 006b9dd5  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9dd8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b9ddb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b9dde  7209                 jb 0x6b9de9
// 006b9de0  56                   push esi
// 006b9de1  e8dafd0200           call 0x6e9bc0
// 006b9de6  83c404               add esp, 4
// 006b9de9  8b4614               mov eax, dword ptr [esi + 0x14]
// 006b9dec  3b4628               cmp eax, dword ptr [esi + 0x28]
// 006b9def  7505                 jne 0x6b9df6
// 006b9df1  8b4648               mov eax, dword ptr [esi + 0x48]
// 006b9df4  eb08                 jmp 0x6b9dfe
// 006b9df6  8b5004               mov edx, dword ptr [eax + 4]
// 006b9df9  8b02                 mov eax, dword ptr [edx]
// 006b9dfb  8b400c               mov eax, dword ptr [eax + 0xc]
// 006b9dfe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006b9e02  50                   push eax
// 006b9e03  51                   push ecx
// 006b9e04  56                   push esi
// 006b9e05  e8262e0300           call 0x6ecc30
// 006b9e0a  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9e0d  8901                 mov dword ptr [ecx], eax
// 006b9e0f  83c40c               add esp, 0xc
// 006b9e12  c7410807000000       mov dword ptr [ecx + 8], 7
// 006b9e19  83460810             add dword ptr [esi + 8], 0x10
// 006b9e1d  83c018               add eax, 0x18
// 006b9e20  5e                   pop esi
// 006b9e21  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
