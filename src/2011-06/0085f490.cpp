// from server: 100% by auto
// roc 2011-06 0085f490  unit: CXTPPrintingDialog  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f490
//
// 0085f490  c701a4a8ac00         mov dword ptr [ecx], 0xaca8a4
// 0085f496  83c108               add ecx, 8
// 0085f499  ff25082ea400         jmp dword ptr [0xa42e08]
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ??1CXTPPropExchangeEnumerator@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
