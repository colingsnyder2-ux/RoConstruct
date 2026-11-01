// from server: 100% by auto
// roc 2010-06 00899710  unit: CXTCaptionButton  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899710
//
// 00899710  f644240804           test byte ptr [esp + 8], 4
// 00899715  56                   push esi
// 00899716  8bf1                 mov esi, ecx
// 00899718  7509                 jne 0x899723
// 0089971a  e851e8f0ff           call 0x7a7f70
// 0089971f  5e                   pop esi
// 00899720  c20800               ret 8
// 00899723  8b442408             mov eax, dword ptr [esp + 8]
// 00899727  50                   push eax
// 00899728  e83f360e00           call 0x97cd6c
// 0089972d  85c0                 test eax, eax
// 0089972f  740d                 je 0x89973e
// 00899731  8b16                 mov edx, dword ptr [esi]
// 00899733  50                   push eax
// 00899734  8b82a0010000         mov eax, dword ptr [edx + 0x1a0]
// 0089973a  8bce                 mov ecx, esi
// 0089973c  ffd0                 call eax
// 0089973e  b801000000           mov eax, 1
// 00899743  5e                   pop esi
// 00899744  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButton.cpp (function ?OnPrintClient@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButton.cpp
