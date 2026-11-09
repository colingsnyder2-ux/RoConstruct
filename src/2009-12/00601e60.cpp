// from server: 100% by auto
// roc 2009-12 00601e60  unit: G3D::_internal::DialogTemplate  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601e60
//
// 00601e60  53                   push ebx
// 00601e61  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00601e65  85db                 test ebx, ebx
// 00601e67  744b                 je 0x601eb4
// 00601e69  53                   push ebx
// 00601e6a  e8313c0000           call 0x605aa0
// 00601e6f  83c404               add esp, 4
// 00601e72  85c0                 test eax, eax
// 00601e74  7e3e                 jle 0x601eb4
// 00601e76  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 00601e7c  55                   push ebp
// 00601e7d  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00601e81  56                   push esi
// 00601e82  57                   push edi
// 00601e83  89442414             mov dword ptr [esp + 0x14], eax
// 00601e87  33f6                 xor esi, esi
// 00601e89  8bfd                 mov edi, ebp
// 00601e8b  85c9                 test ecx, ecx
// 00601e8d  761b                 jbe 0x601eaa
// 00601e8f  90                   nop 
// 00601e90  8b07                 mov eax, dword ptr [edi]
// 00601e92  50                   push eax
// 00601e93  53                   push ebx
// 00601e94  e847f6ffff           call 0x6014e0
// 00601e99  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 00601e9f  46                   inc esi
// 00601ea0  83c408               add esp, 8
// 00601ea3  83c704               add edi, 4
// 00601ea6  3bf1                 cmp esi, ecx
// 00601ea8  72e6                 jb 0x601e90
// 00601eaa  836c241401           sub dword ptr [esp + 0x14], 1
// 00601eaf  75d6                 jne 0x601e87
// 00601eb1  5f                   pop edi
// 00601eb2  5e                   pop esi
// 00601eb3  5d                   pop ebp
// 00601eb4  5b                   pop ebx
// 00601eb5  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
