// from server: 100% by auto
// roc 2007-03 00615c90  unit: seg_00610000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615c90
//
// 00615c90  8b442404             mov eax, dword ptr [esp + 4]
// 00615c94  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00615c97  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00615c9b  3bd1                 cmp edx, ecx
// 00615c9d  751b                 jne 0x615cba
// 00615c9f  89481c               mov dword ptr [eax + 0x1c], ecx
// 00615ca2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00615ca6  8d5020               lea edx, [eax + 0x20]
// 00615ca9  894c240c             mov dword ptr [esp + 0xc], ecx
// 00615cad  89542408             mov dword ptr [esp + 8], edx
// 00615cb1  89442404             mov dword ptr [esp + 4], eax
// 00615cb5  e996e9ffff           jmp 0x614650
// 00615cba  52                   push edx
// 00615cbb  68ff000000           push 0xff
// 00615cc0  52                   push edx
// 00615cc1  50                   push eax
// 00615cc2  8b442418             mov eax, dword ptr [esp + 0x18]
// 00615cc6  e8c5e8ffff           call 0x614590
// 00615ccb  83c410               add esp, 0x10
// 00615cce  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_patchlist)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
