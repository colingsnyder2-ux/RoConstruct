// from server: 100% by auto
// roc 2009-06 006c39b0  unit: lua_exception  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c39b0
//
// 006c39b0  56                   push esi
// 006c39b1  8bf0                 mov esi, eax
// 006c39b3  8b4620               mov eax, dword ptr [esi + 0x20]
// 006c39b6  57                   push edi
// 006c39b7  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006c39ba  50                   push eax
// 006c39bb  56                   push esi
// 006c39bc  e87f940200           call 0x6ece40
// 006c39c1  56                   push esi
// 006c39c2  e8495e0200           call 0x6e9810
// 006c39c7  8b4610               mov eax, dword ptr [esi + 0x10]
// 006c39ca  8b4808               mov ecx, dword ptr [eax + 8]
// 006c39cd  8b10                 mov edx, dword ptr [eax]
// 006c39cf  03c9                 add ecx, ecx
// 006c39d1  6a00                 push 0
// 006c39d3  03c9                 add ecx, ecx
// 006c39d5  51                   push ecx
// 006c39d6  52                   push edx
// 006c39d7  56                   push esi
// 006c39d8  e8839d0200           call 0x6ed760
// 006c39dd  8b473c               mov eax, dword ptr [edi + 0x3c]
// 006c39e0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 006c39e3  6a00                 push 0
// 006c39e5  50                   push eax
// 006c39e6  51                   push ecx
// 006c39e7  56                   push esi
// 006c39e8  e8739d0200           call 0x6ed760
// 006c39ed  894734               mov dword ptr [edi + 0x34], eax
// 006c39f0  c7473c00000000       mov dword ptr [edi + 0x3c], 0
// 006c39f7  8b4630               mov eax, dword ptr [esi + 0x30]
// 006c39fa  8d1440               lea edx, [eax + eax*2]
// 006c39fd  8b4628               mov eax, dword ptr [esi + 0x28]
// 006c3a00  03d2                 add edx, edx
// 006c3a02  03d2                 add edx, edx
// 006c3a04  6a00                 push 0
// 006c3a06  03d2                 add edx, edx
// 006c3a08  52                   push edx
// 006c3a09  50                   push eax
// 006c3a0a  56                   push esi
// 006c3a0b  e8509d0200           call 0x6ed760
// 006c3a10  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 006c3a13  8b5620               mov edx, dword ptr [esi + 0x20]
// 006c3a16  6a00                 push 0
// 006c3a18  c1e104               shl ecx, 4
// 006c3a1b  51                   push ecx
// 006c3a1c  52                   push edx
// 006c3a1d  56                   push esi
// 006c3a1e  e83d9d0200           call 0x6ed760
// 006c3a23  8b4710               mov eax, dword ptr [edi + 0x10]
// 006c3a26  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006c3a29  83c44c               add esp, 0x4c
// 006c3a2c  6a00                 push 0
// 006c3a2e  6884010000           push 0x184
// 006c3a33  83c6f4               add esi, -0xc
// 006c3a36  56                   push esi
// 006c3a37  50                   push eax
// 006c3a38  ffd1                 call ecx
// 006c3a3a  83c410               add esp, 0x10
// 006c3a3d  5f                   pop edi
// 006c3a3e  5e                   pop esi
// 006c3a3f  c3                   ret 
// library lua-5.1.2-rbx/lstate.c (function _close_state)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2-rbx lstate.c
