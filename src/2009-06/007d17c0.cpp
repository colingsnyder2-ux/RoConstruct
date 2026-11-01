// from server: 100% by auto
// roc 2009-06 007d17c0  unit: CXTPDockingPaneWindowSelect  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d17c0
//
// 007d17c0  56                   push esi
// 007d17c1  8b742408             mov esi, dword ptr [esp + 8]
// 007d17c5  57                   push edi
// 007d17c6  8bf9                 mov edi, ecx
// 007d17c8  85f6                 test esi, esi
// 007d17ca  7d05                 jge 0x7d17d1
// 007d17cc  e81375f4ff           call 0x718ce4
// 007d17d1  3b7708               cmp esi, dword ptr [edi + 8]
// 007d17d4  7c0b                 jl 0x7d17e1
// 007d17d6  6aff                 push -1
// 007d17d8  8d4601               lea eax, [esi + 1]
// 007d17db  50                   push eax
// 007d17dc  e87ffeffff           call 0x7d1660
// 007d17e1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d17e5  8b4704               mov eax, dword ptr [edi + 4]
// 007d17e8  8b11                 mov edx, dword ptr [ecx]
// 007d17ea  8914f0               mov dword ptr [eax + esi*8], edx
// 007d17ed  8b4904               mov ecx, dword ptr [ecx + 4]
// 007d17f0  5f                   pop edi
// 007d17f1  894cf004             mov dword ptr [eax + esi*8 + 4], ecx
// 007d17f5  5e                   pop esi
// 007d17f6  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarMsgNotifier.cpp (function ?SetAtGrow@?$CArray@UCLIENT_INFO@CXTPCalendarMsgNotifier@@AAU12@@@QAEXHAAUCLIENT_INFO@CXTPCalendarMsgNotifier@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarMsgNotifier.cpp
