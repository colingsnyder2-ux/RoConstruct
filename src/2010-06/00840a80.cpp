// from server: 100% by auto
// roc 2010-06 00840a80  unit: CXTPHookManagerHookAble  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840a80
//
// 00840a80  56                   push esi
// 00840a81  8b711c               mov esi, dword ptr [ecx + 0x1c]
// 00840a84  57                   push edi
// 00840a85  85f6                 test esi, esi
// 00840a87  7438                 je 0x840ac1
// 00840a89  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00840a8d  8d4900               lea ecx, [ecx]
// 00840a90  8d54240c             lea edx, [esp + 0xc]
// 00840a94  52                   push edx
// 00840a95  8d542418             lea edx, [esp + 0x18]
// 00840a99  52                   push edx
// 00840a9a  8bc6                 mov eax, esi
// 00840a9c  8b4808               mov ecx, dword ptr [eax + 8]
// 00840a9f  8b7604               mov esi, dword ptr [esi + 4]
// 00840aa2  8d542418             lea edx, [esp + 0x18]
// 00840aa6  52                   push edx
// 00840aa7  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00840aaf  8b01                 mov eax, dword ptr [ecx]
// 00840ab1  8b4004               mov eax, dword ptr [eax + 4]
// 00840ab4  57                   push edi
// 00840ab5  6a00                 push 0
// 00840ab7  ffd0                 call eax
// 00840ab9  85c0                 test eax, eax
// 00840abb  750e                 jne 0x840acb
// 00840abd  85f6                 test esi, esi
// 00840abf  75cf                 jne 0x840a90
// 00840ac1  5f                   pop edi
// 00840ac2  b801000000           mov eax, 1
// 00840ac7  5e                   pop esi
// 00840ac8  c20c00               ret 0xc
// 00840acb  33c9                 xor ecx, ecx
// 00840acd  83f802               cmp eax, 2
// 00840ad0  0f95c1               setne cl
// 00840ad3  5f                   pop edi
// 00840ad4  5e                   pop esi
// 00840ad5  8bc1                 mov eax, ecx
// 00840ad7  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPKeyboardManager.cpp (function ?ProcessKeyboardHooks@CXTPKeyboardManager@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPKeyboardManager.cpp
