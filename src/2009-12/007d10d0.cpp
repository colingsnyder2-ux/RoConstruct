// from server: 100% by auto
// roc 2009-12 007d10d0  unit: seg_007d0000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d10d0
//
// 007d10d0  56                   push esi
// 007d10d1  8b742408             mov esi, dword ptr [esp + 8]
// 007d10d5  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d10d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d10db  8d4c2408             lea ecx, [esp + 8]
// 007d10df  51                   push ecx
// 007d10e0  52                   push edx
// 007d10e1  50                   push eax
// 007d10e2  8b4608               mov eax, dword ptr [esi + 8]
// 007d10e5  ffd0                 call eax
// 007d10e7  83c40c               add esp, 0xc
// 007d10ea  85c0                 test eax, eax
// 007d10ec  7419                 je 0x7d1107
// 007d10ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d10f2  85c9                 test ecx, ecx
// 007d10f4  7411                 je 0x7d1107
// 007d10f6  49                   dec ecx
// 007d10f7  894604               mov dword ptr [esi + 4], eax
// 007d10fa  890e                 mov dword ptr [esi], ecx
// 007d10fc  0fb608               movzx ecx, byte ptr [eax]
// 007d10ff  40                   inc eax
// 007d1100  894604               mov dword ptr [esi + 4], eax
// 007d1103  8bc1                 mov eax, ecx
// 007d1105  5e                   pop esi
// 007d1106  c3                   ret 
// 007d1107  83c8ff               or eax, 0xffffffff
// 007d110a  5e                   pop esi
// 007d110b  c3                   ret 
// library lua-5.1/lzio.c (function _luaZ_fill)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lzio.c
