// roc 2012-06 0059a050  unit: RBX::Network::Marker  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a050
//
// 0059a050  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0059a054  85c9                 test ecx, ecx
// 0059a056  7432                 je 0x59a08a
// 0059a058  803900               cmp byte ptr [ecx], 0
// 0059a05b  742d                 je 0x59a08a
// 0059a05d  8bc1                 mov eax, ecx
// 0059a05f  56                   push esi
// 0059a060  8d7001               lea esi, [eax + 1]
// 0059a063  8a10                 mov dl, byte ptr [eax]
// 0059a065  40                   inc eax
// 0059a066  84d2                 test dl, dl
// 0059a068  75f9                 jne 0x59a063
// 0059a06a  2bc6                 sub eax, esi
// 0059a06c  8a5408ff             mov dl, byte ptr [eax + ecx - 1]
// 0059a070  5e                   pop esi
// 0059a071  80fa5c               cmp dl, 0x5c
// 0059a074  7506                 jne 0x59a07c
// 0059a076  c64408ff2f           mov byte ptr [eax + ecx - 1], 0x2f
// 0059a07b  c3                   ret 
// 0059a07c  80fa2f               cmp dl, 0x2f
// 0059a07f  7409                 je 0x59a08a
// 0059a081  c604082f             mov byte ptr [eax + ecx], 0x2f
// 0059a085  c644080100           mov byte ptr [eax + ecx + 1], 0
// 0059a08a  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?AddSlash@@YAXPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
