// from server: 100% by auto
// roc 2009-12 0079f4a0  unit: seg_00790000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f4a0
//
// 0079f4a0  56                   push esi
// 0079f4a1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f4a5  6a01                 push 1
// 0079f4a7  56                   push esi
// 0079f4a8  e80393feff           call 0x7887b0
// 0079f4ad  6a00                 push 0
// 0079f4af  56                   push esi
// 0079f4b0  e83ba3feff           call 0x7897f0
// 0079f4b5  6a01                 push 1
// 0079f4b7  56                   push esi
// 0079f4b8  e8b396feff           call 0x788b70
// 0079f4bd  83c418               add esp, 0x18
// 0079f4c0  85c0                 test eax, eax
// 0079f4c2  0f84a5000000         je 0x79f56d
// 0079f4c8  6a01                 push 1
// 0079f4ca  56                   push esi
// 0079f4cb  e8c094feff           call 0x788990
// 0079f4d0  83c408               add esp, 8
// 0079f4d3  83f801               cmp eax, 1
// 0079f4d6  753a                 jne 0x79f512
// 0079f4d8  6a00                 push 0
// 0079f4da  6a00                 push 0
// 0079f4dc  56                   push esi
// 0079f4dd  e8ee9bfeff           call 0x7890d0
// 0079f4e2  6aff                 push -1
// 0079f4e4  56                   push esi
// 0079f4e5  e87694feff           call 0x788960
// 0079f4ea  6a01                 push 1
// 0079f4ec  56                   push esi
// 0079f4ed  e85e9afeff           call 0x788f50
// 0079f4f2  68edd8ffff           push 0xffffd8ed
// 0079f4f7  56                   push esi
// 0079f4f8  e8939dfeff           call 0x789290
// 0079f4fd  83c424               add esp, 0x24
// 0079f500  6a02                 push 2
// 0079f502  56                   push esi
// 0079f503  e8789efeff           call 0x789380
// 0079f508  83c408               add esp, 8
// 0079f50b  b801000000           mov eax, 1
// 0079f510  5e                   pop esi
// 0079f511  c3                   ret 
// 0079f512  6a01                 push 1
// 0079f514  56                   push esi
// 0079f515  e8169cfeff           call 0x789130
// 0079f51a  83c408               add esp, 8
// 0079f51d  85c0                 test eax, eax
// 0079f51f  7426                 je 0x79f547
// 0079f521  57                   push edi
// 0079f522  68edd8ffff           push 0xffffd8ed
// 0079f527  56                   push esi
// 0079f528  e8239bfeff           call 0x789050
// 0079f52d  6aff                 push -1
// 0079f52f  56                   push esi
// 0079f530  e83b96feff           call 0x788b70
// 0079f535  6afe                 push -2
// 0079f537  56                   push esi
// 0079f538  8bf8                 mov edi, eax
// 0079f53a  e87192feff           call 0x7887b0
// 0079f53f  83c418               add esp, 0x18
// 0079f542  85ff                 test edi, edi
// 0079f544  5f                   pop edi
// 0079f545  7510                 jne 0x79f557
// 0079f547  689cb69e00           push 0x9eb69c
// 0079f54c  6a01                 push 1
// 0079f54e  56                   push esi
// 0079f54f  e82cb0feff           call 0x78a580
// 0079f554  83c40c               add esp, 0xc
// 0079f557  6a01                 push 1
// 0079f559  56                   push esi
// 0079f55a  e8d19bfeff           call 0x789130
// 0079f55f  83c408               add esp, 8
// 0079f562  6a02                 push 2
// 0079f564  56                   push esi
// 0079f565  e8169efeff           call 0x789380
// 0079f56a  83c408               add esp, 8
// 0079f56d  b801000000           mov eax, 1
// 0079f572  5e                   pop esi
// 0079f573  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_newproxy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
