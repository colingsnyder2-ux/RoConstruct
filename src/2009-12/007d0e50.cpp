// from server: 100% by auto
// roc 2009-12 007d0e50  unit: seg_007d0000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0e50
//
// 007d0e50  8b442408             mov eax, dword ptr [esp + 8]
// 007d0e54  8d4810               lea ecx, [eax + 0x10]
// 007d0e57  394808               cmp dword ptr [eax + 8], ecx
// 007d0e5a  7412                 je 0x7d0e6e
// 007d0e5c  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d0e5f  56                   push esi
// 007d0e60  8b31                 mov esi, dword ptr [ecx]
// 007d0e62  897210               mov dword ptr [edx + 0x10], esi
// 007d0e65  8b09                 mov ecx, dword ptr [ecx]
// 007d0e67  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d0e6a  895114               mov dword ptr [ecx + 0x14], edx
// 007d0e6d  5e                   pop esi
// 007d0e6e  6a00                 push 0
// 007d0e70  6a20                 push 0x20
// 007d0e72  50                   push eax
// 007d0e73  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d0e77  50                   push eax
// 007d0e78  e833090000           call 0x7d17b0
// 007d0e7d  83c410               add esp, 0x10
// 007d0e80  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_freeupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
