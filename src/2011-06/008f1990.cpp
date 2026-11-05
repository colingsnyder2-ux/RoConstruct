// from server: 100% by auto
// roc 2011-06 008f1990  unit: CXTCaptionButtonTheme  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f1990
//
// 008f1990  53                   push ebx
// 008f1991  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 008f1995  56                   push esi
// 008f1996  8bb3ac000000         mov esi, dword ptr [ebx + 0xac]
// 008f199c  57                   push edi
// 008f199d  8bf9                 mov edi, ecx
// 008f199f  85f6                 test esi, esi
// 008f19a1  7504                 jne 0x8f19a7
// 008f19a3  33c0                 xor eax, eax
// 008f19a5  eb03                 jmp 0x8f19aa
// 008f19a7  8b4620               mov eax, dword ptr [esi + 0x20]
// 008f19aa  50                   push eax
// 008f19ab  ff15ec1ba400         call dword ptr [0xa41bec]
// 008f19b1  85c0                 test eax, eax
// 008f19b3  740d                 je 0x8f19c2
// 008f19b5  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 008f19b8  8b07                 mov eax, dword ptr [edi]
// 008f19ba  8b502c               mov edx, dword ptr [eax + 0x2c]
// 008f19bd  51                   push ecx
// 008f19be  8bcf                 mov ecx, edi
// 008f19c0  ffd2                 call edx
// 008f19c2  8b442410             mov eax, dword ptr [esp + 0x10]
// 008f19c6  53                   push ebx
// 008f19c7  50                   push eax
// 008f19c8  8bcf                 mov ecx, edi
// 008f19ca  e8710e0100           call 0x902840
// 008f19cf  5f                   pop edi
// 008f19d0  5e                   pop esi
// 008f19d1  5b                   pop ebx
// 008f19d2  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
