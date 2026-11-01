// from server: 100% by auto
// roc 2007-03 00601070  unit: seg_00600000  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00601070
//
// 00601070  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00601074  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00601078  8b542410             mov edx, dword ptr [esp + 0x10]
// 0060107c  56                   push esi
// 0060107d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00601081  894638               mov dword ptr [esi + 0x38], eax
// 00601084  b801000000           mov eax, 1
// 00601089  894604               mov dword ptr [esi + 4], eax
// 0060108c  894608               mov dword ptr [esi + 8], eax
// 0060108f  8b463c               mov eax, dword ptr [esi + 0x3c]
// 00601092  c646442e             mov byte ptr [esi + 0x44], 0x2e
// 00601096  894e34               mov dword ptr [esi + 0x34], ecx
// 00601099  c746201f010000       mov dword ptr [esi + 0x20], 0x11f
// 006010a0  c7463000000000       mov dword ptr [esi + 0x30], 0
// 006010a7  895640               mov dword ptr [esi + 0x40], edx
// 006010aa  8b5008               mov edx, dword ptr [eax + 8]
// 006010ad  8b00                 mov eax, dword ptr [eax]
// 006010af  6a20                 push 0x20
// 006010b1  52                   push edx
// 006010b2  50                   push eax
// 006010b3  51                   push ecx
// 006010b4  e8e7c2ffff           call 0x5fd3a0
// 006010b9  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 006010bc  8901                 mov dword ptr [ecx], eax
// 006010be  8b563c               mov edx, dword ptr [esi + 0x3c]
// 006010c1  c7420820000000       mov dword ptr [edx + 8], 0x20
// 006010c8  8b4638               mov eax, dword ptr [esi + 0x38]
// 006010cb  8b08                 mov ecx, dword ptr [eax]
// 006010cd  8d51ff               lea edx, [ecx - 1]
// 006010d0  83c410               add esp, 0x10
// 006010d3  85c9                 test ecx, ecx
// 006010d5  8910                 mov dword ptr [eax], edx
// 006010d7  8b4638               mov eax, dword ptr [esi + 0x38]
// 006010da  7610                 jbe 0x6010ec
// 006010dc  8b4804               mov ecx, dword ptr [eax + 4]
// 006010df  0fb611               movzx edx, byte ptr [ecx]
// 006010e2  83c101               add ecx, 1
// 006010e5  894804               mov dword ptr [eax + 4], ecx
// 006010e8  8916                 mov dword ptr [esi], edx
// 006010ea  5e                   pop esi
// 006010eb  c3                   ret 
// 006010ec  50                   push eax
// 006010ed  e8aebbffff           call 0x5fcca0
// 006010f2  83c404               add esp, 4
// 006010f5  8906                 mov dword ptr [esi], eax
// 006010f7  5e                   pop esi
// 006010f8  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_setinput)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
