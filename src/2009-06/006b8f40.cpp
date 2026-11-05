// from server: 100% by auto
// roc 2009-06 006b8f40  unit: RBX::UniversalTool  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8f40
//
// 006b8f40  8b442408             mov eax, dword ptr [esp + 8]
// 006b8f44  56                   push esi
// 006b8f45  8b742408             mov esi, dword ptr [esp + 8]
// 006b8f49  8bce                 mov ecx, esi
// 006b8f4b  e880fcffff           call 0x6b8bd0
// 006b8f50  8b10                 mov edx, dword ptr [eax]
// 006b8f52  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b8f55  8911                 mov dword ptr [ecx], edx
// 006b8f57  8b5004               mov edx, dword ptr [eax + 4]
// 006b8f5a  895104               mov dword ptr [ecx + 4], edx
// 006b8f5d  8b4008               mov eax, dword ptr [eax + 8]
// 006b8f60  894108               mov dword ptr [ecx + 8], eax
// 006b8f63  83460810             add dword ptr [esi + 8], 0x10
// 006b8f67  5e                   pop esi
// 006b8f68  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
