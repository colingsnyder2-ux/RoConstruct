// roc 2012-06 005baf00  unit: RakNet::RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005baf00
//
// 005baf00  56                   push esi
// 005baf01  57                   push edi
// 005baf02  8db198040000         lea esi, [ecx + 0x498]
// 005baf08  684c69e200           push 0xe2694c
// 005baf0d  8bce                 mov ecx, esi
// 005baf0f  33ff                 xor edi, edi
// 005baf11  e8ba69faff           call 0x5618d0
// 005baf16  84c0                 test al, al
// 005baf18  741a                 je 0x5baf34
// 005baf1a  8d9b00000000         lea ebx, [ebx]
// 005baf20  83c614               add esi, 0x14
// 005baf23  684c69e200           push 0xe2694c
// 005baf28  8bce                 mov ecx, esi
// 005baf2a  47                   inc edi
// 005baf2b  e8a069faff           call 0x5618d0
// 005baf30  84c0                 test al, al
// 005baf32  75ec                 jne 0x5baf20
// 005baf34  8bc7                 mov eax, edi
// 005baf36  5f                   pop edi
// 005baf37  5e                   pop esi
// 005baf38  c3                   ret 
// copied from an identical function in another client (function ?GetNumberOfAddresses@RakPeer@RakNet@@UAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp