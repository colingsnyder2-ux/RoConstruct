// from server: 100% by auto
// roc 2007-03 006e1460  unit: seg_006e0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e1460
//
// 006e1460  56                   push esi
// 006e1461  57                   push edi
// 006e1462  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006e1466  8bf1                 mov esi, ecx
// 006e1468  8d4674               lea eax, [esi + 0x74]
// 006e146b  50                   push eax
// 006e146c  6a67                 push 0x67
// 006e146e  57                   push edi
// 006e146f  e8769b0500           call 0x73afea
// 006e1474  81c6c8000000         add esi, 0xc8
// 006e147a  56                   push esi
// 006e147b  6a68                 push 0x68
// 006e147d  57                   push edi
// 006e147e  e8679b0500           call 0x73afea
// 006e1483  5f                   pop edi
// 006e1484  5e                   pop esi
// 006e1485  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?DoDataExchange@CXTPImageEditorDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
