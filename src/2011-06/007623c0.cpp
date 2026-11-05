// from server: 100% by auto
// roc 2011-06 007623c0  unit: seg_00760000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007623c0
//
// 007623c0  8b442408             mov eax, dword ptr [esp + 8]
// 007623c4  56                   push esi
// 007623c5  8b742408             mov esi, dword ptr [esp + 8]
// 007623c9  8bce                 mov ecx, esi
// 007623cb  e8e0fdffff           call 0x7621b0
// 007623d0  83c010               add eax, 0x10
// 007623d3  3b4608               cmp eax, dword ptr [esi + 8]
// 007623d6  7323                 jae 0x7623fb
// 007623d8  8d48f0               lea ecx, [eax - 0x10]
// 007623db  eb03                 jmp 0x7623e0
// 007623dd  8d4900               lea ecx, [ecx]
// 007623e0  8b10                 mov edx, dword ptr [eax]
// 007623e2  8911                 mov dword ptr [ecx], edx
// 007623e4  8b5004               mov edx, dword ptr [eax + 4]
// 007623e7  895104               mov dword ptr [ecx + 4], edx
// 007623ea  8b5118               mov edx, dword ptr [ecx + 0x18]
// 007623ed  895108               mov dword ptr [ecx + 8], edx
// 007623f0  83c010               add eax, 0x10
// 007623f3  83c110               add ecx, 0x10
// 007623f6  3b4608               cmp eax, dword ptr [esi + 8]
// 007623f9  72e5                 jb 0x7623e0
// 007623fb  834608f0             add dword ptr [esi + 8], -0x10
// 007623ff  5e                   pop esi
// 00762400  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
