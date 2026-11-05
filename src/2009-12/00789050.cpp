// from server: 100% by auto
// roc 2009-12 00789050  unit: RBX::UniversalTool  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789050
//
// 00789050  8b442408             mov eax, dword ptr [esp + 8]
// 00789054  56                   push esi
// 00789055  8b742408             mov esi, dword ptr [esp + 8]
// 00789059  8bce                 mov ecx, esi
// 0078905b  e890f5ffff           call 0x7885f0
// 00789060  8b4e08               mov ecx, dword ptr [esi + 8]
// 00789063  8b10                 mov edx, dword ptr [eax]
// 00789065  83e910               sub ecx, 0x10
// 00789068  51                   push ecx
// 00789069  52                   push edx
// 0078906a  e8c1720400           call 0x7d0330
// 0078906f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00789072  8b10                 mov edx, dword ptr [eax]
// 00789074  83e910               sub ecx, 0x10
// 00789077  8911                 mov dword ptr [ecx], edx
// 00789079  8b5004               mov edx, dword ptr [eax + 4]
// 0078907c  895104               mov dword ptr [ecx + 4], edx
// 0078907f  8b4008               mov eax, dword ptr [eax + 8]
// 00789082  83c408               add esp, 8
// 00789085  894108               mov dword ptr [ecx + 8], eax
// 00789088  5e                   pop esi
// 00789089  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
