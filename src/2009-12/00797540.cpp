// from server: 100% by auto
// roc 2009-12 00797540  unit: lua_exception  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797540
//
// 00797540  2b4620               sub eax, dword ptr [esi + 0x20]
// 00797543  57                   push edi
// 00797544  6aff                 push -1
// 00797546  6a01                 push 1
// 00797548  56                   push esi
// 00797549  8bf8                 mov edi, eax
// 0079754b  e810feffff           call 0x797360
// 00797550  8b4614               mov eax, dword ptr [esi + 0x14]
// 00797553  8b4804               mov ecx, dword ptr [eax + 4]
// 00797556  8b11                 mov edx, dword ptr [ecx]
// 00797558  83c40c               add esp, 0xc
// 0079755b  807a0600             cmp byte ptr [edx + 6], 0
// 0079755f  7529                 jne 0x79758a
// 00797561  f6463802             test byte ptr [esi + 0x38], 2
// 00797565  7423                 je 0x79758a
// 00797567  8b4614               mov eax, dword ptr [esi + 0x14]
// 0079756a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0079756d  8d51ff               lea edx, [ecx - 1]
// 00797570  895014               mov dword ptr [eax + 0x14], edx
// 00797573  85c9                 test ecx, ecx
// 00797575  7413                 je 0x79758a
// 00797577  6aff                 push -1
// 00797579  6a04                 push 4
// 0079757b  56                   push esi
// 0079757c  e8dffdffff           call 0x797360
// 00797581  83c40c               add esp, 0xc
// 00797584  f6463802             test byte ptr [esi + 0x38], 2
// 00797588  75dd                 jne 0x797567
// 0079758a  8b4620               mov eax, dword ptr [esi + 0x20]
// 0079758d  03c7                 add eax, edi
// 0079758f  5f                   pop edi
// 00797590  c3                   ret 
// library lua-5.1.3/ldo.c (function _callrethooks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
