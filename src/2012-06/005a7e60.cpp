// roc 2012-06 005a7e60  unit: RBX::Image  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a7e60
//
// 005a7e60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005a7e64  56                   push esi
// 005a7e65  8b742408             mov esi, dword ptr [esp + 8]
// 005a7e69  8d442410             lea eax, [esp + 0x10]
// 005a7e6d  50                   push eax
// 005a7e6e  51                   push ecx
// 005a7e6f  8bce                 mov ecx, esi
// 005a7e71  e82afeffff           call 0x5a7ca0
// 005a7e76  8bc6                 mov eax, esi
// 005a7e78  5e                   pop esi
// 005a7e79  c3                   ret 
// copied from an identical function in another client (function ??0RakString@RakNet@@QAA@PBEZZ)

// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp