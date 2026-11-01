// from server: 100% by auto
// roc 2011-06 00851d10  unit: CSourceStream  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00851d10
//
// 00851d10  56                   push esi
// 00851d11  8bf1                 mov esi, ecx
// 00851d13  c7065882ac00         mov dword ptr [esi], 0xac8258
// 00851d19  e8d2f4ffff           call 0x8511f0
// 00851d1e  8d4e04               lea ecx, [esi + 4]
// 00851d21  5e                   pop esi
// 00851d22  ff25082ea400         jmp dword ptr [0xa42e08]
// library xtp-15.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ??1CXTPModuleHandle@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
