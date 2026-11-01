// from server: 100% by auto
// roc 2007-03 005b95c0  unit: seg_005b0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b95c0
//
// 005b95c0  8b442408             mov eax, dword ptr [esp + 8]
// 005b95c4  53                   push ebx
// 005b95c5  56                   push esi
// 005b95c6  57                   push edi
// 005b95c7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b95cb  8bcf                 mov ecx, edi
// 005b95cd  e8def2ffff           call 0x5b88b0
// 005b95d2  8b7708               mov esi, dword ptr [edi + 8]
// 005b95d5  8bd8                 mov ebx, eax
// 005b95d7  8b442418             mov eax, dword ptr [esp + 0x18]
// 005b95db  8b0b                 mov ecx, dword ptr [ebx]
// 005b95dd  50                   push eax
// 005b95de  51                   push ecx
// 005b95df  57                   push edi
// 005b95e0  83ee10               sub esi, 0x10
// 005b95e3  e8f8290400           call 0x5fbfe0
// 005b95e8  8b16                 mov edx, dword ptr [esi]
// 005b95ea  8910                 mov dword ptr [eax], edx
// 005b95ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b95ef  894804               mov dword ptr [eax + 4], ecx
// 005b95f2  8b5608               mov edx, dword ptr [esi + 8]
// 005b95f5  895008               mov dword ptr [eax + 8], edx
// 005b95f8  8b4708               mov eax, dword ptr [edi + 8]
// 005b95fb  b904000000           mov ecx, 4
// 005b9600  83c40c               add esp, 0xc
// 005b9603  3948f8               cmp dword ptr [eax - 8], ecx
// 005b9606  7c1a                 jl 0x5b9622
// 005b9608  8b40f0               mov eax, dword ptr [eax - 0x10]
// 005b960b  f6400503             test byte ptr [eax + 5], 3
// 005b960f  7411                 je 0x5b9622
// 005b9611  8b1b                 mov ebx, dword ptr [ebx]
// 005b9613  844b05               test byte ptr [ebx + 5], cl
// 005b9616  740a                 je 0x5b9622
// 005b9618  53                   push ebx
// 005b9619  57                   push edi
// 005b961a  e8c1020400           call 0x5f98e0
// 005b961f  83c408               add esp, 8
// 005b9622  834708f0             add dword ptr [edi + 8], -0x10
// 005b9626  5f                   pop edi
// 005b9627  5e                   pop esi
// 005b9628  5b                   pop ebx
// 005b9629  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
