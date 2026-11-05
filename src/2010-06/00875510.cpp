// from server: 100% by auto
// roc 2010-06 00875510  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875510
//
// 00875510  8b442404             mov eax, dword ptr [esp + 4]
// 00875514  8b10                 mov edx, dword ptr [eax]
// 00875516  53                   push ebx
// 00875517  56                   push esi
// 00875518  8b7004               mov esi, dword ptr [eax + 4]
// 0087551b  33db                 xor ebx, ebx
// 0087551d  81eeaf230000         sub esi, 0x23af
// 00875523  39b1580a0000         cmp dword ptr [ecx + 0xa58], esi
// 00875529  8bc8                 mov ecx, eax
// 0087552b  8b4204               mov eax, dword ptr [edx + 4]
// 0087552e  0f94c3               sete bl
// 00875531  53                   push ebx
// 00875532  ffd0                 call eax
// 00875534  5e                   pop esi
// 00875535  5b                   pop ebx
// 00875536  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonTool@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
