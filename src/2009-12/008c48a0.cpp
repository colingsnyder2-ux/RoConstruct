// from server: 100% by auto
// roc 2009-12 008c48a0  unit: CXTPImageEditorDlg  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c48a0
//
// 008c48a0  8b442404             mov eax, dword ptr [esp + 4]
// 008c48a4  83f86b               cmp eax, 0x6b
// 008c48a7  7515                 jne 0x8c48be
// 008c48a9  33d2                 xor edx, edx
// 008c48ab  83c8ff               or eax, 0xffffffff
// 008c48ae  52                   push edx
// 008c48af  50                   push eax
// 008c48b0  81c11c090000         add ecx, 0x91c
// 008c48b6  e825f7ffff           call 0x8c3fe0
// 008c48bb  c20400               ret 4
// 008c48be  83f86e               cmp eax, 0x6e
// 008c48c1  7517                 jne 0x8c48da
// 008c48c3  33d2                 xor edx, edx
// 008c48c5  b801000000           mov eax, 1
// 008c48ca  52                   push edx
// 008c48cb  50                   push eax
// 008c48cc  81c11c090000         add ecx, 0x91c
// 008c48d2  e809f7ffff           call 0x8c3fe0
// 008c48d7  c20400               ret 4
// 008c48da  83f86d               cmp eax, 0x6d
// 008c48dd  7515                 jne 0x8c48f4
// 008c48df  83caff               or edx, 0xffffffff
// 008c48e2  33c0                 xor eax, eax
// 008c48e4  52                   push edx
// 008c48e5  50                   push eax
// 008c48e6  81c11c090000         add ecx, 0x91c
// 008c48ec  e8eff6ffff           call 0x8c3fe0
// 008c48f1  c20400               ret 4
// 008c48f4  ba01000000           mov edx, 1
// 008c48f9  33c0                 xor eax, eax
// 008c48fb  52                   push edx
// 008c48fc  50                   push eax
// 008c48fd  81c11c090000         add ecx, 0x91c
// 008c4903  e8d8f6ffff           call 0x8c3fe0
// 008c4908  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnMoveButton@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
