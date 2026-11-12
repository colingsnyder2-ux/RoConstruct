// from server: 100% by auto
// roc 2009-06 004e0d50  unit: RBX::Network::IdSerializer  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e0d50
//
// 004e0d50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004e0d54  85c9                 test ecx, ecx
// 004e0d56  7432                 je 0x4e0d8a
// 004e0d58  803900               cmp byte ptr [ecx], 0
// 004e0d5b  742d                 je 0x4e0d8a
// 004e0d5d  8bc1                 mov eax, ecx
// 004e0d5f  56                   push esi
// 004e0d60  8d7001               lea esi, [eax + 1]
// 004e0d63  8a10                 mov dl, byte ptr [eax]
// 004e0d65  40                   inc eax
// 004e0d66  84d2                 test dl, dl
// 004e0d68  75f9                 jne 0x4e0d63
// 004e0d6a  2bc6                 sub eax, esi
// 004e0d6c  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 004e0d70  5e                   pop esi
// 004e0d71  80fa5c               cmp dl, 0x5c
// 004e0d74  7506                 jne 0x4e0d7c
// 004e0d76  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 004e0d7b  c3                   ret 
// 004e0d7c  80fa2f               cmp dl, 0x2f
// 004e0d7f  7409                 je 0x4e0d8a
// 004e0d81  c604082f             mov byte ptr [eax + ecx], 0x2f
// 004e0d85  c644080100           mov byte ptr [eax + ecx + 1], 0
// 004e0d8a  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
