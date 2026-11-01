// from server: 100% by auto
// roc 2009-06 00732e50  unit: CXTPImageManagerResource::CBitmapDC  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732e50
//
// 00732e50  56                   push esi
// 00732e51  8bf1                 mov esi, ecx
// 00732e53  8b4610               mov eax, dword ptr [esi + 0x10]
// 00732e56  c7061c308f00         mov dword ptr [esi], 0x8f301c
// 00732e5c  85c0                 test eax, eax
// 00732e5e  740b                 je 0x732e6b
// 00732e60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00732e63  50                   push eax
// 00732e64  51                   push ecx
// 00732e65  ff1524e18900         call dword ptr [0x89e124]
// 00732e6b  8bce                 mov ecx, esi
// 00732e6d  e8d0901100           call 0x84bf42
// 00732e72  f644240801           test byte ptr [esp + 8], 1
// 00732e77  7409                 je 0x732e82
// 00732e79  56                   push esi
// 00732e7a  e8b35bfeff           call 0x718a32
// 00732e7f  83c404               add esp, 4
// 00732e82  8bc6                 mov eax, esi
// 00732e84  5e                   pop esi
// 00732e85  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??_GCBitmapDC@CXTPImageManagerResource@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
