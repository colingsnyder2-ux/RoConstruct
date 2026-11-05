// from server: 100% by auto
// roc 2008-06 00622670  unit: lua_exception  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622670
//
// 00622670  8b442404             mov eax, dword ptr [esp + 4]
// 00622674  8b5008               mov edx, dword ptr [eax + 8]
// 00622677  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062267b  3b5108               cmp edx, dword ptr [ecx + 8]
// 0062267e  7403                 je 0x622683
// 00622680  33c0                 xor eax, eax
// 00622682  c3                   ret 
// 00622683  83fa03               cmp edx, 3
// 00622686  771e                 ja 0x6226a6
// 00622688  ff2495b4266200       jmp dword ptr [edx*4 + 0x6226b4]
// 0062268f  b801000000           mov eax, 1
// 00622694  c3                   ret 
// 00622695  dd01                 fld qword ptr [ecx]
// 00622697  dc18                 fcomp qword ptr [eax]
// 00622699  dfe0                 fnstsw ax
// 0062269b  f6c444               test ah, 0x44
// 0062269e  7ae0                 jp 0x622680
// 006226a0  b801000000           mov eax, 1
// 006226a5  c3                   ret 
// 006226a6  8b00                 mov eax, dword ptr [eax]
// 006226a8  33d2                 xor edx, edx
// 006226aa  3b01                 cmp eax, dword ptr [ecx]
// 006226ac  0f94c2               sete dl
// 006226af  8bc2                 mov eax, edx
// 006226b1  c3                   ret 
// 006226b2  8bff                 mov edi, edi
// library lua-5.1/lobject.c (function _luaO_rawequalObj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
