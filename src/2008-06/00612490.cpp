// from server: 100% by auto
// roc 2008-06 00612490  unit: seg_00610000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612490
//
// 00612490  8b442408             mov eax, dword ptr [esp + 8]
// 00612494  83ec10               sub esp, 0x10
// 00612497  53                   push ebx
// 00612498  56                   push esi
// 00612499  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0061249d  57                   push edi
// 0061249e  8bce                 mov ecx, esi
// 006124a0  e8ebf5ffff           call 0x611a90
// 006124a5  8b542428             mov edx, dword ptr [esp + 0x28]
// 006124a9  8bf8                 mov edi, eax
// 006124ab  8bc2                 mov eax, edx
// 006124ad  8d5801               lea ebx, [eax + 1]
// 006124b0  8a08                 mov cl, byte ptr [eax]
// 006124b2  40                   inc eax
// 006124b3  84c9                 test cl, cl
// 006124b5  75f9                 jne 0x6124b0
// 006124b7  2bc3                 sub eax, ebx
// 006124b9  50                   push eax
// 006124ba  52                   push edx
// 006124bb  56                   push esi
// 006124bc  e83fce0400           call 0x65f300
// 006124c1  89442418             mov dword ptr [esp + 0x18], eax
// 006124c5  8b4608               mov eax, dword ptr [esi + 8]
// 006124c8  50                   push eax
// 006124c9  8d4c241c             lea ecx, [esp + 0x1c]
// 006124cd  51                   push ecx
// 006124ce  57                   push edi
// 006124cf  56                   push esi
// 006124d0  c744243004000000     mov dword ptr [esp + 0x30], 4
// 006124d8  e803a40400           call 0x65c8e0
// 006124dd  83c41c               add esp, 0x1c
// 006124e0  83460810             add dword ptr [esi + 8], 0x10
// 006124e4  5f                   pop edi
// 006124e5  5e                   pop esi
// 006124e6  5b                   pop ebx
// 006124e7  83c410               add esp, 0x10
// 006124ea  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
