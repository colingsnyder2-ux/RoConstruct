// from server: 100% by auto
// roc 2007-08 00714980  unit: CXTCaptionButton  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00714980
//
// 00714980  f644240804           test byte ptr [esp + 8], 4
// 00714985  56                   push esi
// 00714986  8bf1                 mov esi, ecx
// 00714988  7509                 jne 0x714993
// 0071498a  e8afb8f1ff           call 0x63023e
// 0071498f  5e                   pop esi
// 00714990  c20800               ret 8
// 00714993  8b442408             mov eax, dword ptr [esp + 8]
// 00714997  50                   push eax
// 00714998  e8213a0200           call 0x7383be
// 0071499d  85c0                 test eax, eax
// 0071499f  740d                 je 0x7149ae
// 007149a1  8b16                 mov edx, dword ptr [esi]
// 007149a3  50                   push eax
// 007149a4  8b8298010000         mov eax, dword ptr [edx + 0x198]
// 007149aa  8bce                 mov ecx, esi
// 007149ac  ffd0                 call eax
// 007149ae  b801000000           mov eax, 1
// 007149b3  5e                   pop esi
// 007149b4  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnPrintClient@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
