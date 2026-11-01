// from server: 100% by auto
// roc 2009-12 0088e570  unit: CXTPShortcutManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088e570
//
// 0088e570  56                   push esi
// 0088e571  8b742408             mov esi, dword ptr [esp + 8]
// 0088e575  57                   push edi
// 0088e576  8bf9                 mov edi, ecx
// 0088e578  85f6                 test esi, esi
// 0088e57a  7d05                 jge 0x88e581
// 0088e57c  e88b55f6ff           call 0x7f3b0c
// 0088e581  3b7708               cmp esi, dword ptr [edi + 8]
// 0088e584  7c0b                 jl 0x88e591
// 0088e586  6aff                 push -1
// 0088e588  8d4601               lea eax, [esi + 1]
// 0088e58b  50                   push eax
// 0088e58c  e87ffeffff           call 0x88e410
// 0088e591  8b5704               mov edx, dword ptr [edi + 4]
// 0088e594  8d0c76               lea ecx, [esi + esi*2]
// 0088e597  8d044a               lea eax, [edx + ecx*2]
// 0088e59a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088e59e  8b11                 mov edx, dword ptr [ecx]
// 0088e5a0  8910                 mov dword ptr [eax], edx
// 0088e5a2  668b4904             mov cx, word ptr [ecx + 4]
// 0088e5a6  5f                   pop edi
// 0088e5a7  66894804             mov word ptr [eax + 4], cx
// 0088e5ab  5e                   pop esi
// 0088e5ac  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetAtGrow@?$CArray@UtagACCEL@@AAU1@@@QAEXHAAUtagACCEL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
