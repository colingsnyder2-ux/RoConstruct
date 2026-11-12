// from server: 100% by auto
// roc 2011-06 0050eb30  unit: RBX::Network::VMarker::?$EventDesc  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050eb30
//
// 0050eb30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050eb34  85c9                 test ecx, ecx
// 0050eb36  7432                 je 0x50eb6a
// 0050eb38  803900               cmp byte ptr [ecx], 0
// 0050eb3b  742d                 je 0x50eb6a
// 0050eb3d  8bc1                 mov eax, ecx
// 0050eb3f  56                   push esi
// 0050eb40  8d7001               lea esi, [eax + 1]
// 0050eb43  8a10                 mov dl, byte ptr [eax]
// 0050eb45  40                   inc eax
// 0050eb46  84d2                 test dl, dl
// 0050eb48  75f9                 jne 0x50eb43
// 0050eb4a  2bc6                 sub eax, esi
// 0050eb4c  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 0050eb50  5e                   pop esi
// 0050eb51  80fa5c               cmp dl, 0x5c
// 0050eb54  7506                 jne 0x50eb5c
// 0050eb56  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 0050eb5b  c3                   ret 
// 0050eb5c  80fa2f               cmp dl, 0x2f
// 0050eb5f  7409                 je 0x50eb6a
// 0050eb61  c604082f             mov byte ptr [eax + ecx], 0x2f
// 0050eb65  c644080100           mov byte ptr [eax + ecx + 1], 0
// 0050eb6a  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
