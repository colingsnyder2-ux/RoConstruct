// from server: 100% by auto
// roc 2010-06 007be040  unit: CXTPImageManagerResource::CBitmapDC  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be040
//
// 007be040  56                   push esi
// 007be041  8bf1                 mov esi, ecx
// 007be043  8b4610               mov eax, dword ptr [esi + 0x10]
// 007be046  c706ec72a500         mov dword ptr [esi], 0xa572ec
// 007be04c  85c0                 test eax, eax
// 007be04e  740b                 je 0x7be05b
// 007be050  8b4e04               mov ecx, dword ptr [esi + 4]
// 007be053  50                   push eax
// 007be054  51                   push ecx
// 007be055  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007be05b  8bce                 mov ecx, esi
// 007be05d  e846ed1b00           call 0x97cda8
// 007be062  f644240801           test byte ptr [esp + 8], 1
// 007be067  7409                 je 0x7be072
// 007be069  56                   push esi
// 007be06a  e82b99feff           call 0x7a799a
// 007be06f  83c404               add esp, 4
// 007be072  8bc6                 mov eax, esi
// 007be074  5e                   pop esi
// 007be075  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ??_GCBitmapDC@CXTPImageManagerResource@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
