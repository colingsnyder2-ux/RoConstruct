// from server: 100% by auto
// roc 2007-03 005fca30  unit: seg_005f0000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fca30
//
// 005fca30  8b442408             mov eax, dword ptr [esp + 8]
// 005fca34  8d4810               lea ecx, [eax + 0x10]
// 005fca37  394808               cmp dword ptr [eax + 8], ecx
// 005fca3a  7412                 je 0x5fca4e
// 005fca3c  8b5014               mov edx, dword ptr [eax + 0x14]
// 005fca3f  56                   push esi
// 005fca40  8b31                 mov esi, dword ptr [ecx]
// 005fca42  897210               mov dword ptr [edx + 0x10], esi
// 005fca45  8b09                 mov ecx, dword ptr [ecx]
// 005fca47  8b5014               mov edx, dword ptr [eax + 0x14]
// 005fca4a  895114               mov dword ptr [ecx + 0x14], edx
// 005fca4d  5e                   pop esi
// 005fca4e  6a00                 push 0
// 005fca50  6a20                 push 0x20
// 005fca52  50                   push eax
// 005fca53  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fca57  50                   push eax
// 005fca58  e843090000           call 0x5fd3a0
// 005fca5d  83c410               add esp, 0x10
// 005fca60  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_freeupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
