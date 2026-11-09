// from server: 100% by auto
// roc 2010-06 00803fb0  unit: CXTPPropertyGrid  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803fb0
//
// 00803fb0  c7010406a600         mov dword ptr [ecx], 0xa60604
// 00803fb6  83c108               add ecx, 8
// 00803fb9  ff25f0ce9e00         jmp dword ptr [0x9ecef0]
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ??1CXTPPropExchangeEnumerator@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
