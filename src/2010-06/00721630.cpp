// from server: 100% by auto
// roc 2010-06 00721630  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721630
//
// 00721630  56                   push esi
// 00721631  8b742408             mov esi, dword ptr [esp + 8]
// 00721635  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721638  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0072163b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0072163e  7209                 jb 0x721649
// 00721640  56                   push esi
// 00721641  e81a980500           call 0x77ae60
// 00721646  83c404               add esp, 4
// 00721649  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072164d  8d542410             lea edx, [esp + 0x10]
// 00721651  52                   push edx
// 00721652  50                   push eax
// 00721653  56                   push esi
// 00721654  e897140100           call 0x732af0
// 00721659  83c40c               add esp, 0xc
// 0072165c  5e                   pop esi
// 0072165d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
