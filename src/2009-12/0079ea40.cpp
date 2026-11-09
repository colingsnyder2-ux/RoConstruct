// from server: 100% by auto
// roc 2009-12 0079ea40  unit: seg_00790000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ea40
//
// 0079ea40  56                   push esi
// 0079ea41  8b742408             mov esi, dword ptr [esp + 8]
// 0079ea45  57                   push edi
// 0079ea46  6a01                 push 1
// 0079ea48  6a02                 push 2
// 0079ea4a  56                   push esi
// 0079ea4b  e8d0befeff           call 0x78a920
// 0079ea50  6a01                 push 1
// 0079ea52  56                   push esi
// 0079ea53  8bf8                 mov edi, eax
// 0079ea55  e8569dfeff           call 0x7887b0
// 0079ea5a  6a01                 push 1
// 0079ea5c  56                   push esi
// 0079ea5d  e8de9ffeff           call 0x788a40
// 0079ea62  83c41c               add esp, 0x1c
// 0079ea65  85c0                 test eax, eax
// 0079ea67  741e                 je 0x79ea87
// 0079ea69  85ff                 test edi, edi
// 0079ea6b  7e1a                 jle 0x79ea87
// 0079ea6d  57                   push edi
// 0079ea6e  56                   push esi
// 0079ea6f  e80cb2feff           call 0x789c80
// 0079ea74  6a01                 push 1
// 0079ea76  56                   push esi
// 0079ea77  e8e49efeff           call 0x788960
// 0079ea7c  6a02                 push 2
// 0079ea7e  56                   push esi
// 0079ea7f  e8ecacfeff           call 0x789770
// 0079ea84  83c418               add esp, 0x18
// 0079ea87  56                   push esi
// 0079ea88  e893acfeff           call 0x789720
// 0079ea8d  83c404               add esp, 4
// 0079ea90  5f                   pop edi
// 0079ea91  5e                   pop esi
// 0079ea92  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
