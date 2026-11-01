// from server: 100% by auto
// roc 2009-12 00605260  unit: seg_00600000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605260
//
// 00605260  53                   push ebx
// 00605261  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00605265  85db                 test ebx, ebx
// 00605267  7457                 je 0x6052c0
// 00605269  55                   push ebp
// 0060526a  53                   push ebx
// 0060526b  e830080000           call 0x605aa0
// 00605270  8babcc000000         mov ebp, dword ptr [ebx + 0xcc]
// 00605276  83c404               add esp, 4
// 00605279  89abd0000000         mov dword ptr [ebx + 0xd0], ebp
// 0060527f  85c0                 test eax, eax
// 00605281  7e3c                 jle 0x6052bf
// 00605283  56                   push esi
// 00605284  89442410             mov dword ptr [esp + 0x10], eax
// 00605288  57                   push edi
// 00605289  8da42400000000       lea esp, [esp]
// 00605290  8b742418             mov esi, dword ptr [esp + 0x18]
// 00605294  85ed                 test ebp, ebp
// 00605296  761e                 jbe 0x6052b6
// 00605298  8bfd                 mov edi, ebp
// 0060529a  8d9b00000000         lea ebx, [ebx]
// 006052a0  8b06                 mov eax, dword ptr [esi]
// 006052a2  6a00                 push 0
// 006052a4  50                   push eax
// 006052a5  53                   push ebx
// 006052a6  e895faffff           call 0x604d40
// 006052ab  83c40c               add esp, 0xc
// 006052ae  83c604               add esi, 4
// 006052b1  83ef01               sub edi, 1
// 006052b4  75ea                 jne 0x6052a0
// 006052b6  836c241401           sub dword ptr [esp + 0x14], 1
// 006052bb  75d3                 jne 0x605290
// 006052bd  5f                   pop edi
// 006052be  5e                   pop esi
// 006052bf  5d                   pop ebp
// 006052c0  5b                   pop ebx
// 006052c1  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
