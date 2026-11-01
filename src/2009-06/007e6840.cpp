// from server: 100% by auto
// roc 2009-06 007e6840  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e6840
//
// 007e6840  8b442404             mov eax, dword ptr [esp + 4]
// 007e6844  8b10                 mov edx, dword ptr [eax]
// 007e6846  53                   push ebx
// 007e6847  56                   push esi
// 007e6848  8b7004               mov esi, dword ptr [eax + 4]
// 007e684b  33db                 xor ebx, ebx
// 007e684d  81eeaf230000         sub esi, 0x23af
// 007e6853  39b1580a0000         cmp dword ptr [ecx + 0xa58], esi
// 007e6859  8bc8                 mov ecx, eax
// 007e685b  8b4204               mov eax, dword ptr [edx + 4]
// 007e685e  0f94c3               sete bl
// 007e6861  53                   push ebx
// 007e6862  ffd0                 call eax
// 007e6864  5e                   pop esi
// 007e6865  5b                   pop ebx
// 007e6866  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonTool@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
