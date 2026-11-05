// from server: 100% by auto
// roc 2010-06 0089ad50  unit: CXTCaptionPopupWnd  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089ad50
//
// 0089ad50  56                   push esi
// 0089ad51  8bf1                 mov esi, ecx
// 0089ad53  8b4658               mov eax, dword ptr [esi + 0x58]
// 0089ad56  57                   push edi
// 0089ad57  85c0                 test eax, eax
// 0089ad59  7403                 je 0x89ad5e
// 0089ad5b  8b4020               mov eax, dword ptr [eax + 0x20]
// 0089ad5e  8b3d28bc9e00         mov edi, dword ptr [0x9ebc28]
// 0089ad64  50                   push eax
// 0089ad65  ffd7                 call edi
// 0089ad67  85c0                 test eax, eax
// 0089ad69  7505                 jne 0x89ad70
// 0089ad6b  5f                   pop edi
// 0089ad6c  33c0                 xor eax, eax
// 0089ad6e  5e                   pop esi
// 0089ad6f  c3                   ret 
// 0089ad70  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0089ad73  85c0                 test eax, eax
// 0089ad75  7403                 je 0x89ad7a
// 0089ad77  8b4020               mov eax, dword ptr [eax + 0x20]
// 0089ad7a  50                   push eax
// 0089ad7b  ffd7                 call edi
// 0089ad7d  85c0                 test eax, eax
// 0089ad7f  74ea                 je 0x89ad6b
// 0089ad81  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0089ad84  8b7658               mov esi, dword ptr [esi + 0x58]
// 0089ad87  85c0                 test eax, eax
// 0089ad89  7403                 je 0x89ad8e
// 0089ad8b  8b4020               mov eax, dword ptr [eax + 0x20]
// 0089ad8e  50                   push eax
// 0089ad8f  8b4620               mov eax, dword ptr [esi + 0x20]
// 0089ad92  50                   push eax
// 0089ad93  ff15f0b99e00         call dword ptr [0x9eb9f0]
// 0089ad99  50                   push eax
// 0089ad9a  e8cbcef0ff           call 0x7a7c6a
// 0089ad9f  5f                   pop edi
// 0089ada0  b801000000           mov eax, 1
// 0089ada5  5e                   pop esi
// 0089ada6  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?ResetParent@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
