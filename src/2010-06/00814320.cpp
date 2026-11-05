// from server: 100% by auto
// roc 2010-06 00814320  unit: CXTPToolTipContext::CHTMLToolTip  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00814320
//
// 00814320  55                   push ebp
// 00814321  56                   push esi
// 00814322  57                   push edi
// 00814323  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00814327  8bf7                 mov esi, edi
// 00814329  c1e604               shl esi, 4
// 0081432c  f7d6                 not esi
// 0081432e  81e600000200         and esi, 0x20000
// 00814334  81ce20080000         or esi, 0x820
// 0081433a  8be9                 mov ebp, ecx
// 0081433c  f7c600000200         test esi, 0x20000
// 00814342  7416                 je 0x81435a
// 00814344  e827b5fdff           call 0x7ef870
// 00814349  8bc8                 mov ecx, eax
// 0081434b  e830befdff           call 0x7f0180
// 00814350  84c0                 test al, al
// 00814352  7506                 jne 0x81435a
// 00814354  81e6fffffdff         and esi, 0xfffdffff
// 0081435a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081435e  53                   push ebx
// 0081435f  85c0                 test eax, eax
// 00814361  7504                 jne 0x814367
// 00814363  33db                 xor ebx, ebx
// 00814365  eb03                 jmp 0x81436a
// 00814367  8b5820               mov ebx, dword ptr [eax + 0x20]
// 0081436a  e8ef38f9ff           call 0x7a7c5e
// 0081436f  68007f0000           push 0x7f00
// 00814374  6a00                 push 0
// 00814376  ff15ccbb9e00         call dword ptr [0x9ebbcc]
// 0081437c  6a00                 push 0
// 0081437e  6a00                 push 0
// 00814380  53                   push ebx
// 00814381  6800000080           push 0x80000000
// 00814386  6800000080           push 0x80000000
// 0081438b  6800000080           push 0x80000000
// 00814390  6800000080           push 0x80000000
// 00814395  81cf00000080         or edi, 0x80000000
// 0081439b  57                   push edi
// 0081439c  6a00                 push 0
// 0081439e  6a00                 push 0
// 008143a0  6a00                 push 0
// 008143a2  50                   push eax
// 008143a3  56                   push esi
// 008143a4  e8bd3ff9ff           call 0x7a8366
// 008143a9  50                   push eax
// 008143aa  6880000000           push 0x80
// 008143af  8bcd                 mov ecx, ebp
// 008143b1  e86236f9ff           call 0x7a7a18
// 008143b6  5b                   pop ebx
// 008143b7  85c0                 test eax, eax
// 008143b9  7419                 je 0x8143d4
// 008143bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008143bf  85c9                 test ecx, ecx
// 008143c1  740c                 je 0x8143cf
// 008143c3  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008143c6  5f                   pop edi
// 008143c7  5e                   pop esi
// 008143c8  894d38               mov dword ptr [ebp + 0x38], ecx
// 008143cb  5d                   pop ebp
// 008143cc  c20800               ret 8
// 008143cf  33c9                 xor ecx, ecx
// 008143d1  894d38               mov dword ptr [ebp + 0x38], ecx
// 008143d4  5f                   pop edi
// 008143d5  5e                   pop esi
// 008143d6  5d                   pop ebp
// 008143d7  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?Create@CXTPToolTipContextToolTip@@QAEHPAVCWnd@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
