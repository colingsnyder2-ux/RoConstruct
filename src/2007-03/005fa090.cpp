// from server: 100% by auto
// roc 2007-03 005fa090  unit: seg_005f0000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fa090
//
// 005fa090  53                   push ebx
// 005fa091  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005fa095  56                   push esi
// 005fa096  8b742410             mov esi, dword ptr [esp + 0x10]
// 005fa09a  8b4608               mov eax, dword ptr [esi + 8]
// 005fa09d  3b4308               cmp eax, dword ptr [ebx + 8]
// 005fa0a0  7412                 je 0x5fa0b4
// 005fa0a2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fa0a6  53                   push ebx
// 005fa0a7  56                   push esi
// 005fa0a8  50                   push eax
// 005fa0a9  e82293fcff           call 0x5c33d0
// 005fa0ae  83c40c               add esp, 0xc
// 005fa0b1  5e                   pop esi
// 005fa0b2  5b                   pop ebx
// 005fa0b3  c3                   ret 
// 005fa0b4  83f803               cmp eax, 3
// 005fa0b7  7518                 jne 0x5fa0d1
// 005fa0b9  dd03                 fld qword ptr [ebx]
// 005fa0bb  dc1e                 fcomp qword ptr [esi]
// 005fa0bd  dfe0                 fnstsw ax
// 005fa0bf  f6c441               test ah, 0x41
// 005fa0c2  7508                 jne 0x5fa0cc
// 005fa0c4  5e                   pop esi
// 005fa0c5  b801000000           mov eax, 1
// 005fa0ca  5b                   pop ebx
// 005fa0cb  c3                   ret 
// 005fa0cc  5e                   pop esi
// 005fa0cd  33c0                 xor eax, eax
// 005fa0cf  5b                   pop ebx
// 005fa0d0  c3                   ret 
// 005fa0d1  83f804               cmp eax, 4
// 005fa0d4  7515                 jne 0x5fa0eb
// 005fa0d6  8b03                 mov eax, dword ptr [ebx]
// 005fa0d8  8b0e                 mov ecx, dword ptr [esi]
// 005fa0da  e841ffffff           call 0x5fa020
// 005fa0df  33c9                 xor ecx, ecx
// 005fa0e1  85c0                 test eax, eax
// 005fa0e3  0f9cc1               setl cl
// 005fa0e6  5e                   pop esi
// 005fa0e7  5b                   pop ebx
// 005fa0e8  8bc1                 mov eax, ecx
// 005fa0ea  c3                   ret 
// 005fa0eb  57                   push edi
// 005fa0ec  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005fa0f0  6a0d                 push 0xd
// 005fa0f2  56                   push esi
// 005fa0f3  8bc7                 mov eax, edi
// 005fa0f5  e8a6feffff           call 0x5f9fa0
// 005fa0fa  83c408               add esp, 8
// 005fa0fd  83f8ff               cmp eax, -1
// 005fa100  750b                 jne 0x5fa10d
// 005fa102  53                   push ebx
// 005fa103  56                   push esi
// 005fa104  57                   push edi
// 005fa105  e8c692fcff           call 0x5c33d0
// 005fa10a  83c40c               add esp, 0xc
// 005fa10d  5f                   pop edi
// 005fa10e  5e                   pop esi
// 005fa10f  5b                   pop ebx
// 005fa110  c3                   ret 
// library lua-5.1.1/lvm.c (function _luaV_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
