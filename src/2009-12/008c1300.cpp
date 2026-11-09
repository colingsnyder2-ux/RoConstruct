// from server: 100% by auto
// roc 2009-12 008c1300  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1300
//
// 008c1300  8b442404             mov eax, dword ptr [esp + 4]
// 008c1304  8b10                 mov edx, dword ptr [eax]
// 008c1306  53                   push ebx
// 008c1307  56                   push esi
// 008c1308  8b7004               mov esi, dword ptr [eax + 4]
// 008c130b  33db                 xor ebx, ebx
// 008c130d  81eeaf230000         sub esi, 0x23af
// 008c1313  39b1580a0000         cmp dword ptr [ecx + 0xa58], esi
// 008c1319  8bc8                 mov ecx, eax
// 008c131b  8b4204               mov eax, dword ptr [edx + 4]
// 008c131e  0f94c3               sete bl
// 008c1321  53                   push ebx
// 008c1322  ffd0                 call eax
// 008c1324  5e                   pop esi
// 008c1325  5b                   pop ebx
// 008c1326  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonTool@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
