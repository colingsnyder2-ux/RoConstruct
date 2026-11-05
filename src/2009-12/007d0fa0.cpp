// from server: 100% by auto
// roc 2009-12 007d0fa0  unit: seg_007d0000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0fa0
//
// 007d0fa0  56                   push esi
// 007d0fa1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007d0fa5  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007d0fa8  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d0fab  57                   push edi
// 007d0fac  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d0fb0  03c0                 add eax, eax
// 007d0fb2  6a00                 push 0
// 007d0fb4  03c0                 add eax, eax
// 007d0fb6  50                   push eax
// 007d0fb7  51                   push ecx
// 007d0fb8  57                   push edi
// 007d0fb9  e8f2070000           call 0x7d17b0
// 007d0fbe  8b5634               mov edx, dword ptr [esi + 0x34]
// 007d0fc1  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d0fc4  03d2                 add edx, edx
// 007d0fc6  6a00                 push 0
// 007d0fc8  03d2                 add edx, edx
// 007d0fca  52                   push edx
// 007d0fcb  50                   push eax
// 007d0fcc  57                   push edi
// 007d0fcd  e8de070000           call 0x7d17b0
// 007d0fd2  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 007d0fd5  8b5608               mov edx, dword ptr [esi + 8]
// 007d0fd8  6a00                 push 0
// 007d0fda  c1e104               shl ecx, 4
// 007d0fdd  51                   push ecx
// 007d0fde  52                   push edx
// 007d0fdf  57                   push edi
// 007d0fe0  e8cb070000           call 0x7d17b0
// 007d0fe5  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d0fe8  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007d0feb  03c0                 add eax, eax
// 007d0fed  6a00                 push 0
// 007d0fef  03c0                 add eax, eax
// 007d0ff1  50                   push eax
// 007d0ff2  51                   push ecx
// 007d0ff3  57                   push edi
// 007d0ff4  e8b7070000           call 0x7d17b0
// 007d0ff9  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d0ffc  8d1440               lea edx, [eax + eax*2]
// 007d0fff  8b4618               mov eax, dword ptr [esi + 0x18]
// 007d1002  83c440               add esp, 0x40
// 007d1005  03d2                 add edx, edx
// 007d1007  6a00                 push 0
// 007d1009  03d2                 add edx, edx
// 007d100b  52                   push edx
// 007d100c  50                   push eax
// 007d100d  57                   push edi
// 007d100e  e89d070000           call 0x7d17b0
// 007d1013  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 007d1016  8b561c               mov edx, dword ptr [esi + 0x1c]
// 007d1019  03c9                 add ecx, ecx
// 007d101b  6a00                 push 0
// 007d101d  03c9                 add ecx, ecx
// 007d101f  51                   push ecx
// 007d1020  52                   push edx
// 007d1021  57                   push edi
// 007d1022  e889070000           call 0x7d17b0
// 007d1027  6a00                 push 0
// 007d1029  6a4c                 push 0x4c
// 007d102b  56                   push esi
// 007d102c  57                   push edi
// 007d102d  e87e070000           call 0x7d17b0
// 007d1032  83c430               add esp, 0x30
// 007d1035  5f                   pop edi
// 007d1036  5e                   pop esi
// 007d1037  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_freeproto)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
