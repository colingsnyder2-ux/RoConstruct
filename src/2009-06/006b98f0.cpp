// from server: 100% by auto
// roc 2009-06 006b98f0  unit: RBX::UniversalTool  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b98f0
//
// 006b98f0  8b442408             mov eax, dword ptr [esp + 8]
// 006b98f4  53                   push ebx
// 006b98f5  56                   push esi
// 006b98f6  57                   push edi
// 006b98f7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006b98fb  8bcf                 mov ecx, edi
// 006b98fd  e8cef2ffff           call 0x6b8bd0
// 006b9902  8b7708               mov esi, dword ptr [edi + 8]
// 006b9905  8bd8                 mov ebx, eax
// 006b9907  8b442418             mov eax, dword ptr [esp + 0x18]
// 006b990b  8b0b                 mov ecx, dword ptr [ebx]
// 006b990d  50                   push eax
// 006b990e  51                   push ecx
// 006b990f  57                   push edi
// 006b9910  83ee10               sub esi, 0x10
// 006b9913  e8e82a0300           call 0x6ec400
// 006b9918  8b16                 mov edx, dword ptr [esi]
// 006b991a  8910                 mov dword ptr [eax], edx
// 006b991c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b991f  894804               mov dword ptr [eax + 4], ecx
// 006b9922  8b5608               mov edx, dword ptr [esi + 8]
// 006b9925  895008               mov dword ptr [eax + 8], edx
// 006b9928  8b4708               mov eax, dword ptr [edi + 8]
// 006b992b  b904000000           mov ecx, 4
// 006b9930  83c40c               add esp, 0xc
// 006b9933  3948f8               cmp dword ptr [eax - 8], ecx
// 006b9936  7c1a                 jl 0x6b9952
// 006b9938  8b40f0               mov eax, dword ptr [eax - 0x10]
// 006b993b  f6400503             test byte ptr [eax + 5], 3
// 006b993f  7411                 je 0x6b9952
// 006b9941  8b1b                 mov ebx, dword ptr [ebx]
// 006b9943  844b05               test byte ptr [ebx + 5], cl
// 006b9946  740a                 je 0x6b9952
// 006b9948  53                   push ebx
// 006b9949  57                   push edi
// 006b994a  e8a1030300           call 0x6e9cf0
// 006b994f  83c408               add esp, 8
// 006b9952  834708f0             add dword ptr [edi + 8], -0x10
// 006b9956  5f                   pop edi
// 006b9957  5e                   pop esi
// 006b9958  5b                   pop ebx
// 006b9959  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
