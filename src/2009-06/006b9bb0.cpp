// from server: 100% by auto
// roc 2009-06 006b9bb0  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9bb0
//
// 006b9bb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b9bb4  8b4108               mov eax, dword ptr [ecx + 8]
// 006b9bb7  83e810               sub eax, 0x10
// 006b9bba  83780806             cmp dword ptr [eax + 8], 6
// 006b9bbe  7522                 jne 0x6b9be2
// 006b9bc0  8b00                 mov eax, dword ptr [eax]
// 006b9bc2  80780600             cmp byte ptr [eax + 6], 0
// 006b9bc6  751a                 jne 0x6b9be2
// 006b9bc8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006b9bcc  8b4010               mov eax, dword ptr [eax + 0x10]
// 006b9bcf  6a00                 push 0
// 006b9bd1  52                   push edx
// 006b9bd2  8b542410             mov edx, dword ptr [esp + 0x10]
// 006b9bd6  52                   push edx
// 006b9bd7  50                   push eax
// 006b9bd8  51                   push ecx
// 006b9bd9  e8e23a0300           call 0x6ed6c0
// 006b9bde  83c414               add esp, 0x14
// 006b9be1  c3                   ret 
// 006b9be2  b801000000           mov eax, 1
// 006b9be7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
