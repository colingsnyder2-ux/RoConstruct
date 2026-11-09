// from server: 100% by auto
// roc 2010-06 00898e40  unit: CXTCaptionButtonTheme  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898e40
//
// 00898e40  53                   push ebx
// 00898e41  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00898e45  56                   push esi
// 00898e46  8bb3ac000000         mov esi, dword ptr [ebx + 0xac]
// 00898e4c  57                   push edi
// 00898e4d  8bf9                 mov edi, ecx
// 00898e4f  85f6                 test esi, esi
// 00898e51  7504                 jne 0x898e57
// 00898e53  33c0                 xor eax, eax
// 00898e55  eb03                 jmp 0x898e5a
// 00898e57  8b4620               mov eax, dword ptr [esi + 0x20]
// 00898e5a  50                   push eax
// 00898e5b  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00898e61  85c0                 test eax, eax
// 00898e63  740d                 je 0x898e72
// 00898e65  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00898e68  8b07                 mov eax, dword ptr [edi]
// 00898e6a  8b502c               mov edx, dword ptr [eax + 0x2c]
// 00898e6d  51                   push ecx
// 00898e6e  8bcf                 mov ecx, edi
// 00898e70  ffd2                 call edx
// 00898e72  8b442410             mov eax, dword ptr [esp + 0x10]
// 00898e76  53                   push ebx
// 00898e77  50                   push eax
// 00898e78  8bcf                 mov ecx, edi
// 00898e7a  e801030100           call 0x8a9180
// 00898e7f  5f                   pop edi
// 00898e80  5e                   pop esi
// 00898e81  5b                   pop ebx
// 00898e82  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
