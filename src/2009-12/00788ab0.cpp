// from server: 100% by auto
// roc 2009-12 00788ab0  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788ab0
//
// 00788ab0  8b442408             mov eax, dword ptr [esp + 8]
// 00788ab4  56                   push esi
// 00788ab5  8b742408             mov esi, dword ptr [esp + 8]
// 00788ab9  57                   push edi
// 00788aba  8bce                 mov ecx, esi
// 00788abc  e82ffbffff           call 0x7885f0
// 00788ac1  8bf8                 mov edi, eax
// 00788ac3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788ac7  8bce                 mov ecx, esi
// 00788ac9  e822fbffff           call 0x7885f0
// 00788ace  81ff28aa9e00         cmp edi, 0x9eaa28
// 00788ad4  7415                 je 0x788aeb
// 00788ad6  3d28aa9e00           cmp eax, 0x9eaa28
// 00788adb  740e                 je 0x788aeb
// 00788add  50                   push eax
// 00788ade  57                   push edi
// 00788adf  56                   push esi
// 00788ae0  e81b5a0400           call 0x7ce500
// 00788ae5  83c40c               add esp, 0xc
// 00788ae8  5f                   pop edi
// 00788ae9  5e                   pop esi
// 00788aea  c3                   ret 
// 00788aeb  5f                   pop edi
// 00788aec  33c0                 xor eax, eax
// 00788aee  5e                   pop esi
// 00788aef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
