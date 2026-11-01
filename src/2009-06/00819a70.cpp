// from server: 100% by auto
// roc 2009-06 00819a70  unit: CXTCaptionButtonTheme  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819a70
//
// 00819a70  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 00819a73  85c0                 test eax, eax
// 00819a75  7406                 je 0x819a7d
// 00819a77  83780400             cmp dword ptr [eax + 4], 0
// 00819a7b  7523                 jne 0x819aa0
// 00819a7d  8b442404             mov eax, dword ptr [esp + 4]
// 00819a81  85c0                 test eax, eax
// 00819a83  7419                 je 0x819a9e
// 00819a85  8b4020               mov eax, dword ptr [eax + 0x20]
// 00819a88  6a00                 push 0
// 00819a8a  6a00                 push 0
// 00819a8c  6a31                 push 0x31
// 00819a8e  50                   push eax
// 00819a8f  ff1590ee8900         call dword ptr [0x89ee90]
// 00819a95  89442404             mov dword ptr [esp + 4], eax
// 00819a99  e998faefff           jmp 0x719536
// 00819a9e  33c0                 xor eax, eax
// 00819aa0  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetThemeFont@CXTButtonTheme@@UBEPAVCFont@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
