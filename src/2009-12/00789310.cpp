// from server: 100% by auto
// roc 2009-12 00789310  unit: RBX::UniversalTool  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789310
//
// 00789310  8b442408             mov eax, dword ptr [esp + 8]
// 00789314  53                   push ebx
// 00789315  56                   push esi
// 00789316  57                   push edi
// 00789317  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0078931b  8bcf                 mov ecx, edi
// 0078931d  e8cef2ffff           call 0x7885f0
// 00789322  8b7708               mov esi, dword ptr [edi + 8]
// 00789325  8bd8                 mov ebx, eax
// 00789327  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078932b  8b0b                 mov ecx, dword ptr [ebx]
// 0078932d  50                   push eax
// 0078932e  51                   push ecx
// 0078932f  57                   push edi
// 00789330  83ee10               sub esi, 0x10
// 00789333  e818710400           call 0x7d0450
// 00789338  8b16                 mov edx, dword ptr [esi]
// 0078933a  8910                 mov dword ptr [eax], edx
// 0078933c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078933f  894804               mov dword ptr [eax + 4], ecx
// 00789342  8b5608               mov edx, dword ptr [esi + 8]
// 00789345  895008               mov dword ptr [eax + 8], edx
// 00789348  8b4708               mov eax, dword ptr [edi + 8]
// 0078934b  b904000000           mov ecx, 4
// 00789350  83c40c               add esp, 0xc
// 00789353  3948f8               cmp dword ptr [eax - 8], ecx
// 00789356  7c1a                 jl 0x789372
// 00789358  8b40f0               mov eax, dword ptr [eax - 0x10]
// 0078935b  f6400503             test byte ptr [eax + 5], 3
// 0078935f  7411                 je 0x789372
// 00789361  8b1b                 mov ebx, dword ptr [ebx]
// 00789363  844b05               test byte ptr [ebx + 5], cl
// 00789366  740a                 je 0x789372
// 00789368  53                   push ebx
// 00789369  57                   push edi
// 0078936a  e8d1490400           call 0x7cdd40
// 0078936f  83c408               add esp, 8
// 00789372  834708f0             add dword ptr [edi + 8], -0x10
// 00789376  5f                   pop edi
// 00789377  5e                   pop esi
// 00789378  5b                   pop ebx
// 00789379  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
