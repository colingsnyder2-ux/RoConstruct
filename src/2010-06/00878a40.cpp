// from server: 100% by auto
// roc 2010-06 00878a40  unit: CXTPImageEditorDlg  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00878a40
//
// 00878a40  8b442404             mov eax, dword ptr [esp + 4]
// 00878a44  83f86b               cmp eax, 0x6b
// 00878a47  7515                 jne 0x878a5e
// 00878a49  33d2                 xor edx, edx
// 00878a4b  83c8ff               or eax, 0xffffffff
// 00878a4e  52                   push edx
// 00878a4f  50                   push eax
// 00878a50  81c11c090000         add ecx, 0x91c
// 00878a56  e825f7ffff           call 0x878180
// 00878a5b  c20400               ret 4
// 00878a5e  83f86e               cmp eax, 0x6e
// 00878a61  7517                 jne 0x878a7a
// 00878a63  33d2                 xor edx, edx
// 00878a65  b801000000           mov eax, 1
// 00878a6a  52                   push edx
// 00878a6b  50                   push eax
// 00878a6c  81c11c090000         add ecx, 0x91c
// 00878a72  e809f7ffff           call 0x878180
// 00878a77  c20400               ret 4
// 00878a7a  83f86d               cmp eax, 0x6d
// 00878a7d  7515                 jne 0x878a94
// 00878a7f  83caff               or edx, 0xffffffff
// 00878a82  33c0                 xor eax, eax
// 00878a84  52                   push edx
// 00878a85  50                   push eax
// 00878a86  81c11c090000         add ecx, 0x91c
// 00878a8c  e8eff6ffff           call 0x878180
// 00878a91  c20400               ret 4
// 00878a94  ba01000000           mov edx, 1
// 00878a99  33c0                 xor eax, eax
// 00878a9b  52                   push edx
// 00878a9c  50                   push eax
// 00878a9d  81c11c090000         add ecx, 0x91c
// 00878aa3  e8d8f6ffff           call 0x878180
// 00878aa8  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnMoveButton@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
