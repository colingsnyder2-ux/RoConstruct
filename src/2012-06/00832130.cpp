// from server: 100% by auto
// roc 2012-06 00832130  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832130
//
// 00832130  55                   push ebp
// 00832131  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00832135  85ed                 test ebp, ebp
// 00832137  7510                 jne 0x832149
// 00832139  8b442408             mov eax, dword ptr [esp + 8]
// 0083213d  8b4808               mov ecx, dword ptr [eax + 8]
// 00832140  896908               mov dword ptr [ecx + 8], ebp
// 00832143  83400810             add dword ptr [eax + 8], 0x10
// 00832147  5d                   pop ebp
// 00832148  c3                   ret 
// 00832149  8bc5                 mov eax, ebp
// 0083214b  8d5001               lea edx, [eax + 1]
// 0083214e  8bff                 mov edi, edi
// 00832150  8a08                 mov cl, byte ptr [eax]
// 00832152  40                   inc eax
// 00832153  84c9                 test cl, cl
// 00832155  75f9                 jne 0x832150
// 00832157  53                   push ebx
// 00832158  2bc2                 sub eax, edx
// 0083215a  56                   push esi
// 0083215b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0083215f  8bd8                 mov ebx, eax
// 00832161  8b4610               mov eax, dword ptr [esi + 0x10]
// 00832164  8b5044               mov edx, dword ptr [eax + 0x44]
// 00832167  57                   push edi
// 00832168  3b5040               cmp edx, dword ptr [eax + 0x40]
// 0083216b  7209                 jb 0x832176
// 0083216d  56                   push esi
// 0083216e  e83d111000           call 0x9332b0
// 00832173  83c404               add esp, 4
// 00832176  8b7e08               mov edi, dword ptr [esi + 8]
// 00832179  53                   push ebx
// 0083217a  55                   push ebp
// 0083217b  56                   push esi
// 0083217c  e8af411000           call 0x936330
// 00832181  83c40c               add esp, 0xc
// 00832184  8907                 mov dword ptr [edi], eax
// 00832186  c7470804000000       mov dword ptr [edi + 8], 4
// 0083218d  83460810             add dword ptr [esi + 8], 0x10
// 00832191  5f                   pop edi
// 00832192  5e                   pop esi
// 00832193  5b                   pop ebx
// 00832194  5d                   pop ebp
// 00832195  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
