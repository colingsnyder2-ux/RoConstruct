// from server: 100% by auto
// roc 2009-06 0080bf40  unit: CXTCaptionPopupWnd  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080bf40
//
// 0080bf40  56                   push esi
// 0080bf41  8bf1                 mov esi, ecx
// 0080bf43  8b4658               mov eax, dword ptr [esi + 0x58]
// 0080bf46  57                   push edi
// 0080bf47  85c0                 test eax, eax
// 0080bf49  7403                 je 0x80bf4e
// 0080bf4b  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080bf4e  8b3de0ed8900         mov edi, dword ptr [0x89ede0]
// 0080bf54  50                   push eax
// 0080bf55  ffd7                 call edi
// 0080bf57  85c0                 test eax, eax
// 0080bf59  7505                 jne 0x80bf60
// 0080bf5b  5f                   pop edi
// 0080bf5c  33c0                 xor eax, eax
// 0080bf5e  5e                   pop esi
// 0080bf5f  c3                   ret 
// 0080bf60  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0080bf63  85c0                 test eax, eax
// 0080bf65  7403                 je 0x80bf6a
// 0080bf67  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080bf6a  50                   push eax
// 0080bf6b  ffd7                 call edi
// 0080bf6d  85c0                 test eax, eax
// 0080bf6f  74ea                 je 0x80bf5b
// 0080bf71  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0080bf74  8b7658               mov esi, dword ptr [esi + 0x58]
// 0080bf77  85c0                 test eax, eax
// 0080bf79  7403                 je 0x80bf7e
// 0080bf7b  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080bf7e  50                   push eax
// 0080bf7f  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080bf82  50                   push eax
// 0080bf83  ff15a0ec8900         call dword ptr [0x89eca0]
// 0080bf89  50                   push eax
// 0080bf8a  e873cdf0ff           call 0x718d02
// 0080bf8f  5f                   pop edi
// 0080bf90  b801000000           mov eax, 1
// 0080bf95  5e                   pop esi
// 0080bf96  c3                   ret 
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?ResetParent@CXTPCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
