// from server: 100% by auto
// roc 2009-12 00860340  unit: CXTPToolTipContext::CHTMLToolTip  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00860340
//
// 00860340  55                   push ebp
// 00860341  56                   push esi
// 00860342  57                   push edi
// 00860343  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00860347  8bf7                 mov esi, edi
// 00860349  c1e604               shl esi, 4
// 0086034c  f7d6                 not esi
// 0086034e  81e600000200         and esi, 0x20000
// 00860354  81ce20080000         or esi, 0x820
// 0086035a  8be9                 mov ebp, ecx
// 0086035c  f7c600000200         test esi, 0x20000
// 00860362  7416                 je 0x86037a
// 00860364  e8b7b3fdff           call 0x83b720
// 00860369  8bc8                 mov ecx, eax
// 0086036b  e8b0bcfdff           call 0x83c020
// 00860370  84c0                 test al, al
// 00860372  7506                 jne 0x86037a
// 00860374  81e6fffffdff         and esi, 0xfffdffff
// 0086037a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0086037e  53                   push ebx
// 0086037f  85c0                 test eax, eax
// 00860381  7504                 jne 0x860387
// 00860383  33db                 xor ebx, ebx
// 00860385  eb03                 jmp 0x86038a
// 00860387  8b5820               mov ebx, dword ptr [eax + 0x20]
// 0086038a  e88f37f9ff           call 0x7f3b1e
// 0086038f  68007f0000           push 0x7f00
// 00860394  6a00                 push 0
// 00860396  ff1548ca9800         call dword ptr [0x98ca48]
// 0086039c  6a00                 push 0
// 0086039e  6a00                 push 0
// 008603a0  53                   push ebx
// 008603a1  6800000080           push 0x80000000
// 008603a6  6800000080           push 0x80000000
// 008603ab  6800000080           push 0x80000000
// 008603b0  6800000080           push 0x80000000
// 008603b5  81cf00000080         or edi, 0x80000000
// 008603bb  57                   push edi
// 008603bc  6a00                 push 0
// 008603be  6a00                 push 0
// 008603c0  6a00                 push 0
// 008603c2  50                   push eax
// 008603c3  56                   push esi
// 008603c4  e85d3ef9ff           call 0x7f4226
// 008603c9  50                   push eax
// 008603ca  6880000000           push 0x80
// 008603cf  8bcd                 mov ecx, ebp
// 008603d1  e80235f9ff           call 0x7f38d8
// 008603d6  5b                   pop ebx
// 008603d7  85c0                 test eax, eax
// 008603d9  7419                 je 0x8603f4
// 008603db  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008603df  85c9                 test ecx, ecx
// 008603e1  740c                 je 0x8603ef
// 008603e3  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008603e6  5f                   pop edi
// 008603e7  5e                   pop esi
// 008603e8  894d38               mov dword ptr [ebp + 0x38], ecx
// 008603eb  5d                   pop ebp
// 008603ec  c20800               ret 8
// 008603ef  33c9                 xor ecx, ecx
// 008603f1  894d38               mov dword ptr [ebp + 0x38], ecx
// 008603f4  5f                   pop edi
// 008603f5  5e                   pop esi
// 008603f6  5d                   pop ebp
// 008603f7  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?Create@CXTPToolTipContextToolTip@@QAEHPAVCWnd@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
