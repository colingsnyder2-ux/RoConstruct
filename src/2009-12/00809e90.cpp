// from server: 100% by auto
// roc 2009-12 00809e90  unit: CXTPImageManagerResource::CBitmapDC  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809e90
//
// 00809e90  56                   push esi
// 00809e91  8bf1                 mov esi, ecx
// 00809e93  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00809e97  85c9                 test ecx, ecx
// 00809e99  7427                 je 0x809ec2
// 00809e9b  85f6                 test esi, esi
// 00809e9d  7511                 jne 0x809eb0
// 00809e9f  33c0                 xor eax, eax
// 00809ea1  51                   push ecx
// 00809ea2  50                   push eax
// 00809ea3  ff154cb19800         call dword ptr [0x98b14c]
// 00809ea9  894610               mov dword ptr [esi + 0x10], eax
// 00809eac  5e                   pop esi
// 00809ead  c20400               ret 4
// 00809eb0  8b4604               mov eax, dword ptr [esi + 4]
// 00809eb3  51                   push ecx
// 00809eb4  50                   push eax
// 00809eb5  ff154cb19800         call dword ptr [0x98b14c]
// 00809ebb  894610               mov dword ptr [esi + 0x10], eax
// 00809ebe  5e                   pop esi
// 00809ebf  c20400               ret 4
// 00809ec2  8b4610               mov eax, dword ptr [esi + 0x10]
// 00809ec5  85c0                 test eax, eax
// 00809ec7  7412                 je 0x809edb
// 00809ec9  8b4e04               mov ecx, dword ptr [esi + 4]
// 00809ecc  50                   push eax
// 00809ecd  51                   push ecx
// 00809ece  ff154cb19800         call dword ptr [0x98b14c]
// 00809ed4  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00809edb  5e                   pop esi
// 00809edc  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetBitmap@CBitmapDC@CXTPImageManagerResource@@QAEXPAUHBITMAP__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
