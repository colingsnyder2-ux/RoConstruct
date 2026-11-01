// from server: 100% by auto
// roc 2007-03 005c51f0  unit: seg_005c0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c51f0
//
// 005c51f0  57                   push edi
// 005c51f1  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005c51f4  83ff20               cmp edi, 0x20
// 005c51f7  7c11                 jl 0x5c520a
// 005c51f9  8b4608               mov eax, dword ptr [esi + 8]
// 005c51fc  68f09f7b00           push 0x7b9ff0
// 005c5201  50                   push eax
// 005c5202  e84949ffff           call 0x5b9b50
// 005c5207  83c408               add esp, 8
// 005c520a  8b542408             mov edx, dword ptr [esp + 8]
// 005c520e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c5212  52                   push edx
// 005c5213  895cfe10             mov dword ptr [esi + edi*8 + 0x10], ebx
// 005c5217  894cfe14             mov dword ptr [esi + edi*8 + 0x14], ecx
// 005c521b  53                   push ebx
// 005c521c  83c701               add edi, 1
// 005c521f  56                   push esi
// 005c5220  897e0c               mov dword ptr [esi + 0xc], edi
// 005c5223  e848010000           call 0x5c5370
// 005c5228  83c40c               add esp, 0xc
// 005c522b  85c0                 test eax, eax
// 005c522d  5f                   pop edi
// 005c522e  7504                 jne 0x5c5234
// 005c5230  83460cff             add dword ptr [esi + 0xc], -1
// 005c5234  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _start_capture)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
