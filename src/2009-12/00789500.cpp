// from server: 100% by auto
// roc 2009-12 00789500  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789500
//
// 00789500  8b442408             mov eax, dword ptr [esp + 8]
// 00789504  8b4804               mov ecx, dword ptr [eax + 4]
// 00789507  8b10                 mov edx, dword ptr [eax]
// 00789509  8b442404             mov eax, dword ptr [esp + 4]
// 0078950d  51                   push ecx
// 0078950e  52                   push edx
// 0078950f  50                   push eax
// 00789510  e8ebe50000           call 0x797b00
// 00789515  83c40c               add esp, 0xc
// 00789518  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
