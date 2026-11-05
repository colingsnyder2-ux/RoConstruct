// from server: 100% by auto
// roc 2010-06 008a8290  unit: CXTCaptionButtonTheme  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a8290
//
// 008a8290  56                   push esi
// 008a8291  8bf1                 mov esi, ecx
// 008a8293  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a8297  85c9                 test ecx, ecx
// 008a8299  7442                 je 0x8a82dd
// 008a829b  8b01                 mov eax, dword ptr [ecx]
// 008a829d  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008a82a3  ffd2                 call edx
// 008a82a5  a900100000           test eax, 0x1000
// 008a82aa  7431                 je 0x8a82dd
// 008a82ac  83c674               add esi, 0x74
// 008a82af  8bce                 mov ecx, esi
// 008a82b1  e8ea7af7ff           call 0x81fda0
// 008a82b6  85c0                 test eax, eax
// 008a82b8  750d                 jne 0x8a82c7
// 008a82ba  68845da500           push 0xa55d84
// 008a82bf  50                   push eax
// 008a82c0  8bce                 mov ecx, esi
// 008a82c2  e8397af7ff           call 0x81fd00
// 008a82c7  8bce                 mov ecx, esi
// 008a82c9  e8e27af7ff           call 0x81fdb0
// 008a82ce  85c0                 test eax, eax
// 008a82d0  740b                 je 0x8a82dd
// 008a82d2  8bce                 mov ecx, esi
// 008a82d4  e8c77af7ff           call 0x81fda0
// 008a82d9  5e                   pop esi
// 008a82da  c20400               ret 4
// 008a82dd  33c0                 xor eax, eax
// 008a82df  5e                   pop esi
// 008a82e0  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButtonTheme.cpp (function ?UseWinXPThemes@CXTButtonTheme@@UAEHPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButtonTheme.cpp
