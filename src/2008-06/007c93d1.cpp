// roc 2008-06 007c93d1  unit: seg_007c0000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007c93d1
//
// 007c93d1  6840294300           push 0x432940
// 007c93d6  6a01                 push 1
// 007c93d8  6a18                 push 0x18
// 007c93da  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 007c93dd  053c020000           add eax, 0x23c
// 007c93e2  50                   push eax
// 007c93e3  e87382edff           call 0x6a165b
// 007c93e8  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function __unwindfunclet$??0RakPeer@@QAE@XZ$3)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
