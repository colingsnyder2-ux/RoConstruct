// from server: 100% by auto
// roc 2007-03 00600be0  unit: seg_00600000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600be0
//
// 00600be0  8b442404             mov eax, dword ptr [esp + 4]
// 00600be4  c7001b4c7561         mov dword ptr [eax], 0x61754c1b
// 00600bea  c6400451             mov byte ptr [eax + 4], 0x51
// 00600bee  83c004               add eax, 4
// 00600bf1  c6400100             mov byte ptr [eax + 1], 0
// 00600bf5  83c001               add eax, 1
// 00600bf8  c6400101             mov byte ptr [eax + 1], 1
// 00600bfc  83c001               add eax, 1
// 00600bff  c6400104             mov byte ptr [eax + 1], 4
// 00600c03  83c001               add eax, 1
// 00600c06  83c001               add eax, 1
// 00600c09  c60004               mov byte ptr [eax], 4
// 00600c0c  83c001               add eax, 1
// 00600c0f  c60004               mov byte ptr [eax], 4
// 00600c12  83c001               add eax, 1
// 00600c15  c60008               mov byte ptr [eax], 8
// 00600c18  c6400100             mov byte ptr [eax + 1], 0
// 00600c1c  c3                   ret 
// library lua-5.1.1/lundump.c (function _luaU_header)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
