// from server: 100% by auto
// roc 2009-12 00835360  unit: CXTPControls  size: 272 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835360
//
// 00835360  837c240800           cmp dword ptr [esp + 8], 0
// 00835365  53                   push ebx
// 00835366  55                   push ebp
// 00835367  56                   push esi
// 00835368  57                   push edi
// 00835369  8bf1                 mov esi, ecx
// 0083536b  0f84f8000000         je 0x835469
// 00835371  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00835375  6a00                 push 0
// 00835377  56                   push esi
// 00835378  68747a9f00           push 0x9f7a74
// 0083537d  57                   push edi
// 0083537e  e87db60100           call 0x850a00
// 00835383  6a01                 push 1
// 00835385  8d4604               lea eax, [esi + 4]
// 00835388  50                   push eax
// 00835389  68b0589b00           push 0x9b58b0
// 0083538e  57                   push edi
// 0083538f  e8ccb60100           call 0x850a60
// 00835394  6a00                 push 0
// 00835396  8d4e08               lea ecx, [esi + 8]
// 00835399  51                   push ecx
// 0083539a  68687a9f00           push 0x9f7a68
// 0083539f  57                   push edi
// 008353a0  e8bbb60100           call 0x850a60
// 008353a5  8d5614               lea edx, [esi + 0x14]
// 008353a8  52                   push edx
// 008353a9  685c7a9f00           push 0x9f7a5c
// 008353ae  57                   push edi
// 008353af  e81cb60100           call 0x8509d0
// 008353b4  6a00                 push 0
// 008353b6  8d4618               lea eax, [esi + 0x18]
// 008353b9  50                   push eax
// 008353ba  684c7a9f00           push 0x9f7a4c
// 008353bf  57                   push edi
// 008353c0  e83bb60100           call 0x850a00
// 008353c5  83c44c               add esp, 0x4c
// 008353c8  33c9                 xor ecx, ecx
// 008353ca  51                   push ecx
// 008353cb  33c0                 xor eax, eax
// 008353cd  50                   push eax
// 008353ce  8d4e0c               lea ecx, [esi + 0xc]
// 008353d1  51                   push ecx
// 008353d2  68407a9f00           push 0x9f7a40
// 008353d7  57                   push edi
// 008353d8  e873b70100           call 0x850b50
// 008353dd  83c404               add esp, 4
// 008353e0  8bc4                 mov eax, esp
// 008353e2  33c9                 xor ecx, ecx
// 008353e4  33d2                 xor edx, edx
// 008353e6  8908                 mov dword ptr [eax], ecx
// 008353e8  895004               mov dword ptr [eax + 4], edx
// 008353eb  8d561c               lea edx, [esi + 0x1c]
// 008353ee  52                   push edx
// 008353ef  33db                 xor ebx, ebx
// 008353f1  68347a9f00           push 0x9f7a34
// 008353f6  33ed                 xor ebp, ebp
// 008353f8  895808               mov dword ptr [eax + 8], ebx
// 008353fb  57                   push edi
// 008353fc  89680c               mov dword ptr [eax + 0xc], ebp
// 008353ff  e87cb70100           call 0x850b80
// 00835404  33c9                 xor ecx, ecx
// 00835406  51                   push ecx
// 00835407  33c0                 xor eax, eax
// 00835409  50                   push eax
// 0083540a  8d4630               lea eax, [esi + 0x30]
// 0083540d  50                   push eax
// 0083540e  68287a9f00           push 0x9f7a28
// 00835413  57                   push edi
// 00835414  e837b70100           call 0x850b50
// 00835419  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0083541d  83c430               add esp, 0x30
// 00835420  833906               cmp dword ptr [ecx], 6
// 00835423  7644                 jbe 0x835469
// 00835425  55                   push ebp
// 00835426  8d5e3c               lea ebx, [esi + 0x3c]
// 00835429  53                   push ebx
// 0083542a  681c7a9f00           push 0x9f7a1c
// 0083542f  57                   push edi
// 00835430  e82bb60100           call 0x850a60
// 00835435  83c410               add esp, 0x10
// 00835438  392b                 cmp dword ptr [ebx], ebp
// 0083543a  742d                 je 0x835469
// 0083543c  33c9                 xor ecx, ecx
// 0083543e  51                   push ecx
// 0083543f  33c0                 xor eax, eax
// 00835441  50                   push eax
// 00835442  8d5640               lea edx, [esi + 0x40]
// 00835445  52                   push edx
// 00835446  68007a9f00           push 0x9f7a00
// 0083544b  57                   push edi
// 0083544c  e8ffb60100           call 0x850b50
// 00835451  33c9                 xor ecx, ecx
// 00835453  51                   push ecx
// 00835454  33c0                 xor eax, eax
// 00835456  50                   push eax
// 00835457  83c648               add esi, 0x48
// 0083545a  56                   push esi
// 0083545b  68e4799f00           push 0x9f79e4
// 00835460  57                   push edi
// 00835461  e8eab60100           call 0x850b50
// 00835466  83c428               add esp, 0x28
// 00835469  5f                   pop edi
// 0083546a  5e                   pop esi
// 0083546b  5d                   pop ebp
// 0083546c  5b                   pop ebx
// 0083546d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?DoPropExchange@CToolBarInfo@CXTPToolBar@@QAEXPAVCXTPPropExchange@@PAVCXTPDockState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
