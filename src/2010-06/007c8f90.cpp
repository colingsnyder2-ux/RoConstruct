// from server: 100% by auto
// roc 2010-06 007c8f90  unit: CXTPCommandBarKeyboardTip  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8f90
//
// 007c8f90  56                   push esi
// 007c8f91  8b742408             mov esi, dword ptr [esp + 8]
// 007c8f95  8b06                 mov eax, dword ptr [esi]
// 007c8f97  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 007c8f9d  8bce                 mov ecx, esi
// 007c8f9f  ffd2                 call edx
// 007c8fa1  8b4028               mov eax, dword ptr [eax + 0x28]
// 007c8fa4  50                   push eax
// 007c8fa5  e8783f1b00           call 0x97cf22
// 007c8faa  50                   push eax
// 007c8fab  e8ceedfdff           call 0x7a7d7e
// 007c8fb0  83c408               add esp, 8
// 007c8fb3  85c0                 test eax, eax
// 007c8fb5  745c                 je 0x7c9013
// 007c8fb7  8bb6e8000000         mov esi, dword ptr [esi + 0xe8]
// 007c8fbd  85f6                 test esi, esi
// 007c8fbf  7454                 je 0x7c9015
// 007c8fc1  397068               cmp dword ptr [eax + 0x68], esi
// 007c8fc4  744f                 je 0x7c9015
// 007c8fc6  e893ecfdff           call 0x7a7c5e
// 007c8fcb  8b4804               mov ecx, dword ptr [eax + 4]
// 007c8fce  e8493f1b00           call 0x97cf1c
// 007c8fd3  89442408             mov dword ptr [esp + 8], eax
// 007c8fd7  85c0                 test eax, eax
// 007c8fd9  7438                 je 0x7c9013
// 007c8fdb  eb03                 jmp 0x7c8fe0
// 007c8fdd  8d4900               lea ecx, [ecx]
// 007c8fe0  e879ecfdff           call 0x7a7c5e
// 007c8fe5  8b4004               mov eax, dword ptr [eax + 4]
// 007c8fe8  8d4c2408             lea ecx, [esp + 8]
// 007c8fec  51                   push ecx
// 007c8fed  8bc8                 mov ecx, eax
// 007c8fef  e8223f1b00           call 0x97cf16
// 007c8ff4  50                   push eax
// 007c8ff5  e8283f1b00           call 0x97cf22
// 007c8ffa  50                   push eax
// 007c8ffb  e87eedfdff           call 0x7a7d7e
// 007c9000  83c408               add esp, 8
// 007c9003  85c0                 test eax, eax
// 007c9005  7405                 je 0x7c900c
// 007c9007  397068               cmp dword ptr [eax + 0x68], esi
// 007c900a  7409                 je 0x7c9015
// 007c900c  837c240800           cmp dword ptr [esp + 8], 0
// 007c9011  75cd                 jne 0x7c8fe0
// 007c9013  33c0                 xor eax, eax
// 007c9015  5e                   pop esi
// 007c9016  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?FindDocTemplate@CXTPCommandBars@@IAEPAVCDocTemplate@@PAVCMDIChildWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
