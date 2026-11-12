// from server: 100% by auto
// roc 2008-06 004c37a0  unit: ProfiledRakPeer  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c37a0
//
// 004c37a0  83ec40               sub esp, 0x40
// 004c37a3  56                   push esi
// 004c37a4  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 004c37a8  57                   push edi
// 004c37a9  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 004c37ad  56                   push esi
// 004c37ae  57                   push edi
// 004c37af  e84cdeffff           call 0x4c1600
// 004c37b4  8b06                 mov eax, dword ptr [esi]
// 004c37b6  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c37b9  8b5608               mov edx, dword ptr [esi + 8]
// 004c37bc  89442440             mov dword ptr [esp + 0x40], eax
// 004c37c0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c37c3  83c408               add esp, 8
// 004c37c6  89442444             mov dword ptr [esp + 0x44], eax
// 004c37ca  33c0                 xor eax, eax
// 004c37cc  894c243c             mov dword ptr [esp + 0x3c], ecx
// 004c37d0  89542440             mov dword ptr [esp + 0x40], edx
// 004c37d4  89442428             mov dword ptr [esp + 0x28], eax
// 004c37d8  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c37dc  89442430             mov dword ptr [esp + 0x30], eax
// 004c37e0  89442434             mov dword ptr [esp + 0x34], eax
// 004c37e4  8b4c8428             mov ecx, dword ptr [esp + eax*4 + 0x28]
// 004c37e8  8d51ff               lea edx, [ecx - 1]
// 004c37eb  89548428             mov dword ptr [esp + eax*4 + 0x28], edx
// 004c37ef  85c9                 test ecx, ecx
// 004c37f1  7506                 jne 0x4c37f9
// 004c37f3  40                   inc eax
// 004c37f4  83f808               cmp eax, 8
// 004c37f7  72eb                 jb 0x4c37e4
// 004c37f9  8b07                 mov eax, dword ptr [edi]
// 004c37fb  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c37fe  8b5708               mov edx, dword ptr [edi + 8]
// 004c3801  89442408             mov dword ptr [esp + 8], eax
// 004c3805  8b470c               mov eax, dword ptr [edi + 0xc]
// 004c3808  894c240c             mov dword ptr [esp + 0xc], ecx
// 004c380c  89442414             mov dword ptr [esp + 0x14], eax
// 004c3810  33c0                 xor eax, eax
// 004c3812  8d4c2428             lea ecx, [esp + 0x28]
// 004c3816  51                   push ecx
// 004c3817  89542414             mov dword ptr [esp + 0x14], edx
// 004c381b  8d54240c             lea edx, [esp + 0xc]
// 004c381f  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c3823  89442420             mov dword ptr [esp + 0x20], eax
// 004c3827  89442424             mov dword ptr [esp + 0x24], eax
// 004c382b  89442428             mov dword ptr [esp + 0x28], eax
// 004c382f  52                   push edx
// 004c3830  8bc2                 mov eax, edx
// 004c3832  50                   push eax
// 004c3833  51                   push ecx
// 004c3834  e867b4ffff           call 0x4beca0
// 004c3839  8b542418             mov edx, dword ptr [esp + 0x18]
// 004c383d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c3841  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c3845  8916                 mov dword ptr [esi], edx
// 004c3847  8b542424             mov edx, dword ptr [esp + 0x24]
// 004c384b  83c410               add esp, 0x10
// 004c384e  894604               mov dword ptr [esi + 4], eax
// 004c3851  894e08               mov dword ptr [esi + 8], ecx
// 004c3854  5f                   pop edi
// 004c3855  89560c               mov dword ptr [esi + 0xc], edx
// 004c3858  5e                   pop esi
// 004c3859  83c440               add esp, 0x40
// 004c385c  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$computeNRinverse@$$BY03I@big@@YAXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
