// from server: 100% by auto
// roc 2009-12 0079b2b0  unit: seg_00790000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b2b0
//
// 0079b2b0  56                   push esi
// 0079b2b1  8b742408             mov esi, dword ptr [esp + 8]
// 0079b2b5  8b4674               mov eax, dword ptr [esi + 0x74]
// 0079b2b8  85c0                 test eax, eax
// 0079b2ba  746e                 je 0x79b32a
// 0079b2bc  57                   push edi
// 0079b2bd  8b7e20               mov edi, dword ptr [esi + 0x20]
// 0079b2c0  03f8                 add edi, eax
// 0079b2c2  837f0806             cmp dword ptr [edi + 8], 6
// 0079b2c6  740b                 je 0x79b2d3
// 0079b2c8  6a05                 push 5
// 0079b2ca  56                   push esi
// 0079b2cb  e880c5ffff           call 0x797850
// 0079b2d0  83c408               add esp, 8
// 0079b2d3  8b4608               mov eax, dword ptr [esi + 8]
// 0079b2d6  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 0079b2d9  8908                 mov dword ptr [eax], ecx
// 0079b2db  8b50f4               mov edx, dword ptr [eax - 0xc]
// 0079b2de  895004               mov dword ptr [eax + 4], edx
// 0079b2e1  8b48f8               mov ecx, dword ptr [eax - 8]
// 0079b2e4  894808               mov dword ptr [eax + 8], ecx
// 0079b2e7  8b4608               mov eax, dword ptr [esi + 8]
// 0079b2ea  8b17                 mov edx, dword ptr [edi]
// 0079b2ec  83e810               sub eax, 0x10
// 0079b2ef  8910                 mov dword ptr [eax], edx
// 0079b2f1  8b4f04               mov ecx, dword ptr [edi + 4]
// 0079b2f4  894804               mov dword ptr [eax + 4], ecx
// 0079b2f7  8b5708               mov edx, dword ptr [edi + 8]
// 0079b2fa  895008               mov dword ptr [eax + 8], edx
// 0079b2fd  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0079b300  2b4608               sub eax, dword ptr [esi + 8]
// 0079b303  5f                   pop edi
// 0079b304  83f810               cmp eax, 0x10
// 0079b307  7f0b                 jg 0x79b314
// 0079b309  6a01                 push 1
// 0079b30b  56                   push esi
// 0079b30c  e81fc0ffff           call 0x797330
// 0079b311  83c408               add esp, 8
// 0079b314  83460810             add dword ptr [esi + 8], 0x10
// 0079b318  8b4608               mov eax, dword ptr [esi + 8]
// 0079b31b  6a01                 push 1
// 0079b31d  83c0e0               add eax, -0x20
// 0079b320  50                   push eax
// 0079b321  56                   push esi
// 0079b322  e8d9c7ffff           call 0x797b00
// 0079b327  83c40c               add esp, 0xc
// 0079b32a  6a02                 push 2
// 0079b32c  56                   push esi
// 0079b32d  e81ec5ffff           call 0x797850
// 0079b332  83c408               add esp, 8
// 0079b335  5e                   pop esi
// 0079b336  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_errormsg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
