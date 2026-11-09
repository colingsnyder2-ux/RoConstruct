// from server: 100% by auto
// roc 2009-12 008e4b80  unit: CXTCaptionButtonTheme  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4b80
//
// 008e4b80  8b442408             mov eax, dword ptr [esp + 8]
// 008e4b84  56                   push esi
// 008e4b85  8bb0ac000000         mov esi, dword ptr [eax + 0xac]
// 008e4b8b  57                   push edi
// 008e4b8c  8bf9                 mov edi, ecx
// 008e4b8e  85f6                 test esi, esi
// 008e4b90  7504                 jne 0x8e4b96
// 008e4b92  33c0                 xor eax, eax
// 008e4b94  eb03                 jmp 0x8e4b99
// 008e4b96  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e4b99  50                   push eax
// 008e4b9a  ff1584cc9800         call dword ptr [0x98cc84]
// 008e4ba0  85c0                 test eax, eax
// 008e4ba2  7408                 je 0x8e4bac
// 008e4ba4  8b4678               mov eax, dword ptr [esi + 0x78]
// 008e4ba7  5f                   pop edi
// 008e4ba8  5e                   pop esi
// 008e4ba9  c20800               ret 8
// 008e4bac  8b4734               mov eax, dword ptr [edi + 0x34]
// 008e4baf  83f8ff               cmp eax, -1
// 008e4bb2  7503                 jne 0x8e4bb7
// 008e4bb4  8b4730               mov eax, dword ptr [edi + 0x30]
// 008e4bb7  5f                   pop edi
// 008e4bb8  5e                   pop esi
// 008e4bb9  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?GetTextColor@CXTCaptionButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
