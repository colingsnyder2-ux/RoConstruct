// from server: 100% by auto
// roc 2011-06 00762c10  unit: seg_00760000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762c10
//
// 00762c10  8b442408             mov eax, dword ptr [esp + 8]
// 00762c14  56                   push esi
// 00762c15  8b742408             mov esi, dword ptr [esp + 8]
// 00762c19  8bce                 mov ecx, esi
// 00762c1b  e890f5ffff           call 0x7621b0
// 00762c20  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762c23  8b10                 mov edx, dword ptr [eax]
// 00762c25  83e910               sub ecx, 0x10
// 00762c28  51                   push ecx
// 00762c29  52                   push edx
// 00762c2a  e8816d0700           call 0x7d99b0
// 00762c2f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762c32  8b10                 mov edx, dword ptr [eax]
// 00762c34  83e910               sub ecx, 0x10
// 00762c37  8911                 mov dword ptr [ecx], edx
// 00762c39  8b5004               mov edx, dword ptr [eax + 4]
// 00762c3c  895104               mov dword ptr [ecx + 4], edx
// 00762c3f  8b4008               mov eax, dword ptr [eax + 8]
// 00762c42  83c408               add esp, 8
// 00762c45  894108               mov dword ptr [ecx + 8], eax
// 00762c48  5e                   pop esi
// 00762c49  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
