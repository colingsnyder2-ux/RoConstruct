// from server: 100% by auto
// roc 2007-08 00715230  unit: CXTCaptionButton  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00715230
//
// 00715230  56                   push esi
// 00715231  8bf1                 mov esi, ecx
// 00715233  e806b0f1ff           call 0x63023e
// 00715238  83f8ff               cmp eax, -1
// 0071523b  7506                 jne 0x715243
// 0071523d  0bc0                 or eax, eax
// 0071523f  5e                   pop esi
// 00715240  c20400               ret 4
// 00715243  8b06                 mov eax, dword ptr [esi]
// 00715245  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0071524b  8bce                 mov ecx, esi
// 0071524d  ffd2                 call edx
// 0071524f  33c0                 xor eax, eax
// 00715251  5e                   pop esi
// 00715252  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnCreate@CXTButton@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
