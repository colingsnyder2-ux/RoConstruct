// from server: 100% by auto
// roc 2010-06 0080f740  unit: CXTPStatusBar  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080f740
//
// 0080f740  56                   push esi
// 0080f741  8bf1                 mov esi, ecx
// 0080f743  e896d61600           call 0x97cdde
// 0080f748  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 0080f74e  2500000010           and eax, 0x10000000
// 0080f753  33d2                 xor edx, edx
// 0080f755  f6c101               test cl, 1
// 0080f758  740b                 je 0x80f765
// 0080f75a  85c0                 test eax, eax
// 0080f75c  7407                 je 0x80f765
// 0080f75e  ba80000000           mov edx, 0x80
// 0080f763  eb0e                 jmp 0x80f773
// 0080f765  f6c102               test cl, 2
// 0080f768  7409                 je 0x80f773
// 0080f76a  85c0                 test eax, eax
// 0080f76c  7505                 jne 0x80f773
// 0080f76e  ba40000000           mov edx, 0x40
// 0080f773  83e1fc               and ecx, 0xfffffffc
// 0080f776  898e80000000         mov dword ptr [esi + 0x80], ecx
// 0080f77c  85d2                 test edx, edx
// 0080f77e  7415                 je 0x80f795
// 0080f780  83ca17               or edx, 0x17
// 0080f783  52                   push edx
// 0080f784  6a00                 push 0
// 0080f786  6a00                 push 0
// 0080f788  6a00                 push 0
// 0080f78a  6a00                 push 0
// 0080f78c  6a00                 push 0
// 0080f78e  8bce                 mov ecx, esi
// 0080f790  e8d785f9ff           call 0x7a7d6c
// 0080f795  8bce                 mov ecx, esi
// 0080f797  e842d61600           call 0x97cdde
// 0080f79c  a900000010           test eax, 0x10000000
// 0080f7a1  745d                 je 0x80f800
// 0080f7a3  8b8e90000000         mov ecx, dword ptr [esi + 0x90]
// 0080f7a9  85c9                 test ecx, ecx
// 0080f7ab  740c                 je 0x80f7b9
// 0080f7ad  e82cd61600           call 0x97cdde
// 0080f7b2  a900000010           test eax, 0x10000000
// 0080f7b7  7447                 je 0x80f800
// 0080f7b9  8b4638               mov eax, dword ptr [esi + 0x38]
// 0080f7bc  57                   push edi
// 0080f7bd  8b3d4cba9e00         mov edi, dword ptr [0x9eba4c]
// 0080f7c3  85c0                 test eax, eax
// 0080f7c5  7506                 jne 0x80f7cd
// 0080f7c7  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080f7ca  50                   push eax
// 0080f7cb  ffd7                 call edi
// 0080f7cd  50                   push eax
// 0080f7ce  e89784f9ff           call 0x7a7c6a
// 0080f7d3  85c0                 test eax, eax
// 0080f7d5  7510                 jne 0x80f7e7
// 0080f7d7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080f7da  51                   push ecx
// 0080f7db  ffd7                 call edi
// 0080f7dd  50                   push eax
// 0080f7de  e88784f9ff           call 0x7a7c6a
// 0080f7e3  85c0                 test eax, eax
// 0080f7e5  7412                 je 0x80f7f9
// 0080f7e7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080f7eb  8b16                 mov edx, dword ptr [esi]
// 0080f7ed  8b924c010000         mov edx, dword ptr [edx + 0x14c]
// 0080f7f3  51                   push ecx
// 0080f7f4  50                   push eax
// 0080f7f5  8bce                 mov ecx, esi
// 0080f7f7  ffd2                 call edx
// 0080f7f9  5f                   pop edi
// 0080f7fa  33c0                 xor eax, eax
// 0080f7fc  5e                   pop esi
// 0080f7fd  c20800               ret 8
// 0080f800  33c0                 xor eax, eax
// 0080f802  5e                   pop esi
// 0080f803  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPStatusBar.cpp (function ?OnIdleUpdateCmdUI@CXTPStatusBar@@QAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPStatusBar.cpp
