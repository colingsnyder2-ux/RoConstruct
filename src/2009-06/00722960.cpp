// from server: 100% by auto
// roc 2009-06 00722960  unit: CXTPPaintManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00722960
//
// 00722960  8b0d4419a500         mov ecx, dword ptr [0xa51944]
// 00722966  85c9                 test ecx, ecx
// 00722968  7405                 je 0x72296f
// 0072296a  e83966ffff           call 0x718fa8
// 0072296f  c7054419a50000000000 mov dword ptr [0xa51944], 0
// 00722979  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Done@CXTPPaintManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
