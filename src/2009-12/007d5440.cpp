// from server: 100% by auto
// roc 2009-12 007d5440  unit: seg_007d0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5440
//
// 007d5440  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d5444  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d5448  8b542410             mov edx, dword ptr [esp + 0x10]
// 007d544c  56                   push esi
// 007d544d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007d5451  894638               mov dword ptr [esi + 0x38], eax
// 007d5454  b801000000           mov eax, 1
// 007d5459  894604               mov dword ptr [esi + 4], eax
// 007d545c  894608               mov dword ptr [esi + 8], eax
// 007d545f  8b463c               mov eax, dword ptr [esi + 0x3c]
// 007d5462  c646442e             mov byte ptr [esi + 0x44], 0x2e
// 007d5466  894e34               mov dword ptr [esi + 0x34], ecx
// 007d5469  c746201f010000       mov dword ptr [esi + 0x20], 0x11f
// 007d5470  c7463000000000       mov dword ptr [esi + 0x30], 0
// 007d5477  895640               mov dword ptr [esi + 0x40], edx
// 007d547a  8b5008               mov edx, dword ptr [eax + 8]
// 007d547d  8b00                 mov eax, dword ptr [eax]
// 007d547f  6a20                 push 0x20
// 007d5481  52                   push edx
// 007d5482  50                   push eax
// 007d5483  51                   push ecx
// 007d5484  e827c3ffff           call 0x7d17b0
// 007d5489  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 007d548c  8901                 mov dword ptr [ecx], eax
// 007d548e  8b563c               mov edx, dword ptr [esi + 0x3c]
// 007d5491  c7420820000000       mov dword ptr [edx + 8], 0x20
// 007d5498  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d549b  8b08                 mov ecx, dword ptr [eax]
// 007d549d  8d51ff               lea edx, [ecx - 1]
// 007d54a0  83c410               add esp, 0x10
// 007d54a3  8910                 mov dword ptr [eax], edx
// 007d54a5  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d54a8  85c9                 test ecx, ecx
// 007d54aa  760e                 jbe 0x7d54ba
// 007d54ac  8b4804               mov ecx, dword ptr [eax + 4]
// 007d54af  0fb611               movzx edx, byte ptr [ecx]
// 007d54b2  41                   inc ecx
// 007d54b3  894804               mov dword ptr [eax + 4], ecx
// 007d54b6  8916                 mov dword ptr [esi], edx
// 007d54b8  5e                   pop esi
// 007d54b9  c3                   ret 
// 007d54ba  50                   push eax
// 007d54bb  e810bcffff           call 0x7d10d0
// 007d54c0  83c404               add esp, 4
// 007d54c3  8906                 mov dword ptr [esi], eax
// 007d54c5  5e                   pop esi
// 007d54c6  c3                   ret 
// library lua-5.1/llex.c (function _luaX_setinput)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
