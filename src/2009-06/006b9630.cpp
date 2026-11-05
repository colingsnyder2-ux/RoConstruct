// from server: 100% by auto
// roc 2009-06 006b9630  unit: RBX::UniversalTool  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9630
//
// 006b9630  8b442408             mov eax, dword ptr [esp + 8]
// 006b9634  56                   push esi
// 006b9635  8b742408             mov esi, dword ptr [esp + 8]
// 006b9639  8bce                 mov ecx, esi
// 006b963b  e890f5ffff           call 0x6b8bd0
// 006b9640  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9643  8b10                 mov edx, dword ptr [eax]
// 006b9645  83e910               sub ecx, 0x10
// 006b9648  51                   push ecx
// 006b9649  52                   push edx
// 006b964a  e8912c0300           call 0x6ec2e0
// 006b964f  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9652  8b10                 mov edx, dword ptr [eax]
// 006b9654  83e910               sub ecx, 0x10
// 006b9657  8911                 mov dword ptr [ecx], edx
// 006b9659  8b5004               mov edx, dword ptr [eax + 4]
// 006b965c  895104               mov dword ptr [ecx + 4], edx
// 006b965f  8b4008               mov eax, dword ptr [eax + 8]
// 006b9662  83c408               add esp, 8
// 006b9665  894108               mov dword ptr [ecx + 8], eax
// 006b9668  5e                   pop esi
// 006b9669  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
