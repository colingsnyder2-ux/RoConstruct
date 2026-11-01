// from server: 100% by auto
// roc 2009-12 0079aaa0  unit: lua_exception  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079aaa0
//
// 0079aaa0  8b442404             mov eax, dword ptr [esp + 4]
// 0079aaa4  8bc8                 mov ecx, eax
// 0079aaa6  83e13f               and ecx, 0x3f
// 0079aaa9  83f91c               cmp ecx, 0x1c
// 0079aaac  7c15                 jl 0x79aac3
// 0079aaae  83f91e               cmp ecx, 0x1e
// 0079aab1  7e05                 jle 0x79aab8
// 0079aab3  83f922               cmp ecx, 0x22
// 0079aab6  750b                 jne 0x79aac3
// 0079aab8  25000080ff           and eax, 0xff800000
// 0079aabd  f7d8                 neg eax
// 0079aabf  1bc0                 sbb eax, eax
// 0079aac1  40                   inc eax
// 0079aac2  c3                   ret 
// 0079aac3  33c0                 xor eax, eax
// 0079aac5  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_checkopenop)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
