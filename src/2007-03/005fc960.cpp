// from server: 100% by auto
// roc 2007-03 005fc960  unit: seg_005f0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc960
//
// 005fc960  56                   push esi
// 005fc961  57                   push edi
// 005fc962  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005fc966  6a20                 push 0x20
// 005fc968  6a00                 push 0
// 005fc96a  6a00                 push 0
// 005fc96c  57                   push edi
// 005fc96d  e82e0a0000           call 0x5fd3a0
// 005fc972  8bf0                 mov esi, eax
// 005fc974  6a0a                 push 0xa
// 005fc976  56                   push esi
// 005fc977  57                   push edi
// 005fc978  e883cfffff           call 0x5f9900
// 005fc97d  8d4610               lea eax, [esi + 0x10]
// 005fc980  83c41c               add esp, 0x1c
// 005fc983  894608               mov dword ptr [esi + 8], eax
// 005fc986  c7400800000000       mov dword ptr [eax + 8], 0
// 005fc98d  5f                   pop edi
// 005fc98e  8bc6                 mov eax, esi
// 005fc990  5e                   pop esi
// 005fc991  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_newupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
