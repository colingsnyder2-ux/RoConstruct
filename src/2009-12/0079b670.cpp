// from server: 100% by auto
// roc 2009-12 0079b670  unit: seg_00790000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b670
//
// 0079b670  8b442408             mov eax, dword ptr [esp + 8]
// 0079b674  8b4808               mov ecx, dword ptr [eax + 8]
// 0079b677  8b048da0eb9e00       mov eax, dword ptr [ecx*4 + 0x9eeba0]
// 0079b67e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079b682  8b4a08               mov ecx, dword ptr [edx + 8]
// 0079b685  8b0c8da0eb9e00       mov ecx, dword ptr [ecx*4 + 0x9eeba0]
// 0079b68c  8a5002               mov dl, byte ptr [eax + 2]
// 0079b68f  3a5102               cmp dl, byte ptr [ecx + 2]
// 0079b692  7516                 jne 0x79b6aa
// 0079b694  50                   push eax
// 0079b695  8b442408             mov eax, dword ptr [esp + 8]
// 0079b699  6844ac9e00           push 0x9eac44
// 0079b69e  50                   push eax
// 0079b69f  e89cfcffff           call 0x79b340
// 0079b6a4  83c40c               add esp, 0xc
// 0079b6a7  33c0                 xor eax, eax
// 0079b6a9  c3                   ret 
// 0079b6aa  51                   push ecx
// 0079b6ab  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079b6af  50                   push eax
// 0079b6b0  6824ac9e00           push 0x9eac24
// 0079b6b5  51                   push ecx
// 0079b6b6  e885fcffff           call 0x79b340
// 0079b6bb  83c410               add esp, 0x10
// 0079b6be  33c0                 xor eax, eax
// 0079b6c0  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_ordererror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
