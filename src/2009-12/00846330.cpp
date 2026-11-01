// from server: 100% by auto
// roc 2009-12 00846330  unit: CXTPControls  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00846330
//
// 00846330  53                   push ebx
// 00846331  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00846335  55                   push ebp
// 00846336  f7db                 neg ebx
// 00846338  56                   push esi
// 00846339  1bdb                 sbb ebx, ebx
// 0084633b  57                   push edi
// 0084633c  8bf9                 mov edi, ecx
// 0084633e  8b472c               mov eax, dword ptr [edi + 0x2c]
// 00846341  83e3fe               and ebx, 0xfffffffe
// 00846344  83c302               add ebx, 2
// 00846347  33f6                 xor esi, esi
// 00846349  85c0                 test eax, eax
// 0084634b  7e37                 jle 0x846384
// 0084634d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00846351  85f6                 test esi, esi
// 00846353  7c11                 jl 0x846366
// 00846355  3bf0                 cmp esi, eax
// 00846357  7d0d                 jge 0x846366
// 00846359  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 0084635c  7d2f                 jge 0x84638d
// 0084635e  8b4728               mov eax, dword ptr [edi + 0x28]
// 00846361  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 00846364  eb02                 jmp 0x846368
// 00846366  33c9                 xor ecx, ecx
// 00846368  8b11                 mov edx, dword ptr [ecx]
// 0084636a  8b8280000000         mov eax, dword ptr [edx + 0x80]
// 00846370  53                   push ebx
// 00846371  ffd0                 call eax
// 00846373  85c0                 test eax, eax
// 00846375  7405                 je 0x84637c
// 00846377  85ed                 test ebp, ebp
// 00846379  7417                 je 0x846392
// 0084637b  4d                   dec ebp
// 0084637c  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0084637f  46                   inc esi
// 00846380  3bf0                 cmp esi, eax
// 00846382  7ccd                 jl 0x846351
// 00846384  5f                   pop edi
// 00846385  5e                   pop esi
// 00846386  5d                   pop ebp
// 00846387  33c0                 xor eax, eax
// 00846389  5b                   pop ebx
// 0084638a  c20800               ret 8
// 0084638d  e87ad7faff           call 0x7f3b0c
// 00846392  85f6                 test esi, esi
// 00846394  7cee                 jl 0x846384
// 00846396  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 00846399  7de9                 jge 0x846384
// 0084639b  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0084639e  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 008463a1  5f                   pop edi
// 008463a2  5e                   pop esi
// 008463a3  5d                   pop ebp
// 008463a4  5b                   pop ebx
// 008463a5  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?GetVisibleAt@CXTPControls@@QBEPAVCXTPControl@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
