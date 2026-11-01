// from server: 100% by auto
// roc 2007-03 00614be0  unit: seg_00610000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614be0
//
// 00614be0  8b542410             mov edx, dword ptr [esp + 0x10]
// 00614be4  c1e208               shl edx, 8
// 00614be7  0b54240c             or edx, dword ptr [esp + 0xc]
// 00614beb  56                   push esi
// 00614bec  8b742408             mov esi, dword ptr [esp + 8]
// 00614bf0  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614bf3  8b4808               mov ecx, dword ptr [eax + 8]
// 00614bf6  c1e206               shl edx, 6
// 00614bf9  0b54240c             or edx, dword ptr [esp + 0xc]
// 00614bfd  51                   push ecx
// 00614bfe  52                   push edx
// 00614bff  e80cffffff           call 0x614b10
// 00614c04  83c408               add esp, 8
// 00614c07  5e                   pop esi
// 00614c08  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_codeABx)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
