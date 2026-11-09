// from server: 100% by auto
// roc 2012-06 006464a0  unit: seg_00640000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006464a0
//
// 006464a0  8b442404             mov eax, dword ptr [esp + 4]
// 006464a4  53                   push ebx
// 006464a5  55                   push ebp
// 006464a6  56                   push esi
// 006464a7  33f6                 xor esi, esi
// 006464a9  33db                 xor ebx, ebx
// 006464ab  33ed                 xor ebp, ebp
// 006464ad  85c0                 test eax, eax
// 006464af  740e                 je 0x6464bf
// 006464b1  8b30                 mov esi, dword ptr [eax]
// 006464b3  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 006464b9  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 006464bf  8b442414             mov eax, dword ptr [esp + 0x14]
// 006464c3  85c0                 test eax, eax
// 006464c5  7459                 je 0x646520
// 006464c7  57                   push edi
// 006464c8  8b38                 mov edi, dword ptr [eax]
// 006464ca  85ff                 test edi, edi
// 006464cc  7451                 je 0x64651f
// 006464ce  85f6                 test esi, esi
// 006464d0  7438                 je 0x64650a
// 006464d2  6aff                 push -1
// 006464d4  68ff7f0000           push 0x7fff
// 006464d9  57                   push edi
// 006464da  56                   push esi
// 006464db  e8007affff           call 0x63dee0
// 006464e0  83c410               add esp, 0x10
// 006464e3  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 006464ea  741e                 je 0x64650a
// 006464ec  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 006464f2  50                   push eax
// 006464f3  56                   push esi
// 006464f4  e827800000           call 0x64e520
// 006464f9  83c408               add esp, 8
// 006464fc  33c0                 xor eax, eax
// 006464fe  898624020000         mov dword ptr [esi + 0x224], eax
// 00646504  898620020000         mov dword ptr [esi + 0x220], eax
// 0064650a  55                   push ebp
// 0064650b  53                   push ebx
// 0064650c  57                   push edi
// 0064650d  e8ce7e0000           call 0x64e3e0
// 00646512  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00646516  83c40c               add esp, 0xc
// 00646519  c70100000000         mov dword ptr [ecx], 0
// 0064651f  5f                   pop edi
// 00646520  85f6                 test esi, esi
// 00646522  741b                 je 0x64653f
// 00646524  56                   push esi
// 00646525  e8c6f8ffff           call 0x645df0
// 0064652a  55                   push ebp
// 0064652b  53                   push ebx
// 0064652c  56                   push esi
// 0064652d  e8ae7e0000           call 0x64e3e0
// 00646532  8b542420             mov edx, dword ptr [esp + 0x20]
// 00646536  83c410               add esp, 0x10
// 00646539  c70200000000         mov dword ptr [edx], 0
// 0064653f  5e                   pop esi
// 00646540  5d                   pop ebp
// 00646541  5b                   pop ebx
// 00646542  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
