// from server: 100% by auto
// roc 2009-12 0079b600  unit: seg_00790000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b600
//
// 0079b600  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079b604  8b4108               mov eax, dword ptr [ecx + 8]
// 0079b607  83f804               cmp eax, 4
// 0079b60a  7405                 je 0x79b611
// 0079b60c  83f803               cmp eax, 3
// 0079b60f  7504                 jne 0x79b615
// 0079b611  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079b615  c744240c00ac9e00     mov dword ptr [esp + 0xc], 0x9eac00
// 0079b61d  894c2408             mov dword ptr [esp + 8], ecx
// 0079b621  e94affffff           jmp 0x79b570
// library lua-5.1.3/ldebug.c (function _luaG_concaterror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldebug.c
