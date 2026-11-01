// from server: 100% by auto
// roc 2009-12 007d1970  unit: seg_007d0000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1970
//
// 007d1970  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d1977  7424                 je 0x7d199d
// 007d1979  681d010000           push 0x11d
// 007d197e  56                   push esi
// 007d197f  e8bc380000           call 0x7d5240
// 007d1984  50                   push eax
// 007d1985  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d1988  68d0ed9e00           push 0x9eedd0
// 007d198d  50                   push eax
// 007d198e  e8ed8bfcff           call 0x79a580
// 007d1993  50                   push eax
// 007d1994  56                   push esi
// 007d1995  e8a6390000           call 0x7d5340
// 007d199a  83c41c               add esp, 0x1c
// 007d199d  53                   push ebx
// 007d199e  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007d19a1  56                   push esi
// 007d19a2  e8894d0000           call 0x7d6730
// 007d19a7  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 007d19aa  53                   push ebx
// 007d19ab  51                   push ecx
// 007d19ac  e8efa80000           call 0x7dc2a0
// 007d19b1  83c9ff               or ecx, 0xffffffff
// 007d19b4  83c40c               add esp, 0xc
// 007d19b7  894f10               mov dword ptr [edi + 0x10], ecx
// 007d19ba  894f14               mov dword ptr [edi + 0x14], ecx
// 007d19bd  c70704000000         mov dword ptr [edi], 4
// 007d19c3  894708               mov dword ptr [edi + 8], eax
// 007d19c6  5b                   pop ebx
// 007d19c7  c3                   ret 
// library lua-5.1/lparser.c (function _checkname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
