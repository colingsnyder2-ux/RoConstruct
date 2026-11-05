// from server: 100% by auto
// roc 2010-06 00721840  unit: RBX::UniversalTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721840
//
// 00721840  8b442408             mov eax, dword ptr [esp + 8]
// 00721844  56                   push esi
// 00721845  8b742408             mov esi, dword ptr [esp + 8]
// 00721849  8bce                 mov ecx, esi
// 0072184b  e850f5ffff           call 0x720da0
// 00721850  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00721854  8b10                 mov edx, dword ptr [eax]
// 00721856  51                   push ecx
// 00721857  52                   push edx
// 00721858  e843bc0500           call 0x77d4a0
// 0072185d  8b10                 mov edx, dword ptr [eax]
// 0072185f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721862  8911                 mov dword ptr [ecx], edx
// 00721864  8b5004               mov edx, dword ptr [eax + 4]
// 00721867  895104               mov dword ptr [ecx + 4], edx
// 0072186a  8b4008               mov eax, dword ptr [eax + 8]
// 0072186d  83c408               add esp, 8
// 00721870  894108               mov dword ptr [ecx + 8], eax
// 00721873  83460810             add dword ptr [esi + 8], 0x10
// 00721877  5e                   pop esi
// 00721878  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
