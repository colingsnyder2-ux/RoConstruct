// from server: 100% by auto
// roc 2009-12 0079eec0  unit: seg_00790000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079eec0
//
// 0079eec0  56                   push esi
// 0079eec1  8b742408             mov esi, dword ptr [esp + 8]
// 0079eec5  6a05                 push 5
// 0079eec7  6a01                 push 1
// 0079eec9  56                   push esi
// 0079eeca  e821b8feff           call 0x78a6f0
// 0079eecf  6a02                 push 2
// 0079eed1  56                   push esi
// 0079eed2  e8d998feff           call 0x7887b0
// 0079eed7  6a01                 push 1
// 0079eed9  56                   push esi
// 0079eeda  e851a8feff           call 0x789730
// 0079eedf  83c41c               add esp, 0x1c
// 0079eee2  85c0                 test eax, eax
// 0079eee4  7407                 je 0x79eeed
// 0079eee6  b802000000           mov eax, 2
// 0079eeeb  5e                   pop esi
// 0079eeec  c3                   ret 
// 0079eeed  56                   push esi
// 0079eeee  e84d9efeff           call 0x788d40
// 0079eef3  83c404               add esp, 4
// 0079eef6  b801000000           mov eax, 1
// 0079eefb  5e                   pop esi
// 0079eefc  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
