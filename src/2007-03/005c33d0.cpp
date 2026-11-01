// from server: 100% by auto
// roc 2007-03 005c33d0  unit: seg_005c0000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c33d0
//
// 005c33d0  8b442408             mov eax, dword ptr [esp + 8]
// 005c33d4  8b4808               mov ecx, dword ptr [eax + 8]
// 005c33d7  8b048d00027c00       mov eax, dword ptr [ecx*4 + 0x7c0200]
// 005c33de  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005c33e2  8b4a08               mov ecx, dword ptr [edx + 8]
// 005c33e5  8b0c8d00027c00       mov ecx, dword ptr [ecx*4 + 0x7c0200]
// 005c33ec  8a5002               mov dl, byte ptr [eax + 2]
// 005c33ef  3a5102               cmp dl, byte ptr [ecx + 2]
// 005c33f2  7516                 jne 0x5c340a
// 005c33f4  50                   push eax
// 005c33f5  8b442408             mov eax, dword ptr [esp + 8]
// 005c33f9  68fc9a7b00           push 0x7b9afc
// 005c33fe  50                   push eax
// 005c33ff  e8acfcffff           call 0x5c30b0
// 005c3404  83c40c               add esp, 0xc
// 005c3407  33c0                 xor eax, eax
// 005c3409  c3                   ret 
// 005c340a  51                   push ecx
// 005c340b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c340f  50                   push eax
// 005c3410  68dc9a7b00           push 0x7b9adc
// 005c3415  51                   push ecx
// 005c3416  e895fcffff           call 0x5c30b0
// 005c341b  83c410               add esp, 0x10
// 005c341e  33c0                 xor eax, eax
// 005c3420  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_ordererror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
