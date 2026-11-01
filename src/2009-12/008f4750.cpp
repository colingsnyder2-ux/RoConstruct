// from server: 100% by auto
// roc 2009-12 008f4750  unit: CXTCaptionButtonTheme  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f4750
//
// 008f4750  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 008f4753  85c0                 test eax, eax
// 008f4755  7406                 je 0x8f475d
// 008f4757  83780400             cmp dword ptr [eax + 4], 0
// 008f475b  7523                 jne 0x8f4780
// 008f475d  8b442404             mov eax, dword ptr [esp + 4]
// 008f4761  85c0                 test eax, eax
// 008f4763  7419                 je 0x8f477e
// 008f4765  8b4020               mov eax, dword ptr [eax + 0x20]
// 008f4768  6a00                 push 0
// 008f476a  6a00                 push 0
// 008f476c  6a31                 push 0x31
// 008f476e  50                   push eax
// 008f476f  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008f4775  89442404             mov dword ptr [esp + 4], eax
// 008f4779  e9e6fbefff           jmp 0x7f4364
// 008f477e  33c0                 xor eax, eax
// 008f4780  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetThemeFont@CXTButtonTheme@@UBEPAVCFont@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
