// from server: 100% by auto
// roc 2009-12 00566660  unit: RakPeer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00566660
//
// 00566660  8b4104               mov eax, dword ptr [ecx + 4]
// 00566663  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00566666  56                   push esi
// 00566667  57                   push edi
// 00566668  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0056666c  8d3438               lea esi, [eax + edi]
// 0056666f  3bf2                 cmp esi, edx
// 00566671  720e                 jb 0x566681
// 00566673  8b09                 mov ecx, dword ptr [ecx]
// 00566675  2bc2                 sub eax, edx
// 00566677  03c7                 add eax, edi
// 00566679  5f                   pop edi
// 0056667a  8d0481               lea eax, [ecx + eax*4]
// 0056667d  5e                   pop esi
// 0056667e  c20400               ret 4
// 00566681  8b11                 mov edx, dword ptr [ecx]
// 00566683  5f                   pop edi
// 00566684  8d04b2               lea eax, [edx + esi*4]
// 00566687  5e                   pop esi
// 00566688  c20400               ret 4
// library raknet-4.081/FileList.cpp (function ??A?$Queue@PAD@DataStructures@@QBEAAPADI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FileList.cpp
