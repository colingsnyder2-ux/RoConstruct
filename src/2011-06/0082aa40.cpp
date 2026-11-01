// from server: 100% by auto
// roc 2011-06 0082aa40  unit: CXTPCommandBarKeyboardTip  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082aa40
//
// 0082aa40  56                   push esi
// 0082aa41  8b742408             mov esi, dword ptr [esp + 8]
// 0082aa45  8b06                 mov eax, dword ptr [esi]
// 0082aa47  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0082aa4d  8bce                 mov ecx, esi
// 0082aa4f  ffd2                 call edx
// 0082aa51  8b4028               mov eax, dword ptr [eax + 0x28]
// 0082aa54  50                   push eax
// 0082aa55  e8ea1c1a00           call 0x9cc744
// 0082aa5a  50                   push eax
// 0082aa5b  e8dcf9fdff           call 0x80a43c
// 0082aa60  83c408               add esp, 8
// 0082aa63  85c0                 test eax, eax
// 0082aa65  745c                 je 0x82aac3
// 0082aa67  8bb6e8000000         mov esi, dword ptr [esi + 0xe8]
// 0082aa6d  85f6                 test esi, esi
// 0082aa6f  7454                 je 0x82aac5
// 0082aa71  397068               cmp dword ptr [eax + 0x68], esi
// 0082aa74  744f                 je 0x82aac5
// 0082aa76  e8a1f8fdff           call 0x80a31c
// 0082aa7b  8b4804               mov ecx, dword ptr [eax + 4]
// 0082aa7e  e8bb1c1a00           call 0x9cc73e
// 0082aa83  89442408             mov dword ptr [esp + 8], eax
// 0082aa87  85c0                 test eax, eax
// 0082aa89  7438                 je 0x82aac3
// 0082aa8b  eb03                 jmp 0x82aa90
// 0082aa8d  8d4900               lea ecx, [ecx]
// 0082aa90  e887f8fdff           call 0x80a31c
// 0082aa95  8b4004               mov eax, dword ptr [eax + 4]
// 0082aa98  8d4c2408             lea ecx, [esp + 8]
// 0082aa9c  51                   push ecx
// 0082aa9d  8bc8                 mov ecx, eax
// 0082aa9f  e8941c1a00           call 0x9cc738
// 0082aaa4  50                   push eax
// 0082aaa5  e89a1c1a00           call 0x9cc744
// 0082aaaa  50                   push eax
// 0082aaab  e88cf9fdff           call 0x80a43c
// 0082aab0  83c408               add esp, 8
// 0082aab3  85c0                 test eax, eax
// 0082aab5  7405                 je 0x82aabc
// 0082aab7  397068               cmp dword ptr [eax + 0x68], esi
// 0082aaba  7409                 je 0x82aac5
// 0082aabc  837c240800           cmp dword ptr [esp + 8], 0
// 0082aac1  75cd                 jne 0x82aa90
// 0082aac3  33c0                 xor eax, eax
// 0082aac5  5e                   pop esi
// 0082aac6  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?FindDocTemplate@CXTPCommandBars@@IAEPAVCDocTemplate@@PAVCMDIChildWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
