// from server: 100% by auto
// roc 2009-12 005520a0  unit: RBX::Network::VMarker::?$EventDesc  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005520a0
//
// 005520a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005520a4  85c9                 test ecx, ecx
// 005520a6  7432                 je 0x5520da
// 005520a8  803900               cmp byte ptr [ecx], 0
// 005520ab  742d                 je 0x5520da
// 005520ad  8bc1                 mov eax, ecx
// 005520af  56                   push esi
// 005520b0  8d7001               lea esi, [eax + 1]
// 005520b3  8a10                 mov dl, byte ptr [eax]
// 005520b5  40                   inc eax
// 005520b6  84d2                 test dl, dl
// 005520b8  75f9                 jne 0x5520b3
// 005520ba  2bc6                 sub eax, esi
// 005520bc  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 005520c0  5e                   pop esi
// 005520c1  80fa5c               cmp dl, 0x5c
// 005520c4  7506                 jne 0x5520cc
// 005520c6  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 005520cb  c3                   ret 
// 005520cc  80fa2f               cmp dl, 0x2f
// 005520cf  7409                 je 0x5520da
// 005520d1  c604082f             mov byte ptr [eax + ecx], 0x2f
// 005520d5  c644080100           mov byte ptr [eax + ecx + 1], 0
// 005520da  c3                   ret 
// library raknet-4.081/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileOperations.cpp
