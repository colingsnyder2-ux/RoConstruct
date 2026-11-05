// from server: 100% by auto
// roc 2010-06 0057e5f0  unit: seg_00570000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0057e5f0
//
// 0057e5f0  8b442404             mov eax, dword ptr [esp + 4]
// 0057e5f4  8b4804               mov ecx, dword ptr [eax + 4]
// 0057e5f7  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 0057e5fa  2b442410             sub eax, dword ptr [esp + 0x10]
// 0057e5fe  c3                   ret 
// library rbx2016-jpeg/jmemansi.c (function _jpeg_mem_available)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbx2016-jpeg jmemansi.c
