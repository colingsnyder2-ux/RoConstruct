// from server: 100% by auto
// roc 2009-06 007e9d20  unit: CXTPImageEditorDlg  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e9d20
//
// 007e9d20  8b442404             mov eax, dword ptr [esp + 4]
// 007e9d24  83f86b               cmp eax, 0x6b
// 007e9d27  7515                 jne 0x7e9d3e
// 007e9d29  33d2                 xor edx, edx
// 007e9d2b  83c8ff               or eax, 0xffffffff
// 007e9d2e  52                   push edx
// 007e9d2f  50                   push eax
// 007e9d30  81c11c090000         add ecx, 0x91c
// 007e9d36  e825f7ffff           call 0x7e9460
// 007e9d3b  c20400               ret 4
// 007e9d3e  83f86e               cmp eax, 0x6e
// 007e9d41  7517                 jne 0x7e9d5a
// 007e9d43  33d2                 xor edx, edx
// 007e9d45  b801000000           mov eax, 1
// 007e9d4a  52                   push edx
// 007e9d4b  50                   push eax
// 007e9d4c  81c11c090000         add ecx, 0x91c
// 007e9d52  e809f7ffff           call 0x7e9460
// 007e9d57  c20400               ret 4
// 007e9d5a  83f86d               cmp eax, 0x6d
// 007e9d5d  7515                 jne 0x7e9d74
// 007e9d5f  83caff               or edx, 0xffffffff
// 007e9d62  33c0                 xor eax, eax
// 007e9d64  52                   push edx
// 007e9d65  50                   push eax
// 007e9d66  81c11c090000         add ecx, 0x91c
// 007e9d6c  e8eff6ffff           call 0x7e9460
// 007e9d71  c20400               ret 4
// 007e9d74  ba01000000           mov edx, 1
// 007e9d79  33c0                 xor eax, eax
// 007e9d7b  52                   push edx
// 007e9d7c  50                   push eax
// 007e9d7d  81c11c090000         add ecx, 0x91c
// 007e9d83  e8d8f6ffff           call 0x7e9460
// 007e9d88  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnMoveButton@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
