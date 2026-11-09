// from server: 100% by auto
// roc 2010-06 00721800  unit: RBX::UniversalTool  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721800
//
// 00721800  8b442408             mov eax, dword ptr [esp + 8]
// 00721804  56                   push esi
// 00721805  8b742408             mov esi, dword ptr [esp + 8]
// 00721809  8bce                 mov ecx, esi
// 0072180b  e890f5ffff           call 0x720da0
// 00721810  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721813  8b10                 mov edx, dword ptr [eax]
// 00721815  83e910               sub ecx, 0x10
// 00721818  51                   push ecx
// 00721819  52                   push edx
// 0072181a  e861bd0500           call 0x77d580
// 0072181f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721822  8b10                 mov edx, dword ptr [eax]
// 00721824  83e910               sub ecx, 0x10
// 00721827  8911                 mov dword ptr [ecx], edx
// 00721829  8b5004               mov edx, dword ptr [eax + 4]
// 0072182c  895104               mov dword ptr [ecx + 4], edx
// 0072182f  8b4008               mov eax, dword ptr [eax + 8]
// 00721832  83c408               add esp, 8
// 00721835  894108               mov dword ptr [ecx + 8], eax
// 00721838  5e                   pop esi
// 00721839  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
