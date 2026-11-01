// from server: 100% by auto
// roc 2009-12 0079b630  unit: seg_00790000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b630
//
// 0079b630  83ec10               sub esp, 0x10
// 0079b633  56                   push esi
// 0079b634  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0079b638  8d442404             lea eax, [esp + 4]
// 0079b63c  50                   push eax
// 0079b63d  56                   push esi
// 0079b63e  e89d280300           call 0x7cdee0
// 0079b643  83c408               add esp, 8
// 0079b646  85c0                 test eax, eax
// 0079b648  8bc6                 mov eax, esi
// 0079b64a  7404                 je 0x79b650
// 0079b64c  8b442420             mov eax, dword ptr [esp + 0x20]
// 0079b650  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079b654  680cac9e00           push 0x9eac0c
// 0079b659  50                   push eax
// 0079b65a  51                   push ecx
// 0079b65b  e810ffffff           call 0x79b570
// 0079b660  83c40c               add esp, 0xc
// 0079b663  5e                   pop esi
// 0079b664  83c410               add esp, 0x10
// 0079b667  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_aritherror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
