// from server: 100% by auto
// roc 2007-03 005ffab0  unit: seg_005f0000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffab0
//
// 005ffab0  51                   push ecx
// 005ffab1  53                   push ebx
// 005ffab2  56                   push esi
// 005ffab3  8bf0                 mov esi, eax
// 005ffab5  57                   push edi
// 005ffab6  8b7e30               mov edi, dword ptr [esi + 0x30]
// 005ffab9  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005ffac1  e86affffff           call 0x5ffa30
// 005ffac6  817e1005010000       cmp dword ptr [esi + 0x10], 0x105
// 005ffacd  8bd8                 mov ebx, eax
// 005ffacf  752c                 jne 0x5ffafd
// 005ffad1  57                   push edi
// 005ffad2  e869520100           call 0x614d40
// 005ffad7  50                   push eax
// 005ffad8  8d442414             lea eax, [esp + 0x14]
// 005ffadc  50                   push eax
// 005ffadd  57                   push edi
// 005ffade  e86d4b0100           call 0x614650
// 005ffae3  53                   push ebx
// 005ffae4  57                   push edi
// 005ffae5  e826530100           call 0x614e10
// 005ffaea  83c418               add esp, 0x18
// 005ffaed  e83effffff           call 0x5ffa30
// 005ffaf2  817e1005010000       cmp dword ptr [esi + 0x10], 0x105
// 005ffaf9  8bd8                 mov ebx, eax
// 005ffafb  74d4                 je 0x5ffad1
// 005ffafd  817e1004010000       cmp dword ptr [esi + 0x10], 0x104
// 005ffb04  752b                 jne 0x5ffb31
// 005ffb06  57                   push edi
// 005ffb07  e834520100           call 0x614d40
// 005ffb0c  50                   push eax
// 005ffb0d  8d4c2414             lea ecx, [esp + 0x14]
// 005ffb11  51                   push ecx
// 005ffb12  57                   push edi
// 005ffb13  e8384b0100           call 0x614650
// 005ffb18  53                   push ebx
// 005ffb19  57                   push edi
// 005ffb1a  e8f1520100           call 0x614e10
// 005ffb1f  56                   push esi
// 005ffb20  e87b280000           call 0x6023a0
// 005ffb25  83c41c               add esp, 0x1c
// 005ffb28  8bc6                 mov eax, esi
// 005ffb2a  e8b1f2ffff           call 0x5fede0
// 005ffb2f  eb0f                 jmp 0x5ffb40
// 005ffb31  53                   push ebx
// 005ffb32  8d542410             lea edx, [esp + 0x10]
// 005ffb36  52                   push edx
// 005ffb37  57                   push edi
// 005ffb38  e8134b0100           call 0x614650
// 005ffb3d  83c40c               add esp, 0xc
// 005ffb40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ffb44  50                   push eax
// 005ffb45  57                   push edi
// 005ffb46  e8c5520100           call 0x614e10
// 005ffb4b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ffb4f  680a010000           push 0x10a
// 005ffb54  bf06010000           mov edi, 0x106
// 005ffb59  e872d9ffff           call 0x5fd4d0
// 005ffb5e  83c40c               add esp, 0xc
// 005ffb61  5f                   pop edi
// 005ffb62  5e                   pop esi
// 005ffb63  5b                   pop ebx
// 005ffb64  59                   pop ecx
// 005ffb65  c3                   ret 
// library lua-5.1.1/lparser.c (function _ifstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
