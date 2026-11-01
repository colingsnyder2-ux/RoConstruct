// from server: 100% by auto
// roc 2007-03 005c3020  unit: seg_005c0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3020
//
// 005c3020  56                   push esi
// 005c3021  8b742408             mov esi, dword ptr [esp + 8]
// 005c3025  8b4674               mov eax, dword ptr [esi + 0x74]
// 005c3028  85c0                 test eax, eax
// 005c302a  746e                 je 0x5c309a
// 005c302c  57                   push edi
// 005c302d  8b7e20               mov edi, dword ptr [esi + 0x20]
// 005c3030  03f8                 add edi, eax
// 005c3032  837f0806             cmp dword ptr [edi + 8], 6
// 005c3036  740b                 je 0x5c3043
// 005c3038  6a05                 push 5
// 005c303a  56                   push esi
// 005c303b  e8c0d1ffff           call 0x5c0200
// 005c3040  83c408               add esp, 8
// 005c3043  8b4608               mov eax, dword ptr [esi + 8]
// 005c3046  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 005c3049  8908                 mov dword ptr [eax], ecx
// 005c304b  8b50f4               mov edx, dword ptr [eax - 0xc]
// 005c304e  895004               mov dword ptr [eax + 4], edx
// 005c3051  8b48f8               mov ecx, dword ptr [eax - 8]
// 005c3054  894808               mov dword ptr [eax + 8], ecx
// 005c3057  8b4608               mov eax, dword ptr [esi + 8]
// 005c305a  8b17                 mov edx, dword ptr [edi]
// 005c305c  83e810               sub eax, 0x10
// 005c305f  8910                 mov dword ptr [eax], edx
// 005c3061  8b4f04               mov ecx, dword ptr [edi + 4]
// 005c3064  894804               mov dword ptr [eax + 4], ecx
// 005c3067  8b5708               mov edx, dword ptr [edi + 8]
// 005c306a  895008               mov dword ptr [eax + 8], edx
// 005c306d  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005c3070  2b4608               sub eax, dword ptr [esi + 8]
// 005c3073  5f                   pop edi
// 005c3074  83f810               cmp eax, 0x10
// 005c3077  7f0b                 jg 0x5c3084
// 005c3079  6a01                 push 1
// 005c307b  56                   push esi
// 005c307c  e86fccffff           call 0x5bfcf0
// 005c3081  83c408               add esp, 8
// 005c3084  83460810             add dword ptr [esi + 8], 0x10
// 005c3088  8b4608               mov eax, dword ptr [esi + 8]
// 005c308b  6a01                 push 1
// 005c308d  83c0e0               add eax, -0x20
// 005c3090  50                   push eax
// 005c3091  56                   push esi
// 005c3092  e819d4ffff           call 0x5c04b0
// 005c3097  83c40c               add esp, 0xc
// 005c309a  6a02                 push 2
// 005c309c  56                   push esi
// 005c309d  e85ed1ffff           call 0x5c0200
// 005c30a2  83c408               add esp, 8
// 005c30a5  5e                   pop esi
// 005c30a6  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_errormsg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
