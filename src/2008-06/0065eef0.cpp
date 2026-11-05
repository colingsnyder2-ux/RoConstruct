// from server: 100% by auto
// roc 2008-06 0065eef0  unit: seg_00650000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065eef0
//
// 0065eef0  8b442408             mov eax, dword ptr [esp + 8]
// 0065eef4  817810d0c38400       cmp dword ptr [eax + 0x10], 0x84c3d0
// 0065eefb  7516                 jne 0x65ef13
// 0065eefd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0065ef01  33d2                 xor edx, edx
// 0065ef03  52                   push edx
// 0065ef04  8b542408             mov edx, dword ptr [esp + 8]
// 0065ef08  51                   push ecx
// 0065ef09  52                   push edx
// 0065ef0a  e801feffff           call 0x65ed10
// 0065ef0f  83c40c               add esp, 0xc
// 0065ef12  c3                   ret 
// 0065ef13  8a4807               mov cl, byte ptr [eax + 7]
// 0065ef16  ba01000000           mov edx, 1
// 0065ef1b  d3e2                 shl edx, cl
// 0065ef1d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0065ef21  52                   push edx
// 0065ef22  8b542408             mov edx, dword ptr [esp + 8]
// 0065ef26  51                   push ecx
// 0065ef27  52                   push edx
// 0065ef28  e8e3fdffff           call 0x65ed10
// 0065ef2d  83c40c               add esp, 0xc
// 0065ef30  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_resizearray)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
