// from server: 100% by auto
// roc 2008-06 00612010  unit: seg_00610000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612010
//
// 00612010  56                   push esi
// 00612011  8b742408             mov esi, dword ptr [esp + 8]
// 00612015  57                   push edi
// 00612016  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061201a  8bc7                 mov eax, edi
// 0061201c  8bce                 mov ecx, esi
// 0061201e  e86dfaffff           call 0x611a90
// 00612023  83780804             cmp dword ptr [eax + 8], 4
// 00612027  743e                 je 0x612067
// 00612029  50                   push eax
// 0061202a  56                   push esi
// 0061202b  e880a60400           call 0x65c6b0
// 00612030  83c408               add esp, 8
// 00612033  85c0                 test eax, eax
// 00612035  7513                 jne 0x61204a
// 00612037  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061203b  85c0                 test eax, eax
// 0061203d  7406                 je 0x612045
// 0061203f  c70000000000         mov dword ptr [eax], 0
// 00612045  5f                   pop edi
// 00612046  33c0                 xor eax, eax
// 00612048  5e                   pop esi
// 00612049  c3                   ret 
// 0061204a  8b4610               mov eax, dword ptr [esi + 0x10]
// 0061204d  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00612050  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00612053  7209                 jb 0x61205e
// 00612055  56                   push esi
// 00612056  e835a30400           call 0x65c390
// 0061205b  83c404               add esp, 4
// 0061205e  8bc7                 mov eax, edi
// 00612060  8bce                 mov ecx, esi
// 00612062  e829faffff           call 0x611a90
// 00612067  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0061206b  85c9                 test ecx, ecx
// 0061206d  7407                 je 0x612076
// 0061206f  8b10                 mov edx, dword ptr [eax]
// 00612071  8b520c               mov edx, dword ptr [edx + 0xc]
// 00612074  8911                 mov dword ptr [ecx], edx
// 00612076  8b00                 mov eax, dword ptr [eax]
// 00612078  5f                   pop edi
// 00612079  83c010               add eax, 0x10
// 0061207c  5e                   pop esi
// 0061207d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
