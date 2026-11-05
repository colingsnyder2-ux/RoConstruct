// from server: 100% by auto
// roc 2011-06 005748a0  unit: seg_00570000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005748a0
//
// 005748a0  8b442404             mov eax, dword ptr [esp + 4]
// 005748a4  8b4804               mov ecx, dword ptr [eax + 4]
// 005748a7  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 005748aa  2b442410             sub eax, dword ptr [esp + 0x10]
// 005748ae  c3                   ret 
// library rbx2016-jpeg/jmemansi.c (function _jpeg_mem_available)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-jpeg jmemansi.c
