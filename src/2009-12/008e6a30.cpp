// from server: 100% by auto
// roc 2009-12 008e6a30  unit: CXTCaptionPopupWnd  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6a30
//
// 008e6a30  56                   push esi
// 008e6a31  8bf1                 mov esi, ecx
// 008e6a33  8b4658               mov eax, dword ptr [esi + 0x58]
// 008e6a36  57                   push edi
// 008e6a37  85c0                 test eax, eax
// 008e6a39  7403                 je 0x8e6a3e
// 008e6a3b  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e6a3e  8b3d84cc9800         mov edi, dword ptr [0x98cc84]
// 008e6a44  50                   push eax
// 008e6a45  ffd7                 call edi
// 008e6a47  85c0                 test eax, eax
// 008e6a49  7505                 jne 0x8e6a50
// 008e6a4b  5f                   pop edi
// 008e6a4c  33c0                 xor eax, eax
// 008e6a4e  5e                   pop esi
// 008e6a4f  c3                   ret 
// 008e6a50  8b465c               mov eax, dword ptr [esi + 0x5c]
// 008e6a53  85c0                 test eax, eax
// 008e6a55  7403                 je 0x8e6a5a
// 008e6a57  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e6a5a  50                   push eax
// 008e6a5b  ffd7                 call edi
// 008e6a5d  85c0                 test eax, eax
// 008e6a5f  74ea                 je 0x8e6a4b
// 008e6a61  8b465c               mov eax, dword ptr [esi + 0x5c]
// 008e6a64  8b7658               mov esi, dword ptr [esi + 0x58]
// 008e6a67  85c0                 test eax, eax
// 008e6a69  7403                 je 0x8e6a6e
// 008e6a6b  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e6a6e  50                   push eax
// 008e6a6f  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e6a72  50                   push eax
// 008e6a73  ff1538cb9800         call dword ptr [0x98cb38]
// 008e6a79  50                   push eax
// 008e6a7a  e8abd0f0ff           call 0x7f3b2a
// 008e6a7f  5f                   pop edi
// 008e6a80  b801000000           mov eax, 1
// 008e6a85  5e                   pop esi
// 008e6a86  c3                   ret 
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?ResetParent@CXTPCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
