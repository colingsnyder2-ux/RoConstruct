// from server: 100% by auto
// roc 2008-06 004a9b30  unit: seg_004a0000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a9b30
//
// 004a9b30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004a9b34  85c9                 test ecx, ecx
// 004a9b36  7432                 je 0x4a9b6a
// 004a9b38  803900               cmp byte ptr [ecx], 0
// 004a9b3b  742d                 je 0x4a9b6a
// 004a9b3d  8bc1                 mov eax, ecx
// 004a9b3f  56                   push esi
// 004a9b40  8d7001               lea esi, [eax + 1]
// 004a9b43  8a10                 mov dl, byte ptr [eax]
// 004a9b45  40                   inc eax
// 004a9b46  84d2                 test dl, dl
// 004a9b48  75f9                 jne 0x4a9b43
// 004a9b4a  2bc6                 sub eax, esi
// 004a9b4c  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 004a9b50  5e                   pop esi
// 004a9b51  80fa5c               cmp dl, 0x5c
// 004a9b54  7506                 jne 0x4a9b5c
// 004a9b56  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 004a9b5b  c3                   ret 
// 004a9b5c  80fa2f               cmp dl, 0x2f
// 004a9b5f  7409                 je 0x4a9b6a
// 004a9b61  c604082f             mov byte ptr [eax + ecx], 0x2f
// 004a9b65  c644080100           mov byte ptr [eax + ecx + 1], 0
// 004a9b6a  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
