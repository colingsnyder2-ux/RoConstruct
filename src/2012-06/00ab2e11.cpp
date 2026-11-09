// roc 2012-06 00ab2e11  unit: seg_00ab0000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ab2e11
//
// 00ab2e11  6860fd4100           push 0x41fd60
// 00ab2e16  6a02                 push 2
// 00ab2e18  6a18                 push 0x18
// 00ab2e1a  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 00ab2e1d  0550020000           add eax, 0x250
// 00ab2e22  50                   push eax
// 00ab2e23  e84804edff           call 0x983270
// 00ab2e28  c3                   ret 
// library raknet-4.081/RakPeer.cpp (function __unwindfunclet$??0RakPeer@RakNet@@QAE@XZ$4)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakPeer.cpp
