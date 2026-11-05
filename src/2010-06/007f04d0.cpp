// from server: 100% by auto
// roc 2010-06 007f04d0  unit: CPatchedControlComboBox  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f04d0
//
// 007f04d0  56                   push esi
// 007f04d1  8bf1                 mov esi, ecx
// 007f04d3  c70610c6a500         mov dword ptr [esi], 0xa5c610
// 007f04d9  e8c2f4ffff           call 0x7ef9a0
// 007f04de  8d4e04               lea ecx, [esi + 4]
// 007f04e1  5e                   pop esi
// 007f04e2  ff25f0ce9e00         jmp dword ptr [0x9ecef0]
// library xtp-13.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ??1CXTPModuleHandle@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
