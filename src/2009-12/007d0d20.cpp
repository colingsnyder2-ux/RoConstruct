// from server: 100% by auto
// roc 2009-12 007d0d20  unit: RBX::PartDropTool  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0d20
//
// 007d0d20  53                   push ebx
// 007d0d21  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007d0d25  55                   push ebp
// 007d0d26  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d0d2a  56                   push esi
// 007d0d2b  57                   push edi
// 007d0d2c  8d3c9d14000000       lea edi, [ebx*4 + 0x14]
// 007d0d33  57                   push edi
// 007d0d34  6a00                 push 0
// 007d0d36  6a00                 push 0
// 007d0d38  55                   push ebp
// 007d0d39  e8720a0000           call 0x7d17b0
// 007d0d3e  8bf0                 mov esi, eax
// 007d0d40  6a06                 push 6
// 007d0d42  56                   push esi
// 007d0d43  55                   push ebp
// 007d0d44  e817d0ffff           call 0x7cdd60
// 007d0d49  8b442438             mov eax, dword ptr [esp + 0x38]
// 007d0d4d  83c41c               add esp, 0x1c
// 007d0d50  c6460600             mov byte ptr [esi + 6], 0
// 007d0d54  89460c               mov dword ptr [esi + 0xc], eax
// 007d0d57  885e07               mov byte ptr [esi + 7], bl
// 007d0d5a  85db                 test ebx, ebx
// 007d0d5c  7411                 je 0x7d0d6f
// 007d0d5e  8d0437               lea eax, [edi + esi]
// 007d0d61  4b                   dec ebx
// 007d0d62  83e804               sub eax, 4
// 007d0d65  c70000000000         mov dword ptr [eax], 0
// 007d0d6b  85db                 test ebx, ebx
// 007d0d6d  75f2                 jne 0x7d0d61
// 007d0d6f  5f                   pop edi
// 007d0d70  8bc6                 mov eax, esi
// 007d0d72  5e                   pop esi
// 007d0d73  5d                   pop ebp
// 007d0d74  5b                   pop ebx
// 007d0d75  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_newLclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
