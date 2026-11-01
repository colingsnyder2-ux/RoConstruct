// from server: 100% by auto
// roc 2009-12 0079d1c0  unit: seg_00790000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d1c0
//
// 0079d1c0  81ec0c020000         sub esp, 0x20c
// 0079d1c6  56                   push esi
// 0079d1c7  8bb42414020000       mov esi, dword ptr [esp + 0x214]
// 0079d1ce  6a06                 push 6
// 0079d1d0  6a01                 push 1
// 0079d1d2  56                   push esi
// 0079d1d3  e818d5feff           call 0x78a6f0
// 0079d1d8  6a01                 push 1
// 0079d1da  56                   push esi
// 0079d1db  e8d0b5feff           call 0x7887b0
// 0079d1e0  8d442418             lea eax, [esp + 0x18]
// 0079d1e4  50                   push eax
// 0079d1e5  56                   push esi
// 0079d1e6  e845cffeff           call 0x78a130
// 0079d1eb  8d4c2420             lea ecx, [esp + 0x20]
// 0079d1ef  51                   push ecx
// 0079d1f0  68a0d17900           push 0x79d1a0
// 0079d1f5  56                   push esi
// 0079d1f6  e8d5c3feff           call 0x7895d0
// 0079d1fb  83c428               add esp, 0x28
// 0079d1fe  85c0                 test eax, eax
// 0079d200  740e                 je 0x79d210
// 0079d202  6898b09e00           push 0x9eb098
// 0079d207  56                   push esi
// 0079d208  e8e3cafeff           call 0x789cf0
// 0079d20d  83c408               add esp, 8
// 0079d210  8d542404             lea edx, [esp + 4]
// 0079d214  52                   push edx
// 0079d215  e856cefeff           call 0x78a070
// 0079d21a  83c404               add esp, 4
// 0079d21d  b801000000           mov eax, 1
// 0079d222  5e                   pop esi
// 0079d223  81c40c020000         add esp, 0x20c
// 0079d229  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
