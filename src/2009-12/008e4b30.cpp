// from server: 100% by auto
// roc 2009-12 008e4b30  unit: CXTCaptionButtonTheme  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4b30
//
// 008e4b30  53                   push ebx
// 008e4b31  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 008e4b35  56                   push esi
// 008e4b36  8bb3ac000000         mov esi, dword ptr [ebx + 0xac]
// 008e4b3c  57                   push edi
// 008e4b3d  8bf9                 mov edi, ecx
// 008e4b3f  85f6                 test esi, esi
// 008e4b41  7504                 jne 0x8e4b47
// 008e4b43  33c0                 xor eax, eax
// 008e4b45  eb03                 jmp 0x8e4b4a
// 008e4b47  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e4b4a  50                   push eax
// 008e4b4b  ff1584cc9800         call dword ptr [0x98cc84]
// 008e4b51  85c0                 test eax, eax
// 008e4b53  740d                 je 0x8e4b62
// 008e4b55  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 008e4b58  8b07                 mov eax, dword ptr [edi]
// 008e4b5a  8b502c               mov edx, dword ptr [eax + 0x2c]
// 008e4b5d  51                   push ecx
// 008e4b5e  8bcf                 mov ecx, edi
// 008e4b60  ffd2                 call edx
// 008e4b62  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e4b66  53                   push ebx
// 008e4b67  50                   push eax
// 008e4b68  8bcf                 mov ecx, edi
// 008e4b6a  e8b1040100           call 0x8f5020
// 008e4b6f  5f                   pop edi
// 008e4b70  5e                   pop esi
// 008e4b71  5b                   pop ebx
// 008e4b72  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
