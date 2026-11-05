// from server: 100% by auto
// roc 2010-06 005637d0  unit: G3D::_internal::DialogTemplate  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005637d0
//
// 005637d0  53                   push ebx
// 005637d1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005637d5  85db                 test ebx, ebx
// 005637d7  744b                 je 0x563824
// 005637d9  53                   push ebx
// 005637da  e8413c0000           call 0x567420
// 005637df  83c404               add esp, 4
// 005637e2  85c0                 test eax, eax
// 005637e4  7e3e                 jle 0x563824
// 005637e6  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 005637ec  55                   push ebp
// 005637ed  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005637f1  56                   push esi
// 005637f2  57                   push edi
// 005637f3  89442414             mov dword ptr [esp + 0x14], eax
// 005637f7  33f6                 xor esi, esi
// 005637f9  8bfd                 mov edi, ebp
// 005637fb  85c9                 test ecx, ecx
// 005637fd  761b                 jbe 0x56381a
// 005637ff  90                   nop 
// 00563800  8b07                 mov eax, dword ptr [edi]
// 00563802  50                   push eax
// 00563803  53                   push ebx
// 00563804  e847f6ffff           call 0x562e50
// 00563809  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 0056380f  46                   inc esi
// 00563810  83c408               add esp, 8
// 00563813  83c704               add edi, 4
// 00563816  3bf1                 cmp esi, ecx
// 00563818  72e6                 jb 0x563800
// 0056381a  836c241401           sub dword ptr [esp + 0x14], 1
// 0056381f  75d6                 jne 0x5637f7
// 00563821  5f                   pop edi
// 00563822  5e                   pop esi
// 00563823  5d                   pop ebp
// 00563824  5b                   pop ebx
// 00563825  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
