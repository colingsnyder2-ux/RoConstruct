// from server: 100% by auto
// roc 2007-08 006297b0  unit: RBX::AssemblyStage  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006297b0
//
// 006297b0  56                   push esi
// 006297b1  8b742408             mov esi, dword ptr [esp + 8]
// 006297b5  57                   push edi
// 006297b6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006297ba  57                   push edi
// 006297bb  56                   push esi
// 006297bc  e83ff8ffff           call 0x629000
// 006297c1  8b07                 mov eax, dword ptr [edi]
// 006297c3  83c0fe               add eax, -2
// 006297c6  83c408               add esp, 8
// 006297c9  83f808               cmp eax, 8
// 006297cc  772c                 ja 0x6297fa
// 006297ce  0fb68040986200       movzx eax, byte ptr [eax + 0x629840]
// 006297d5  ff248530986200       jmp dword ptr [eax*4 + 0x629830]
// 006297dc  83c8ff               or eax, 0xffffffff
// 006297df  eb22                 jmp 0x629803
// 006297e1  56                   push esi
// 006297e2  e829f7ffff           call 0x628f10
// 006297e7  83c404               add esp, 4
// 006297ea  eb17                 jmp 0x629803
// 006297ec  8bc7                 mov eax, edi
// 006297ee  8bce                 mov ecx, esi
// 006297f0  e88bf3ffff           call 0x628b80
// 006297f5  8b4708               mov eax, dword ptr [edi + 8]
// 006297f8  eb09                 jmp 0x629803
// 006297fa  53                   push ebx
// 006297fb  33db                 xor ebx, ebx
// 006297fd  e82effffff           call 0x629730
// 00629802  5b                   pop ebx
// 00629803  50                   push eax
// 00629804  8d4f14               lea ecx, [edi + 0x14]
// 00629807  51                   push ecx
// 00629808  56                   push esi
// 00629809  e812f0ffff           call 0x628820
// 0062980e  8b4710               mov eax, dword ptr [edi + 0x10]
// 00629811  8b5618               mov edx, dword ptr [esi + 0x18]
// 00629814  50                   push eax
// 00629815  8d4620               lea eax, [esi + 0x20]
// 00629818  50                   push eax
// 00629819  56                   push esi
// 0062981a  89561c               mov dword ptr [esi + 0x1c], edx
// 0062981d  e8feefffff           call 0x628820
// 00629822  83c418               add esp, 0x18
// 00629825  c74710ffffffff       mov dword ptr [edi + 0x10], 0xffffffff
// 0062982c  5f                   pop edi
// 0062982d  5e                   pop esi
// 0062982e  c3                   ret 
// 0062982f  90                   nop 
// 00629830  dc976200e197         fcom qword ptr [edi - 0x681eff9e]
// 00629836  6200                 bound eax, qword ptr [eax]
// 00629838  ec                   in al, dx
// 00629839  97                   xchg edi, eax
// 0062983a  6200                 bound eax, qword ptr [eax]
// 0062983c  fa                   cli 
// 0062983d  97                   xchg edi, eax
// 0062983e  6200                 bound eax, qword ptr [eax]
// 00629840  0001                 add byte ptr [ecx], al
// 00629842  0000                 add byte ptr [eax], al
// 00629844  0303                 add eax, dword ptr [ebx]
// 00629846  0303                 add eax, dword ptr [ebx]
// library lua-5.1/lcode.c (function _luaK_goiftrue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
