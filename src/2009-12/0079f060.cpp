// from server: 100% by auto
// roc 2009-12 0079f060  unit: seg_00790000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f060
//
// 0079f060  56                   push esi
// 0079f061  8b742408             mov esi, dword ptr [esp + 8]
// 0079f065  682cb69e00           push 0x9eb62c
// 0079f06a  6a02                 push 2
// 0079f06c  56                   push esi
// 0079f06d  e80eadfeff           call 0x789d80
// 0079f072  6a01                 push 1
// 0079f074  56                   push esi
// 0079f075  e8e698feff           call 0x788960
// 0079f07a  6a01                 push 1
// 0079f07c  6a00                 push 0
// 0079f07e  56                   push esi
// 0079f07f  e83ca4feff           call 0x7894c0
// 0079f084  6aff                 push -1
// 0079f086  56                   push esi
// 0079f087  e80499feff           call 0x788990
// 0079f08c  83c428               add esp, 0x28
// 0079f08f  85c0                 test eax, eax
// 0079f091  750e                 jne 0x79f0a1
// 0079f093  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079f097  c70000000000         mov dword ptr [eax], 0
// 0079f09d  33c0                 xor eax, eax
// 0079f09f  5e                   pop esi
// 0079f0a0  c3                   ret 
// 0079f0a1  6aff                 push -1
// 0079f0a3  56                   push esi
// 0079f0a4  e89799feff           call 0x788a40
// 0079f0a9  83c408               add esp, 8
// 0079f0ac  85c0                 test eax, eax
// 0079f0ae  741a                 je 0x79f0ca
// 0079f0b0  6a03                 push 3
// 0079f0b2  56                   push esi
// 0079f0b3  e8e897feff           call 0x7888a0
// 0079f0b8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079f0bc  51                   push ecx
// 0079f0bd  6a03                 push 3
// 0079f0bf  56                   push esi
// 0079f0c0  e8db9afeff           call 0x788ba0
// 0079f0c5  83c414               add esp, 0x14
// 0079f0c8  5e                   pop esi
// 0079f0c9  c3                   ret 
// 0079f0ca  6804b69e00           push 0x9eb604
// 0079f0cf  56                   push esi
// 0079f0d0  e81bacfeff           call 0x789cf0
// 0079f0d5  83c408               add esp, 8
// 0079f0d8  33c0                 xor eax, eax
// 0079f0da  5e                   pop esi
// 0079f0db  c3                   ret 
// library lua-5.1/lbaselib.c (function _generic_reader)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
