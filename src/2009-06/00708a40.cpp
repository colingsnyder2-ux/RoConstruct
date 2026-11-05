// from server: 100% by auto
// roc 2009-06 00708a40  unit: RBX::Log  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00708a40
//
// 00708a40  837c240800           cmp dword ptr [esp + 8], 0
// 00708a45  8b542404             mov edx, dword ptr [esp + 4]
// 00708a49  8bc1                 mov eax, ecx
// 00708a4b  7705                 ja 0x708a52
// 00708a4d  83fafe               cmp edx, -2
// 00708a50  7607                 jbe 0x708a59
// 00708a52  b901000000           mov ecx, 1
// 00708a57  eb02                 jmp 0x708a5b
// 00708a59  33c9                 xor ecx, ecx
// 00708a5b  8808                 mov byte ptr [eax], cl
// 00708a5d  84c9                 test cl, cl
// 00708a5f  740b                 je 0x708a6c
// 00708a61  b9feffffff           mov ecx, 0xfffffffe
// 00708a66  894804               mov dword ptr [eax + 4], ecx
// 00708a69  c20800               ret 8
// 00708a6c  895004               mov dword ptr [eax + 4], edx
// 00708a6f  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0remaining_time@timeout@detail@boost@@QAE@_K@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
