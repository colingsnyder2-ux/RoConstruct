// from server: 100% by auto
// roc 2009-12 00809ee0  unit: CXTPImageManagerResource::CBitmapDC  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809ee0
//
// 00809ee0  56                   push esi
// 00809ee1  8bf1                 mov esi, ecx
// 00809ee3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00809ee6  c70604309f00         mov dword ptr [esi], 0x9f3004
// 00809eec  85c0                 test eax, eax
// 00809eee  740b                 je 0x809efb
// 00809ef0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00809ef3  50                   push eax
// 00809ef4  51                   push ecx
// 00809ef5  ff154cb19800         call dword ptr [0x98b14c]
// 00809efb  8bce                 mov ecx, esi
// 00809efd  e8a6c51100           call 0x9264a8
// 00809f02  f644240801           test byte ptr [esp + 8], 1
// 00809f07  7409                 je 0x809f12
// 00809f09  56                   push esi
// 00809f0a  e84b99feff           call 0x7f385a
// 00809f0f  83c404               add esp, 4
// 00809f12  8bc6                 mov eax, esi
// 00809f14  5e                   pop esi
// 00809f15  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??_GCBitmapDC@CXTPImageManagerResource@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
