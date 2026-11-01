// from server: 100% by auto
// roc 2007-03 00614880  unit: seg_00610000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614880
//
// 00614880  83ec20               sub esp, 0x20
// 00614883  53                   push ebx
// 00614884  8bd8                 mov ebx, eax
// 00614886  8b4304               mov eax, dword ptr [ebx + 4]
// 00614889  8d4c2414             lea ecx, [esp + 0x14]
// 0061488d  51                   push ecx
// 0061488e  8d4c2408             lea ecx, [esp + 8]
// 00614892  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0061489a  89442408             mov dword ptr [esp + 8], eax
// 0061489e  c744241005000000     mov dword ptr [esp + 0x10], 5
// 006148a6  e895feffff           call 0x614740
// 006148ab  83c404               add esp, 4
// 006148ae  5b                   pop ebx
// 006148af  83c420               add esp, 0x20
// 006148b2  c3                   ret 
// library lua-5.1.1/lcode.c (function _nilK)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
