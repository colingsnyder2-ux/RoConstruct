// from server: 100% by auto
// roc 2012-06 00832660  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832660
//
// 00832660  8b442408             mov eax, dword ptr [esp + 8]
// 00832664  53                   push ebx
// 00832665  56                   push esi
// 00832666  57                   push edi
// 00832667  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0083266b  8bcf                 mov ecx, edi
// 0083266d  e8cef2ffff           call 0x831940
// 00832672  8b7708               mov esi, dword ptr [edi + 8]
// 00832675  8bd8                 mov ebx, eax
// 00832677  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083267b  8b0b                 mov ecx, dword ptr [ebx]
// 0083267d  50                   push eax
// 0083267e  51                   push ecx
// 0083267f  57                   push edi
// 00832680  83ee10               sub esi, 0x10
// 00832683  e858351000           call 0x935be0
// 00832688  8b16                 mov edx, dword ptr [esi]
// 0083268a  8910                 mov dword ptr [eax], edx
// 0083268c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0083268f  894804               mov dword ptr [eax + 4], ecx
// 00832692  8b5608               mov edx, dword ptr [esi + 8]
// 00832695  895008               mov dword ptr [eax + 8], edx
// 00832698  8b4708               mov eax, dword ptr [edi + 8]
// 0083269b  b904000000           mov ecx, 4
// 008326a0  83c40c               add esp, 0xc
// 008326a3  3948f8               cmp dword ptr [eax - 8], ecx
// 008326a6  7c1a                 jl 0x8326c2
// 008326a8  8b40f0               mov eax, dword ptr [eax - 0x10]
// 008326ab  f6400503             test byte ptr [eax + 5], 3
// 008326af  7411                 je 0x8326c2
// 008326b1  8b1b                 mov ebx, dword ptr [ebx]
// 008326b3  844b05               test byte ptr [ebx + 5], cl
// 008326b6  740a                 je 0x8326c2
// 008326b8  53                   push ebx
// 008326b9  57                   push edi
// 008326ba  e8210d1000           call 0x9333e0
// 008326bf  83c408               add esp, 8
// 008326c2  834708f0             add dword ptr [edi + 8], -0x10
// 008326c6  5f                   pop edi
// 008326c7  5e                   pop esi
// 008326c8  5b                   pop ebx
// 008326c9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
