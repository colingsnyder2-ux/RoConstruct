// from server: 100% by auto
// roc 2011-06 00763080  unit: seg_00760000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00763080
//
// 00763080  8b442408             mov eax, dword ptr [esp + 8]
// 00763084  56                   push esi
// 00763085  8b742408             mov esi, dword ptr [esp + 8]
// 00763089  8b4e08               mov ecx, dword ptr [esi + 8]
// 0076308c  57                   push edi
// 0076308d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00763091  40                   inc eax
// 00763092  c1e004               shl eax, 4
// 00763095  57                   push edi
// 00763096  2bc8                 sub ecx, eax
// 00763098  51                   push ecx
// 00763099  56                   push esi
// 0076309a  e801ba0100           call 0x77eaa0
// 0076309f  83c40c               add esp, 0xc
// 007630a2  83ffff               cmp edi, -1
// 007630a5  750e                 jne 0x7630b5
// 007630a7  8b4614               mov eax, dword ptr [esi + 0x14]
// 007630aa  8b7608               mov esi, dword ptr [esi + 8]
// 007630ad  3b7008               cmp esi, dword ptr [eax + 8]
// 007630b0  7203                 jb 0x7630b5
// 007630b2  897008               mov dword ptr [eax + 8], esi
// 007630b5  5f                   pop edi
// 007630b6  5e                   pop esi
// 007630b7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
