// from server: 100% by auto
// roc 2010-06 00721880  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721880
//
// 00721880  56                   push esi
// 00721881  8b742408             mov esi, dword ptr [esp + 8]
// 00721885  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721888  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0072188b  57                   push edi
// 0072188c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0072188f  7209                 jb 0x72189a
// 00721891  56                   push esi
// 00721892  e8c9950500           call 0x77ae60
// 00721897  83c404               add esp, 4
// 0072189a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0072189e  8b442410             mov eax, dword ptr [esp + 0x10]
// 007218a2  8b7e08               mov edi, dword ptr [esi + 8]
// 007218a5  52                   push edx
// 007218a6  50                   push eax
// 007218a7  56                   push esi
// 007218a8  e833bb0500           call 0x77d3e0
// 007218ad  83c40c               add esp, 0xc
// 007218b0  8907                 mov dword ptr [edi], eax
// 007218b2  c7470805000000       mov dword ptr [edi + 8], 5
// 007218b9  83460810             add dword ptr [esi + 8], 0x10
// 007218bd  5f                   pop edi
// 007218be  5e                   pop esi
// 007218bf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
