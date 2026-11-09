// from server: 100% by auto
// roc 2010-06 008a88b0  unit: CXTCaptionButtonTheme  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a88b0
//
// 008a88b0  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 008a88b3  85c0                 test eax, eax
// 008a88b5  7406                 je 0x8a88bd
// 008a88b7  83780400             cmp dword ptr [eax + 4], 0
// 008a88bb  7523                 jne 0x8a88e0
// 008a88bd  8b442404             mov eax, dword ptr [esp + 4]
// 008a88c1  85c0                 test eax, eax
// 008a88c3  7419                 je 0x8a88de
// 008a88c5  8b4020               mov eax, dword ptr [eax + 0x20]
// 008a88c8  6a00                 push 0
// 008a88ca  6a00                 push 0
// 008a88cc  6a31                 push 0x31
// 008a88ce  50                   push eax
// 008a88cf  ff1554ba9e00         call dword ptr [0x9eba54]
// 008a88d5  89442404             mov dword ptr [esp + 4], eax
// 008a88d9  e9c6fbefff           jmp 0x7a84a4
// 008a88de  33c0                 xor eax, eax
// 008a88e0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetThemeFont@CXTButtonTheme@@UBEPAVCFont@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
