// from server: 100% by auto
// roc 2012-06 006397a0  unit: G3D::_internal::DialogTemplate  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006397a0
//
// 006397a0  8b442404             mov eax, dword ptr [esp + 4]
// 006397a4  2b4148               sub eax, dword ptr [ecx + 0x48]
// 006397a7  7917                 jns 0x6397c0
// 006397a9  6860e0cf00           push 0xcfe060
// 006397ae  8d442408             lea eax, [esp + 8]
// 006397b2  50                   push eax
// 006397b3  c744240c083fb800     mov dword ptr [esp + 0xc], 0xb83f08
// 006397bb  e884993400           call 0x983144
// 006397c0  56                   push esi
// 006397c1  8b7138               mov esi, dword ptr [ecx + 0x38]
// 006397c4  3bc6                 cmp eax, esi
// 006397c6  7d03                 jge 0x6397cb
// 006397c8  894140               mov dword ptr [ecx + 0x40], eax
// 006397cb  7e1c                 jle 0x6397e9
// 006397cd  8b5140               mov edx, dword ptr [ecx + 0x40]
// 006397d0  2bc6                 sub eax, esi
// 006397d2  03d0                 add edx, eax
// 006397d4  3bf2                 cmp esi, edx
// 006397d6  7c02                 jl 0x6397da
// 006397d8  8bd6                 mov edx, esi
// 006397da  3b513c               cmp edx, dword ptr [ecx + 0x3c]
// 006397dd  895138               mov dword ptr [ecx + 0x38], edx
// 006397e0  7e07                 jle 0x6397e9
// 006397e2  56                   push esi
// 006397e3  50                   push eax
// 006397e4  e8d7bdffff           call 0x6355c0
// 006397e9  5e                   pop esi
// 006397ea  c20400               ret 4
// library rbx2016-g3d/GImage_bmp.cpp (function ?setLength@BinaryOutput@G3D@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_bmp.cpp
