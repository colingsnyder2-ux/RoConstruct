// from server: 100% by auto
// roc 2009-12 008c2790  unit: CXTPImageEditorDlg  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2790
//
// 008c2790  56                   push esi
// 008c2791  57                   push edi
// 008c2792  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008c2796  8bf1                 mov esi, ecx
// 008c2798  8d4674               lea eax, [esi + 0x74]
// 008c279b  50                   push eax
// 008c279c  6a67                 push 0x67
// 008c279e  57                   push edi
// 008c279f  e80a1af3ff           call 0x7f41ae
// 008c27a4  81c6c8000000         add esi, 0xc8
// 008c27aa  56                   push esi
// 008c27ab  6a68                 push 0x68
// 008c27ad  57                   push edi
// 008c27ae  e8fb19f3ff           call 0x7f41ae
// 008c27b3  5f                   pop edi
// 008c27b4  5e                   pop esi
// 008c27b5  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?DoDataExchange@CXTPImageEditorDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
