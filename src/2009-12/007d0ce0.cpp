// from server: 100% by auto
// roc 2009-12 007d0ce0  unit: RBX::PartDropTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0ce0
//
// 007d0ce0  53                   push ebx
// 007d0ce1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007d0ce5  56                   push esi
// 007d0ce6  57                   push edi
// 007d0ce7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d0ceb  8bc3                 mov eax, ebx
// 007d0ced  c1e004               shl eax, 4
// 007d0cf0  83c018               add eax, 0x18
// 007d0cf3  50                   push eax
// 007d0cf4  6a00                 push 0
// 007d0cf6  6a00                 push 0
// 007d0cf8  57                   push edi
// 007d0cf9  e8b20a0000           call 0x7d17b0
// 007d0cfe  8bf0                 mov esi, eax
// 007d0d00  6a06                 push 6
// 007d0d02  56                   push esi
// 007d0d03  57                   push edi
// 007d0d04  e857d0ffff           call 0x7cdd60
// 007d0d09  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007d0d0d  83c41c               add esp, 0x1c
// 007d0d10  5f                   pop edi
// 007d0d11  885e07               mov byte ptr [esi + 7], bl
// 007d0d14  c6460601             mov byte ptr [esi + 6], 1
// 007d0d18  894e0c               mov dword ptr [esi + 0xc], ecx
// 007d0d1b  8bc6                 mov eax, esi
// 007d0d1d  5e                   pop esi
// 007d0d1e  5b                   pop ebx
// 007d0d1f  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_newCclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
