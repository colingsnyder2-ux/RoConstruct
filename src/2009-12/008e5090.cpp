// from server: 100% by auto
// roc 2009-12 008e5090  unit: CXTCaptionButtonThemeOffice2003  size: 363 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5090
//
// 008e5090  83ec44               sub esp, 0x44
// 008e5093  53                   push ebx
// 008e5094  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 008e5098  894c2404             mov dword ptr [esp + 4], ecx
// 008e509c  85db                 test ebx, ebx
// 008e509e  7504                 jne 0x8e50a4
// 008e50a0  33c0                 xor eax, eax
// 008e50a2  eb03                 jmp 0x8e50a7
// 008e50a4  8b4320               mov eax, dword ptr [ebx + 0x20]
// 008e50a7  50                   push eax
// 008e50a8  ff1584cc9800         call dword ptr [0x98cc84]
// 008e50ae  85c0                 test eax, eax
// 008e50b0  7507                 jne 0x8e50b9
// 008e50b2  5b                   pop ebx
// 008e50b3  83c444               add esp, 0x44
// 008e50b6  c20800               ret 8
// 008e50b9  55                   push ebp
// 008e50ba  56                   push esi
// 008e50bb  8b742454             mov esi, dword ptr [esp + 0x54]
// 008e50bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e50c2  57                   push edi
// 008e50c3  50                   push eax
// 008e50c4  e867130400           call 0x926430
// 008e50c9  8d4e1c               lea ecx, [esi + 0x1c]
// 008e50cc  51                   push ecx
// 008e50cd  8d542418             lea edx, [esp + 0x18]
// 008e50d1  52                   push edx
// 008e50d2  8bf8                 mov edi, eax
// 008e50d4  ff1564cc9800         call dword ptr [0x98cc64]
// 008e50da  8babac000000         mov ebp, dword ptr [ebx + 0xac]
// 008e50e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008e50e3  8944245c             mov dword ptr [esp + 0x5c], eax
// 008e50e7  85ed                 test ebp, ebp
// 008e50e9  7504                 jne 0x8e50ef
// 008e50eb  33c0                 xor eax, eax
// 008e50ed  eb03                 jmp 0x8e50f2
// 008e50ef  8b4520               mov eax, dword ptr [ebp + 0x20]
// 008e50f2  50                   push eax
// 008e50f3  ff1584cc9800         call dword ptr [0x98cc84]
// 008e50f9  85c0                 test eax, eax
// 008e50fb  0f84e5000000         je 0x8e51e6
// 008e5101  83bba000000000       cmp dword ptr [ebx + 0xa0], 0
// 008e5108  750f                 jne 0x8e5119
// 008e510a  ff1528cc9800         call dword ptr [0x98cc28]
// 008e5110  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 008e5113  7404                 je 0x8e5119
// 008e5115  33c9                 xor ecx, ecx
// 008e5117  eb05                 jmp 0x8e511e
// 008e5119  b901000000           mov ecx, 1
// 008e511e  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 008e5122  83e001               and eax, 1
// 008e5125  7557                 jne 0x8e517e
// 008e5127  85c9                 test ecx, ecx
// 008e5129  755f                 jne 0x8e518a
// 008e512b  53                   push ebx
// 008e512c  8d4c2428             lea ecx, [esp + 0x28]
// 008e5130  e83b61f6ff           call 0x84b270
// 008e5135  8d4c2434             lea ecx, [esp + 0x34]
// 008e5139  e8f29cf4ff           call 0x82ee30
// 008e513e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e5142  8b11                 mov edx, dword ptr [ecx]
// 008e5144  8b527c               mov edx, dword ptr [edx + 0x7c]
// 008e5147  8d442434             lea eax, [esp + 0x34]
// 008e514b  50                   push eax
// 008e514c  55                   push ebp
// 008e514d  8d44242c             lea eax, [esp + 0x2c]
// 008e5151  50                   push eax
// 008e5152  ffd2                 call edx
// 008e5154  6a00                 push 0
// 008e5156  6a00                 push 0
// 008e5158  8d44243c             lea eax, [esp + 0x3c]
// 008e515c  50                   push eax
// 008e515d  8d4c2420             lea ecx, [esp + 0x20]
// 008e5161  51                   push ecx
// 008e5162  57                   push edi
// 008e5163  e83881f6ff           call 0x84d2a0
// 008e5168  8bc8                 mov ecx, eax
// 008e516a  e85184f6ff           call 0x84d5c0
// 008e516f  5f                   pop edi
// 008e5170  5e                   pop esi
// 008e5171  5d                   pop ebp
// 008e5172  b801000000           mov eax, 1
// 008e5177  5b                   pop ebx
// 008e5178  83c444               add esp, 0x44
// 008e517b  c20800               ret 8
// 008e517e  e84da8f4ff           call 0x82f9d0
// 008e5183  0520010000           add eax, 0x120
// 008e5188  eb0a                 jmp 0x8e5194
// 008e518a  e841a8f4ff           call 0x82f9d0
// 008e518f  0540010000           add eax, 0x140
// 008e5194  6a00                 push 0
// 008e5196  6a00                 push 0
// 008e5198  50                   push eax
// 008e5199  8d542420             lea edx, [esp + 0x20]
// 008e519d  52                   push edx
// 008e519e  57                   push edi
// 008e519f  e8fc80f6ff           call 0x84d2a0
// 008e51a4  8bc8                 mov ecx, eax
// 008e51a6  e81584f6ff           call 0x84d5c0
// 008e51ab  e820a8f4ff           call 0x82f9d0
// 008e51b0  6a20                 push 0x20
// 008e51b2  8bc8                 mov ecx, eax
// 008e51b4  e877a1f4ff           call 0x82f330
// 008e51b9  8bf0                 mov esi, eax
// 008e51bb  e810a8f4ff           call 0x82f9d0
// 008e51c0  56                   push esi
// 008e51c1  6a20                 push 0x20
// 008e51c3  8bc8                 mov ecx, eax
// 008e51c5  e866a1f4ff           call 0x82f330
// 008e51ca  50                   push eax
// 008e51cb  8d44241c             lea eax, [esp + 0x1c]
// 008e51cf  50                   push eax
// 008e51d0  8bcf                 mov ecx, edi
// 008e51d2  e821f4f0ff           call 0x7f45f8
// 008e51d7  5f                   pop edi
// 008e51d8  5e                   pop esi
// 008e51d9  5d                   pop ebp
// 008e51da  b801000000           mov eax, 1
// 008e51df  5b                   pop ebx
// 008e51e0  83c444               add esp, 0x44
// 008e51e3  c20800               ret 8
// 008e51e6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e51ea  53                   push ebx
// 008e51eb  56                   push esi
// 008e51ec  e89f050100           call 0x8f5790
// 008e51f1  5f                   pop edi
// 008e51f2  5e                   pop esi
// 008e51f3  5d                   pop ebp
// 008e51f4  5b                   pop ebx
// 008e51f5  83c444               add esp, 0x44
// 008e51f8  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonThemeOffice2003@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
