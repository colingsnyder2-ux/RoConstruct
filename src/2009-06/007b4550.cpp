// from server: 100% by auto
// roc 2009-06 007b4550  unit: CXTPShortcutManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b4550
//
// 007b4550  56                   push esi
// 007b4551  8b742408             mov esi, dword ptr [esp + 8]
// 007b4555  57                   push edi
// 007b4556  8bf9                 mov edi, ecx
// 007b4558  85f6                 test esi, esi
// 007b455a  7d05                 jge 0x7b4561
// 007b455c  e88347f6ff           call 0x718ce4
// 007b4561  3b7708               cmp esi, dword ptr [edi + 8]
// 007b4564  7c0b                 jl 0x7b4571
// 007b4566  6aff                 push -1
// 007b4568  8d4601               lea eax, [esi + 1]
// 007b456b  50                   push eax
// 007b456c  e87ffeffff           call 0x7b43f0
// 007b4571  8b5704               mov edx, dword ptr [edi + 4]
// 007b4574  8d0c76               lea ecx, [esi + esi*2]
// 007b4577  8d044a               lea eax, [edx + ecx*2]
// 007b457a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007b457e  8b11                 mov edx, dword ptr [ecx]
// 007b4580  8910                 mov dword ptr [eax], edx
// 007b4582  668b4904             mov cx, word ptr [ecx + 4]
// 007b4586  5f                   pop edi
// 007b4587  66894804             mov word ptr [eax + 4], cx
// 007b458b  5e                   pop esi
// 007b458c  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetAtGrow@?$CArray@UtagACCEL@@AAU1@@@QAEXHAAUtagACCEL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
