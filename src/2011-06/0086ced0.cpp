// from server: 100% by auto
// roc 2011-06 0086ced0  unit: CXTPStatusBar  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086ced0
//
// 0086ced0  56                   push esi
// 0086ced1  8bf1                 mov esi, ecx
// 0086ced3  e840f71500           call 0x9cc618
// 0086ced8  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 0086cede  2500000010           and eax, 0x10000000
// 0086cee3  33d2                 xor edx, edx
// 0086cee5  f6c101               test cl, 1
// 0086cee8  740b                 je 0x86cef5
// 0086ceea  85c0                 test eax, eax
// 0086ceec  7407                 je 0x86cef5
// 0086ceee  ba80000000           mov edx, 0x80
// 0086cef3  eb0e                 jmp 0x86cf03
// 0086cef5  f6c102               test cl, 2
// 0086cef8  7409                 je 0x86cf03
// 0086cefa  85c0                 test eax, eax
// 0086cefc  7505                 jne 0x86cf03
// 0086cefe  ba40000000           mov edx, 0x40
// 0086cf03  83e1fc               and ecx, 0xfffffffc
// 0086cf06  898e80000000         mov dword ptr [esi + 0x80], ecx
// 0086cf0c  85d2                 test edx, edx
// 0086cf0e  7415                 je 0x86cf25
// 0086cf10  83ca17               or edx, 0x17
// 0086cf13  52                   push edx
// 0086cf14  6a00                 push 0
// 0086cf16  6a00                 push 0
// 0086cf18  6a00                 push 0
// 0086cf1a  6a00                 push 0
// 0086cf1c  6a00                 push 0
// 0086cf1e  8bce                 mov ecx, esi
// 0086cf20  e805d5f9ff           call 0x80a42a
// 0086cf25  8bce                 mov ecx, esi
// 0086cf27  e8ecf61500           call 0x9cc618
// 0086cf2c  a900000010           test eax, 0x10000000
// 0086cf31  745d                 je 0x86cf90
// 0086cf33  8b8e90000000         mov ecx, dword ptr [esi + 0x90]
// 0086cf39  85c9                 test ecx, ecx
// 0086cf3b  740c                 je 0x86cf49
// 0086cf3d  e8d6f61500           call 0x9cc618
// 0086cf42  a900000010           test eax, 0x10000000
// 0086cf47  7447                 je 0x86cf90
// 0086cf49  8b4638               mov eax, dword ptr [esi + 0x38]
// 0086cf4c  57                   push edi
// 0086cf4d  8b3db819a400         mov edi, dword ptr [0xa419b8]
// 0086cf53  85c0                 test eax, eax
// 0086cf55  7506                 jne 0x86cf5d
// 0086cf57  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086cf5a  50                   push eax
// 0086cf5b  ffd7                 call edi
// 0086cf5d  50                   push eax
// 0086cf5e  e8c5d3f9ff           call 0x80a328
// 0086cf63  85c0                 test eax, eax
// 0086cf65  7510                 jne 0x86cf77
// 0086cf67  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0086cf6a  51                   push ecx
// 0086cf6b  ffd7                 call edi
// 0086cf6d  50                   push eax
// 0086cf6e  e8b5d3f9ff           call 0x80a328
// 0086cf73  85c0                 test eax, eax
// 0086cf75  7412                 je 0x86cf89
// 0086cf77  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0086cf7b  8b16                 mov edx, dword ptr [esi]
// 0086cf7d  8b924c010000         mov edx, dword ptr [edx + 0x14c]
// 0086cf83  51                   push ecx
// 0086cf84  50                   push eax
// 0086cf85  8bce                 mov ecx, esi
// 0086cf87  ffd2                 call edx
// 0086cf89  5f                   pop edi
// 0086cf8a  33c0                 xor eax, eax
// 0086cf8c  5e                   pop esi
// 0086cf8d  c20800               ret 8
// 0086cf90  33c0                 xor eax, eax
// 0086cf92  5e                   pop esi
// 0086cf93  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPStatusBar.cpp (function ?OnIdleUpdateCmdUI@CXTPStatusBar@@QAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPStatusBar.cpp
