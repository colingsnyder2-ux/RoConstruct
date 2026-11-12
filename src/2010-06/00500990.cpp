// from server: 100% by auto
// roc 2010-06 00500990  unit: RBX::Network::VMarker::?$EventDesc  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00500990
//
// 00500990  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00500994  85c9                 test ecx, ecx
// 00500996  7432                 je 0x5009ca
// 00500998  803900               cmp byte ptr [ecx], 0
// 0050099b  742d                 je 0x5009ca
// 0050099d  8bc1                 mov eax, ecx
// 0050099f  56                   push esi
// 005009a0  8d7001               lea esi, [eax + 1]
// 005009a3  8a10                 mov dl, byte ptr [eax]
// 005009a5  40                   inc eax
// 005009a6  84d2                 test dl, dl
// 005009a8  75f9                 jne 0x5009a3
// 005009aa  2bc6                 sub eax, esi
// 005009ac  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 005009b0  5e                   pop esi
// 005009b1  80fa5c               cmp dl, 0x5c
// 005009b4  7506                 jne 0x5009bc
// 005009b6  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 005009bb  c3                   ret 
// 005009bc  80fa2f               cmp dl, 0x2f
// 005009bf  7409                 je 0x5009ca
// 005009c1  c604082f             mov byte ptr [eax + ecx], 0x2f
// 005009c5  c644080100           mov byte ptr [eax + ecx + 1], 0
// 005009ca  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
