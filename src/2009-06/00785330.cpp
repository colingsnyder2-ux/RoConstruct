// from server: 100% by auto
// roc 2009-06 00785330  unit: CInstanceRecord::CNameItem  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00785330
//
// 00785330  55                   push ebp
// 00785331  56                   push esi
// 00785332  57                   push edi
// 00785333  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00785337  8bf7                 mov esi, edi
// 00785339  c1e604               shl esi, 4
// 0078533c  f7d6                 not esi
// 0078533e  81e600000200         and esi, 0x20000
// 00785344  81ce20080000         or esi, 0x820
// 0078534a  8be9                 mov ebp, ecx
// 0078534c  f7c600000200         test esi, 0x20000
// 00785352  7416                 je 0x78536a
// 00785354  e8f7b5fdff           call 0x760950
// 00785359  8bc8                 mov ecx, eax
// 0078535b  e8f0befdff           call 0x761250
// 00785360  84c0                 test al, al
// 00785362  7506                 jne 0x78536a
// 00785364  81e6fffffdff         and esi, 0xfffdffff
// 0078536a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078536e  53                   push ebx
// 0078536f  85c0                 test eax, eax
// 00785371  7504                 jne 0x785377
// 00785373  33db                 xor ebx, ebx
// 00785375  eb03                 jmp 0x78537a
// 00785377  8b5820               mov ebx, dword ptr [eax + 0x20]
// 0078537a  e87739f9ff           call 0x718cf6
// 0078537f  68007f0000           push 0x7f00
// 00785384  6a00                 push 0
// 00785386  ff15b0ed8900         call dword ptr [0x89edb0]
// 0078538c  6a00                 push 0
// 0078538e  6a00                 push 0
// 00785390  53                   push ebx
// 00785391  6800000080           push 0x80000000
// 00785396  6800000080           push 0x80000000
// 0078539b  6800000080           push 0x80000000
// 007853a0  6800000080           push 0x80000000
// 007853a5  81cf00000080         or edi, 0x80000000
// 007853ab  57                   push edi
// 007853ac  6a00                 push 0
// 007853ae  6a00                 push 0
// 007853b0  6a00                 push 0
// 007853b2  50                   push eax
// 007853b3  56                   push esi
// 007853b4  e84540f9ff           call 0x7193fe
// 007853b9  50                   push eax
// 007853ba  6880000000           push 0x80
// 007853bf  8bcd                 mov ecx, ebp
// 007853c1  e8ea36f9ff           call 0x718ab0
// 007853c6  5b                   pop ebx
// 007853c7  85c0                 test eax, eax
// 007853c9  7419                 je 0x7853e4
// 007853cb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007853cf  85c9                 test ecx, ecx
// 007853d1  740c                 je 0x7853df
// 007853d3  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007853d6  5f                   pop edi
// 007853d7  5e                   pop esi
// 007853d8  894d38               mov dword ptr [ebp + 0x38], ecx
// 007853db  5d                   pop ebp
// 007853dc  c20800               ret 8
// 007853df  33c9                 xor ecx, ecx
// 007853e1  894d38               mov dword ptr [ebp + 0x38], ecx
// 007853e4  5f                   pop edi
// 007853e5  5e                   pop esi
// 007853e6  5d                   pop ebp
// 007853e7  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?Create@CXTPToolTipContextToolTip@@QAEHPAVCWnd@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
