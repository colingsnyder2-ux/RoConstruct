// from server: 100% by auto
// roc 2007-08 005be0f0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be0f0
//
// 005be0f0  8b442408             mov eax, dword ptr [esp + 8]
// 005be0f4  53                   push ebx
// 005be0f5  56                   push esi
// 005be0f6  57                   push edi
// 005be0f7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005be0fb  8bcf                 mov ecx, edi
// 005be0fd  e82ef3ffff           call 0x5bd430
// 005be102  8b7708               mov esi, dword ptr [edi + 8]
// 005be105  8bd8                 mov ebx, eax
// 005be107  8b442418             mov eax, dword ptr [esp + 0x18]
// 005be10b  8b0b                 mov ecx, dword ptr [ebx]
// 005be10d  50                   push eax
// 005be10e  51                   push ecx
// 005be10f  57                   push edi
// 005be110  83ee10               sub esi, 0x10
// 005be113  e818450500           call 0x612630
// 005be118  8b16                 mov edx, dword ptr [esi]
// 005be11a  8910                 mov dword ptr [eax], edx
// 005be11c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005be11f  894804               mov dword ptr [eax + 4], ecx
// 005be122  8b5608               mov edx, dword ptr [esi + 8]
// 005be125  895008               mov dword ptr [eax + 8], edx
// 005be128  8b4708               mov eax, dword ptr [edi + 8]
// 005be12b  b904000000           mov ecx, 4
// 005be130  83c40c               add esp, 0xc
// 005be133  3948f8               cmp dword ptr [eax - 8], ecx
// 005be136  7c1a                 jl 0x5be152
// 005be138  8b40f0               mov eax, dword ptr [eax - 0x10]
// 005be13b  f6400503             test byte ptr [eax + 5], 3
// 005be13f  7411                 je 0x5be152
// 005be141  8b1b                 mov ebx, dword ptr [ebx]
// 005be143  844b05               test byte ptr [ebx + 5], cl
// 005be146  740a                 je 0x5be152
// 005be148  53                   push ebx
// 005be149  57                   push edi
// 005be14a  e8e11d0500           call 0x60ff30
// 005be14f  83c408               add esp, 8
// 005be152  834708f0             add dword ptr [edi + 8], -0x10
// 005be156  5f                   pop edi
// 005be157  5e                   pop esi
// 005be158  5b                   pop ebx
// 005be159  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
