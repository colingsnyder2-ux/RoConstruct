// from server: 100% by auto
// roc 2011-06 008f19e0  unit: CXTCaptionButtonTheme  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f19e0
//
// 008f19e0  8b442408             mov eax, dword ptr [esp + 8]
// 008f19e4  56                   push esi
// 008f19e5  8bb0ac000000         mov esi, dword ptr [eax + 0xac]
// 008f19eb  57                   push edi
// 008f19ec  8bf9                 mov edi, ecx
// 008f19ee  85f6                 test esi, esi
// 008f19f0  7504                 jne 0x8f19f6
// 008f19f2  33c0                 xor eax, eax
// 008f19f4  eb03                 jmp 0x8f19f9
// 008f19f6  8b4620               mov eax, dword ptr [esi + 0x20]
// 008f19f9  50                   push eax
// 008f19fa  ff15ec1ba400         call dword ptr [0xa41bec]
// 008f1a00  85c0                 test eax, eax
// 008f1a02  7408                 je 0x8f1a0c
// 008f1a04  8b4678               mov eax, dword ptr [esi + 0x78]
// 008f1a07  5f                   pop edi
// 008f1a08  5e                   pop esi
// 008f1a09  c20800               ret 8
// 008f1a0c  8b4734               mov eax, dword ptr [edi + 0x34]
// 008f1a0f  83f8ff               cmp eax, -1
// 008f1a12  7503                 jne 0x8f1a17
// 008f1a14  8b4730               mov eax, dword ptr [edi + 0x30]
// 008f1a17  5f                   pop edi
// 008f1a18  5e                   pop esi
// 008f1a19  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?GetTextColor@CXTCaptionButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
