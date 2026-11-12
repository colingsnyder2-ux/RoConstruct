// from server: 100% by colin
// roc 2007-08 004b8610  unit: RBX::Network::ClientPhysics  size: 384 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8610
//
// 004b8610  8b442408             mov eax, dword ptr [esp + 8]
// 004b8614  56                   push esi
// 004b8615  8bf1                 mov esi, ecx
// 004b8617  8b08                 mov ecx, dword ptr [eax]
// 004b8619  010e                 add dword ptr [esi], ecx
// 004b861b  8b5010               mov edx, dword ptr [eax + 0x10]
// 004b861e  015610               add dword ptr [esi + 0x10], edx
// 004b8621  8b4820               mov ecx, dword ptr [eax + 0x20]
// 004b8624  014e20               add dword ptr [esi + 0x20], ecx
// 004b8627  8b5030               mov edx, dword ptr [eax + 0x30]
// 004b862a  015630               add dword ptr [esi + 0x30], edx
// 004b862d  8b4804               mov ecx, dword ptr [eax + 4]
// 004b8630  014e04               add dword ptr [esi + 4], ecx
// 004b8633  8b5014               mov edx, dword ptr [eax + 0x14]
// 004b8636  015614               add dword ptr [esi + 0x14], edx
// 004b8639  8b4824               mov ecx, dword ptr [eax + 0x24]
// 004b863c  014e24               add dword ptr [esi + 0x24], ecx
// 004b863f  8b5034               mov edx, dword ptr [eax + 0x34]
// 004b8642  015634               add dword ptr [esi + 0x34], edx
// 004b8645  8b4808               mov ecx, dword ptr [eax + 8]
// 004b8648  014e08               add dword ptr [esi + 8], ecx
// 004b864b  8b5018               mov edx, dword ptr [eax + 0x18]
// 004b864e  015618               add dword ptr [esi + 0x18], edx
// 004b8651  8b4828               mov ecx, dword ptr [eax + 0x28]
// 004b8654  014e28               add dword ptr [esi + 0x28], ecx
// 004b8657  8b5038               mov edx, dword ptr [eax + 0x38]
// 004b865a  015638               add dword ptr [esi + 0x38], edx
// 004b865d  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004b8660  014e0c               add dword ptr [esi + 0xc], ecx
// 004b8663  8b501c               mov edx, dword ptr [eax + 0x1c]
// 004b8666  01561c               add dword ptr [esi + 0x1c], edx
// 004b8669  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 004b866c  014e2c               add dword ptr [esi + 0x2c], ecx
// 004b866f  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004b8672  01563c               add dword ptr [esi + 0x3c], edx
// 004b8675  8b4840               mov ecx, dword ptr [eax + 0x40]
// 004b8678  014e40               add dword ptr [esi + 0x40], ecx
// 004b867b  8b5040               mov edx, dword ptr [eax + 0x40]
// 004b867e  015644               add dword ptr [esi + 0x44], edx
// 004b8681  8b4848               mov ecx, dword ptr [eax + 0x48]
// 004b8684  014e48               add dword ptr [esi + 0x48], ecx
// 004b8687  8b504c               mov edx, dword ptr [eax + 0x4c]
// 004b868a  01564c               add dword ptr [esi + 0x4c], edx
// 004b868d  8b4850               mov ecx, dword ptr [eax + 0x50]
// 004b8690  014e50               add dword ptr [esi + 0x50], ecx
// 004b8693  8b5054               mov edx, dword ptr [eax + 0x54]
// 004b8696  015654               add dword ptr [esi + 0x54], edx
// 004b8699  8b4858               mov ecx, dword ptr [eax + 0x58]
// 004b869c  014e58               add dword ptr [esi + 0x58], ecx
// 004b869f  8b505c               mov edx, dword ptr [eax + 0x5c]
// 004b86a2  01565c               add dword ptr [esi + 0x5c], edx
// 004b86a5  8b4860               mov ecx, dword ptr [eax + 0x60]
// 004b86a8  014e60               add dword ptr [esi + 0x60], ecx
// 004b86ab  8b5064               mov edx, dword ptr [eax + 0x64]
// 004b86ae  015664               add dword ptr [esi + 0x64], edx
// 004b86b1  8b4868               mov ecx, dword ptr [eax + 0x68]
// 004b86b4  014e68               add dword ptr [esi + 0x68], ecx
// 004b86b7  8b506c               mov edx, dword ptr [eax + 0x6c]
// 004b86ba  01566c               add dword ptr [esi + 0x6c], edx
// 004b86bd  8b4870               mov ecx, dword ptr [eax + 0x70]
// 004b86c0  014e70               add dword ptr [esi + 0x70], ecx
// 004b86c3  8b5074               mov edx, dword ptr [eax + 0x74]
// 004b86c6  015674               add dword ptr [esi + 0x74], edx
// 004b86c9  8b4878               mov ecx, dword ptr [eax + 0x78]
// 004b86cc  014e78               add dword ptr [esi + 0x78], ecx
// 004b86cf  8b507c               mov edx, dword ptr [eax + 0x7c]
// 004b86d2  01567c               add dword ptr [esi + 0x7c], edx
// 004b86d5  8b8880000000         mov ecx, dword ptr [eax + 0x80]
// 004b86db  018e80000000         add dword ptr [esi + 0x80], ecx
// 004b86e1  8b9084000000         mov edx, dword ptr [eax + 0x84]
// 004b86e7  019684000000         add dword ptr [esi + 0x84], edx
// 004b86ed  8b8888000000         mov ecx, dword ptr [eax + 0x88]
// 004b86f3  018e88000000         add dword ptr [esi + 0x88], ecx
// 004b86f9  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 004b86ff  01968c000000         add dword ptr [esi + 0x8c], edx
// 004b8705  8b8890000000         mov ecx, dword ptr [eax + 0x90]
// 004b870b  018e90000000         add dword ptr [esi + 0x90], ecx
// 004b8711  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 004b8717  019694000000         add dword ptr [esi + 0x94], edx
// 004b871d  8b8898000000         mov ecx, dword ptr [eax + 0x98]
// 004b8723  57                   push edi
// 004b8724  018e98000000         add dword ptr [esi + 0x98], ecx
// 004b872a  8b909c000000         mov edx, dword ptr [eax + 0x9c]
// 004b8730  01969c000000         add dword ptr [esi + 0x9c], edx
// 004b8736  8b88a0000000         mov ecx, dword ptr [eax + 0xa0]
// 004b873c  018ea0000000         add dword ptr [esi + 0xa0], ecx
// 004b8742  8b90a4000000         mov edx, dword ptr [eax + 0xa4]
// 004b8748  0196a4000000         add dword ptr [esi + 0xa4], edx
// 004b874e  8b88a8000000         mov ecx, dword ptr [eax + 0xa8]
// 004b8754  018ea8000000         add dword ptr [esi + 0xa8], ecx
// 004b875a  8b90ac000000         mov edx, dword ptr [eax + 0xac]
// 004b8760  0196ac000000         add dword ptr [esi + 0xac], edx
// 004b8766  8b88b0000000         mov ecx, dword ptr [eax + 0xb0]
// 004b876c  018eb0000000         add dword ptr [esi + 0xb0], ecx
// 004b8772  8b90b4000000         mov edx, dword ptr [eax + 0xb4]
// 004b8778  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b877c  0196b4000000         add dword ptr [esi + 0xb4], edx
// 004b8782  b932000000           mov ecx, 0x32
// 004b8787  8bf8                 mov edi, eax
// 004b8789  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004b878b  5f                   pop edi
// 004b878c  5e                   pop esi
// 004b878d  c20800               ret 8
// copied from an identical function in another client (function ??YRakNetStatistics@@QAE?AU0@ABU0@@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp