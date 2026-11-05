// from server: 100% by auto
// roc 2009-06 00580090  unit: G3D::_internal::DialogTemplate  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00580090
//
// 00580090  53                   push ebx
// 00580091  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00580095  85db                 test ebx, ebx
// 00580097  744b                 je 0x5800e4
// 00580099  53                   push ebx
// 0058009a  e8513c0000           call 0x583cf0
// 0058009f  83c404               add esp, 4
// 005800a2  85c0                 test eax, eax
// 005800a4  7e3e                 jle 0x5800e4
// 005800a6  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 005800ac  55                   push ebp
// 005800ad  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005800b1  56                   push esi
// 005800b2  57                   push edi
// 005800b3  89442414             mov dword ptr [esp + 0x14], eax
// 005800b7  33f6                 xor esi, esi
// 005800b9  8bfd                 mov edi, ebp
// 005800bb  85c9                 test ecx, ecx
// 005800bd  761b                 jbe 0x5800da
// 005800bf  90                   nop 
// 005800c0  8b07                 mov eax, dword ptr [edi]
// 005800c2  50                   push eax
// 005800c3  53                   push ebx
// 005800c4  e837f6ffff           call 0x57f700
// 005800c9  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 005800cf  46                   inc esi
// 005800d0  83c408               add esp, 8
// 005800d3  83c704               add edi, 4
// 005800d6  3bf1                 cmp esi, ecx
// 005800d8  72e6                 jb 0x5800c0
// 005800da  836c241401           sub dword ptr [esp + 0x14], 1
// 005800df  75d6                 jne 0x5800b7
// 005800e1  5f                   pop edi
// 005800e2  5e                   pop esi
// 005800e3  5d                   pop ebp
// 005800e4  5b                   pop ebx
// 005800e5  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
