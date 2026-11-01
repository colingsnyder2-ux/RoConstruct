// from server: 100% by auto
// roc 2009-12 008ac440  unit: CXTPDockingPaneWindowSelect  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ac440
//
// 008ac440  56                   push esi
// 008ac441  8b742408             mov esi, dword ptr [esp + 8]
// 008ac445  57                   push edi
// 008ac446  8bf9                 mov edi, ecx
// 008ac448  85f6                 test esi, esi
// 008ac44a  7d05                 jge 0x8ac451
// 008ac44c  e8bb76f4ff           call 0x7f3b0c
// 008ac451  3b7708               cmp esi, dword ptr [edi + 8]
// 008ac454  7c0b                 jl 0x8ac461
// 008ac456  6aff                 push -1
// 008ac458  8d4601               lea eax, [esi + 1]
// 008ac45b  50                   push eax
// 008ac45c  e8df0ef8ff           call 0x82d340
// 008ac461  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ac465  8b4704               mov eax, dword ptr [edi + 4]
// 008ac468  8b11                 mov edx, dword ptr [ecx]
// 008ac46a  8914f0               mov dword ptr [eax + esi*8], edx
// 008ac46d  8b4904               mov ecx, dword ptr [ecx + 4]
// 008ac470  5f                   pop edi
// 008ac471  894cf004             mov dword ptr [eax + esi*8 + 4], ecx
// 008ac475  5e                   pop esi
// 008ac476  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarMsgNotifier.cpp (function ?SetAtGrow@?$CArray@UCLIENT_INFO@CXTPCalendarMsgNotifier@@AAU12@@@QAEXHAAUCLIENT_INFO@CXTPCalendarMsgNotifier@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMsgNotifier.cpp
