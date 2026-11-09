// from server: 100% by auto
// roc 2009-12 007d5010  unit: seg_007d0000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5010
//
// 007d5010  8b442404             mov eax, dword ptr [esp + 4]
// 007d5014  c7001b4c7561         mov dword ptr [eax], 0x61754c1b
// 007d501a  c6400451             mov byte ptr [eax + 4], 0x51
// 007d501e  83c004               add eax, 4
// 007d5021  c6400100             mov byte ptr [eax + 1], 0
// 007d5025  40                   inc eax
// 007d5026  c6400101             mov byte ptr [eax + 1], 1
// 007d502a  40                   inc eax
// 007d502b  c6400104             mov byte ptr [eax + 1], 4
// 007d502f  40                   inc eax
// 007d5030  40                   inc eax
// 007d5031  c60004               mov byte ptr [eax], 4
// 007d5034  40                   inc eax
// 007d5035  c60004               mov byte ptr [eax], 4
// 007d5038  40                   inc eax
// 007d5039  c60008               mov byte ptr [eax], 8
// 007d503c  c6400100             mov byte ptr [eax + 1], 0
// 007d5040  c3                   ret 
// library lua-5.1/lundump.c (function _luaU_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
