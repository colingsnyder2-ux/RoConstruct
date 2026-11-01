// from server: 100% by auto
// roc 2009-12 0079a9b0  unit: lua_exception  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a9b0
//
// 0079a9b0  51                   push ecx
// 0079a9b1  56                   push esi
// 0079a9b2  33f6                 xor esi, esi
// 0079a9b4  3bde                 cmp ebx, esi
// 0079a9b6  745f                 je 0x79aa17
// 0079a9b8  807b0600             cmp byte ptr [ebx + 6], 0
// 0079a9bc  7559                 jne 0x79aa17
// 0079a9be  55                   push ebp
// 0079a9bf  56                   push esi
// 0079a9c0  56                   push esi
// 0079a9c1  57                   push edi
// 0079a9c2  e8c9570300           call 0x7d0190
// 0079a9c7  8be8                 mov ebp, eax
// 0079a9c9  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0079a9cc  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0079a9cf  83c40c               add esp, 0xc
// 0079a9d2  397030               cmp dword ptr [eax + 0x30], esi
// 0079a9d5  894c2408             mov dword ptr [esp + 8], ecx
// 0079a9d9  7e2d                 jle 0x79aa08
// 0079a9db  eb03                 jmp 0x79a9e0
// 0079a9dd  8d4900               lea ecx, [ecx]
// 0079a9e0  8b542408             mov edx, dword ptr [esp + 8]
// 0079a9e4  8b04b2               mov eax, dword ptr [edx + esi*4]
// 0079a9e7  50                   push eax
// 0079a9e8  55                   push ebp
// 0079a9e9  57                   push edi
// 0079a9ea  e8615a0300           call 0x7d0450
// 0079a9ef  c70001000000         mov dword ptr [eax], 1
// 0079a9f5  c7400801000000       mov dword ptr [eax + 8], 1
// 0079a9fc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0079a9ff  46                   inc esi
// 0079aa00  83c40c               add esp, 0xc
// 0079aa03  3b7130               cmp esi, dword ptr [ecx + 0x30]
// 0079aa06  7cd8                 jl 0x79a9e0
// 0079aa08  8b4708               mov eax, dword ptr [edi + 8]
// 0079aa0b  8928                 mov dword ptr [eax], ebp
// 0079aa0d  c7400805000000       mov dword ptr [eax + 8], 5
// 0079aa14  5d                   pop ebp
// 0079aa15  eb06                 jmp 0x79aa1d
// 0079aa17  8b5708               mov edx, dword ptr [edi + 8]
// 0079aa1a  897208               mov dword ptr [edx + 8], esi
// 0079aa1d  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0079aa20  2b4708               sub eax, dword ptr [edi + 8]
// 0079aa23  be10000000           mov esi, 0x10
// 0079aa28  3bc6                 cmp eax, esi
// 0079aa2a  7f0b                 jg 0x79aa37
// 0079aa2c  6a01                 push 1
// 0079aa2e  57                   push edi
// 0079aa2f  e8fcc8ffff           call 0x797330
// 0079aa34  83c408               add esp, 8
// 0079aa37  017708               add dword ptr [edi + 8], esi
// 0079aa3a  5e                   pop esi
// 0079aa3b  59                   pop ecx
// 0079aa3c  c3                   ret 
// library lua-5.1/ldebug.c (function _collectvalidlines)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
