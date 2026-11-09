// from server: 100% by auto
// roc 2009-12 00789520  unit: RBX::UniversalTool  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789520
//
// 00789520  8b442410             mov eax, dword ptr [esp + 0x10]
// 00789524  83ec08               sub esp, 8
// 00789527  56                   push esi
// 00789528  8b742410             mov esi, dword ptr [esp + 0x10]
// 0078952c  85c0                 test eax, eax
// 0078952e  7504                 jne 0x789534
// 00789530  33c9                 xor ecx, ecx
// 00789532  eb0c                 jmp 0x789540
// 00789534  8bce                 mov ecx, esi
// 00789536  e8b5f0ffff           call 0x7885f0
// 0078953b  2b4620               sub eax, dword ptr [esi + 0x20]
// 0078953e  8bc8                 mov ecx, eax
// 00789540  8b442414             mov eax, dword ptr [esp + 0x14]
// 00789544  40                   inc eax
// 00789545  c1e004               shl eax, 4
// 00789548  8bd0                 mov edx, eax
// 0078954a  8b4608               mov eax, dword ptr [esi + 8]
// 0078954d  57                   push edi
// 0078954e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00789552  2bc2                 sub eax, edx
// 00789554  89442408             mov dword ptr [esp + 8], eax
// 00789558  2b4620               sub eax, dword ptr [esi + 0x20]
// 0078955b  51                   push ecx
// 0078955c  50                   push eax
// 0078955d  8d442410             lea eax, [esp + 0x10]
// 00789561  50                   push eax
// 00789562  6800957800           push 0x789500
// 00789567  56                   push esi
// 00789568  897c2420             mov dword ptr [esp + 0x20], edi
// 0078956c  e83fe70000           call 0x797cb0
// 00789571  83c414               add esp, 0x14
// 00789574  83ffff               cmp edi, -1
// 00789577  5f                   pop edi
// 00789578  750e                 jne 0x789588
// 0078957a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0078957d  8b7608               mov esi, dword ptr [esi + 8]
// 00789580  3b7108               cmp esi, dword ptr [ecx + 8]
// 00789583  7203                 jb 0x789588
// 00789585  897108               mov dword ptr [ecx + 8], esi
// 00789588  5e                   pop esi
// 00789589  83c408               add esp, 8
// 0078958c  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
