// from server: 100% by auto
// roc 2009-12 00788960  unit: RBX::UniversalTool  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788960
//
// 00788960  8b442408             mov eax, dword ptr [esp + 8]
// 00788964  56                   push esi
// 00788965  8b742408             mov esi, dword ptr [esp + 8]
// 00788969  8bce                 mov ecx, esi
// 0078896b  e880fcffff           call 0x7885f0
// 00788970  8b10                 mov edx, dword ptr [eax]
// 00788972  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788975  8911                 mov dword ptr [ecx], edx
// 00788977  8b5004               mov edx, dword ptr [eax + 4]
// 0078897a  895104               mov dword ptr [ecx + 4], edx
// 0078897d  8b4008               mov eax, dword ptr [eax + 8]
// 00788980  894108               mov dword ptr [ecx + 8], eax
// 00788983  83460810             add dword ptr [esi + 8], 0x10
// 00788987  5e                   pop esi
// 00788988  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
