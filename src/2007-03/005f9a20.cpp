// from server: 100% by auto
// roc 2007-03 005f9a20  unit: seg_005f0000  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9a20
//
// 005f9a20  8b542408             mov edx, dword ptr [esp + 8]
// 005f9a24  8b4208               mov eax, dword ptr [edx + 8]
// 005f9a27  8bc8                 mov ecx, eax
// 005f9a29  83e905               sub ecx, 5
// 005f9a2c  56                   push esi
// 005f9a2d  8b742408             mov esi, dword ptr [esp + 8]
// 005f9a31  7418                 je 0x5f9a4b
// 005f9a33  83e902               sub ecx, 2
// 005f9a36  740c                 je 0x5f9a44
// 005f9a38  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f9a3b  8b848198000000       mov eax, dword ptr [ecx + eax*4 + 0x98]
// 005f9a42  eb0c                 jmp 0x5f9a50
// 005f9a44  8b12                 mov edx, dword ptr [edx]
// 005f9a46  8b4208               mov eax, dword ptr [edx + 8]
// 005f9a49  eb05                 jmp 0x5f9a50
// 005f9a4b  8b02                 mov eax, dword ptr [edx]
// 005f9a4d  8b4008               mov eax, dword ptr [eax + 8]
// 005f9a50  85c0                 test eax, eax
// 005f9a52  741a                 je 0x5f9a6e
// 005f9a54  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f9a57  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f9a5b  8b8c91bc000000       mov ecx, dword ptr [ecx + edx*4 + 0xbc]
// 005f9a62  51                   push ecx
// 005f9a63  50                   push eax
// 005f9a64  e817240000           call 0x5fbe80
// 005f9a69  83c408               add esp, 8
// 005f9a6c  5e                   pop esi
// 005f9a6d  c3                   ret 
// 005f9a6e  b8a0007c00           mov eax, 0x7c00a0
// 005f9a73  5e                   pop esi
// 005f9a74  c3                   ret 
// library lua-5.1.1/ltm.c (function _luaT_gettmbyobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltm.c
