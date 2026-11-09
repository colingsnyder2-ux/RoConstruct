// roc 2012-06 00856160  unit: lua_exception  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00856160
//
// 00856160  55                   push ebp
// 00856161  8bec                 mov ebp, esp
// 00856163  83e4c0               and esp, 0xffffffc0
// 00856166  83ec34               sub esp, 0x34
// 00856169  53                   push ebx
// 0085616a  56                   push esi
// 0085616b  57                   push edi
// 0085616c  ff15b029b200         call dword ptr [0xb229b0]
// 00856172  99                   cdq 
// 00856173  b9ff7f0000           mov ecx, 0x7fff
// 00856178  f7f9                 idiv ecx
// 0085617a  8b7d08               mov edi, dword ptr [ebp + 8]
// 0085617d  57                   push edi
// 0085617e  89542434             mov dword ptr [esp + 0x34], edx
// 00856182  db442434             fild dword ptr [esp + 0x34]
// 00856186  dc0d6039b800         fmul qword ptr [0xb83960]
// 0085618c  dd5c243c             fstp qword ptr [esp + 0x3c]
// 00856190  e85bb9fdff           call 0x831af0
// 00856195  83c404               add esp, 4
// 00856198  83e800               sub eax, 0
// 0085619b  0f84ad000000         je 0x85624e
// 008561a1  83e801               sub eax, 1
// 008561a4  7469                 je 0x85620f
// 008561a6  83e801               sub eax, 1
// 008561a9  7415                 je 0x8561c0
// 008561ab  686c3cbd00           push 0xbd3c6c
// 008561b0  57                   push edi
// 008561b1  e8eaccfdff           call 0x832ea0
// 008561b6  83c408               add esp, 8
// 008561b9  5f                   pop edi
// 008561ba  5e                   pop esi
// 008561bb  5b                   pop ebx
// 008561bc  8be5                 mov esp, ebp
// 008561be  5d                   pop ebp
// 008561bf  c3                   ret 
// 008561c0  6a01                 push 1
// 008561c2  57                   push edi
// 008561c3  e898d8fdff           call 0x833a60
// 008561c8  8bd8                 mov ebx, eax
// 008561ca  6a02                 push 2
// 008561cc  57                   push edi
// 008561cd  895c2444             mov dword ptr [esp + 0x44], ebx
// 008561d1  e88ad8fdff           call 0x833a60
// 008561d6  8bf0                 mov esi, eax
// 008561d8  83c410               add esp, 0x10
// 008561db  3bde                 cmp ebx, esi
// 008561dd  7e10                 jle 0x8561ef
// 008561df  68583cbd00           push 0xbd3c58
// 008561e4  6a02                 push 2
// 008561e6  57                   push edi
// 008561e7  e844d5fdff           call 0x833730
// 008561ec  83c40c               add esp, 0xc
// 008561ef  2bf3                 sub esi, ebx
// 008561f1  46                   inc esi
// 008561f2  89742430             mov dword ptr [esp + 0x30], esi
// 008561f6  db442430             fild dword ptr [esp + 0x30]
// 008561fa  83ec08               sub esp, 8
// 008561fd  dc4c2440             fmul qword ptr [esp + 0x40]
// 00856201  dd1c24               fstp qword ptr [esp]
// 00856204  e82dd91200           call 0x983b36
// 00856209  da44243c             fiadd dword ptr [esp + 0x3c]
// 0085620d  eb46                 jmp 0x856255
// 0085620f  6a01                 push 1
// 00856211  57                   push edi
// 00856212  e849d8fdff           call 0x833a60
// 00856217  83c408               add esp, 8
// 0085621a  83f801               cmp eax, 1
// 0085621d  89442434             mov dword ptr [esp + 0x34], eax
// 00856221  7d10                 jge 0x856233
// 00856223  68583cbd00           push 0xbd3c58
// 00856228  6a01                 push 1
// 0085622a  57                   push edi
// 0085622b  e800d5fdff           call 0x833730
// 00856230  83c40c               add esp, 0xc
// 00856233  db442434             fild dword ptr [esp + 0x34]
// 00856237  83ec08               sub esp, 8
// 0085623a  dc4c2440             fmul qword ptr [esp + 0x40]
// 0085623e  dd1c24               fstp qword ptr [esp]
// 00856241  e8f0d81200           call 0x983b36
// 00856246  dc0570fdb400         fadd qword ptr [0xb4fd70]
// 0085624c  eb07                 jmp 0x856255
// 0085624e  dd442438             fld qword ptr [esp + 0x38]
// 00856252  83ec08               sub esp, 8
// 00856255  dd1c24               fstp qword ptr [esp]
// 00856258  57                   push edi
// 00856259  e852befdff           call 0x8320b0
// 0085625e  83c40c               add esp, 0xc
// 00856261  5f                   pop edi
// 00856262  5e                   pop esi
// 00856263  b801000000           mov eax, 1
// 00856268  5b                   pop ebx
// 00856269  8be5                 mov esp, ebp
// 0085626b  5d                   pop ebp
// 0085626c  c3                   ret 
// copied from an identical function in another client (function _math_random)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
// roc-lib: lua-5.1.2-dll lmathlib.c