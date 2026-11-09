// from server: 100% by auto
// roc 2010-06 00721940  unit: RBX::UniversalTool  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721940
//
// 00721940  8b442408             mov eax, dword ptr [esp + 8]
// 00721944  56                   push esi
// 00721945  8b742408             mov esi, dword ptr [esp + 8]
// 00721949  8bce                 mov ecx, esi
// 0072194b  e850f4ffff           call 0x720da0
// 00721950  8b4808               mov ecx, dword ptr [eax + 8]
// 00721953  83e906               sub ecx, 6
// 00721956  7439                 je 0x721991
// 00721958  83e901               sub ecx, 1
// 0072195b  7434                 je 0x721991
// 0072195d  83e901               sub ecx, 1
// 00721960  7410                 je 0x721972
// 00721962  8b4608               mov eax, dword ptr [esi + 8]
// 00721965  c7400800000000       mov dword ptr [eax + 8], 0
// 0072196c  83460810             add dword ptr [esi + 8], 0x10
// 00721970  5e                   pop esi
// 00721971  c3                   ret 
// 00721972  8b00                 mov eax, dword ptr [eax]
// 00721974  8b5048               mov edx, dword ptr [eax + 0x48]
// 00721977  8b4e08               mov ecx, dword ptr [esi + 8]
// 0072197a  83c048               add eax, 0x48
// 0072197d  8911                 mov dword ptr [ecx], edx
// 0072197f  8b5004               mov edx, dword ptr [eax + 4]
// 00721982  895104               mov dword ptr [ecx + 4], edx
// 00721985  8b4008               mov eax, dword ptr [eax + 8]
// 00721988  894108               mov dword ptr [ecx + 8], eax
// 0072198b  83460810             add dword ptr [esi + 8], 0x10
// 0072198f  5e                   pop esi
// 00721990  c3                   ret 
// 00721991  8b10                 mov edx, dword ptr [eax]
// 00721993  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721996  8b420c               mov eax, dword ptr [edx + 0xc]
// 00721999  c7410805000000       mov dword ptr [ecx + 8], 5
// 007219a0  8901                 mov dword ptr [ecx], eax
// 007219a2  83460810             add dword ptr [esi + 8], 0x10
// 007219a6  5e                   pop esi
// 007219a7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
