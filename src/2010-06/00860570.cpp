// from server: 100% by auto
// roc 2010-06 00860570  unit: CXTPDockingPaneWindowSelect  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00860570
//
// 00860570  56                   push esi
// 00860571  8b742408             mov esi, dword ptr [esp + 8]
// 00860575  57                   push edi
// 00860576  8bf9                 mov edi, ecx
// 00860578  85f6                 test esi, esi
// 0086057a  7d05                 jge 0x860581
// 0086057c  e8cb76f4ff           call 0x7a7c4c
// 00860581  3b7708               cmp esi, dword ptr [edi + 8]
// 00860584  7c0b                 jl 0x860591
// 00860586  6aff                 push -1
// 00860588  8d4601               lea eax, [esi + 1]
// 0086058b  50                   push eax
// 0086058c  e84f0ff8ff           call 0x7e14e0
// 00860591  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00860595  8b4704               mov eax, dword ptr [edi + 4]
// 00860598  8b11                 mov edx, dword ptr [ecx]
// 0086059a  8914f0               mov dword ptr [eax + esi*8], edx
// 0086059d  8b4904               mov ecx, dword ptr [ecx + 4]
// 008605a0  5f                   pop edi
// 008605a1  894cf004             mov dword ptr [eax + esi*8 + 4], ecx
// 008605a5  5e                   pop esi
// 008605a6  c20800               ret 8
// library xtp-13.2.1/Source\Calendar\XTPTopLevelWndMsgNotifier.cpp (function ?SetAtGrow@?$CArray@UCLIENT_INFO@CXTPTopLevelWndMsgNotifier@@AAU12@@@QAEXHAAUCLIENT_INFO@CXTPTopLevelWndMsgNotifier@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPTopLevelWndMsgNotifier.cpp
