// from server: 100% by auto
// roc 2010-06 007bdff0  unit: CXTPImageManagerResource::CBitmapDC  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdff0
//
// 007bdff0  56                   push esi
// 007bdff1  8bf1                 mov esi, ecx
// 007bdff3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007bdff7  85c9                 test ecx, ecx
// 007bdff9  7427                 je 0x7be022
// 007bdffb  85f6                 test esi, esi
// 007bdffd  7511                 jne 0x7be010
// 007bdfff  33c0                 xor eax, eax
// 007be001  51                   push ecx
// 007be002  50                   push eax
// 007be003  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007be009  894610               mov dword ptr [esi + 0x10], eax
// 007be00c  5e                   pop esi
// 007be00d  c20400               ret 4
// 007be010  8b4604               mov eax, dword ptr [esi + 4]
// 007be013  51                   push ecx
// 007be014  50                   push eax
// 007be015  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007be01b  894610               mov dword ptr [esi + 0x10], eax
// 007be01e  5e                   pop esi
// 007be01f  c20400               ret 4
// 007be022  8b4610               mov eax, dword ptr [esi + 0x10]
// 007be025  85c0                 test eax, eax
// 007be027  7412                 je 0x7be03b
// 007be029  8b4e04               mov ecx, dword ptr [esi + 4]
// 007be02c  50                   push eax
// 007be02d  51                   push ecx
// 007be02e  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007be034  c7461000000000       mov dword ptr [esi + 0x10], 0
// 007be03b  5e                   pop esi
// 007be03c  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?SetBitmap@CBitmapDC@CXTPImageManagerResource@@QAEXPAUHBITMAP__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
