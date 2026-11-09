// from server: 100% by auto
// roc 2010-06 00721600  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721600
//
// 00721600  56                   push esi
// 00721601  8b742408             mov esi, dword ptr [esp + 8]
// 00721605  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721608  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0072160b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0072160e  7209                 jb 0x721619
// 00721610  56                   push esi
// 00721611  e84a980500           call 0x77ae60
// 00721616  83c404               add esp, 4
// 00721619  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072161d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00721621  52                   push edx
// 00721622  50                   push eax
// 00721623  56                   push esi
// 00721624  e8c7140100           call 0x732af0
// 00721629  83c40c               add esp, 0xc
// 0072162c  5e                   pop esi
// 0072162d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
