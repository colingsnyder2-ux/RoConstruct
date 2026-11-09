// from server: 100% by auto
// roc 2009-12 006ab840  unit: RBX::VHat::?$FactoryProduct  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ab840
//
// 006ab840  8b442404             mov eax, dword ptr [esp + 4]
// 006ab844  6a00                 push 0
// 006ab846  50                   push eax
// 006ab847  e8a4feffff           call 0x6ab6f0
// 006ab84c  83c408               add esp, 8
// 006ab84f  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
