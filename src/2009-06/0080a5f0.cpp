// from server: 100% by auto
// roc 2009-06 0080a5f0  unit: CXTCaptionButtonThemeOffice2003  size: 363 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080a5f0
//
// 0080a5f0  83ec44               sub esp, 0x44
// 0080a5f3  53                   push ebx
// 0080a5f4  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0080a5f8  894c2404             mov dword ptr [esp + 4], ecx
// 0080a5fc  85db                 test ebx, ebx
// 0080a5fe  7504                 jne 0x80a604
// 0080a600  33c0                 xor eax, eax
// 0080a602  eb03                 jmp 0x80a607
// 0080a604  8b4320               mov eax, dword ptr [ebx + 0x20]
// 0080a607  50                   push eax
// 0080a608  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080a60e  85c0                 test eax, eax
// 0080a610  7507                 jne 0x80a619
// 0080a612  5b                   pop ebx
// 0080a613  83c444               add esp, 0x44
// 0080a616  c20800               ret 8
// 0080a619  55                   push ebp
// 0080a61a  56                   push esi
// 0080a61b  8b742454             mov esi, dword ptr [esp + 0x54]
// 0080a61f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0080a622  57                   push edi
// 0080a623  50                   push eax
// 0080a624  e8e3180400           call 0x84bf0c
// 0080a629  8d4e1c               lea ecx, [esi + 0x1c]
// 0080a62c  51                   push ecx
// 0080a62d  8d542418             lea edx, [esp + 0x18]
// 0080a631  52                   push edx
// 0080a632  8bf8                 mov edi, eax
// 0080a634  ff1500ee8900         call dword ptr [0x89ee00]
// 0080a63a  8babac000000         mov ebp, dword ptr [ebx + 0xac]
// 0080a640  8b4610               mov eax, dword ptr [esi + 0x10]
// 0080a643  8944245c             mov dword ptr [esp + 0x5c], eax
// 0080a647  85ed                 test ebp, ebp
// 0080a649  7504                 jne 0x80a64f
// 0080a64b  33c0                 xor eax, eax
// 0080a64d  eb03                 jmp 0x80a652
// 0080a64f  8b4520               mov eax, dword ptr [ebp + 0x20]
// 0080a652  50                   push eax
// 0080a653  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080a659  85c0                 test eax, eax
// 0080a65b  0f84e5000000         je 0x80a746
// 0080a661  83bba000000000       cmp dword ptr [ebx + 0xa0], 0
// 0080a668  750f                 jne 0x80a679
// 0080a66a  ff153cee8900         call dword ptr [0x89ee3c]
// 0080a670  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 0080a673  7404                 je 0x80a679
// 0080a675  33c9                 xor ecx, ecx
// 0080a677  eb05                 jmp 0x80a67e
// 0080a679  b901000000           mov ecx, 1
// 0080a67e  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0080a682  83e001               and eax, 1
// 0080a685  7557                 jne 0x80a6de
// 0080a687  85c9                 test ecx, ecx
// 0080a689  755f                 jne 0x80a6ea
// 0080a68b  53                   push ebx
// 0080a68c  8d4c2428             lea ecx, [esp + 0x28]
// 0080a690  e8db5df6ff           call 0x770470
// 0080a695  8d4c2434             lea ecx, [esp + 0x34]
// 0080a699  e83299f4ff           call 0x753fd0
// 0080a69e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080a6a2  8b11                 mov edx, dword ptr [ecx]
// 0080a6a4  8b527c               mov edx, dword ptr [edx + 0x7c]
// 0080a6a7  8d442434             lea eax, [esp + 0x34]
// 0080a6ab  50                   push eax
// 0080a6ac  55                   push ebp
// 0080a6ad  8d44242c             lea eax, [esp + 0x2c]
// 0080a6b1  50                   push eax
// 0080a6b2  ffd2                 call edx
// 0080a6b4  6a00                 push 0
// 0080a6b6  6a00                 push 0
// 0080a6b8  8d44243c             lea eax, [esp + 0x3c]
// 0080a6bc  50                   push eax
// 0080a6bd  8d4c2420             lea ecx, [esp + 0x20]
// 0080a6c1  51                   push ecx
// 0080a6c2  57                   push edi
// 0080a6c3  e8a87ef6ff           call 0x772570
// 0080a6c8  8bc8                 mov ecx, eax
// 0080a6ca  e8c181f6ff           call 0x772890
// 0080a6cf  5f                   pop edi
// 0080a6d0  5e                   pop esi
// 0080a6d1  5d                   pop ebp
// 0080a6d2  b801000000           mov eax, 1
// 0080a6d7  5b                   pop ebx
// 0080a6d8  83c444               add esp, 0x44
// 0080a6db  c20800               ret 8
// 0080a6de  e83da4f4ff           call 0x754b20
// 0080a6e3  0520010000           add eax, 0x120
// 0080a6e8  eb0a                 jmp 0x80a6f4
// 0080a6ea  e831a4f4ff           call 0x754b20
// 0080a6ef  0540010000           add eax, 0x140
// 0080a6f4  6a00                 push 0
// 0080a6f6  6a00                 push 0
// 0080a6f8  50                   push eax
// 0080a6f9  8d542420             lea edx, [esp + 0x20]
// 0080a6fd  52                   push edx
// 0080a6fe  57                   push edi
// 0080a6ff  e86c7ef6ff           call 0x772570
// 0080a704  8bc8                 mov ecx, eax
// 0080a706  e88581f6ff           call 0x772890
// 0080a70b  e810a4f4ff           call 0x754b20
// 0080a710  6a20                 push 0x20
// 0080a712  8bc8                 mov ecx, eax
// 0080a714  e8b79df4ff           call 0x7544d0
// 0080a719  8bf0                 mov esi, eax
// 0080a71b  e800a4f4ff           call 0x754b20
// 0080a720  56                   push esi
// 0080a721  6a20                 push 0x20
// 0080a723  8bc8                 mov ecx, eax
// 0080a725  e8a69df4ff           call 0x7544d0
// 0080a72a  50                   push eax
// 0080a72b  8d44241c             lea eax, [esp + 0x1c]
// 0080a72f  50                   push eax
// 0080a730  8bcf                 mov ecx, edi
// 0080a732  e893f0f0ff           call 0x7197ca
// 0080a737  5f                   pop edi
// 0080a738  5e                   pop esi
// 0080a739  5d                   pop ebp
// 0080a73a  b801000000           mov eax, 1
// 0080a73f  5b                   pop ebx
// 0080a740  83c444               add esp, 0x44
// 0080a743  c20800               ret 8
// 0080a746  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080a74a  53                   push ebx
// 0080a74b  56                   push esi
// 0080a74c  e85f030100           call 0x81aab0
// 0080a751  5f                   pop edi
// 0080a752  5e                   pop esi
// 0080a753  5d                   pop ebp
// 0080a754  5b                   pop ebx
// 0080a755  83c444               add esp, 0x44
// 0080a758  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonThemeOffice2003@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
