// from server: 100% by auto
// roc 2009-12 0079ed40  unit: seg_00790000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ed40
//
// 0079ed40  56                   push esi
// 0079ed41  8b742408             mov esi, dword ptr [esp + 8]
// 0079ed45  6a05                 push 5
// 0079ed47  6a01                 push 1
// 0079ed49  56                   push esi
// 0079ed4a  e8a1b9feff           call 0x78a6f0
// 0079ed4f  6a02                 push 2
// 0079ed51  56                   push esi
// 0079ed52  e8e9b9feff           call 0x78a740
// 0079ed57  6a02                 push 2
// 0079ed59  56                   push esi
// 0079ed5a  e8519afeff           call 0x7887b0
// 0079ed5f  6a01                 push 1
// 0079ed61  56                   push esi
// 0079ed62  e8e9a2feff           call 0x789050
// 0079ed67  83c424               add esp, 0x24
// 0079ed6a  b801000000           mov eax, 1
// 0079ed6f  5e                   pop esi
// 0079ed70  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
