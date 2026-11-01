// from server: 100% by auto
// roc 2009-06 0076b550  unit: CXTPControls  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076b550
//
// 0076b550  53                   push ebx
// 0076b551  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0076b555  55                   push ebp
// 0076b556  f7db                 neg ebx
// 0076b558  56                   push esi
// 0076b559  1bdb                 sbb ebx, ebx
// 0076b55b  57                   push edi
// 0076b55c  8bf9                 mov edi, ecx
// 0076b55e  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0076b561  83e3fe               and ebx, 0xfffffffe
// 0076b564  83c302               add ebx, 2
// 0076b567  33f6                 xor esi, esi
// 0076b569  85c0                 test eax, eax
// 0076b56b  7e37                 jle 0x76b5a4
// 0076b56d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0076b571  85f6                 test esi, esi
// 0076b573  7c11                 jl 0x76b586
// 0076b575  3bf0                 cmp esi, eax
// 0076b577  7d0d                 jge 0x76b586
// 0076b579  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 0076b57c  7d2f                 jge 0x76b5ad
// 0076b57e  8b4728               mov eax, dword ptr [edi + 0x28]
// 0076b581  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 0076b584  eb02                 jmp 0x76b588
// 0076b586  33c9                 xor ecx, ecx
// 0076b588  8b11                 mov edx, dword ptr [ecx]
// 0076b58a  8b8280000000         mov eax, dword ptr [edx + 0x80]
// 0076b590  53                   push ebx
// 0076b591  ffd0                 call eax
// 0076b593  85c0                 test eax, eax
// 0076b595  7405                 je 0x76b59c
// 0076b597  85ed                 test ebp, ebp
// 0076b599  7417                 je 0x76b5b2
// 0076b59b  4d                   dec ebp
// 0076b59c  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0076b59f  46                   inc esi
// 0076b5a0  3bf0                 cmp esi, eax
// 0076b5a2  7ccd                 jl 0x76b571
// 0076b5a4  5f                   pop edi
// 0076b5a5  5e                   pop esi
// 0076b5a6  5d                   pop ebp
// 0076b5a7  33c0                 xor eax, eax
// 0076b5a9  5b                   pop ebx
// 0076b5aa  c20800               ret 8
// 0076b5ad  e832d7faff           call 0x718ce4
// 0076b5b2  85f6                 test esi, esi
// 0076b5b4  7cee                 jl 0x76b5a4
// 0076b5b6  3b772c               cmp esi, dword ptr [edi + 0x2c]
// 0076b5b9  7de9                 jge 0x76b5a4
// 0076b5bb  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0076b5be  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 0076b5c1  5f                   pop edi
// 0076b5c2  5e                   pop esi
// 0076b5c3  5d                   pop ebp
// 0076b5c4  5b                   pop ebx
// 0076b5c5  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?GetVisibleAt@CXTPControls@@QBEPAVCXTPControl@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
