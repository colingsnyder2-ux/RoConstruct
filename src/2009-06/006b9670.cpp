// from server: 100% by auto
// roc 2009-06 006b9670  unit: RBX::UniversalTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9670
//
// 006b9670  8b442408             mov eax, dword ptr [esp + 8]
// 006b9674  56                   push esi
// 006b9675  8b742408             mov esi, dword ptr [esp + 8]
// 006b9679  8bce                 mov ecx, esi
// 006b967b  e850f5ffff           call 0x6b8bd0
// 006b9680  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b9684  8b10                 mov edx, dword ptr [eax]
// 006b9686  51                   push ecx
// 006b9687  52                   push edx
// 006b9688  e8832b0300           call 0x6ec210
// 006b968d  8b10                 mov edx, dword ptr [eax]
// 006b968f  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9692  8911                 mov dword ptr [ecx], edx
// 006b9694  8b5004               mov edx, dword ptr [eax + 4]
// 006b9697  895104               mov dword ptr [ecx + 4], edx
// 006b969a  8b4008               mov eax, dword ptr [eax + 8]
// 006b969d  83c408               add esp, 8
// 006b96a0  894108               mov dword ptr [ecx + 8], eax
// 006b96a3  83460810             add dword ptr [esi + 8], 0x10
// 006b96a7  5e                   pop esi
// 006b96a8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
