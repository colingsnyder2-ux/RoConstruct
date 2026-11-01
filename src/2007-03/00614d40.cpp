// from server: 100% by auto
// roc 2007-03 00614d40  unit: seg_00610000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614d40
//
// 00614d40  56                   push esi
// 00614d41  8b742408             mov esi, dword ptr [esp + 8]
// 00614d45  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614d48  57                   push edi
// 00614d49  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00614d4c  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00614d53  8b4808               mov ecx, dword ptr [eax + 8]
// 00614d56  51                   push ecx
// 00614d57  681680ff7f           push 0x7fff8016
// 00614d5c  e8affdffff           call 0x614b10
// 00614d61  57                   push edi
// 00614d62  8d542418             lea edx, [esp + 0x18]
// 00614d66  52                   push edx
// 00614d67  56                   push esi
// 00614d68  89442420             mov dword ptr [esp + 0x20], eax
// 00614d6c  e8dff8ffff           call 0x614650
// 00614d71  8b442420             mov eax, dword ptr [esp + 0x20]
// 00614d75  83c414               add esp, 0x14
// 00614d78  5f                   pop edi
// 00614d79  5e                   pop esi
// 00614d7a  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_jump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
