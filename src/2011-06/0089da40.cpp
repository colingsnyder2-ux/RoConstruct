// from server: 100% by auto
// roc 2011-06 0089da40  unit: CXTPHookManagerHookAble  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089da40
//
// 0089da40  56                   push esi
// 0089da41  8b711c               mov esi, dword ptr [ecx + 0x1c]
// 0089da44  57                   push edi
// 0089da45  85f6                 test esi, esi
// 0089da47  7438                 je 0x89da81
// 0089da49  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089da4d  8d4900               lea ecx, [ecx]
// 0089da50  8d54240c             lea edx, [esp + 0xc]
// 0089da54  52                   push edx
// 0089da55  8d542418             lea edx, [esp + 0x18]
// 0089da59  52                   push edx
// 0089da5a  8bc6                 mov eax, esi
// 0089da5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0089da5f  8b7604               mov esi, dword ptr [esi + 4]
// 0089da62  8d542418             lea edx, [esp + 0x18]
// 0089da66  52                   push edx
// 0089da67  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0089da6f  8b01                 mov eax, dword ptr [ecx]
// 0089da71  8b4004               mov eax, dword ptr [eax + 4]
// 0089da74  57                   push edi
// 0089da75  6a00                 push 0
// 0089da77  ffd0                 call eax
// 0089da79  85c0                 test eax, eax
// 0089da7b  750e                 jne 0x89da8b
// 0089da7d  85f6                 test esi, esi
// 0089da7f  75cf                 jne 0x89da50
// 0089da81  5f                   pop edi
// 0089da82  b801000000           mov eax, 1
// 0089da87  5e                   pop esi
// 0089da88  c20c00               ret 0xc
// 0089da8b  33c9                 xor ecx, ecx
// 0089da8d  83f802               cmp eax, 2
// 0089da90  0f95c1               setne cl
// 0089da93  5f                   pop edi
// 0089da94  5e                   pop esi
// 0089da95  8bc1                 mov eax, ecx
// 0089da97  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPKeyboardManager.cpp (function ?ProcessKeyboardHooks@CXTPKeyboardManager@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPKeyboardManager.cpp
