// from server: 100% by auto
// roc 2007-03 00600ed0  unit: seg_00600000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600ed0
//
// 00600ed0  83ec50               sub esp, 0x50
// 00600ed3  53                   push ebx
// 00600ed4  8b5c2458             mov ebx, dword ptr [esp + 0x58]
// 00600ed8  8b4340               mov eax, dword ptr [ebx + 0x40]
// 00600edb  56                   push esi
// 00600edc  6a50                 push 0x50
// 00600ede  83c010               add eax, 0x10
// 00600ee1  50                   push eax
// 00600ee2  8d4c2410             lea ecx, [esp + 0x10]
// 00600ee6  51                   push ecx
// 00600ee7  e87479ffff           call 0x5f8860
// 00600eec  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 00600ef0  8b4304               mov eax, dword ptr [ebx + 4]
// 00600ef3  52                   push edx
// 00600ef4  8b5334               mov edx, dword ptr [ebx + 0x34]
// 00600ef7  50                   push eax
// 00600ef8  8d4c241c             lea ecx, [esp + 0x1c]
// 00600efc  51                   push ecx
// 00600efd  686c9a7b00           push 0x7b9a6c
// 00600f02  52                   push edx
// 00600f03  e83879ffff           call 0x5f8840
// 00600f08  8bf0                 mov esi, eax
// 00600f0a  8b842484000000       mov eax, dword ptr [esp + 0x84]
// 00600f11  83c420               add esp, 0x20
// 00600f14  85c0                 test eax, eax
// 00600f16  743c                 je 0x600f54
// 00600f18  3d1c010000           cmp eax, 0x11c
// 00600f1d  7c18                 jl 0x600f37
// 00600f1f  3d1e010000           cmp eax, 0x11e
// 00600f24  7f11                 jg 0x600f37
// 00600f26  6a00                 push 0
// 00600f28  e883feffff           call 0x600db0
// 00600f2d  8b433c               mov eax, dword ptr [ebx + 0x3c]
// 00600f30  8b00                 mov eax, dword ptr [eax]
// 00600f32  83c404               add esp, 4
// 00600f35  eb0a                 jmp 0x600f41
// 00600f37  50                   push eax
// 00600f38  53                   push ebx
// 00600f39  e832ffffff           call 0x600e70
// 00600f3e  83c408               add esp, 8
// 00600f41  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 00600f44  50                   push eax
// 00600f45  56                   push esi
// 00600f46  68140a7c00           push 0x7c0a14
// 00600f4b  51                   push ecx
// 00600f4c  e8ef78ffff           call 0x5f8840
// 00600f51  83c410               add esp, 0x10
// 00600f54  8b5334               mov edx, dword ptr [ebx + 0x34]
// 00600f57  6a03                 push 3
// 00600f59  52                   push edx
// 00600f5a  e8a1f2fbff           call 0x5c0200
// 00600f5f  83c408               add esp, 8
// 00600f62  5e                   pop esi
// 00600f63  5b                   pop ebx
// 00600f64  83c450               add esp, 0x50
// 00600f67  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_lexerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
