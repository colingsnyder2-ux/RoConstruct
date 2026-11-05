// from server: 100% by auto
// roc 2007-08 005be080  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be080
//
// 005be080  8b442408             mov eax, dword ptr [esp + 8]
// 005be084  53                   push ebx
// 005be085  56                   push esi
// 005be086  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005be08a  57                   push edi
// 005be08b  8bce                 mov ecx, esi
// 005be08d  e89ef3ffff           call 0x5bd430
// 005be092  8b7e08               mov edi, dword ptr [esi + 8]
// 005be095  8bd8                 mov ebx, eax
// 005be097  8b0b                 mov ecx, dword ptr [ebx]
// 005be099  8d47e0               lea eax, [edi - 0x20]
// 005be09c  50                   push eax
// 005be09d  51                   push ecx
// 005be09e  56                   push esi
// 005be09f  e81c450500           call 0x6125c0
// 005be0a4  8b57f0               mov edx, dword ptr [edi - 0x10]
// 005be0a7  8910                 mov dword ptr [eax], edx
// 005be0a9  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 005be0ac  894804               mov dword ptr [eax + 4], ecx
// 005be0af  8b57f8               mov edx, dword ptr [edi - 8]
// 005be0b2  895008               mov dword ptr [eax + 8], edx
// 005be0b5  8b4608               mov eax, dword ptr [esi + 8]
// 005be0b8  b904000000           mov ecx, 4
// 005be0bd  83c40c               add esp, 0xc
// 005be0c0  3948f8               cmp dword ptr [eax - 8], ecx
// 005be0c3  7c1a                 jl 0x5be0df
// 005be0c5  8b40f0               mov eax, dword ptr [eax - 0x10]
// 005be0c8  f6400503             test byte ptr [eax + 5], 3
// 005be0cc  7411                 je 0x5be0df
// 005be0ce  8b1b                 mov ebx, dword ptr [ebx]
// 005be0d0  844b05               test byte ptr [ebx + 5], cl
// 005be0d3  740a                 je 0x5be0df
// 005be0d5  53                   push ebx
// 005be0d6  56                   push esi
// 005be0d7  e8541e0500           call 0x60ff30
// 005be0dc  83c408               add esp, 8
// 005be0df  834608e0             add dword ptr [esi + 8], -0x20
// 005be0e3  5f                   pop edi
// 005be0e4  5e                   pop esi
// 005be0e5  5b                   pop ebx
// 005be0e6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawset)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
