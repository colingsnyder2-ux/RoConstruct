// from server: 100% by auto
// roc 2009-12 00789090  unit: RBX::UniversalTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789090
//
// 00789090  8b442408             mov eax, dword ptr [esp + 8]
// 00789094  56                   push esi
// 00789095  8b742408             mov esi, dword ptr [esp + 8]
// 00789099  8bce                 mov ecx, esi
// 0078909b  e850f5ffff           call 0x7885f0
// 007890a0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007890a4  8b10                 mov edx, dword ptr [eax]
// 007890a6  51                   push ecx
// 007890a7  52                   push edx
// 007890a8  e8a3710400           call 0x7d0250
// 007890ad  8b10                 mov edx, dword ptr [eax]
// 007890af  8b4e08               mov ecx, dword ptr [esi + 8]
// 007890b2  8911                 mov dword ptr [ecx], edx
// 007890b4  8b5004               mov edx, dword ptr [eax + 4]
// 007890b7  895104               mov dword ptr [ecx + 4], edx
// 007890ba  8b4008               mov eax, dword ptr [eax + 8]
// 007890bd  83c408               add esp, 8
// 007890c0  894108               mov dword ptr [ecx + 8], eax
// 007890c3  83460810             add dword ptr [esi + 8], 0x10
// 007890c7  5e                   pop esi
// 007890c8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
