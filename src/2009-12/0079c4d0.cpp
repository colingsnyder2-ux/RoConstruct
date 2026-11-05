// from server: 100% by auto
// roc 2009-12 0079c4d0  unit: seg_00790000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c4d0
//
// 0079c4d0  56                   push esi
// 0079c4d1  8b742408             mov esi, dword ptr [esp + 8]
// 0079c4d5  57                   push edi
// 0079c4d6  6a05                 push 5
// 0079c4d8  6a01                 push 1
// 0079c4da  56                   push esi
// 0079c4db  e810e2feff           call 0x78a6f0
// 0079c4e0  6a01                 push 1
// 0079c4e2  56                   push esi
// 0079c4e3  e828c7feff           call 0x788c10
// 0079c4e8  6856fd9900           push 0x99fd56
// 0079c4ed  6a28                 push 0x28
// 0079c4ef  56                   push esi
// 0079c4f0  8bf8                 mov edi, eax
// 0079c4f2  e889d8feff           call 0x789d80
// 0079c4f7  6a02                 push 2
// 0079c4f9  56                   push esi
// 0079c4fa  e891c4feff           call 0x788990
// 0079c4ff  83c428               add esp, 0x28
// 0079c502  85c0                 test eax, eax
// 0079c504  7e0d                 jle 0x79c513
// 0079c506  6a06                 push 6
// 0079c508  6a02                 push 2
// 0079c50a  56                   push esi
// 0079c50b  e8e0e1feff           call 0x78a6f0
// 0079c510  83c40c               add esp, 0xc
// 0079c513  6a02                 push 2
// 0079c515  56                   push esi
// 0079c516  e895c2feff           call 0x7887b0
// 0079c51b  57                   push edi
// 0079c51c  6a01                 push 1
// 0079c51e  56                   push esi
// 0079c51f  e8acfbffff           call 0x79c0d0
// 0079c524  83c414               add esp, 0x14
// 0079c527  5f                   pop edi
// 0079c528  33c0                 xor eax, eax
// 0079c52a  5e                   pop esi
// 0079c52b  c3                   ret 
// library lua-5.1/ltablib.c (function _sort)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
