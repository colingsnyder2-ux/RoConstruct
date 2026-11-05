// from server: 100% by auto
// roc 2010-06 00898e90  unit: CXTCaptionButtonTheme  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898e90
//
// 00898e90  8b442408             mov eax, dword ptr [esp + 8]
// 00898e94  56                   push esi
// 00898e95  8bb0ac000000         mov esi, dword ptr [eax + 0xac]
// 00898e9b  57                   push edi
// 00898e9c  8bf9                 mov edi, ecx
// 00898e9e  85f6                 test esi, esi
// 00898ea0  7504                 jne 0x898ea6
// 00898ea2  33c0                 xor eax, eax
// 00898ea4  eb03                 jmp 0x898ea9
// 00898ea6  8b4620               mov eax, dword ptr [esi + 0x20]
// 00898ea9  50                   push eax
// 00898eaa  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00898eb0  85c0                 test eax, eax
// 00898eb2  7408                 je 0x898ebc
// 00898eb4  8b4678               mov eax, dword ptr [esi + 0x78]
// 00898eb7  5f                   pop edi
// 00898eb8  5e                   pop esi
// 00898eb9  c20800               ret 8
// 00898ebc  8b4734               mov eax, dword ptr [edi + 0x34]
// 00898ebf  83f8ff               cmp eax, -1
// 00898ec2  7503                 jne 0x898ec7
// 00898ec4  8b4730               mov eax, dword ptr [edi + 0x30]
// 00898ec7  5f                   pop edi
// 00898ec8  5e                   pop esi
// 00898ec9  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?GetTextColor@CXTCaptionButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
