// from server: 100% by auto
// roc 2009-06 00732e00  unit: CXTPImageManagerResource::CBitmapDC  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732e00
//
// 00732e00  56                   push esi
// 00732e01  8bf1                 mov esi, ecx
// 00732e03  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00732e07  85c9                 test ecx, ecx
// 00732e09  7427                 je 0x732e32
// 00732e0b  85f6                 test esi, esi
// 00732e0d  7511                 jne 0x732e20
// 00732e0f  33c0                 xor eax, eax
// 00732e11  51                   push ecx
// 00732e12  50                   push eax
// 00732e13  ff1524e18900         call dword ptr [0x89e124]
// 00732e19  894610               mov dword ptr [esi + 0x10], eax
// 00732e1c  5e                   pop esi
// 00732e1d  c20400               ret 4
// 00732e20  8b4604               mov eax, dword ptr [esi + 4]
// 00732e23  51                   push ecx
// 00732e24  50                   push eax
// 00732e25  ff1524e18900         call dword ptr [0x89e124]
// 00732e2b  894610               mov dword ptr [esi + 0x10], eax
// 00732e2e  5e                   pop esi
// 00732e2f  c20400               ret 4
// 00732e32  8b4610               mov eax, dword ptr [esi + 0x10]
// 00732e35  85c0                 test eax, eax
// 00732e37  7412                 je 0x732e4b
// 00732e39  8b4e04               mov ecx, dword ptr [esi + 4]
// 00732e3c  50                   push eax
// 00732e3d  51                   push ecx
// 00732e3e  ff1524e18900         call dword ptr [0x89e124]
// 00732e44  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00732e4b  5e                   pop esi
// 00732e4c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetBitmap@CBitmapDC@CXTPImageManagerResource@@QAEXPAUHBITMAP__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
