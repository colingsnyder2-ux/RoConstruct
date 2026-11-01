// from server: 100% by auto
// roc 2007-03 005fc8c0  unit: seg_005f0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc8c0
//
// 005fc8c0  53                   push ebx
// 005fc8c1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005fc8c5  56                   push esi
// 005fc8c6  57                   push edi
// 005fc8c7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005fc8cb  8bc3                 mov eax, ebx
// 005fc8cd  c1e004               shl eax, 4
// 005fc8d0  83c018               add eax, 0x18
// 005fc8d3  50                   push eax
// 005fc8d4  6a00                 push 0
// 005fc8d6  6a00                 push 0
// 005fc8d8  57                   push edi
// 005fc8d9  e8c20a0000           call 0x5fd3a0
// 005fc8de  8bf0                 mov esi, eax
// 005fc8e0  6a06                 push 6
// 005fc8e2  56                   push esi
// 005fc8e3  57                   push edi
// 005fc8e4  e817d0ffff           call 0x5f9900
// 005fc8e9  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005fc8ed  83c41c               add esp, 0x1c
// 005fc8f0  5f                   pop edi
// 005fc8f1  885e07               mov byte ptr [esi + 7], bl
// 005fc8f4  c6460601             mov byte ptr [esi + 6], 1
// 005fc8f8  894e0c               mov dword ptr [esi + 0xc], ecx
// 005fc8fb  8bc6                 mov eax, esi
// 005fc8fd  5e                   pop esi
// 005fc8fe  5b                   pop ebx
// 005fc8ff  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_newCclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
