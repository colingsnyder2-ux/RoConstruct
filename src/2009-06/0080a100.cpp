// from server: 100% by auto
// roc 2009-06 0080a100  unit: CXTCaptionButtonTheme  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080a100
//
// 0080a100  8b442408             mov eax, dword ptr [esp + 8]
// 0080a104  56                   push esi
// 0080a105  8bb0ac000000         mov esi, dword ptr [eax + 0xac]
// 0080a10b  57                   push edi
// 0080a10c  8bf9                 mov edi, ecx
// 0080a10e  85f6                 test esi, esi
// 0080a110  7504                 jne 0x80a116
// 0080a112  33c0                 xor eax, eax
// 0080a114  eb03                 jmp 0x80a119
// 0080a116  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080a119  50                   push eax
// 0080a11a  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080a120  85c0                 test eax, eax
// 0080a122  7408                 je 0x80a12c
// 0080a124  8b4678               mov eax, dword ptr [esi + 0x78]
// 0080a127  5f                   pop edi
// 0080a128  5e                   pop esi
// 0080a129  c20800               ret 8
// 0080a12c  8b4734               mov eax, dword ptr [edi + 0x34]
// 0080a12f  83f8ff               cmp eax, -1
// 0080a132  7503                 jne 0x80a137
// 0080a134  8b4730               mov eax, dword ptr [edi + 0x30]
// 0080a137  5f                   pop edi
// 0080a138  5e                   pop esi
// 0080a139  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?GetTextColor@CXTCaptionButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
