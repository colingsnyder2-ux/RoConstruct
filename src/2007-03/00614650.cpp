// from server: 100% by auto
// roc 2007-03 00614650  unit: seg_00610000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614650
//
// 00614650  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00614654  83f8ff               cmp eax, -1
// 00614657  743e                 je 0x614697
// 00614659  8b542408             mov edx, dword ptr [esp + 8]
// 0061465d  8b0a                 mov ecx, dword ptr [edx]
// 0061465f  83f9ff               cmp ecx, -1
// 00614662  7503                 jne 0x614667
// 00614664  8902                 mov dword ptr [edx], eax
// 00614666  c3                   ret 
// 00614667  53                   push ebx
// 00614668  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0061466c  8b13                 mov edx, dword ptr [ebx]
// 0061466e  56                   push esi
// 0061466f  8b720c               mov esi, dword ptr [edx + 0xc]
// 00614672  8b148e               mov edx, dword ptr [esi + ecx*4]
// 00614675  c1ea0e               shr edx, 0xe
// 00614678  81eaffff0100         sub edx, 0x1ffff
// 0061467e  83faff               cmp edx, -1
// 00614681  740d                 je 0x614690
// 00614683  8d540a01             lea edx, [edx + ecx + 1]
// 00614687  83faff               cmp edx, -1
// 0061468a  7404                 je 0x614690
// 0061468c  8bca                 mov ecx, edx
// 0061468e  ebe2                 jmp 0x614672
// 00614690  e82bfdffff           call 0x6143c0
// 00614695  5e                   pop esi
// 00614696  5b                   pop ebx
// 00614697  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
