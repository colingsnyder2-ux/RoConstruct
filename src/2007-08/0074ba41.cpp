// roc 2007-08 0074ba41  unit: seg_00740000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0074ba41
//
// 0074ba41  6830314300           push 0x433130
// 0074ba46  6a01                 push 1
// 0074ba48  6a18                 push 0x18
// 0074ba4a  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0074ba4d  053c020000           add eax, 0x23c
// 0074ba52  50                   push eax
// 0074ba53  e89f50eeff           call 0x630af7
// 0074ba58  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function __unwindfunclet$??0RakPeer@@QAE@XZ$3)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
