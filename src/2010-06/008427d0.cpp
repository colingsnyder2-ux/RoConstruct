// from server: 100% by auto
// roc 2010-06 008427d0  unit: CXTPShortcutManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008427d0
//
// 008427d0  56                   push esi
// 008427d1  8b742408             mov esi, dword ptr [esp + 8]
// 008427d5  57                   push edi
// 008427d6  8bf9                 mov edi, ecx
// 008427d8  85f6                 test esi, esi
// 008427da  7d05                 jge 0x8427e1
// 008427dc  e86b54f6ff           call 0x7a7c4c
// 008427e1  3b7708               cmp esi, dword ptr [edi + 8]
// 008427e4  7c0b                 jl 0x8427f1
// 008427e6  6aff                 push -1
// 008427e8  8d4601               lea eax, [esi + 1]
// 008427eb  50                   push eax
// 008427ec  e87ffeffff           call 0x842670
// 008427f1  8b5704               mov edx, dword ptr [edi + 4]
// 008427f4  8d0c76               lea ecx, [esi + esi*2]
// 008427f7  8d044a               lea eax, [edx + ecx*2]
// 008427fa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008427fe  8b11                 mov edx, dword ptr [ecx]
// 00842800  8910                 mov dword ptr [eax], edx
// 00842802  668b4904             mov cx, word ptr [ecx + 4]
// 00842806  5f                   pop edi
// 00842807  66894804             mov word ptr [eax + 4], cx
// 0084280b  5e                   pop esi
// 0084280c  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetAtGrow@?$CArray@UtagACCEL@@AAU1@@@QAEXHAAUtagACCEL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPShortcutManager.cpp
